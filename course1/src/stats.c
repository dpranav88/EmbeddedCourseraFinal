/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief contains implementation and definitions for following file:
 *   main() - The main entry point for your program
 *   print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *   print_array() - Given an array of data and a length, prints the array to the screen
 *   find_median() - Given an array of data and a length, returns the median value
 *   find_mean() - Given an array of data and a length, returns the mean
 *   find_maximum() - Given an array of data and a length, returns the maximum
 *   find_minimum() - Given an array of data and a length, returns the minimum
 *   sort_array() - Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 *
 * @author Pranav Deshpande
 * @date  Tuesday, 24 April 2018
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
//#define SIZE (40)

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
			114, 88,   45,  76, 123,  87,  25,  23,
			200, 122, 150, 90,   92,  87, 177, 244,
			201,   6,  12,  60,   8,   2,   5,  67,
			7,  87, 250, 230,  99,   3, 100,  90};

	/* Other Variable Declarations Go Here */
	unsigned int lenghOfArray = SIZE;
	/* Statistics and printing Functions Go Here */

#ifdef VERBOSE
	print_statistics(test, lenghOfArray);
#endif
}

/* Add other Implementation File Code Here */


float find_mean(unsigned char array[SIZE], unsigned int lenghOfArray)
{
	unsigned int i =0;
	float meanVal = 0.0f;

	for (i = 0;i <= lenghOfArray-1;i++)
	{
		meanVal +=  ((float)(array[i]));
	}

	meanVal = meanVal/((float)lenghOfArray);
	return meanVal;
} 

#ifdef VERBOSE
void print_array(unsigned char array[SIZE], unsigned int lenghOfArray)
{
	unsigned int i =0;

	for (i = 0;i <= lenghOfArray-1;i++)
	{
		if(((i+1)%10 == 0) || ((i+1) == lenghOfArray ))
		{
			PRINTF("Array[%d] = %d,\n", i, array[i]);
		}
		else
		{
			PRINTF("Array[%d] = %d,\t", i, array[i]);
		}
	}

}
#endif


void sort_array(unsigned char array[SIZE], unsigned int lenghOfArray)
{
	unsigned int i =0, j =0;

	for (i=0; i<lenghOfArray-1; i++)
	{
		for (j=i+1; j<lenghOfArray; j++)
		{
			if(array[j] > array[i])
			{
				array[j] = array[j] + array[i];
				array[i] = array[j] - array[i];
				array[j] = array[j] - array[i];

			}

		}
	}
}

float find_median(unsigned char array[SIZE], unsigned int lenghOfArray)
{
	sort_array(array, lenghOfArray);

	if((lenghOfArray%2) == 0)
		return (((float)array[((unsigned int)(lenghOfArray/2))]) + ((float)array[((unsigned int)(lenghOfArray/2)) +1]))/2.0;
	else
		return ((float)array[((unsigned int)(lenghOfArray/2))]);

}


unsigned char find_min(unsigned char array[SIZE], unsigned int lenghOfArray)
{
	sort_array(array, lenghOfArray);

	return array[SIZE-1];

}

unsigned char find_max(unsigned char array[SIZE], unsigned int lenghOfArray)
{
	sort_array(array, lenghOfArray);

	return array[0];

}

void print_statistics(unsigned char test[SIZE], unsigned int lenghOfArray)
{
#ifdef VERBOSE

	PRINTF("\nThe original Array is:\n");
	print_array(test, lenghOfArray);
#endif
	sort_array(test,  lenghOfArray);
#ifdef VERBOSE
	PRINTF("\nThe sorted Array is:\n");
	print_array(test, lenghOfArray);
#endif

	PRINTF("\nMinimum value of Array is: %d\n", find_min(test, lenghOfArray));
	PRINTF("\nMaximum value of Array is: %d\n", find_max(test, lenghOfArray));
	PRINTF("\nMean value of Array is: %f\n", find_mean(test, lenghOfArray));
	PRINTF("\nMedian value of Array is: %f\n", find_median(test, lenghOfArray));
}
