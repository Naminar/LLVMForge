#include "sim.h"

#define N_STARS 50

void app() {

  int f_cross_x, f_cross_y, s_cross_x, s_cross_y;
  int stars_x = simRand() % SIM_X_SIZE;
  int stars_y= simRand() % SIM_Y_SIZE;


    for (int x_l = stars_x; x_l > 0; --x_l) {
      simPutPixel(x_l, stars_y, 0xFFFF0000);
      simFlush();
    }

    for (int x_r = stars_x; x_r < SIM_X_SIZE; ++x_r) {
      simPutPixel(x_r, stars_y, 0xFFFF0000);
      simFlush();
    }

    for (int y_up = stars_y; y_up < SIM_Y_SIZE; ++y_up) {
      simPutPixel(stars_x, y_up, 0xFFFF0000);
      simFlush();
    }

    for (int y_down = stars_y; y_down > 0; --y_down) {
      simPutPixel(stars_x, y_down, 0xFFFF0000);
      simFlush();
    }
}
