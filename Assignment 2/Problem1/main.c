#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
// Write a function that takes as an input an array of longeger numbers(both positive and negative numbers)  and returns the value of the triplet with the maximum product, as well as the elements that form this triplet.
// Use pass by polonger / address to return the elements that form that triplet.
// In the main function, you will first read the size of the array n, and then n longegers representing the elements in the array.

void quicksort(long number[], long begin, long end)
{
	long i, j, pivot, temp;

	if (begin < end) {
		pivot = begin;
		i = begin;
		j = end;

		while (i < j) {
			while (number[i] <= number[pivot] && i < end)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}

		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, begin, j - 1);
		quicksort(number, j + 1, end);

	}
}

long long findTriplets(long* a, long number_elements, long* max1, long* max2, long* max3)
{
	long long check_maxim = 0;
	long long maxim = a[0];
	maxim *= a[1];
	maxim *= a[2];
	*max1 = a[0];
	*max2 = a[1];
	*max3 = a[2];

	for (long i = 0; i < number_elements - 2; i++)
	{
		for (long j = i + 1; j < number_elements - 1; j++)
		{
			for (long k = j + 1; k < number_elements; k++)
			{
				check_maxim = a[i];
				check_maxim *= a[j];
				check_maxim *= a[k];
				if (check_maxim > maxim)
				{
					maxim = a[i];
					maxim *= a[j];
					maxim *= a[k];
					
					*max1 = a[i];
					*max2 = a[j];
					*max3 = a[k];
				}
				
			}
		}
	}
	return maxim;
}
int main()
{
	long number_elements;
	
	scanf("%ld", &number_elements);

	long* a = (long*)malloc(number_elements * sizeof(long));
	long check_numbers = 0;
	char term;
	for (long i = 0; i < number_elements; i++)
	{
		if (scanf("%d%c", &a[i], &term) != 2)
		{
			printf("Invalid input! Application will now stop");
			return 0;
		}
	}
	
	if (number_elements < 3)
	{
		printf("Invalid input! Application will now stop");
		return 0;
	}
	quicksort(a, 0, number_elements - 1);
	long max1 = 1;
	long max2 = 1;
	long max3 = 2;
	 long long maxProd = findTriplets(a, number_elements, &max1, &max2, &max3);
	printf("The triplet with the maximum product %lld is (%ld, %ld, %ld)",maxProd, max1, max2, max3);
}