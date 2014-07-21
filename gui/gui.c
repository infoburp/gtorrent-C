#include <gtk/gtk.h>
#include <stdbool.h>
#include "main_window.h"
#include "headerbar.h"
#include "addtorrent.h"

#define DEFAULT_WIDTH 1366
#define DEFAULT_HEIGHT 768

GtkWidget* dataview_create()
{
	GtkWidget *dataview = gtk_notebook_new();

	return dataview;
}

GtkWidget* torrentview_create()
{
	GtkWidget *torrentview = gtk_tree_view_new();

	return torrentview;
}

GtkWidget* sideview_create()
{
	GtkWidget *sideview = gtk_tree_view_new();

	return sideview;
}

int main(int argc, char *argv[])
{
	GtkWidget *v_pane;
	GtkWidget *h_pane;

	GtkWidget *sideview;
	GtkWidget *torrentview;
	GtkWidget *dataview;

	gtk_init(&argc, &argv);

	main_window_init();
	headerbar_init();
	addtorrent_window_init();

	/* Creating containers */
	v_pane = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
	h_pane = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);

	/* Creating main widgets */
	sideview = sideview_create();
	torrentview = torrentview_create();
	dataview = dataview_create();

	/* Packing containers */
	gtk_paned_add1(GTK_PANED(v_pane), h_pane);
	gtk_paned_add2(GTK_PANED(v_pane), dataview);
	gtk_paned_add1(GTK_PANED(h_pane), sideview);
	gtk_paned_add2(GTK_PANED(h_pane), torrentview);

	gtk_paned_set_position(GTK_PANED(v_pane), DEFAULT_HEIGHT * 0.65);
	gtk_paned_set_position(GTK_PANED(h_pane), DEFAULT_WIDTH * 0.15);

	gtk_container_add(GTK_CONTAINER(main_window), v_pane);

	g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(main_window);

	gtk_main();

	return 0;
}
