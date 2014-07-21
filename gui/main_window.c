#include <gtk/gtk.h>

#include "main_window.h"

#define MAIN_DEFAULT_WIDTH 1366
#define MAIN_DEFAULT_HEIGHT 768

void main_window_init()
{
	main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(main_window), "gTorrent");
	gtk_container_set_border_width(GTK_CONTAINER(main_window), 5);
	gtk_window_set_default_geometry(GTK_WINDOW(main_window),
			MAIN_DEFAULT_WIDTH, MAIN_DEFAULT_HEIGHT);
}
