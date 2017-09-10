/*
 * In The Name Of God
 * ========================================
 * [] File Name : gui.h
 *
 * [] Creation Date : 26-02-2015
 *
 * [] Last Modified : Thu 26 Feb 2015 12:07:24 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef GUI_H
#define GUI_H


void clear_surface(void);

gboolean configure_event_handler(GtkWidget *widget,
		GdkEventConfigure *event, gpointer data);

gboolean draw_handler(GtkWidget *widget,
		cairo_t *cr, gpointer data);

void draw_buildings(GtkWidget *widget);

gboolean button_press_event_handler(GtkWidget *widget,
		GdkEventButton *event, gpointer data);

void close_window(void);

#endif
