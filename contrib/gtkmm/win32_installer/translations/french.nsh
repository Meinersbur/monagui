;;
;;  french.nsh
;;
;;  French language strings for the Windows gtkmm NSIS installer.
;;  Windows Code page: 1252
;;
;;  Author: Eric Boumaour <zongo@nekeme.net>, 2003.
;;

LangString GTK_RUNTIME_REQUIRED	        ${LANG_FRENCH} \
  "Le GTK+ $R1 Runtime Environment est n�cessaire pour pouvoir utiliser gtkmm. D�sirez-vous l'installer maintenant ?$\n$\nCliquez 'Oui' pour d�charger puis installer GTK+ $R1, 'Non' pour passer cette �tape ou 'Annuler' pour annuler l'installation de gtkmm."
LangString GTK_DEVEL_REQUIRED           ${LANG_FRENCH} \
  "Le GTK+ $R1 Development Environment est n�cessaire pour pouvoir utiliser gtkmm. D�sirez-vous l'installer maintenant ?$\n$\nCliquez 'Oui' pour d�charger puis installer GTK+ $R1, 'Non' pour passer cette �tape ou 'Annuler' pour annuler l'installation de gtkmm."
LangString GTK_GET_VERSION		${LANG_FRENCH} "Acquisition de la version de l'installeur GTK+"
LangString GTK_DOWNLOADING		${LANG_FRENCH} "Dechargement de l'installeur GTK+"
LangString GTK_STARTING	        	${LANG_FRENCH} "Lancement de l'installeur GTK+"
LangString GTK_FINISHED        	        ${LANG_FRENCH} "Installation de GTK+ termin�e"
LangString GTK_INTERRUPTED 	        ${LANG_FRENCH} "L'installeur GTK+ s'est arr�t� de mani�re anormale"
LangString GTK_INTERRUPT_REASON         ${LANG_FRENCH} \
  "L'installeur GTK+ va s'arr�ter pour la raison suivante : $2.$\n$\nD�sirez-vous poursuivre l'installation de gtkmm ?"

LangString MISC_DOWNLOAD_CANCELLED     	${LANG_FRENCH} "D�chargement annul�"
LangString MISC_DOWNLOAD_ERROR          ${LANG_FRENCH} "Erreur inconnue durant le d�chargement"
LangString MISC_ADMIN_REQUIRED          ${LANG_FRENCH} \
  "Des droits administrateur sont n�cessaires pour d�sinstaller${PRODUCT_NAME}. L'installation va s'arr�ter maintenant..."
LangString MISC_INSTALL_OPTION          ${LANG_FRENCH} "Option d'installation"
LangString MISC_UNINSTALL_CONTEXT       ${LANG_FRENCH} \
  "${PRODUCT_NAME} peut �tre install� pour tous les utilisateurs ou uniquement l'utilisateur actuel."
LangString MISC_ANSWER_SYSTEM           ${LANG_FRENCH} \
  "Veuillez r�pondre aux questions suivantes relatives � votre syst�me."


LangString GTKMM_PREVIOUS_VERSION       ${LANG_FRENCH} \
"Une version pr�c�dente de ${PRODUCT_NAME} ($R1) a �t� d�tect�e. Etes-vous d'accord de la d�sinstaller maintenant ? $\n$\nCliquer sur `Oui` pour supprimer \
  la version pr�c�dente, `Non` pour l'�craser, ou `Annuler` pour annuler cette mise � jour."
LangString GTKMM_PREVIOUS_ERROR         ${LANG_FRENCH} \
  "Une erreur s'est produite ou une version pr�c�dente de ${PRODUCT_NAME} ($R1) n'a pas �t� correctement d�sinstall�e. \
   L'installation va s'arr�ter maintenant."
LangString GTKMM_NEWER                  ${LANG_FRENCH} \
"${PRODUCT_NAME} ($R1) est d�j� install� sur votre syst�me, et est plus r�cent que cette distribution (${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER})."
   
LangString GTKMM_ADD_PATH               ${LANG_FRENCH} \
"Ajouter le repertoire racine de gtkmm � la variable PATH"

LangString GTKMM_RIGHTS_INSTALL         ${LANG_FRENCH} \
"Installer pour"
LangString GTKMM_RIGHTS_ANYONE          ${LANG_FRENCH} \
"Tous les utilisateurs de cet ordinateur"
LangString GTKMM_RIGHTS_CURRENT         ${LANG_FRENCH} \
"Uniquement l'utilisateur actuel"
