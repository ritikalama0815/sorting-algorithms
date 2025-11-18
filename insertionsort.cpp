#include <iostream>
#include <vector>
using namespace std;

/**
 * 
 * This function sorts the input vector `array` by repeatedly inserting each element 
 * into its correct position within the sorted portion of the array. The sorting is done in-place.
 * 
 * @param array The vector of integers to be sorted.
 **/
void insertionSort(vector<int>& array){
    int n = array.size();
    for(int j = 2; j < n; j++){
        int key = array[j];
        int i = j - 1;
        while( i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
    
    cout << "Sorted array: ";
    for (int k = 0; k < n; k++){
        cout << array[k] << " ";
    }
    cout << endl;
}

/**
 * 
 * This function initializes a sample vector, applies the Insertion Sort algorithm, 
 * and outputs the sorted array to the console.
 * 
 * @return 0 to indicate successful execution.
 */
int main(){
    vector <int> array = { 10, 50, 16, 16, 2, 5};
    cout << "Original array: ";
    for (int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }

    insertionSort(array);
    return 0;
}
