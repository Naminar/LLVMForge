#include "sim.h"

#define N_STARS 50

void app() {

  int stars_x[N_STARS] = {};
  int stars_y[N_STARS] = {};

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
}
