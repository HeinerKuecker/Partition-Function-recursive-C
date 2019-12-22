/*
 ============================================================================
 Name        : PARTITION_FUNCTION_C.c
 Author      : Heiner Kuecker
 Version     :
 Copyright   : do what you want, no guarantee
 Description : Generate partition set of given int number in C, Ansi-style
 https://de.wikipedia.org/wiki/Partitionsfunktion
 https://en.wikipedia.org/wiki/Partition_function_(number_theory)
 https://de.wikipedia.org/wiki/Partitionierungsproblem
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_TO_BE_PARTITIONED 5

// function pointer type for a function to handle the current partttion of the number to be partitioned
typedef void (*OnePartitionHandler_fp) (
		// number to be partitioned
		const int numberToPartitioned,
		// 0 terminated array of the current partition (sequence of summands)
		const int * entirePartitionArray);

// inner recursive function
static void executeForPartitionFunctionRecursive(
		// number to be partitioned from the root call of recursion
		const int numberToPartitioned,
		// current subsequent number to be partitioned for the current call
		const int currentNumberToPartitioned,
		// 0 terminated array of the current partition (sequence of summands) from the root call of recursion
		int * entirePartitionArray,
		// current index in the array of all partitions
		// the count of left array cells is enough for all partitions of the current number to be partitioned
		const int currentIndexInEntirePartitionArray,
		// function pointer to execute for every partition of the number to be partitioned
		OnePartitionHandler_fp onePartitionHandlerFunctionPointer)
{
	for (int i = 1; i <= currentNumberToPartitioned; ++i)
	{
		entirePartitionArray[currentIndexInEntirePartitionArray] = i;
		//printf(" %d", i);
		//fflush(stdout);

		const int rest = currentNumberToPartitioned - i;
		if (rest > 0)
		{
			executeForPartitionFunctionRecursive(
					numberToPartitioned,
					rest,
					entirePartitionArray,
					currentIndexInEntirePartitionArray + 1,
					onePartitionHandlerFunctionPointer);
		}
		else
		{
			// call of function pointer for the current partition
			onePartitionHandlerFunctionPointer(
					numberToPartitioned,
					entirePartitionArray);
		}
	}
	entirePartitionArray[currentIndexInEntirePartitionArray] = 0; // set terminator
}

/**
 * API function for 'partition function' (mathematical term)
 */
void executeForPartitionFunction(
		// number to be partitioned for the current call
		const int numberToPartitioned,
		// function pointer to execute for every partition of the number to be partitioned
		OnePartitionHandler_fp onePartitionHandlerFunctionPointer)
{
	int entirePartitionArray[MAX_NUMBER_TO_BE_PARTITIONED + 1];

	for (int i = 0; i < (MAX_NUMBER_TO_BE_PARTITIONED + 1); ++i)
	{
		entirePartitionArray[i] = 0;
	}

	executeForPartitionFunctionRecursive(
			numberToPartitioned,
			numberToPartitioned,
			entirePartitionArray,
			0,
			onePartitionHandlerFunctionPointer);
}

/**
 * Test and example for using the function
 */

// function to execute for every partition
void printCurrentPartition(
		// number to be partitioned
		const int numberToPartitioned,
		// 0 terminated array of the current partition (sequence of summands)
		const int * entirePartitionArray)
{
	for (int i = 0; entirePartitionArray[i] != 0; ++i)
	{
		printf(" %d", entirePartitionArray[i]);
	}
	printf("\n");
	fflush(stdout);
}

// main
int main(void)
{
	// loop over all numbers to be partitioned
	for (int i = 1; i <= MAX_NUMBER_TO_BE_PARTITIONED; ++i)
	{
		printf("%d\n", i);

		// recursive run over one number to be partitioned
		executeForPartitionFunction(
				i,
				printCurrentPartition);

		printf("\n");
		printf("\n");
		fflush(stdout);
	}

	puts("ok");
	return EXIT_SUCCESS;
}
