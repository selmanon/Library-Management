GtkWidget *pWindow;
const gchar *Titre;
const gchar *Auteur;
const gchar *Annee;
const gchar *Edition;
const gchar *Placard;
const gchar *Date;
const gchar *Personne;
const gchar *sLabel;
const gchar *rechercher;


typedef struct Livre_
{
char Titre[20];
char Auteur[20];
char Annee[20];
char  Edition[20];
char  Placard[20];
struct Livre_*next;
}livre;


typedef struct Emprunt_
{
char Titre[20];
char Date[20];
char Personne[20];
struct Emprunt_*next;
}emprunt;

livre*premier=NULL;


emprunt*premier1=NULL;




void OnQuitter(GtkWidget* widget, gpointer data)
{
GtkWidget *pQuestion;
pQuestion = gtk_message_dialog_new(GTK_WINDOW(data),
GTK_DIALOG_MODAL,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_YES_NO,
"Voulez vous vraiment\n"
"quitter le programme?");
switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
{
case GTK_RESPONSE_YES:
gtk_main_quit();
break;
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_NO:
gtk_widget_destroy(pQuestion);
break;
}
}


void OnAbout(GtkWidget* widget, gpointer data)
{
GtkWidget*pBoite,*Frame,*pvbox,*phbox,*plabel;
gint resultat_choix;
pBoite = gtk_dialog_new_with_buttons("Apropos de ...",GTK_WINDOW(pWindow),GTK_DIALOG_NO_SEPARATOR,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 10);



phbox= gtk_hbox_new(TRUE, 0);
gtk_box_pack_start(GTK_BOX(pvbox),phbox ,FALSE,FALSE, 10);
plabel=gtk_label_new(NULL);
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Georgia 17\"foreground=\"#FF9900\">Mini Projet </span>");
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_CENTER);
gtk_box_pack_start(GTK_BOX(phbox),plabel ,FALSE,FALSE, 10);




phbox= gtk_hbox_new(TRUE, 0);
plabel=gtk_label_new(NULL);
gtk_box_pack_start(GTK_BOX(pvbox),phbox ,FALSE,FALSE, 10);
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Georgia 17\"foreground=\"#FF9900\">Copirght@2009 Abdellah SELASSI </span>");
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_CENTER);
gtk_box_pack_start(GTK_BOX(phbox),plabel ,FALSE,FALSE, 10);


phbox= gtk_hbox_new(TRUE, 0);
gtk_box_pack_start(GTK_BOX(pvbox),phbox ,FALSE,FALSE, 10);
plabel=gtk_label_new(NULL);
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Georgia 13\"foreground=\"#FF9900\">Version 1.0 </span>");
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_CENTER);
gtk_box_pack_start(GTK_BOX(phbox),plabel ,FALSE,FALSE, 10);




gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));


switch (resultat_choix)
{
/* L utilisateur valide */

case GTK_RESPONSE_OK:gtk_widget_destroy(pBoite);}

}


void Msg_Emprunt(GtkWidget* widget, gpointer data,gchar *msg)
{
GtkWidget *pAbout;
pAbout = gtk_message_dialog_new (GTK_WINDOW(data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,msg);
gtk_dialog_run(GTK_DIALOG(pAbout));
gtk_widget_destroy(pAbout);
}


void Vide(void)
{
GtkWidget *pAbout;
pAbout = gtk_message_dialog_new (GTK_WINDOW(NULL),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Il faut que les champs soient remplis");
gtk_dialog_run(GTK_DIALOG(pAbout));
gtk_widget_destroy(pAbout);
}

void Ajouter_Livre_Fichier(void){
                               FILE*e=0;               
                               e = fopen("livre.txt","a+");
                               fprintf(e,"%s\t%s\t%s\t%s\t%s\n",Titre,Auteur,Annee,Edition,Placard);
                               fclose(e);
}


void supprimer(char t1[],char t2[],char t3[],char t4[],char t5[])
{
  /* Déclarations : */
  /* Noms des fichiers et pointeurs de référence */
  FILE *INFILE, *OUTFILE;
  /* Autres variables */
int tr=0,tr2=0;
  char te1[20],te2[20],te3[22],te4[22],te5[22];
  /* Ouverture de l'ancien fichier en lecture */
  do
    {
     INFILE = fopen("LIVRE.txt", "r");
     if (!INFILE)
	 printf("\aERREUR: Impossible d'ouvrir "
		"le fichier: %s.\n","LIVRE.txt");
    }
  while (!INFILE);
  /* Ouverture du nouveau fichier en écriture */
  do
    {
     OUTFILE = fopen("NOUVEAU.txt", "w");
     if (!OUTFILE)
	 printf("\aERREUR: Impossible d'ouvrir "
		"le fichier: %s.\n","NOUVEAU.txt");
    }
  while (!OUTFILE);
  /* Saisie de l'enregistrement à supprimer */
  /* Traitement */
  /* Copie de tous les enregistrements à */
  /* l'exception de celui à supprimer.   */
  while (!feof(INFILE))
    {    
    fscanf(INFILE, "%s\t%s\t%s\t%s\t%s\n",te1,te2,te3,te4,te5);
    if (tr==1 || strcmp(te1,t1) != 0 || strcmp(te2,t2) != 0 || strcmp(te3,t3) != 0 || strcmp(te4,t4) != 0 || strcmp(te5,t5) != 0){
   	fprintf(OUTFILE,"%s\t%s\t%s\t%s\t%s\n",te1,te2,te3,te4,te5);                                                                        }
    if(tr==0){
    if (strcmp(te1,t1) == 0 && strcmp(te2,t2) == 0 && strcmp(te3,t3) == 0 && strcmp(te4,t4) == 0 && strcmp(te5,t5) == 0)
    tr=1;
    }
}
  /* Fermeture des fichiers */
  fclose(OUTFILE);
  fclose(INFILE);

  remove("livre.txt");
  rename("NOUVEAU.txt","livre.txt");
  remove("NOUVEAU.txt");
}


void Supprimer_Livre_Fichier(void){      
FILE*f=0,*h=NULL; 
livre*n=NULL;
int tr=-1;
char Titre1[22],Annee1[20],Auteur1[20],Edition1[20],Placard1[20];
f = fopen(".txt","r");   


                                                                                                                                              
			       while(!feof(f)){          
			       n=(livre*)malloc(sizeof(livre));
			       fscanf(f,"%s\t%s\t%s\t%s\t%s\n",Titre1,Auteur1,Annee1,Edition1,Placard1);
			       strcpy(n->Titre,Titre1);
			       strcpy(n->Auteur,Auteur1);
			       strcpy(n->Annee,Annee1);
			       strcpy(n->Edition,Edition1);
			       strcpy(n->Placard,Placard1);
			       n->next=premier;
		           premier=n;			            		                    
			       }
			       fclose(f);
			      while(premier!=NULL){
         	      if(strcmp(premier->Titre,Titre)==0 && strcmp(premier->Auteur,Auteur)==0 && strcmp(premier->Annee,Annee)==0  && strcmp(premier->Edition,Edition)==0 && strcmp(premier->Placard,Placard)==0)
                  {
                  tr=1;

                  goto label;
                  }
premier=premier->next;
}  
label:

                         if(tr!=1){
                                     Msg_Emprunt(NULL,NULL,"Livre inexistant");  
                                     }   
                                     else{
                                          supprimer(Titre,Auteur,Annee,Edition,Placard);
                                          }           
          
          
                            
tr=-1;                                                                                                                                                                                   
}




void Ajouter_Livre(GtkWidget *pBtn, gpointer data)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget* pRadio1;
GtkWidget* pRadio2;
GtkWidget*pFrame;
GSList *pList;
const gchar* sNom;
gint resultat_choix;
/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("Ajouter ou supprimer un livre",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

pFrame = gtk_frame_new("titre");
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, TRUE, TRUE, 10);

phbox[1] = gtk_hbox_new(TRUE, 0);
phbox[2] = gtk_hbox_new(TRUE, 0);
phbox[3] = gtk_hbox_new(TRUE, 0);
phbox[4] = gtk_hbox_new(TRUE, 0);
phbox[5] = gtk_hbox_new(TRUE, 0);
phbox[6] = gtk_hbox_new(TRUE, 0);
phbox[7] = gtk_hbox_new(TRUE, 0);
phbox[8] = gtk_hbox_new(TRUE, 0);


gtk_box_pack_start(GTK_BOX(pvbox),phbox[1] ,FALSE,FALSE, 10);



plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Titre </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);
gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[1]), pEntry, TRUE, TRUE,0);
Titre=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[2] , TRUE, TRUE, 0);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Auteur</span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[2]), pEntry, TRUE, TRUE,0);
Auteur=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[3] , TRUE, TRUE, 10);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Annee </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);
gtk_box_pack_start(GTK_BOX(phbox[3]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[3]), pEntry, TRUE, TRUE,0);
Annee=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[4] , TRUE, TRUE, 0);

plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Edition </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[4]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[4]), pEntry, TRUE, TRUE,0);
Edition=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[5] , FALSE, FALSE, 0);

plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Placard </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[5]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[5]), pEntry, TRUE, TRUE,0);
Placard=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[7] , TRUE, TRUE, 8);
/* Creation du premier bouton radio */
pRadio1 = gtk_radio_button_new_with_label(NULL, "Enregistrer");
gtk_box_pack_start(GTK_BOX (phbox[7]), pRadio1,TRUE, TRUE, 5);


gtk_box_pack_start(GTK_BOX(pvbox),phbox[8] ,TRUE,TRUE,8);
/* Ajout du deuxieme */
pRadio2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(pRadio1), "Effacer");
gtk_box_pack_start(GTK_BOX (phbox[8]), pRadio2, TRUE, TRUE,5);



gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
/* On lance la boite de dialogue et on recupere la reponse */
resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));



switch (resultat_choix)
{
case GTK_RESPONSE_OK:
            
     /* Recuperation de la liste des boutons */
pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(pRadio1));
/* Parcours de la liste */
while(pList)
{
/* Le bouton est il selectionne */
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
{
/* OUI >
on copie le label du bouton */
sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
/* On met la liste a NULL pour sortir de la boucle */
pList = NULL;
}
else
{
/* NON >
on passe au bouton suivant */
pList = g_slist_next(pList);
}
}

if(strcmp(sLabel,"Enregistrer")==0){
                                   if(strcmp(Titre,"")==0 || strcmp(Auteur,"")==0 || strcmp(Annee,"")==0 || strcmp(Edition,"")==0 || strcmp(Placard,"")==0){
                                   Vide();
                                   }
                                   else{
                                   Ajouter_Livre_Fichier();  
                                   Msg_Emprunt(NULL,NULL,"Livre ajoute avec success");
                                   }
                                   }
if(strcmp(sLabel,"Effacer")==0){
                                   if(strcmp(Titre,"")==0 || strcmp(Auteur,"")==0 || strcmp(Annee,"")==0 || strcmp(Edition,"")==0 || strcmp(Placard,"")==0 ){
                                   Vide();
                                   }
                                   {
                                   Supprimer_Livre_Fichier();
                                   Msg_Emprunt(NULL,NULL,"Livre supprime avec success");                                   
                                   }
                                   }
                                                                 
                                   
                                   break;
}              
/* L utilisateur annule */
/* Destruction de la boite de dialogue */
gtk_widget_destroy(pBoite);
}















void Liste_Livre(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget*pFrame;
GtkWidget*pHBoxFrame;
int i=0,nbr_emprunt=Nombre_Emprunt();
gint resultat_choix;
char t1[20],t2[20],t3[20],t4[20],t5[20];
    int comp=0;
    FILE*p;

/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("Liste des livres",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
pFrame = gtk_frame_new("titre");
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 0);

phbox[1] = gtk_hbox_new(TRUE, 0);
phbox[2] = gtk_hbox_new(TRUE, 0);




gtk_box_pack_start(GTK_BOX(pvbox),phbox[1] , FALSE, FALSE, 0);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Titre </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Auteur </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Annee </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Edition </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Placard </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);



gtk_box_pack_start(GTK_BOX(pvbox),phbox[2] , FALSE, FALSE, 0);


plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);


p=fopen("livre.txt","r");    
    while(!feof(p)){
                    fscanf(p,"%s\t%s\t%s\t%s\t%s\n",t1,t2,t3,t4,t5);  
                    if(i<=nbr_emprunt){
                           phbox[i+3] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+3] , FALSE, FALSE, 0);
                           plabel=gtk_label_new(t1);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t2);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t3);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t4);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t5);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           
                           }
                           
                    }
fclose(p);
 phbox[i+4] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+4] , FALSE, FALSE, 0);
                           plabel=gtk_label_new("");

gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
/* On lance la boite de dialogue et on recupere la reponse */
resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));
/* Destruction de la boite de dialogue */
gtk_widget_destroy(pBoite);
}





void Afficher_Livre(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget*pFrame;
GtkWidget*pHBoxFrame;
int i=0,nbr_emprunt=Nombre_Emprunt();
gint resultat_choix;
char t1[20],t2[20],t4[20],t3[20],t5[20];
    int comp,bol=0;
    FILE*n;
    FILE*m;

/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("Resultat de la recherche",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
pFrame = gtk_frame_new("titre");
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 0);

phbox[1] = gtk_hbox_new(TRUE, 0);
phbox[2] = gtk_hbox_new(TRUE, 0);

n=fopen("livre.txt","r");    
    while(!feof(n)){
                    fscanf(n,"%s\t%s\t%s\t%s\t%s\n",t1,t2,t3,t4,t5);  
                    if(strcmp(t1,rechercher)==0 || strcmp(t2,rechercher)==0 || strcmp(t3,rechercher)==0 || strcmp(t4,rechercher)==0 || strcmp(t5,rechercher)==0 ){
                    bol=1;                                                        
                           }
                    }
fclose(n);
if(bol==1){
           
           gtk_box_pack_start(GTK_BOX(pvbox),phbox[1] , FALSE, FALSE, 0);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Titre </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Auteur </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Annee </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);


gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Edition </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);


gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Placard </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);



gtk_box_pack_start(GTK_BOX(pvbox),phbox[2] , FALSE, FALSE, 0);


plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);


m=fopen("livre.txt","r");    
    while(!feof(m)){
                    
                    fscanf(m,"%s\t%s\t%s\t%s\t%s\n",t1,t2,t3,t4,t5);  
                    if(strcmp(t1,rechercher)==0 || strcmp(t2,rechercher)==0 || strcmp(t3,rechercher)==0  || strcmp(t4,rechercher)==0  || strcmp(t5,rechercher)==0){
                           phbox[i+3] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+3] , FALSE, FALSE, 0);
                           plabel=gtk_label_new(t1);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t2);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t3);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t4);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t5);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           /* Destruction de la boite de dialogue */
                                     }
                           }
                           fclose(m);
                           gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);                           
                           phbox[i+4] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+4] , FALSE, FALSE, 0);
                           plabel=gtk_label_new("");
                           resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));
                           switch (resultat_choix)
                           {
                           /* L utilisateur valide */
                           
                           case GTK_RESPONSE_OK:gtk_widget_destroy(pBoite);
                                break;
                                
                                                           }
                                                                                         }


                           else{
                                Msg_Emprunt(NULL,NULL,"Aucune resultat correspond a cette recherche");                                          
                                     }
}














void Ajouter_Emprunt_Fichier(void){
                               FILE*r=0;               
                               r = fopen("emprunt.txt","a+");
                               fprintf(r,"%s\t%s\t%s\n",Titre,Date,Personne);
                               fclose(r);
}


void supprimer1(char t1[],char t2[],char t3[])
{
  /* Déclarations : */
  /* Noms des fichiers et pointeurs de référence */
  FILE *IN, *OUT;
  /* Autres variables */
int tr=0,tr2=0;
  char te1[20],te2[20],te3[22];
  /* Ouverture de l'ancien fichier en lecture */
  do
    {
     IN = fopen("emprunt.txt", "r");
     if (!IN)
	 printf("\aERREUR: Impossible d'ouvrir "
		"le fichier: %s.\n","emprunt.txt");
    }
  while (!IN);
  /* Ouverture du nouveau fichier en écriture */
  do
    {
     OUT = fopen("NOUVEAU.txt", "w");
     if (!OUT)
	 printf("\aERREUR: Impossible d'ouvrir "
		"le fichier: %s.\n","NOUVEAU.txt");
    }
  while (!OUT);
  /* Saisie de l'enregistrement à supprimer */
  /* Traitement */
  /* Copie de tous les enregistrements à */
  /* l'exception de celui à supprimer.   */
  while (!feof(IN))
    {    
    fscanf(IN, "%s\t%s\t%s\n",te1,te2,te3);
    if (tr==1 || strcmp(te1,t1) != 0 || strcmp(te2,t2) != 0 || strcmp(te3,t3) != 0){
   	fprintf(OUT,"%s\t%s\t%s\n",te1,te2,te3);                                                                        }
    if(tr==0){
    if (strcmp(te1,t1) == 0 && strcmp(te2,t2) == 0 && strcmp(te3,t3) == 0)
    tr=1;
    }
}
  /* Fermeture des fichiers */
  fclose(OUT);
  fclose(IN);

  remove("emprunt.txt");
  rename("NOUVEAU.txt","emprunt.txt");
  remove("NOUVEAU.txt");
}


void Supprimer_Emprunt_Fichier(void){      
FILE*s=0; 
emprunt*m=NULL;
int tr=-1;
char Titre1[22],Date1[20],Personne1[20];
s = fopen("emprunt.txt","r");                                                                                                                                                
			       while(!feof(s)){          
			       m=(emprunt*)malloc(sizeof(emprunt));
			       fscanf(s,"%s\t%s\t%s\n",Titre1,Date1,Personne1);
			       strcpy(m->Titre,Titre1);
			       strcpy(m->Date,Date1);
			       strcpy(m->Personne,Personne1);
			       m->next=premier1;
		           premier1=m;    
			       }
			       fclose(s);
			      while(premier1!=NULL){
         	      if(strcmp(premier1->Titre,Titre)==0 && strcmp(premier1->Date,Date)==0 && strcmp(premier1->Personne,Personne)==0)
                  {
                  tr=1;
                  goto label;
                  }
premier1=premier1->next;
}  
label:

                         if(tr!=1){
                                           Msg_Emprunt(NULL,NULL,"Emprunt inexistant");  
                                     }   
                                     else{
                                           supprimer1(Titre,Date,Personne);
                                           Msg_Emprunt(NULL,NULL,"Emprunt supprime avec success");                                           
                                          }                                                
tr=-1;                                                                                                                                                                                   
}



















void Ajouter_Emprunt(GtkWidget *pBtn, gpointer data)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget* pRadio1;
GtkWidget* pRadio2;
GtkWidget*pFrame;
GSList *pList;
const gchar* sNom;
int nbr=0;

gint resultat_choix;
/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("Ajouter ou supprimer un emprunt",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

pFrame = gtk_frame_new("titre");
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, TRUE, TRUE, 10);

phbox[1] = gtk_hbox_new(TRUE, 0);
phbox[2] = gtk_hbox_new(TRUE, 0);
phbox[3] = gtk_hbox_new(TRUE, 0);
phbox[4] = gtk_hbox_new(TRUE, 0);
phbox[5] = gtk_hbox_new(TRUE, 0);
phbox[8] = gtk_hbox_new(TRUE, 0);
phbox[7] = gtk_hbox_new(TRUE, 0);

gtk_box_pack_start(GTK_BOX(pvbox),phbox[1] ,FALSE,FALSE, 10);



plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Titre </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);
gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[1]), pEntry, TRUE, TRUE,0);
Titre=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[2] , TRUE, TRUE, 0);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Date</span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[2]), pEntry, TRUE, TRUE,0);
Date=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_box_pack_start(GTK_BOX(pvbox),phbox[3] , TRUE, TRUE, 10);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Personne </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);
gtk_box_pack_start(GTK_BOX(phbox[3]), plabel, TRUE, TRUE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[3]), pEntry, TRUE, TRUE,0);
Personne=gtk_entry_get_text(GTK_ENTRY(pEntry));




gtk_box_pack_start(GTK_BOX(pvbox),phbox[7] , TRUE, TRUE, 8);
/* Creation du premier bouton radio */
pRadio1 = gtk_radio_button_new_with_label(NULL, "Enregistrer");
gtk_box_pack_start(GTK_BOX (phbox[7]), pRadio1,TRUE, TRUE, 5);


gtk_box_pack_start(GTK_BOX(pvbox),phbox[8] ,TRUE,TRUE,8);
/* Ajout du deuxieme */
pRadio2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(pRadio1), "Effacer");
gtk_box_pack_start(GTK_BOX (phbox[8]), pRadio2, TRUE, TRUE,5);



gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
/* On lance la boite de dialogue et on recupere la reponse */
resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));



switch (resultat_choix)
{
case GTK_RESPONSE_OK:
            
     /* Recuperation de la liste des boutons */
pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(pRadio1));
/* Parcours de la liste */
while(pList)
{
/* Le bouton est il selectionne */
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
{
/* OUI >
on copie le label du bouton */
sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
/* On met la liste a NULL pour sortir de la boucle */
pList = NULL;
}
else
{
/* NON >
on passe au bouton suivant */
pList = g_slist_next(pList);
}
}

if(strcmp(sLabel,"Enregistrer")==0){
                                   if(strcmp(Titre,"")==0 || strcmp(Date,"")==0 || strcmp(Personne,"")==0){
                                   Vide();
                                   }
                                   else{
                                   nbr=Nombre_Livre_Emprunter(Personne);
                                   if(nbr<3){
                                   Ajouter_Emprunt_Fichier(); 
                                   Msg_Emprunt(NULL,NULL,"Emprunt ajoute avec success");
                                   }
                                   else
                                   Msg_Emprunt(NULL,NULL,"Ce etudiant a deja emprunter 3 livres");
                                   }
                                   }
if(strcmp(sLabel,"Effacer")==0){
                                   if(strcmp(Titre,"")==0 || strcmp(Date,"")==0 || strcmp(Personne,"")==0){
                                   Vide();
                                   }
                                   else
                                   Supprimer_Emprunt_Fichier();
                                   }
                                                                 
                                   
                                   break;
}              
/* L utilisateur annule */
/* Destruction de la boite de dialogue */
gtk_widget_destroy(pBoite);
}















void Liste_Emprunt(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget*pFrame;
GtkWidget*pHBoxFrame;
int i=0,nbr_emprunt=Nombre_Emprunt();
gint resultat_choix;
char t1[20],t2[20],t3[20],t4[20],t5[20];
    int comp=0;
    FILE*x;

/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("Liste des emprunts",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
pFrame = gtk_frame_new("titre");
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 0);

phbox[1] = gtk_hbox_new(TRUE, 0);
phbox[2] = gtk_hbox_new(TRUE, 0);




gtk_box_pack_start(GTK_BOX(pvbox),phbox[1] , FALSE, FALSE, 0);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Titre </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Date </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Personne </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);



gtk_box_pack_start(GTK_BOX(pvbox),phbox[2] , FALSE, FALSE, 0);


plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);


x=fopen("emprunt.txt","r");    
    while(!feof(x)){
                    fscanf(x,"%s\t%s\t%s\n",t1,t2,t3);  
                    if(i<=nbr_emprunt){
                           phbox[i+3] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+3] , FALSE, FALSE, 0);
                           plabel=gtk_label_new(t1);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t2);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t3);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           }
                           
                    }
fclose(x);
 phbox[i+4] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+4] , FALSE, FALSE, 0);
                           plabel=gtk_label_new("");

gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
/* On lance la boite de dialogue et on recupere la reponse */
resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));
/* Destruction de la boite de dialogue */
gtk_widget_destroy(pBoite);
}



void Afficher_Emprunt(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget*pFrame;
GtkWidget*pHBoxFrame;
int i=0,nbr_emprunt=Nombre_Emprunt();
gint resultat_choix;
char t1[20],t2[20],t3[20];
    int comp,bol=0;
    FILE*d;
    FILE*y;

/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("resultat de la recherche",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
pFrame = gtk_frame_new("titre");
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 0);

phbox[1] = gtk_hbox_new(TRUE, 0);
phbox[2] = gtk_hbox_new(TRUE, 0);

y=fopen("emprunt.txt","r");    
    while(!feof(y)){
                    fscanf(y,"%s\t%s\t%s\n",t1,t2,t3);  
                    if(strcmp(t1,rechercher)==0 || strcmp(t2,rechercher)==0 || strcmp(t3,rechercher)==0 ){
                    bol=1;                                                        
                           }
                    }
fclose(y);
if(bol==1){
           
           gtk_box_pack_start(GTK_BOX(pvbox),phbox[1] , FALSE, FALSE, 0);


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Titre </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Date </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Personne </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Edition </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);




gtk_box_pack_start(GTK_BOX(pvbox),phbox[2] , FALSE, FALSE, 0);


plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);
plabel=gtk_label_new("__________________");
gtk_box_pack_start(GTK_BOX(phbox[2]), plabel, TRUE, FALSE,0);




d=fopen("emprunt.txt","r");    
    while(!feof(d)){
                    
                    fscanf(d,"%s\t%s\t%s\n",t1,t2,t3);  
                    if(strcmp(t1,rechercher)==0 || strcmp(t2,rechercher)==0 || strcmp(t3,rechercher)==0){
                           phbox[i+3] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+3] , FALSE, FALSE, 0);
                           plabel=gtk_label_new(t1);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t2);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           plabel=gtk_label_new(t3);
                           gtk_box_pack_start(GTK_BOX(phbox[i+3]), plabel, TRUE, FALSE,0);                                                         
                           /* Destruction de la boite de dialogue */
                                     }
                           }
                           fclose(d);
                           gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);                           
                           phbox[i+4] = gtk_hbox_new(TRUE, 0);
                           gtk_box_pack_start(GTK_BOX(pvbox),phbox[i+4] , FALSE, FALSE, 0);
                           plabel=gtk_label_new("");
                           resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));
                           switch (resultat_choix)
                           {
                           /* L utilisateur valide */
                           
                           case GTK_RESPONSE_OK:gtk_widget_destroy(pBoite);
                                break;
                                
                                                           }
                                                                                         }


                           else{
                                Msg_Emprunt(NULL,NULL,"Aucune resultat correspond a cette recherche");                                          
                                     }
}



























void Rechercher_Emprunt(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget*Frame;
GtkWidget*pHBoxFrame;
int i=0,nbr_emprunt=Nombre_Emprunt();
gint resultat_choix;
char temp1[20],temp2[20],temp3[20];
    int comp=4;    
    


/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */


pBoite = gtk_dialog_new_with_buttons("Rechercher emprunt",GTK_WINDOW(pWindow),GTK_DIALOG_NO_SEPARATOR,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 10);

Frame = gtk_frame_new("Rechercher emprunt");
gtk_box_pack_start(GTK_BOX(pvbox),Frame,TRUE,FALSE, 5);



phbox[1] = gtk_hbox_new(TRUE, 0);

gtk_container_add(GTK_CONTAINER(Frame), phbox[1]);


/* Creation du premier GtkFrame */


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Rechercher </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,5);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[1]), pEntry, TRUE, TRUE,5);
rechercher=gtk_entry_get_text(GTK_ENTRY(pEntry));



gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
/* On lance la boite de dialogue et on recupere la reponse */

resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));
switch (resultat_choix)
{
/* L utilisateur valide */

case GTK_RESPONSE_OK:
     if(strcmp(rechercher,"")==0){
         Vide();
         gtk_widget_destroy(pBoite);
         Rechercher_Emprunt();
     }
     else
     {
      Afficher_Emprunt();      
         }
break;
/* L utilisateur annule */
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
default:                              
break;
}
gtk_widget_destroy(pBoite);
}


void Rechercher_Livre(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* phbox[7];
GtkWidget* pvbox;
GtkWidget*Frame;
GtkWidget*pHBoxFrame;
int i=0,nbr_emprunt=Nombre_Emprunt();
gint resultat_choix;
char temp1[20],temp2[20],temp3[20];
    int comp=4;
    


/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */

pBoite = gtk_dialog_new_with_buttons("Rechercher livre",GTK_WINDOW(pWindow),GTK_DIALOG_NO_SEPARATOR,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
pvbox = gtk_vbox_new(TRUE, 6);
gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), pvbox, FALSE, FALSE, 10);

Frame = gtk_frame_new("Rechercher livre");
gtk_box_pack_start(GTK_BOX(pvbox),Frame,TRUE,FALSE, 5);



phbox[1] = gtk_hbox_new(TRUE, 0);

gtk_container_add(GTK_CONTAINER(Frame), phbox[1]);


/* Creation du premier GtkFrame */


plabel=gtk_label_new(NULL);
/* On utilise les balises */
gtk_label_set_markup(GTK_LABEL(plabel), "<span font_desc=\"Times New Roman 12\"foreground=\"#0000FF\">Rechercher </span>");
/* On centre le texte */
gtk_label_set_justify(GTK_LABEL(plabel), GTK_JUSTIFY_LEFT);

gtk_box_pack_start(GTK_BOX(phbox[1]), plabel, TRUE, FALSE,5);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(phbox[1]), pEntry, TRUE, TRUE,5);
rechercher=gtk_entry_get_text(GTK_ENTRY(pEntry));


gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);
/* On lance la boite de dialogue et on recupere la reponse */

resultat_choix=gtk_dialog_run(GTK_DIALOG(pBoite));
switch (resultat_choix)
{
/* L utilisateur valide */

case GTK_RESPONSE_OK:
     if(strcmp(rechercher,"")==0){
         Vide();
         gtk_widget_destroy(pBoite);
         Rechercher_Livre();
     }
     else
     {
      Afficher_Livre();      
         }
break;
/* L utilisateur annule */
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
default:                              
break;
}
gtk_widget_destroy(pBoite);
}







//Fonction permet de savoir le nombre de livre emprunter par un etudiant

int Nombre_Livre_Emprunter(char per[20]){
    char t1[20],t2[20],t3[20];
    int comp=0;
    FILE*o;
    o=fopen("EMPRUNT.txt","r");    
    while(!feof(o)){
                    fscanf(o,"%s\t%s\t%s\n",t1,t2,t3);                                        
                    if(strcmp(t3,per)==0)
                    comp++;                   
                    }
                        fclose(o);
return comp;
}


//Fonction permet de savoir le nombre d'occurence pour un livre

int Nombre_Livre(char titre[30]){
    char t1[20],t2[20],t3[20],t4[20],t5[20],t6[20];
    FILE*f;
    int comp=0;
    f=fopen("LIVRE.txt","r");
    while(!feof(f)){
		    fscanf(f,"%s\t%s\t%s\t%s\t%s\t%s\n",t1,t2,t3,t4,t5,t6);
		    if(strcmp(t1,titre)==0){
		    comp++;
		    }
    }
    fclose(f);
return comp;
}





//fonction de savoir le nombre defois qu'un livre est deja emprunter

int Nombre_Fois_Emprunter(char titre[30]){
    char t1[20],t2[20],t3[20];
    int comp=0;
    FILE*j;
    j=fopen("EMPRUNT.txt","r");
    while(!feof(j)){
		    fscanf(j,"%s\t%s\t%s\n",t1,t2,t3);
		    if(strcmp(t1,titre)==0){
		    comp++;
		    }
		    }
		    fclose(j);
return comp;
}

//fonction permet de savoir le nombre de livre emprunter

int Nombre_Emprunt(){
    char t1[20],t2[20],t3[20];
    FILE*g;
    int comp=0;
    g=fopen("EMPRUNT.txt","r");    
    while(!feof(g)){
                    fscanf(g,"%s\t%s\t%s\n",t1,t2,t3);  
                    comp++;
                    }
                    fclose(g);                    
return comp;
}



