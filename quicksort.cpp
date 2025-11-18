#include <iostream>
#include <vector>
using namespace std;

/**
 * Partitions the array around a pivot such that elements smaller than or equal to the pivot are on the left,
 * and elements greater than the pivot are on the right.
 * 
 * @param array The vector of integers to be partitioned.
 * @param start The starting index of the section of the array to partition.
 * @param end The ending index of the section of the array to partition.
 * 
 * @return The index of the pivot after partitioning.
 */
int partition(vector<int>& array, int start, int end){
    int pivot = array[start];  // The pivot is chosen as the first element of the array
    int count = 0;
    
    // Count how many elements are less than or equal to the pivot
    for( int i = start + 1; i <= end; i++){
        if(array[i] <= pivot){
            count++;
        }
    }

    // Place the pivot at its correct position
    int pivotIndex = start + count;
    swap(array[pivotIndex], array[start]);

    int i = start, j = end;

    // Partition the array 
    while(i < pivotIndex && j > pivotIndex){
        while(array[i] <= pivot){
            i++;
        }
        
        while(array[j] > pivot){
            j--;
        }
        
        // Swap elements if necessary
        if(i < pivotIndex && j > pivotIndex){
            swap(array[i++], array[j--]);
        }
    }

    return pivotIndex;  
}

/**
 * Sorts the array using the quicksort algorithm.
 * 
 * @param array The vector of integers to be sorted.
 * @param start The starting index of the section of the array to be sorted.
 * @param end The ending index of the section of the array to be sorted.
 */
void quicksort(vector<int>& array, int start, int end){
    // Base case
    if(start >= end){
        return;
    }

    // Partition the array and get the pivot index
    int p = partition(array, start, end);
    // sorting recursively
    quicksort(array, start, p-1);
    quicksort(array, p+1, end);
}

/**
 * The main function where the program starts execution.
 * It initializes an array, calls the quicksort function, and prints the sorted array.
 * 
 * @return Returns 0 to indicate successful execution.
 */
int main() {
    vector<int> array = {10, 50, 16, 16, 2, 5};
    
    int n = array.size();  

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    quicksort(array, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    
    return 0;  
}
