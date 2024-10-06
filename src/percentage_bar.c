#include "progress.h"

void draw_percentage_bar(WINDOW *win, int percentage, int width)
{
  int filled_width = (percentage * width) / 100; // Calculate filled width

  wattron(win, COLOR_PAIR(2)); // Set color for filled part
  mvwprintw(win, 2, 1, "[");   // Draw the start bracket

  for (int i = 0; i < filled_width; i++)
  {
    mvwprintw(win, 2, 2 + i, "#"); // Draw filled part
  }

  for (int i = filled_width; i < width; i++)
  {
    mvwprintw(win, 2, 2 + i, " "); // Draw empty part
  }

  mvwprintw(win, 2, width + 2, "] %d%%", percentage); // Draw end bracket and percentage
  wattroff(win, COLOR_PAIR(2));
}
