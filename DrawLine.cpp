#include <stdio.h>
#include <conio.h>
#include "graphics.h"
#include <math.h>
#include <dos.h>

int main() {
	// request auto detection 
	int gdriver = DETECT, gmode, err;
	int i, x1, y1, x2, y2, dX, dY, steps;
	float x, y, xI, yI;

	// initialize graphic mode 
	initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
	err = graphresult();

	if (err != grOk) {
		// error occurred 
		printf("Graphic Error: %s\n",
			grapherrormsg(err));
		getch();
		return 0;
	}

	// draw line from (0, 0) to x-axis & y-axis maximum 
	x1 = y1 = 0;
	x2 = getmaxx(), y2 = getmaxy();

	dX = x2 - x1;
	dY = y2 - y1;

	x = x1, y = y1;

	steps = abs(dX) > abs(dY) ? dX : dY;

	xI = (1.0 * dX) / steps;
	yI = (1.0 * dY) / steps;

	putpixel((int)x, (int)y, WHITE);

	// find the x and y successors and plot the pixels 
	for (i = 0; i < steps; i++) {
		x = x + xI;
		y = y + yI;

		// put a pixel at the given postion(x, y) 
		putpixel((int)x, (int)y, WHITE);

		// sleep for 10 milliseconds 
		delay(10);
	}

	// deallocate memory allocated for graphic screen 
	closegraph();
	return 0;
} 


