#include <stdio.h>

int main() {
	double pi = 0;
	for (int i = 0; i < 100000; i++) {
		double in = 1;
		for (int j = 0; j < i; j++) {
			in *= -1;
		}
		in /= 2 * i + 1;
		pi += in;
		printf("%lf\n", pi * 4);
	}
	return 0;
}