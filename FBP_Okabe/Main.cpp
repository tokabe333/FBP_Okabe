#include "Common.h"

int main() {
	string filename = "C:\\Okabe_8th\\Program\\FBP_Okabe\\FBP_Okabe\\ct_data1.img";
	string outname = "ct_data_test.img";
	int fileSize = Width * Height;

	float* imageTrue = ReadData(filename.c_str(), fileSize);
	WriteData(outname.c_str(), imageTrue, fileSize);


	return 0;
}