#include "sort.h"

/**
 * find_max - find the maximun value number in a array
 * @arr: array of numbers
 * @size: length of the array
 * Return: the maximun number of the array
 */
int find_max(int *arr, size_t size)
{
	int max_n = 0;
	size_t i = 0;

	for (max_n = arr[0], i = 1; i < size; i++)
		if (arr[i] > max_n)
			max_n = arr[i];

	return (max_n);
}

/**
 * sort_radix - sort a list using the radix sort based on a specific digit
 * @arr: array of numbers
 * @size: length of the array
 * @d: significant digit representing the radix
 * Return: the array ordered by a specific digit, NULL otherwise
 */
int *sort_radix(int *arr, size_t size, int d)
{
	int *sort_d = NULL, digit_array[10] = {0}, j = 0;
	size_t i = 0;

	sort_d = malloc(sizeof(int) * size);
	if (!sort_d)
		return (NULL);

	for (i = 0; i < size; i++)
		digit_array[(arr[i] / d) % 10]++;

	for (i = 1; i < 10; i++)
		digit_array[i] += digit_array[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		sort_d[digit_array[(arr[j] / d) % 10] - 1] = arr[j];
		digit_array[(arr[j] / d) % 10]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = sort_d[i];

	free(sort_d);
	return (arr);
}

/**
 * radix_sort - sort an array using radix sort method
 * @array: list of numbers
 * @size: array length
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max_n = 0, digit = 0;

	if (array == NULL || size < 2)
		return;

	max_n = find_max(array, size);
	for (digit = 1; (max_n / digit) > 0; digit *= 10)
	{
		if (!sort_radix(array, size, digit))
			return;
		print_array(array, size);
	}
}
