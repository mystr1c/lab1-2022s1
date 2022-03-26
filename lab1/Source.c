#include <stdio.h>
#define E 0.0001				//точность приближения
#define Pi 3.1415926

double abs(double x) {
	if (x >= 0)
		return x;
	else
		return x * -1;
}

double cos(double n) {			//1 - x^2/2! +  x^4/4! ... 

	int k = 0;
	while ((n - Pi * k) >= Pi) {        //формула приведения
		k++;
	}

	n = n - Pi * k;

	int sign = 1;
	if (k % 2 != 0)              //знак
		sign = -1;

	double current = 0, next = 1;
	double a = 1;

	while (abs(next) > E) {
		current = current + next;
		next = (next * -1 * n * n) / ((2 * a - 1) * (2 * a));   //сам ряд Тейлора
			a = a + 1;
	}

	return sign * current;

}

int test() {
	int r = 1;

	r = r && (abs(cos(Pi) + 1.0) <= E);
	r = r && (abs(cos(Pi / 2) - 0.0) <= E);
	r = r && (abs(cos(5) - 0.2836) <= E);

	return r;
}

int main(int argc, char** argv) {
	return test();
}