#include "sort.h"
/**
 * swap_int - Swap two integers in an array.
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
 * hoare_p - Order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 * Description: Prints the array after each swap of two elements.
 *
 */
int hoare_p(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_int(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}
/**
 * hoare_s - quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Hoare partition scheme.
 */
void hoare_s(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_p(array, size, left, right);
		hoare_s(array, size, left, part - 1);
		hoare_s(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 * Description:  Prints the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_s(array, size, 0, size - 1);
}
