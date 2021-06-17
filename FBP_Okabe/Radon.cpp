#include "Common.h"

float* RadonTranslate(float *img, int detectorNum, int angleNum, int width, int height) {
	float *dupImg = new float[width * height]{ 0 };
	float *projection = new float[detectorNum * angleNum]{ 0 };

	// 180‹ / angleNum ‚Å‰ñ“]‚³‚¹‚È‚ª‚çüÏ•ª
	for (int k = 0; k < angleNum; ++k) {
		double angle = k * 180.0 / angleNum;
		memcpy(dupImg, img, sizeof(float) * width * height);

		// “Š‰eŠp“x‚É‡‚í‚¹‚Ä‰ñ“]
		rotate(dupImg, width, height, angle);

		cout << "angle:" << angle << endl;

		// c•ûŒü‚Ì‘˜a(üÏ•ª)‚ğ‹‚ß‚é
		for (int j = 0; j < width; ++j) {
			for (int i = 0; i < height; ++i) {
				projection[k * detectorNum + j] += dupImg[i * width + j];
			}
		} // End_Dual_For
	} // End_For

	return projection;
} // End_Func


// üŒ`•âŠÔ‚Å‰ñ“]‚ğs‚¤(“¡ˆä‚³‚ñ)
void rotate(float *img, int nx, int ny, double th) {
	int     i, j, i0, j0, i1, j1;
	double  x0, y0, si, co;
	float   *ima;

	ima = (float *)malloc((unsigned long)nx*ny * sizeof(float));

	co = cos(th*PI / 180);
	si = sin(th*PI / 180);

	for (i = 0; i < nx*ny; i++) {
		ima[i] = 0;
	}

	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			x0 = (j - nx / 2)*co - (ny / 2 - i)*si + nx / 2;
			j0 = (int)x0;
			j1 = j0 + 1;
			y0 = -(j - nx / 2)*si - (ny / 2 - i)*co + ny / 2;
			i0 = (int)y0;
			i1 = i0 + 1;

			if (i0 >= 0 && i1 < ny && j0 >= 0 && j1 < nx) {
				ima[i*nx + j] = (float)((j1 - x0)*(i1 - y0)*img[i0*nx + j0]
					+ (x0 - j0)*(i1 - y0)*img[i0*nx + j1]
					+ (j1 - x0)*(y0 - i0)*img[i1*nx + j0]
					+ (x0 - j0)*(y0 - i0)*img[i1*nx + j1]);
			} else {
				ima[i*nx + j] = 0;
			}

		}
	}

	for (i = 0; i < nx*ny; i++) {
		img[i] = ima[i];
	}

	free(ima);
} // End_Func