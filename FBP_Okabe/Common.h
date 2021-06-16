#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <stdio.h>

using namespace std;

#include "GlobalVariable.h"

// Radon.cpp
// üŒ`•âŠÔ‚Å‰ñ“]‚ğs‚¤(“¡ˆä‚³‚ñ)
void rotate(float *img, int nx, int ny, double th);


// Utility.cpp
float* ReadData(const char* fileName, int size);
void WriteData(const char* fileName, float* projection, int size);
