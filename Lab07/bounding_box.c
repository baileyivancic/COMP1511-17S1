//written by Bailey Ivancic, 16/4/17
//calculates the sub-part of the image black pixels

#include <stdio.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width],
		int *start_row, int *start_column, int *box_height, int *box_width)
{

	int topRow = 0;
	int endCol = 0;

	//find starting row
	int row = 0;
	int col = 0;
	while (row < height)
	{
		while (col < width)
		{
			if (pixels[row][col] == 1)
			{
				*start_row = row;
				row = height;
				col = width;
			}
			col++;
		}
		row++;
		col = 0;
	}

	//find top row
	row = 0;
	col = 0;
	while (row < height)
	{
		while (col < width)
		{
			if (pixels[row][col] == 1)
			{
				topRow = row + 1;
			}
			col++;
		}
		row++;
		col = 0;
	}

	//calculate height
	*box_height = topRow - *start_row;

	//find start col
	col = 0;
	row = 0;
	while (col < width)
	{
		while (row < height)
		{
			if (pixels[row][col] == 1)
			{
				*start_column = col;
				row = height;
				col = width;
			}
			row++;
		}
		row = 0;
		col ++;
	}

	//find end col
	col = 0;
	row = 0;
	while (col < width)
	{
		while (row < height)
		{
			if (pixels[row][col] == 1)
			{
				endCol = col + 1;
			}
			row++;
		}
		row = 0;
		col ++;
	}

	//Calculate width             
	*box_width =  endCol - *start_column;          
}

