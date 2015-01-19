GtkWidget*pWindow;
const gchar *Titre=NULL;
const gchar *Auteur=NULL;
const gchar *Annee=NULL;
const gchar *Edition=NULL;
const gchar *Placard=NULL;
const gchar *Nombre=NULL;



void OnAbout(GtkWidget* widget, gpointer data)
{
GtkWidget *pAbout;
pAbout = gtk_message_dialog_new (GTK_WINDOW(data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_OK,"Gestion Bibliotheque en C");
gtk_dialog_run(GTK_DIALOG(pAbout));
gtk_widget_destroy(pAbout);
}

void Ajouter_Livre(void)
{
GtkWidget* pBoite;
GtkWidget* plabel;
GtkWidget* pEntry;
GtkWidget* pvbox1;
GtkWidget* pvbox2;
GtkWidget* phbox;
GtkWidget* pbutton; 
GtkWidget*pFrame;
const gchar* sNom;
gtk_container_set_border_width(GTK_CONTAINER(pWindow), 0);
gtk_window_set_default_size(GTK_WINDOW(pWindow), 500, 400);
/* Creation de la boite de dialogue */
/* 1 bouton Valider */
/* 1 bouton Annuler */
pBoite = gtk_dialog_new_with_buttons("Ajouter un livre",GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

phbox = gtk_hbox_new(TRUE,0);
pvbox1 = gtk_vbox_new(TRUE,0);
pvbox2 = gtk_vbox_new(TRUE,0);

pFrame = gtk_frame_new("Entrer les informations requises");
gtk_box_pack_start(GTK_BOX(pFrame),phbox , TRUE, FALSE, 20);



gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), phbox, FALSE, FALSE,20);

gtk_box_pack_start(GTK_BOX(phbox), pvbox1, TRUE, FALSE,20);
gtk_box_pack_start(GTK_BOX(phbox), pvbox2, TRUE, FALSE,20);

plabel=gtk_label_new("Titre : ");
gtk_box_pack_start(GTK_BOX(pvbox1),plabel, TRUE, FALSE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(pvbox2),pEntry, TRUE, FALSE,0);
sNom=gtk_entry_get_text(GTK_ENTRY(pEntry));
Titre=gtk_entry_get_text(GTK_ENTRY(pEntry));

plabel=gtk_label_new("Auteur : ");
gtk_box_pack_start(GTK_BOX(pvbox1),plabel, TRUE, FALSE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(pvbox2),pEntry, TRUE, FALSE,0);
Auteur=gtk_entry_get_text(GTK_ENTRY(pEntry));

plabel=gtk_label_new("Annee : ");
gtk_box_pack_start(GTK_BOX(pvbox1),plabel, TRUE, FALSE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(pvbox2),pEntry, TRUE, FALSE,0);
Annee=gtk_entry_get_text(GTK_ENTRY(pEntry));

plabel=gtk_label_new("Edition : ");
gtk_box_pack_start(GTK_BOX(pvbox1),plabel, TRUE, FALSE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(pvbox2),pEntry, TRUE, FALSE,0);
Edition=gtk_entry_get_text(GTK_ENTRY(pEntry));

plabel=gtk_label_new("Placard : ");
gtk_box_pack_start(GTK_BOX(pvbox1),plabel, TRUE, FALSE,0);
pEntry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(pvbox2),pEntry, TRUE, FALSE,0);
Placard=gtk_entry_get_text(GTK_ENTRY(pEntry));

gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);

/* On lance la boite de dialogue et on recupere la reponse */

switch (gtk_dialog_run(GTK_DIALOG(pBoite)))
{
/* L utilisateur valide */
case GTK_RESPONSE_OK:ajouter_livre_fichier();
break;
/* L utilisateur annule */
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
default:

break;
}
/* Destruction de la boite de dialogue */
gtk_widget_destroy(pBoite);
}


void ajouter_livre_fichier(){
                                FILE*p;
                                p=fopen("LIVRE.txt","a+");
                                fprintf(p,"%s\t%s\t%d\t%d\t%d\t%d\r\n",Titre,Auteur,*Annee-48,*Edition-48,*Placard-48,*Nombre-48);
                                fclose(p);

}
