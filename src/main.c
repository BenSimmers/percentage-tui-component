#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h> // For sleep()
#include "progress.h"

double return_percentage()
{
  return (double)rand() / (double)RAND_MAX;
}

int main()
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);

  int max_width = 50;

  WINDOW *win = newwin(0, 0, 0, 0);
  box(win, 0, 0);

  wrefresh(win);

  // for (int i = 0; i <= 100; i++)
  // {
  //   draw_progress_bar(win, i, max_width);
  //   wrefresh(win);
  //   sleep(1);
  // }

  double percentage = return_percentage();
  draw_percentage_bar(win, percentage, max_width);
  wrefresh(win);
  sleep(1);

  endwin();
  return 0;
}
