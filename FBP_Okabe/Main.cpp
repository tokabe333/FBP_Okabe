#include "Common.h"

int main() {
	printf("%.15lf\n", PI);

	int *a = new int[10]{ 0 };
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}

	int *b = new int[10];
	memcpy(b, a, sizeof(int) * 10);
	for (int i = 0; i < 10; ++i)cout << b[i] << endl;

	return 0;
}