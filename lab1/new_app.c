#include "sim.h"

#define N_STARS 50

void app() {

  int stars_x;//[N_STARS] = {};
  int stars_y;//[N_STARS] = {};

  // for (int i = 0; i < N_STARS; ++i){
    stars_x = simRand() % SIM_X_SIZE;
    stars_y = simRand() % SIM_Y_SIZE;
    int x_l_gradient = simRand() % 1024;
    int x_r_gradient = simRand() % 1024;
    int y_up_gradient = simRand() % 4056;
    int y_down_gradient = simRand() % 4056;
  // }

  // for (int star = 0; star < N_STARS; ++star){
    for (int x_l = stars_x; x_l > 0; --x_l) {
      simPutPixel(x_l, stars_y, 0x0000FFFF + x_l*(16+x_l_gradient));
      simFlush();
    }

    for (int x_r = stars_x; x_r < SIM_X_SIZE; ++x_r) {
      simPutPixel(x_r, stars_y, 0x0000FFFF + x_r*(16+x_r_gradient));
      simFlush();
    }

    for (int y_up = stars_y; y_up < SIM_Y_SIZE; ++y_up) {
      simPutPixel(stars_x, y_up, 0x0000FFFF + y_up*(16+y_up_gradient));
      simFlush();
    }

    for (int y_down = stars_y; y_down > 0; --y_down) {
      simPutPixel(stars_x, y_down, 0x0000FFFF + y_down*(16+y_down_gradient));
      simFlush();
    }
    // simFlush();
  // }
}
