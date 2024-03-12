#! /bin/sh

# Clear old filelist.am 
echo > filelist.am


### Monagui ###

echo src_cpp = \\ >> filelist.am
find -maxdepth 2 -wholename './src/*.cpp' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo src_c = \\ >> filelist.am
find -maxdepth 2 -wholename './src/*.c' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo src_h = \\ >> filelist.am
find -maxdepth 2 -wholename './src/*.h' -printf ' %P'  >> filelist.am
echo >> filelist.am
echo >> filelist.am


echo src_front2_cpp = \\ >> filelist.am
find -wholename './src/front2/*.cpp' -printf '%P\n' | grep 'parser\.cpp' -v | grep 'scanner\.cpp' -v | grep 'completiongen\.cpp' -v | grep 'activetable\.cpp' -v | grep 'completiontable\.cpp' -v | xargs echo >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo src_front2_c = \\ >> filelist.am
find -wholename './src/front2/*.c' -printf '%P\n' | xargs echo >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo src_front2_h = \\ >> filelist.am
find -wholename './src/front2/*.h' -printf '%P\n'  | grep 'parser\.h' -v | grep 'completiongen\.h' -v | grep 'activetable\.h' -v | grep 'completiontable\.h' -v | xargs echo  >> filelist.am
echo >> filelist.am
echo >> filelist.am


### Mona ###

echo contrib_mona_bdd_c = \\ >> filelist.am
find -wholename './contrib/mona/BDD/*.c' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_bdd_h = \\ >> filelist.am
find -wholename './contrib/mona/BDD/*.h' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_dfa_c = \\ >> filelist.am
find -wholename './contrib/mona/DFA/*.c' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_dfa_h = \\ >> filelist.am
find -wholename './contrib/mona/DFA/*.h' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_gta_c = \\ >> filelist.am
find -wholename './contrib/mona/GTA/*.c' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_gta_h = \\ >> filelist.am
find -wholename './contrib/mona/GTA/*.h' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_mem_c = \\ >> filelist.am
find -wholename './contrib/mona/Mem/*.c' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_mona_mem_h = \\ >> filelist.am
find -wholename './contrib/mona/Mem/*.h' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am


### Other contrib  ###

## Boost

echo contrib_boost_hpp = \\ >> filelist.am
find -wholename './contrib/boost/*.hpp' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_boost_cpp = \\ >> filelist.am
find -wholename './contrib/boost/*.cpp' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am


## Gtksourceviewmm

echo contrib_gtksourceviewmm_h = \\ >> filelist.am
find -wholename './contrib/gtksourceviewmm/*.h' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am

echo contrib_gtksourceviewmm_cc = \\ >> filelist.am
find -wholename './contrib/gtksourceviewmm/*.cc' -printf ' %P' >> filelist.am
echo >> filelist.am
echo >> filelist.am


## gtkmm and its dependencies

#echo contrib_glibmm_h = \\ >> filelist.am
#find -wholename './contrib/glibmm/*.h' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_glibmm_cc = \\ >> filelist.am
#find -wholename './contrib/glibmm/*.cc' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_atkmm_h = \\ >> filelist.am
#find -wholename './contrib/atkmm/*.h' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_atkmm_cc = \\ >> filelist.am
#find -wholename './contrib/atkmm/*.cc' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_cairomm_h = \\ >> filelist.am
#find -wholename './contrib/cairomm/*.h' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_cairomm_cc = \\ >> filelist.am
#find -wholename './contrib/cairomm/*.cc' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_pangomm_h = \\ >> filelist.am
#find -wholename './contrib/pangomm/*.h' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_pangomm_cc = \\ >> filelist.am
#find -wholename './contrib/pangomm/*.cc' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_gtkmm_h = \\ >> filelist.am
#find -wholename './contrib/gtkmm/*.h' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_gtkmm_cc = \\ >> filelist.am
#find -wholename './contrib/gtkmm/*.cc' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_sigcmm_h = \\ >> filelist.am
#find -wholename './contrib/sigc++/*.h' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am

#echo contrib_sigcmm_cc = \\ >> filelist.am
#find -wholename './contrib/sigc++/*.cc' -printf ' %P' >> filelist.am
#echo >> filelist.am
#echo >> filelist.am



