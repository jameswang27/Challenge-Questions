//Intuit Coding Question 01

/*
Sort the following list in numeric order :
1, 10, 5, 63, 29, 71, 10, 12, 44, 29, 10, -1
*/

/*
We will solve this problem by implementing a QuickSort algorithm. This algorithm can solve basic sorting in O(nlogn) time.

Note that the sorted answer should look like this:
-1, 1, 5, 10, 10, 10, 12, 29, 29, 44, 63, 71
*/


#include <assert.h>		//For test cases
#include <algorithm>	//For swap
#include <iostream>		//For cout
using namespace std;

void QuickSort(int data[], int first, int last);
int partition(int data[], int low, int high);


int main()
{
	int test[12] = { 1, 10, 5, 63, 29, 71, 10, 12, 44, 29, 10, -1 };

	QuickSort(test, 0, 11);

	//Have cassert break the program if the result isn't sorted
	assert(test[0] == -1);
	assert(test[1] == 1);
	assert(test[2] == 5);
	assert(test[3] == 10);
	assert(test[4] == 10);
	assert(test[5] == 10);
	assert(test[6] == 12);
	assert(test[7] == 29);
	assert(test[8] == 29);
	assert(test[9] == 44);
	assert(test[10] == 63);
	assert(test[11] == 71);

	//Confirm using I/O that the program has been successfully sorted
	for (int i = 0; i < 12; i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;
	cout << "Finished" << endl;

	
}

/*
Purpose: Answer the problem, sort the list of numbers in an integer array format.
Functionality: After ensuring integrity of the parameters, sort the input array by partitioning it and recursively running it.
Parameters:
	-int data[]: input array of integers
	-int first: index to begin at
	-int last: index to end at
Return value: Nothing. The data array will be sorted upon conclusion of this function.
*/

void QuickSort(int data[], int first, int last)
{
	if (last - first >= 1) //ensure parameters are passed in correctly
	{
		int pivotIndex;
		pivotIndex = partition(data, first, last);
		QuickSort(data, first, pivotIndex - 1); //Recursive call on left hand side
		QuickSort(data, pivotIndex + 1, last);	//Recursive call on right hand side

	}
}

/*
Purpose: Helper function for QuickSort.
Functionality: For the input array, select the first item as a pivot. Swap smaller items to the left and larger items to the right.
Parameters:
	-int data[]: input array of integers
	-int low: low end of the array to begin at
	-int high: high end of the array to begin at
Return value: The pivot's index in the array
*/
int partition(int data[], int low , int high)
{
	int pivot = data[low];
	int pivot_Index = low;

	do
	{
		while (low <= high && data[low] <= pivot)
		{
			low++;
		}
		while (data[high] > pivot)
		{
			high--;
		}
		if (low < high)
		{
			swap(data[low], data[high]);
		}
	} while (low < high);
	swap(data[pivot_Index], data[high]);
	pivot_Index = high;
	return pivot_Index;
}