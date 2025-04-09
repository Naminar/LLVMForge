#define SIM_X_SIZE (512*2)
#define SIM_Y_SIZE (256*2)

#ifndef __sim__
void simFlush();
void simPutPixel(int x, int y, int argb);
#endif

extern void simInit();
extern void app();
extern void simExit();
