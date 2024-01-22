#include "sort.h"


/**
 * swap_int - swap two integer
 *
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_h - turn a binary tree into a complete binary heap.
 *
 * @array: array of integers representing a binary tree.
 * @size: size of the array
 * @base:index of the base row of the array
 * @root: root node of the binary array
 */

void max_h(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_int(array + root, array + large);
		print_array(array, size);
		max_h(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: sift-down heap sort
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_h(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		max_h(array, size, i, 0);
	}
}
