#include "sim.h"
#include <stdio.h>

#define N_STARS 50

void delta(int x, int y) {
  int color = 0xFF00FF00;
  int delta = 3;

  for (int x_l = x; x_l > 0 && x_l > x - delta; --x_l) {
      simPutPixel(x_l, y, color);
  }

  for (int x_r = x; x_r < SIM_X_SIZE && x_r < x + delta; ++x_r) {
    simPutPixel(x_r, y, color);
  }

  for (int y_up = y; y_up < SIM_Y_SIZE && y_up < y + delta; ++y_up) {
    simPutPixel(x, y_up, color);
  }

  for (int y_down = y; y_down > 0 && y_down > y - delta; --y_down) {
    simPutPixel(x, y_down, color);
  }
}

void app() {
  int stars_x[N_STARS] = {};
  int stars_y[N_STARS] = {};
  int max_diagon = 0;

  int f_cross_x, f_cross_y, s_cross_x, s_cross_y;

  for (int i = 0; i < N_STARS; ++i){
    stars_x[i] = simRand() % SIM_X_SIZE;
    stars_y[i] = simRand() % SIM_Y_SIZE;
  }


  for (int star = 0; star < N_STARS; ++star){
    for (int x_l = stars_x[star]; x_l > 0; --x_l) {
      simPutPixel(x_l, stars_y[star], 0xFFFF0000 + star*25);
    }

    for (int x_r = stars_x[star]; x_r < SIM_X_SIZE; ++x_r) {
      simPutPixel(x_r, stars_y[star], 0xFFFF0000 + star*25);
    }

    for (int y_up = stars_y[star]; y_up < SIM_Y_SIZE; ++y_up) {
      simPutPixel(stars_x[star], y_up, 0xFFFF0000 + star*25);
    }

    for (int y_down = stars_y[star]; y_down > 0; --y_down) {
      simPutPixel(stars_x[star], y_down, 0xFFFF0000 + star*25);
    }
    simFlush();
  }

  for (int star = 0; star < N_STARS; ++star){
    for (int cmp_star = star + 1; cmp_star < N_STARS; ++cmp_star){
      f_cross_y = stars_y[star];
      f_cross_x = stars_x[cmp_star];
      s_cross_y = stars_y[cmp_star];
      s_cross_x = stars_x[star];

      delta(f_cross_x, f_cross_y);
      delta(s_cross_x, s_cross_y);
    }
    simFlush();
  }
}
