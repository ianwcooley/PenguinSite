#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

void generate_points();

int main() {
	generate_points();
}

void generate_points() {
	FILE *file = fopen("points_2.csv", "w");
	double cx= 100.0, cy=100.0, r=70.0;
	double x[17], y[17];
	fprintf(file, "x0, y0, x1, y1\n");
	int i, j;
	for (i = 0; i < 17; i++) {
		x[i] = cx + r * cos(((double) i) * (360.0 * PI)/(17.0 * 180.0));
		y[i] = cy + r * sin(((double) i) * (360.0 * PI)/(17.0 * 180.0));
	}
	for (i = 0; i < 16; i++) {
		for (j = i+1; j < 17; j++) {
			fprintf(file, "[%f, %f, %f, %f],\n", x[i], y[i], x[j], y[j]);
		}
	}
	fclose(file);
}