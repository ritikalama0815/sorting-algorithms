
# Sorting Algorithm

This repository contains implementations of sorting algorithms as follows:

* **Heapsort**
* **Quicksort**
* **Merge Sort**
* **Insertion Sort**

---

## 📂 Repository Structure

```
/sorting-algorithms
│
├── heapsort.cpp
│
├── quicksort.cpp
│
├── mergesort.cpp
│
├── insertionsort.cpp
│
└── README.md
```

---

##  Algorithms Overview

### **1. Heapsort**

Heapsort builds a max-heap from the input array and repeatedly extracts the maximum element, placing it at the end of the array.

* **Time Complexity:**

  * Best: O(n log n)
  * Average: O(n log n)
  * Worst: O(n log n)
* **Space Complexity:** O(1)

---

### **2. Quicksort**

Quicksort is a divide-and-conquer algorithm that partitions the array around a pivot and recursively sorts subarrays.

* **Time Complexity:**

  * Best: O(n log n)
  * Average: O(n log n)
  * Worst: O(n²)
* **Space Complexity:** O(log n) (recursive stack)

---

### **3. Merge Sort**

Merge Sort is a stable divide-and-conquer algorithm that splits the array into halves, recursively sorts them, and merges the results.

* **Time Complexity:**

  * Best: O(n log n)
  * Average: O(n log n)
  * Worst: O(n log n)
* **Space Complexity:** O(n)

---

### **4. Insertion Sort**

Insertion Sort processes the array one element at a time, inserting each into its correct position.

* **Time Complexity:**

  * Best: O(n)
  * Average: O(n²)
  * Worst: O(n²)
* **Space Complexity:** O(1)

---

## How to Run

Clone the repo:

```bash
git clone https://github.com/ritikalama0815/sorting-algorithms.git
cd sorting-algorithms
```

Run any algorithm file:

```bash
g++ heapsort.cpp -o heapsort
./heapsort
g++ mergesort.cpp -o mergesort
./mergesort
g++ quicksort.cpp -o quicksort
./quicksort
g++ insertion.cpp -o insertion
./insertion
```

---


If you want, I can rewrite this in a more formal/stylish tone, add GIFs, add algorithm diagrams, or generate the folder structure with code files too.
