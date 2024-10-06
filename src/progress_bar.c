#include "progress.h"

void draw_progress_bar(WINDOW *win, int progress, int max_width)
{
  int width = (progress * max_width) / 100; // Calculate filled width

  wattron(win, COLOR_PAIR(1)); // Set color for filled part
  mvwprintw(win, 1, 1, "[");

  for (int i = 0; i < width; i++)
  {
    mvwprintw(win, 1, 2 + i, "#");
  }

  for (int i = width; i < max_width; i++)
  {
    mvwprintw(win, 1, 2 + i, " ");
  }

  mvwprintw(win, 1, max_width + 2, "] %d%%", progress); // Draw end bracket and percentage
}
