#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

void draw_progress_bar(WINDOW *win, int progress, int max_width);
void draw_percentage_bar(WINDOW *win, int percentage, int width);