#include <iostream>
#include <vector>
using namespace std;

/**
 * Merges two sorted subarrays of the array into a single sorted subarray.
 * 
 * @param array The vector of integers to be merged.
 * @param left The starting index of the first subarray.
 * @param mid The ending index of the first subarray, which is also the midpoint between the two subarrays.
 * @param right The ending index of the second subarray.
 */
void merge(vector<int>& array, const int left, const int mid, const int right) {
    const int length1 = mid - left + 1;
    const int length2 = right - mid;

    // Create temporary arrays to hold the values of the two subarrays
    int* leftArray = new int[length1];
    int* rightArray = new int[length2];

    // Copy data into the temporary arrays
    for (int i = 0; i < length1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < length2; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    int indexOfLeftArray = 0;
    int indexOfRightArray = 0;
    int indexOfMergedArray = left;

    // Merge the temporary arrays back into the original array
    while (indexOfLeftArray < length1 && indexOfRightArray < length2) {
        if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
            array[indexOfMergedArray] = leftArray[indexOfLeftArray];
            indexOfLeftArray++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfRightArray];
            indexOfRightArray++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of the left subarray 
    while (indexOfLeftArray < length1) {
        array[indexOfMergedArray] = leftArray[indexOfLeftArray];
        indexOfLeftArray++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of the right subarray 
    while (indexOfRightArray < length2) {
        array[indexOfMergedArray] = rightArray[indexOfRightArray];
        indexOfRightArray++;
        indexOfMergedArray++;
    }

    // memory deallocation
    delete[] leftArray;
    delete[] rightArray;
}

/**
 * Recursively divides the array into two halves and then merges them back together.
 * 
 * @param array The vector of integers to be sorted.
 * @param begin The starting index of the section of the array to be sorted.
 * @param end The ending index of the section of the array to be sorted.
 */
void mergesort(vector<int>& array, const int begin, const int end) {
    if (begin >= end) {
        return; // Base case
    }

    int mid = begin + (end - begin) / 2;
    mergesort(array, begin, mid);     // Recursively sort the left half
    mergesort(array, mid + 1, end);   // Recursively sort the right half
    merge(array, begin, mid, end);    // Merge the sorted halves
}

/**
 * Main function where the program starts execution.
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
    mergesort(array, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0; 
}
