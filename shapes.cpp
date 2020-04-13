#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#include "imagehelpers.h"
#include "shapes.h"

int nothing(std::string filename){    //the test function from the sample main, used for debugging.
  int img[MAX_H][MAX_W];
  int h, w;

  readImage("inImage.pgm",img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data

  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }

  // and save this new image to file "outImage.pgm"
  writeImage("z.pgm",out, h, w);
}


int invert(std::string filename){
  int img[MAX_H][MAX_W];
  int h, w;

  readImage(filename,img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data

  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = 255 - img[row][col];
    }
  }

  // and save this new image to file "outImage.pgm"
  writeImage("taska.pgm",out, h, w);
  // std::cout<< w<<'\n';
}
int invertHalf(std::string filename){
  int img[MAX_H][MAX_W];
  int h, w;

  readImage(filename,img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w/2; col++) {
      out[row][col] = img[row][col];
    }
    for(int col = w/2; col < w; col++) {
      out[row][col] = 255 - img[row][col];
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taskb.pgm",out, h, w);
  // std::cout<< w<<'\n';
}

int box(std::string filename){
  int img[MAX_H][MAX_W];
  int h, w;

  readImage(filename,img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h/4; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  for(int row = h/4; row< (3*h)/4; row++){
    for(int col = 0; col < w/4; col++) {
      out[row][col] = img[row][col];
    }
    for(int col = w/4; col < (3*w)/4; col++) {
      out[row][col] = 255;
    }
    for(int col = (3*w)/4; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  for(int row = (3*h)/4; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taskc.pgm",out, h, w);
  // std::cout<< w<<'\n';
}

int frame(std::string filename){
  int img[MAX_H][MAX_W];
  int h, w;

  readImage(filename,img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h/4; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  for(int col = 0; col < w/4; col++){
    out[(h/4)][col] = img[(h/4)][col];
  }
  for(int col = w/4; col < 3*w/4; col++){
    out[(h/4)][col] = 255;
  }
  for(int col = 3*w/4; col < w; col++){
    out[(h/4)][col] = img[(h/4)][col];
  }

  for(int row = (h/4)+1; row< (3*h)/4; row++){
    for(int col = 0; col < w/4; col++) {
      out[row][col] = img[row][col];
    }
    out[row][(w/4)]= 255;
    for(int col = (w/4)+1; col < (3*w)/4; col++) {
      out[row][col] = img[row][col];
    }
    out[row][((w*3)/4)] = 255;
    for(int col = ((3*w)/4)+1; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  for(int col = 0; col < w/4; col++){
    out[(3*h/4)][col] = img[(3*h/4)][col];
  }
  for(int col = w/4; col < 3*w/4; col++){
    out[(3*h/4)][col] = 255;
  }
  for(int col = 3*w/4; col < w; col++){
    out[(3*h/4)][col] = img[(3*h/4)][col];
  }
  for(int row = ((3*h)/4)+1; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taskd.pgm",out, h, w);
  // std::cout<< w<<'\n';
}

int scale(std::string filename){
  int img[MAX_H][MAX_W];
  int h, w;

  readImage(filename,img, h, w);
  h = h*2;
  w = w*2;
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h/2; row++) {
    for(int col = 0; col < w/2; col++) {
      out[row*2][2*col] = img[row][col];
      out[row*2][2*col+1] = img[row][col];
      out[row*2+1][col*2] = img[row][col];
      out[row*2+1][col*2+1] = img[row][col];
    }
    // std::cout<<row<<'\n';
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taske.pgm",out, h, w);
  // std::cout<< w<<'\n'<< h<<'\n';
}

int pixelate(std::string filename){
  int img[MAX_H][MAX_W];
  int h, w;

  readImage(filename,img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      int n = (img[row*2+1][col*2+1]+ img[row*2+1][col*2]+ img[row*2][2*col+1]+ img[row*2][2*col])/4;
      out[row*2][2*col] = n;
      out[row*2][2*col+1] = n;
      out[row*2+1][col*2] = n;
      out[row*2+1][col*2+1] = n;
    }
    // std::cout<<row<<'\n';
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taskf.pgm",out, h, w);
  // std::cout<< w<<'\n'<< h<<'\n';
}
















//endcomment
