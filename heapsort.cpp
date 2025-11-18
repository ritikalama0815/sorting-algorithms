#include <iostream>
#include <vector>
using namespace std;

/**
 * Percolates a node down the heap to restore the heap property.
 * 
 * @param array The vector representing the heap.
 * @param size The size of the heap (number of elements).
 * @param parent The index of the parent node to percolate down.
 */
void percolateDown(vector<int>& array, int size, int parent) {
    int target = parent;
    
    // Continue percolating down as long as the parent has at least one child
    while (2 * parent + 1 < size) {
        int left = 2 * parent + 1;    // Left child index
        int right = left + 1;         // Right child index

        // Choose the larger of the two children
        if (right < size && array[left] < array[right]) {
            target = right;
        } else {
            target = left;
        }

        // If the parent is smaller than the target child, swap and move down
        if (array[target] > array[parent]) {
            swap(array[parent], array[target]);
            parent = target;  
        } else {
            return;  
        }
    }
}

/**
 * Sorts the array using the heapsort algorithm.
 * 
 * @param array The vector of integers to be sorted.
 * @param n The size of the array.
 */
void heapsort(vector<int>& array, int n) {
    // Build the max-heap 
    for (int i = n / 2 - 1; i >= 0; i--) {
        percolateDown(array, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 1; i--) {
        swap(array[0], array[i]);  
        percolateDown(array, i, 0); 
    }

    cout << "Sorted array: ";
    // Print sorted array 
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

/**
 * The main function where the program starts execution.
 * 
 * @return Returns 0 to indicate successful execution.
 */
int main() {
    // Initialize an unsorted array
    vector<int> array = {10, 50, 16, 16, 2, 5};
    int n = array.size();
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    heapsort(array, n);

    return 0;  
}
