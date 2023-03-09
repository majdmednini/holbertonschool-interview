#include "menger.h"
#include <math.h>

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of the menger sponge to draw
 */

void menger(int level)
{
	int i, j, x, y;
	char s;

	if (level < 0)
		return;
	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level);)
		{
			s = '#';
			x = i;
			y = j++;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					s = ' ';
				x /= 3;
				y /= 3;
			}
			putchar(s);
		}
		printf("\n");
	}
}