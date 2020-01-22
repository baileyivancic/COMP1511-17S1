//balance.c
double horizontalBalance(int height, int width, int boundedPixels[height][width]);
double verticalBalance(int height, int width, int boundedPixels[height][width]);
double holeBalance(int height, int width, int holePixels[height][width], int holes);

//holes.c
void getHoles(int height, int width, int row, int col, int altered[height][width], int marker);
int countHoles(int height, int width, int altered[height][width], int marker);
double getholeFraction(int height, int width, int altered[height][width]);

//read_pbm.c
int read_pbm(char filename[], int height, int width, int pixels[height][width]);
int get_pbm_dimensions(char filename[], int *height, int *width);

//copy_pixels.c
void copyPixels(int height, int width, int pixels[height][width],
  int start_row, int start_column, int copy_height, int copy_width, 
  int copy[copy_height][copy_width]);
void copypixelsAlt(int height, int width, int pixels[height][width], 
  int start_row, int start_column, int copy_height, 
  int copy_width, int copy[copy_height][copy_width]);

//print_image.c
void printImage(int height, int width, int pixels[height][width]);

//bounding_box.c
void boundingBox(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
void boundingBoxHoles(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
                  
//density.c
double get_density(int height, int width, int altered[height][width]);
double get_holedensity(int height, int width, int boundedPixels[height][width]);
double get_leftDensity(int height, int width, int boundedPixels[height][width]);
double get_rightDensity(int height, int width, int boundedPixels[height][width]);
double get_topDensity(int height, int width, int boundedPixels[height][width]);
double get_bottomDensity(int height, int width, int boundedPixels[height][width]);

//varience.c
double varience(double val1, double val2);

//other_functions.c
double get_holeposition(int height, int width, int altered[height][width], int holes);
double get_verticalblack(int height, int width, int altered[height][width]);
double get_holeheight(int height, int width, int altered[height][width], int start, int holes);

//calculate_probability.c
void get_number(int height, int width, int pixels[height][width]);

//test_functions.c
int test(int argc, char *argv[]);

//calculate_probabilityCaptcha
void get_numberCaptcha(int height, int width, int pixels[height][width]);
