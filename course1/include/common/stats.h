/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maunsigned intain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
#define SIZE (40)

/**
 * @brief Given an array of data and a length, returns the mean
 *
 * Computes mean of all values inside array
 *
 * @param array array containing values
 * @param lengthOfArray length of array
 *
 * @return mean value of array
 */
float find_mean(unsigned char array[SIZE], unsigned int lengthOfArray);

/**
 * @brief Prints all values inside array
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param array array containing values
 * @param lengthOfArray length of array
 *
 */
#ifdef VERBOSE
void print_array(unsigned char array[SIZE], unsigned int lengthOfArray);
#endif

/**
 * @brief sorts all values inside array in descending order
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param array array containing values
 * @param lengthOfArray length of array
 *
 */
void sort_array(unsigned char array[SIZE], unsigned int lengthOfArray);

/**
 * @brief returns the median of all values inside array
 *
 * Given an array of data and a length, returns the median value
 *
 * @param array array containing values
 * @param lengthOfArray length of array
 *
 * @return median value of array
 */
float find_median(unsigned char array[SIZE], unsigned int lengthOfArray);

/**
 * @brief returns the minimum of all values inside array
 *
 * Given an array of data and a length, returns the minimum value
 *
 * @param array array containing values
 * @param lengthOfArray length of array
 *
 * @return mean value of array
 */
unsigned char find_min(unsigned char array[SIZE], unsigned int lenghOfArray);

/**
 * @brief returns the minimum of all values inside array
 *
 * Given an array of data and a length, returns the minimum value
 *
 * @param array array containing values
 * @param lengthOfArray length of array
 *
 * @return mean value of array
 */
unsigned char find_max(unsigned char array[SIZE], unsigned int lenghOfArray);
void print_statistics(unsigned char test[SIZE], unsigned int lenghOfArray);

#endif /* __STATS_H__ */
