/* Images
 *
 * GtkImage is used to display an image; the image can be in a number of formats.
 * Typically, you load an image into a GdkPixbuf, then display the pixbuf.
 *
 * This demo code shows some of the more obscure cases, in the simple
 * case a call to gtk_image_new_from_file() is all you need.
 *
 * If you want to put image data in your program as a C variable,
 * use the make-inline-pixbuf program that comes with GTK+.
 * This way you won't need to depend on loading external files, your
 * application binary can be self-contained.
 */

#include <gtkmm.h>
#include "demo-common.h"

class Example_Images : public Gtk::Window
{
public:
  Example_Images();
  virtual ~Example_Images();

protected:
  virtual void start_progressive_loading();

  //signal handler:
  virtual bool on_timeout();
  virtual void on_loader_area_prepared();
  virtual void on_loader_area_updated(int x, int y, int width, int height);

  //Member widgets:
  Gtk::VBox m_VBox;
  Gtk::Label m_Label_Image, m_Label_Animation, m_Label_Progressive;
  Gtk::Frame m_Frame_Image, m_Frame_Animation, m_Frame_Progressive;
  Gtk::Alignment m_Alignment_Image, m_Alignment_Animation, m_Alignment_Progressive;
  Gtk::Image m_Image_Progressive;
  Glib::RefPtr<Gdk::PixbufLoader> m_refPixbufLoader;

  Glib::RefPtr<Glib::IOChannel> m_image_stream;
};

//Called by DemoWindow;
Gtk::Window* do_images()
{
  return new Example_Images();
}

Example_Images::Example_Images()
:
  m_VBox                (false, 8),
  m_Alignment_Image     (0.5, 0.5, 0, 0),
  m_Alignment_Animation (0.5, 0.5, 0, 0),
  m_image_stream        (0)
{
  set_title("Images");
  set_border_width(8);

  m_VBox.set_border_width(8);
  add(m_VBox);

  /* Image */

  m_Label_Image.set_markup("<u>Image loaded from a file</u>");
  m_VBox.pack_start(m_Label_Image, Gtk::PACK_SHRINK);

  m_Frame_Image.set_shadow_type(Gtk::SHADOW_IN);

  /* The alignment keeps the frame from growing when users resize
   * the window
   */
  m_Alignment_Image.add(m_Frame_Image);
  m_VBox.pack_start(m_Alignment_Image, Gtk::PACK_SHRINK);

  Gtk::Image* pImage = Gtk::manage(new Gtk::Image(demo_find_file("gtk-logo-rgb.gif")));
  m_Frame_Image.add(*pImage);

  /* Animation */

  m_Label_Animation.set_markup("<u>Animation loaded from a file</u>");
  m_VBox.pack_start(m_Label_Animation, Gtk::PACK_SHRINK);

  m_Frame_Animation.set_shadow_type(Gtk::SHADOW_IN);

  /* The alignment keeps the frame from growing when users resize
   * the window
   */
  m_Alignment_Animation.add(m_Frame_Animation);
  m_VBox.pack_start(m_Alignment_Animation, Gtk::PACK_SHRINK);

  pImage = Gtk::manage(new Gtk::Image(demo_find_file("floppybuddy.gif")));
  m_Frame_Animation.add(*pImage);

  /* Progressive */

  m_Label_Progressive.set_markup("<u>Progressive image loading</u>");
  m_VBox.pack_start(m_Label_Progressive, Gtk::PACK_SHRINK);

  m_Frame_Progressive.set_shadow_type(Gtk::SHADOW_IN);

  /* The alignment keeps the frame from growing when users resize
  * the window
  */
  m_Alignment_Progressive.add(m_Frame_Progressive);
  m_VBox.pack_start(m_Alignment_Progressive, Gtk::PACK_SHRINK);

  /* Create an empty image for now; the progressive loader
   * will create the pixbuf and fill it in.
   */
  m_Frame_Progressive.add(m_Image_Progressive);

  start_progressive_loading();

  show_all();
}

Example_Images::~Example_Images()
{
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
    if(m_refPixbufLoader)
      m_refPixbufLoader->close();
  }
  catch(const Gdk::PixbufError&)
  {
    // ignore errors
  }
  #else
  std::auto_ptr<Glib::Error> error;
  if(m_refPixbufLoader)
      m_refPixbufLoader->close(error);
  #endif //GLIBMM_EXCEPTIONS_ENABLED
}

void Example_Images::start_progressive_loading()
{
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &Example_Images::on_timeout), 150);
}

bool Example_Images::on_timeout()
{
  /* This shows off fully-paranoid error handling, so looks scary.
   * You could factor out the error handling code into a nice separate
   * function to make things nicer.
   */

  if(m_image_stream)
  {
    guint8 buf[256];
    gsize bytes_read = 0;
    Glib::IOStatus status = Glib::IO_STATUS_NORMAL;

    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
      status = m_image_stream->read(reinterpret_cast<char*>(&buf[0]), sizeof(buf), bytes_read);
    }
    catch(const Glib::Error& error)
    {
    #else
    std::auto_ptr<Glib::Error> error;
    status = m_image_stream->read(reinterpret_cast<char*>(&buf[0]), sizeof(buf), bytes_read, error);
    if(error.get())
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
     
      Glib::ustring strMsg = "Failure reading image file 'alphatest.png': ";
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      strMsg += error.what();
      #else
      strMsg += error->what();
      #endif //GLIBMM_EXCEPTIONS_ENABLED

      Gtk::MessageDialog dialog(strMsg, false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
      dialog.run();

      m_image_stream.clear();

      return false; // uninstall the timeout
    }

    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
      m_refPixbufLoader->write(buf, bytes_read);
    }
    catch(const Glib::Error& error)
    {
    #else
    //std::auto_ptr<Glib::Error> error;
    m_refPixbufLoader->write(buf, bytes_read, error);
    if(error.get())
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      Glib::ustring strMsg = "Failed to load image: ";

      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      strMsg += error.what();
      #else
      strMsg += error->what();
      #endif //GLIBMM_EXCEPTIONS_ENABLED

      Gtk::MessageDialog dialog(strMsg, false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
      dialog.run();

      m_image_stream.clear();

      return false; // uninstall the timeout
    }

    if(status == Glib::IO_STATUS_EOF)
    {
      m_image_stream.clear();

      /* Errors can happen on close, e.g. if the image
       * file was truncated we'll know on close that
       * it was incomplete.
       */

      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try
      {
        m_refPixbufLoader->close();
      }
      catch(const Glib::Error& error)
      {
      #else
      std::auto_ptr<Glib::Error> error;
      m_refPixbufLoader->close(error);
      if(error.get())
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        Glib::ustring strMsg = "Failed to load image: ";

        #ifdef GLIBMM_EXCEPTIONS_ENABLED
        strMsg += error.what();
        #else
        strMsg += error->what();
        #endif //GLIBMM_EXCEPTIONS_ENABLED

        Gtk::MessageDialog dialog(strMsg, false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
        dialog.run();

        m_refPixbufLoader.clear();

        return false; // uninstall the timeout
      }

      m_refPixbufLoader.clear();
    }
  }
  else
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
      m_image_stream = Glib::IOChannel::create_from_file(demo_find_file("alphatest.png"), "r");
    }
    catch(const Glib::Error& error)
    {
    #else
    std::auto_ptr<Glib::Error> error;
    m_image_stream = Glib::IOChannel::create_from_file(demo_find_file("alphatest.png"), "r", error);
    if(error.get())
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED

      Glib::ustring strMsg = "Unable to open image file 'alphatest.png': ";
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      strMsg += error.what();
      #else
      strMsg += error->what();
      #endif //GLIBMM_EXCEPTIONS_ENABLED

      Gtk::MessageDialog dialog(strMsg, false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
      dialog.run();

      return false; // uninstall the timeout
    }

    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    m_image_stream->set_encoding(); // no encoding == binary
    #else
    m_image_stream->set_encoding("", error); // no encoding == binary
    #endif //GLIBMM_EXCEPTIONS_ENABLED

    if(m_refPixbufLoader)
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      m_refPixbufLoader->close();
      #else
      std::auto_ptr<Glib::Error> error;
      m_refPixbufLoader->close(error);
      #endif //GLIBMM_EXCEPTIONS_ENABLED

      m_refPixbufLoader.clear();
    }

    m_refPixbufLoader = Gdk::PixbufLoader::create();

    m_refPixbufLoader->signal_area_prepared().connect(
        sigc::mem_fun(*this, &Example_Images::on_loader_area_prepared));

    m_refPixbufLoader->signal_area_updated().connect(
        sigc::mem_fun(*this, &Example_Images::on_loader_area_updated));
  }

  return true; // leave timeout installed
}

void Example_Images::on_loader_area_prepared()
{
  const Glib::RefPtr<Gdk::Pixbuf> refPixbuf = m_refPixbufLoader->get_pixbuf();

  /* Avoid displaying random memory contents, since the pixbuf
   * isn't filled in yet.
   */
  refPixbuf->fill(0xaaaaaaff);
  m_Image_Progressive.set(refPixbuf);
}

void Example_Images::on_loader_area_updated(int/*x*/, int/*y*/, int/*width*/, int/*height*/)
{
  /* We know the pixbuf inside the Gtk::Image has changed, but the image
   * itself doesn't know this; so queue a redraw.  If we wanted to be
   * really efficient, we could use a drawing area or something
   * instead of a GtkImage, so we could control the exact position of
   * the pixbuf on the display, then we could queue a draw for only
   * the updated area of the image.
   */
  m_Image_Progressive.queue_draw();
}

