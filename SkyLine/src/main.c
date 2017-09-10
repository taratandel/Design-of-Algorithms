/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 12-02-2015
 *
 * [] Last Modified : Thu 05 Mar 2015 11:05:13 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>

#include "building.h"
#include "skyliner.h"
#include "common.h"
#include "gui.h"

/* Buildings ... */
struct building *buildings;
int number;

struct building *buildings_out;
int number_out;

int main(int argc, char *argv[])
{

	GtkWidget *window;
	GtkWidget *frame;
	GtkWidget *board;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Skyline");

	g_signal_connect(window, "destroy", G_CALLBACK(close_window), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window), 8);

	frame = gtk_frame_new(NULL);
	gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
	gtk_container_add(GTK_CONTAINER(window), frame);

	board = gtk_drawing_area_new();
	/* set a minimum size */
	gtk_widget_set_size_request(board, 800, 600);

	gtk_container_add(GTK_CONTAINER(frame), board);

	/* Signals used to handle the backing surface */
	g_signal_connect(board, "draw",
			G_CALLBACK(draw_handler), NULL);
	g_signal_connect(board, "configure-event",
			G_CALLBACK(configure_event_handler), NULL);

	/* Event signals */
	g_signal_connect(board, "button-press-event",
			G_CALLBACK(button_press_event_handler), NULL);

	/*
	 * Ask to receive events the drawing area doesn't normally
	 * subscribe to. In particular, we need to ask for the
	 * button press and motion notify events that want to handle.
	*/
	gtk_widget_set_events(board,
			gtk_widget_get_events(board) | GDK_BUTTON_PRESS_MASK);

	GtkWidget *file_open;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
	int res;

	file_open = gtk_file_chooser_dialog_new("Input File", NULL,
			action, "Cancel", GTK_RESPONSE_CANCEL,
			"Open", GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(file_open));
	if (res == GTK_RESPONSE_ACCEPT) {
		char *filename;

		GtkFileChooser *chooser = GTK_FILE_CHOOSER(file_open);
		filename = gtk_file_chooser_get_filename(chooser);
		
		int i = 0;
		FILE *file = NULL;


		file = fopen(filename, "r");
		if (!file)
			sdie("fopen()");

		fscanf(file, "%d", &number);
		buildings = malloc(sizeof(struct building) * number);
		for (i = 0; i < number; i++) {
			int start, end;
			double height;

			fscanf(file, "%d %d %lg", &start, &end, &height);
			buildings[i].height = height;
			buildings[i].start_point = start;
			buildings[i].end_point = end;
		}
		fclose(file);	

		g_free(filename);
	} else {
		udie("Plese enter input filename");
	}

	gtk_widget_destroy(file_open);
	
	GtkWidget *file_save;
	GtkFileChooser *chooser;
	action = GTK_FILE_CHOOSER_ACTION_SAVE;

	file_save = gtk_file_chooser_dialog_new("Output File", NULL,
			action, "Cancel", GTK_RESPONSE_CANCEL,
			"Save", GTK_RESPONSE_ACCEPT, NULL);
	chooser = GTK_FILE_CHOOSER(file_save);

	gtk_file_chooser_set_do_overwrite_confirmation(chooser, TRUE);

	res = gtk_dialog_run(GTK_DIALOG(file_save));
	if (res == GTK_RESPONSE_ACCEPT) {
		char *filename;

		filename = gtk_file_chooser_get_filename(chooser);

		int i = 0;
		FILE *file = NULL;

		file = fopen(filename, "w");
		if (!file)
			sdie("fopen()");

		skyliner(buildings, number, &buildings_out, &number_out);

		fprintf(file, "%d\n", number_out);
		for (i = 0; i < number_out; i++)
			fprintf(file, "%d %lg\n", buildings_out[i].start_point,
					buildings_out[i].height);
		fclose(file);
		
		g_free (filename);
	} else {
		udie("Please enter output filename");
	}

	gtk_widget_destroy(file_save);

	gtk_widget_show_all(window);
	
	gtk_main();

	return 0;
}
