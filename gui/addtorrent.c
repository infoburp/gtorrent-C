#include <gtk/gtk.h>
#include <stdbool.h>
#include "addtorrent.h"
#include "main_window.h"

#define ADD_DEFAULT_WIDTH 426
#define ADD_DEFAULT_HEIGHT 320

void addtorrent_window_hide()
{
	gtk_widget_hide(addtorrent_window);
}

void addtorrent_window_show()
{
	gtk_window_set_position(GTK_WINDOW(addtorrent_window),
			GTK_WIN_POS_CENTER_ON_PARENT);
	gtk_widget_show_all(addtorrent_window);
}

void addtorrent_window_init()
{
	addtorrent_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(addtorrent_window), "Add torrent");
	gtk_container_set_border_width(GTK_CONTAINER(addtorrent_window), 5);
	gtk_window_set_default_geometry(GTK_WINDOW(addtorrent_window),
			ADD_DEFAULT_WIDTH, ADD_DEFAULT_HEIGHT);

	/* Headerbar for the addtorrent window */
	GtkWidget *hb = gtk_header_bar_new();
	gtk_header_bar_set_title(GTK_HEADER_BAR(hb), "Add torrent");
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(hb), true);
	gtk_window_set_titlebar(GTK_WINDOW(addtorrent_window), hb);

	/* Hide window when 'X' is pressed */
	g_signal_connect(addtorrent_window, "delete_event",
			G_CALLBACK(addtorrent_window_hide), NULL);

	/* Make main window this window's parent */
	gtk_window_set_transient_for(GTK_WINDOW(addtorrent_window),
			GTK_WINDOW(main_window));

	/* File choosers */
	GtkWidget *dirlabel = gtk_label_new("Save to:");
	GtkWidget *dirchooser = gtk_file_chooser_button_new("Save to:",
			GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	GtkWidget *filelabel = gtk_label_new("Torrent file:");
	GtkWidget *filechooser = gtk_file_chooser_button_new("Add torrent:",
			GTK_FILE_CHOOSER_ACTION_OPEN);

	/* Container */
	GtkWidget *v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	/* Packing container */
	gtk_box_pack_start(GTK_BOX(v_box), dirlabel, true, false, 0);
	gtk_box_pack_start(GTK_BOX(v_box), dirchooser, false, false, 0);
	gtk_box_pack_start(GTK_BOX(v_box), filelabel, true, false, 0);
	gtk_box_pack_start(GTK_BOX(v_box), filechooser, false, false, 0);

	gtk_container_add(GTK_CONTAINER(addtorrent_window), v_box);
}
