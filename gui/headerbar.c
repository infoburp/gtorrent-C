#include <gtk/gtk.h>
#include <stdbool.h>
#include "headerbar.h"
#include "addtorrent.h"
#include "main_window.h"

void headerbar_init()
{
	headerbar = gtk_header_bar_new();

	gtk_header_bar_set_title(GTK_HEADER_BAR(headerbar), "gTorrent");
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerbar), true);

	/* Creating buttons and separators */
	GtkWidget *btn1 = gtk_button_new_from_icon_name("gtk-add",
			GTK_ICON_SIZE_LARGE_TOOLBAR);
	GtkWidget *btn2 = gtk_button_new_from_icon_name("media-playback-start",
			GTK_ICON_SIZE_LARGE_TOOLBAR);
	GtkWidget *btn3 = gtk_button_new_from_icon_name("media-playback-pause",
			GTK_ICON_SIZE_LARGE_TOOLBAR);
	GtkWidget *btn4 = gtk_button_new_from_icon_name("media-playback-stop",
			GTK_ICON_SIZE_LARGE_TOOLBAR);
	GtkWidget *btn5 = gtk_button_new_from_icon_name("gtk-properties",
			GTK_ICON_SIZE_LARGE_TOOLBAR);
	GtkWidget *sep1 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
	GtkWidget *sep2 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
	GtkWidget *sep3 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);

	/* Connecting signals to the buttons */
	/* TODO */
	g_signal_connect(btn1, "clicked", G_CALLBACK(addtorrent_window_show), NULL);

	/* Packing buttons and separators into header bar */
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), btn1);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), sep1);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), btn2);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), btn3);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), btn4);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), sep2);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), btn5);
	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), sep3);

	/* Add headerbar to main window */
	gtk_window_set_titlebar(GTK_WINDOW(main_window), headerbar);
}
