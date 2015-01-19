#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h> 
#include<dos.h>
#include<malloc.h>  
#include "entrer.h"


GtkWidget *pWindow; 
void OnQuitter(GtkWidget* widget, gpointer data);
void OnAbout(GtkWidget* widget, gpointer data);
 
void Ajouter_Livre(GtkWidget *pBtn, gpointer data);
void Ajouter_Livre_Fichier(void);
void Supprmier_Livre_Fichier();   
void Ajouter_Emprunt(GtkWidget *pBtn, gpointer data);
void Ajouter_Emprunt_Fichier(void);
void Supprmier_Emprunt_Fichier();    
void Liste_Emprunt(void);  
    



int main(int argc, char **argv)
{       
GtkWidget *pVBox;         
GtkWidget *pMenuBar;                 
GtkWidget *pMenu; 
GtkWidget *pMenuItem;
GtkWidget* Image;
GtkWidget* Tableau; //Tableau de mise en page
             
gtk_init(&argc, &argv);          


/*creation de l'arriere plan*/   
Image=gtk_image_new_from_file("images/ron-arad-bibliotheque.jpg");


/* Ajout d'un tableau */   
Tableau=gtk_table_new(1,1, TRUE); //Création du tableau    



/* Creation de la fenetre */       
pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_icon_from_file(GTK_WINDOW(pWindow),"Book.ico", NULL);
gtk_window_set_title(GTK_WINDOW(pWindow), "Menu Principal");
gtk_window_set_default_size(GTK_WINDOW(pWindow), 590, 430);
g_signal_connect(G_OBJECT(pWindow),"destroy", G_CALLBACK(gtk_main_quit),NULL);
gtk_window_set_resizable(GTK_WINDOW(pWindow),TRUE);

/* Creation de la GtkVBox */
pVBox = gtk_vbox_new(FALSE, 0);
gtk_container_add(GTK_CONTAINER(pWindow), pVBox);    
/**** Creation du menu ****/    
/* ETAPE 1 */
pMenuBar = gtk_menu_bar_new();
/** Premier sousmenu

**/
/* ETAPE 2 */
pMenu = gtk_menu_new();

/* ETAPE 3 */         
pMenuItem = gtk_menu_item_new_with_label("Livre");
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Ajouter_Livre),NULL);
pMenuItem = gtk_menu_item_new_with_label("Emprunt ");
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Ajouter_Emprunt),NULL);
/* ETAPE 4 */
pMenuItem = gtk_menu_item_new_with_label("Nouveau");
/* ETAPE 5 */
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
/* ETAPE 6 */
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
/** Second sousmenu
**/        
/* ETAPE 2 */
pMenu = gtk_menu_new();
/* ETAPE 3 */
pMenuItem = gtk_menu_item_new_with_label("Liste Livre");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Liste_Livre),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
pMenuItem = gtk_menu_item_new_with_label("Liste emprunts");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Liste_Emprunt),NULL);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);


/* ETAPE 4 */                                           
pMenuItem = gtk_menu_item_new_with_label("Liste");
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);

/* ETAPE 6 */
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);

/* ETAPE 2 */
pMenu = gtk_menu_new();

/* ETAPE 3 */         
pMenuItem = gtk_menu_item_new_with_label("Rechercher livre");
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Rechercher_Livre),NULL);
pMenuItem = gtk_menu_item_new_with_label("Rechercher emprunt ");
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Rechercher_Emprunt),NULL);
/* ETAPE 4 */
pMenuItem = gtk_menu_item_new_with_label("Rechercher");
/* ETAPE 5 */
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
/* ETAPE 6 */
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);




/* ETAPE 2 */
pMenu = gtk_menu_new();
/* ETAPE 3 */
/* ETAPE 4 */
pMenuItem = gtk_menu_item_new_with_label("Quitter");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(OnQuitter),(GtkWidget*) pWindow);
/* ETAPE 6 */
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);


/* ETAPE 2 */
pMenu = gtk_menu_new();
/* ETAPE 3 */
pMenuItem = gtk_menu_item_new_with_label("A propos de...");
g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(OnAbout),
(GtkWidget*) pWindow);
gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);
/* ETAPE 4 */
pMenuItem = gtk_menu_item_new_with_label("?");
/* ETAPE 5 */                            
gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);
/* ETAPE 6 */        
gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
/* Ajout du menu a la fenetre */

/* Ajout d'un tableau */
Tableau=gtk_table_new(2,1, TRUE); //Création du tableau
gtk_box_pack_start(GTK_BOX(pVBox), pMenuBar, FALSE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), Tableau, FALSE, FALSE, 0);

gtk_table_attach(GTK_TABLE(Tableau),Image,0,2,0,2,GTK_SHRINK,GTK_SHRINK,0,0);
gtk_widget_show_all(pWindow);
gtk_main();
return EXIT_SUCCESS;
}
