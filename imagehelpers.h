#pragma once

const int MAX_H = 1023;
const int MAX_W = 1023;


void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);

void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width);
