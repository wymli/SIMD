#ifndef FUNCPROTOCOL_H
#define FUNCPROTOCOL_H
#include <stdio.h>

int read_pgm_image(char* infilename,
                   unsigned char** image,
                   int* rows,
                   int* cols);
int write_pgm_image(char* outfilename,
                    unsigned char* image,
                    int rows,
                    int cols,
                    char* comment,
                    int maxval);

void canny(unsigned char* image,
           int rows,
           int cols,
           float sigma,
           float tlow,
           float thigh,
           unsigned char** edge,
           char* fname);
void gaussian_smooth(unsigned char* image,
                     int rows,
                     int cols,
                     float sigma,
                     short int** smoothedim);
void make_gaussian_kernel(float sigma, float** kernel, int* windowsize);
void derrivative_x_y(short int* smoothedim,
                     int rows,
                     int cols,
                     short int** delta_x,
                     short int** delta_y);
void magnitude_x_y(short int* delta_x,
                   short int* delta_y,
                   int rows,
                   int cols,
                   short int** magnitude);
void apply_hysteresis(short int* mag,
                      unsigned char* nms,
                      int rows,
                      int cols,
                      float tlow,
                      float thigh,
                      unsigned char* edge);
void radian_direction(short int* delta_x,
                      short int* delta_y,
                      int rows,
                      int cols,
                      float** dir_radians,
                      int xdirtag,
                      int ydirtag);
double angle_radians(double x, double y);
void non_max_supp(short* mag,
                  short* gradx,
                  short* grady,
                  int nrows,
                  int ncols,
                  unsigned char* result);

#endif