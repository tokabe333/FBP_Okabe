#include "Common.h"

int main() {
	string filename = "ct_data1.img";
	string outname = "ct_data_radon.img";
	int fileSize = Width * Height;

	float* imageTrue = ReadData(filename.c_str(), fileSize);
	float* radon = RadonTranslate(imageTrue, DetectorNum, AngleNum, Width, Height);

	//WriteData(outname.c_str(), imageTrue, fileSize);
	WriteData(outname.c_str(), radon, DetectorNum * AngleNum);

	return 0;
} // End_Func