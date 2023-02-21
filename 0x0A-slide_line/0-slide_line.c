#include "slide_line.h"
/**
 * slide_line - slide th line to left or right
 *
 * @line: points to an array of integers containing elements
 * @size: size of the array
 * @direction: direction to slide
 *
 * Return: 1 on success, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));

	return (0);
}
/**
 * organize_list_left - organize the list
 *
 * @line: array to organize
 * @size: size of the array
 */
void organize_list_left(int *line, size_t size)
{
	size_t i = 0, j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				break;
			}	
		}
	}
}
/**
 * organize_list_right - organize the list
 *
 * @line: array to organize
 * @size: size of the array
 */
void organize_list_right(int *line, size_t size)
{
	int i = 0, j = 0;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				break;
			}	
		}
	}
}
/**
 * slide_left - slide to left
 * @line: array of ints
 * @size: size of the array
 */
int slide_left(int *line, size_t size)
{
	size_t prev = 0, curr = 0;

	for (prev = 0; prev < size; prev++)
	{
		for (curr = prev + 1; curr < size; curr++)
		{
			if (line[curr] != 0 && line[curr] != line[prev])
			{
				line[prev + 1] = line[curr];
				break;
			}
			if (line[curr] == line[prev])
			{
				line[prev] += line[curr];
				line[curr] = 0;
				break;
			}
		}
	}
	organize_list_left(line, size);
	return (1);
}
/**
 * slide_right - slide to the right side
 *
 * @line: array to slide
 * @size: size of the array
 *
 * Return: 1 on success, 0 otherwise
 */
int slide_right(int *line, size_t size)
{
	int prev = 0, curr = 0;

	for (prev = size - 1; prev >= 0; prev--)
	{
		for (curr = prev - 1; curr >= 0; curr--)
		{
			if (line[curr] != 0 && line[curr] != line[prev])
			{
				line[prev - 1] = line[curr];
				break;
			}
			if (line[curr] == line[prev])
			{
				line[prev] += line[curr];
				line[curr] = 0;
				break;
			}
		}
	}
	organize_list_right(line, size);
	return (1);
}
