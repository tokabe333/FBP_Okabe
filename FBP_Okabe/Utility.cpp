#include "Common.h"

//unsigned char* MakeBMPHeader(int width, int height, int colorScale) {
//	// –¢ŽÀ‘•
//} // End_Func


float* ReadData(const char* fileName, int size) {
	FILE *fp;
	if ((fp = fopen(fileName, "rb")) == NULL) {
		cout << "File cannot open Error. filename:" << fileName << endl;
		exit(-1);
	} // End_If
	float* projection = new float[size];
	fread(projection, sizeof(float), size, fp);
	fclose(fp);
} // End_Func

void WriteData(const char* fileName, float* projection, int size) {
	FILE *fp;
	if ((fp = fopen(fileName, "wb")) == NULL) {
		cout << "file cannot open Error. filename:" << fileName << endl;
		exit(-1);
	} // End_If
	fwrite(projection, sizeof(float), size, fp);
	fclose(fp);
} // End_Func
