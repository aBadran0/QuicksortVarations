#include "QuickSort.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
using namespace std;

QuickSort::QuickSort() { resetAll(); }

void QuickSort::generateArrays() {
  for (int i = 0; i < arr_size; i++) {
    best[i] = rand() % arr_size;
    avg[i] = rand() % arr_size;
    worst[i] = i;
  }
}

void QuickSort::generateMedian() {
  for (int i = 0; i < arr_size; i++) {
    best[i] = rand() % arr_size;
    avg[i] = rand() % arr_size;
    worst[i] = arr_size / 2;
  }
}

void QuickSort::generateBasic() {
  for (int i = 0; i < arr_size; i++) {
    best[i] = i;
    avg[i] = rand() % arr_size;
    worst[i] = arr_size - i;
  }
  // for the best case array
  int start = 0, end = arr_size - 1;
  while (start < end) {
    int pivot = (start + end) / 2;
    std::swap(best[pivot], best[start]);
    start++;
  }
}

void QuickSort::reset() {
  // reset counters
  nComparisons = 0;
  nSwaps = 0;
}

void QuickSort::print(ofstream &ost) {
  ost << nComparisons << ",";
  reset();
}

void QuickSort::printArray(int *arr) {
  for (int i = 0; i < QuickSort::arr_size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void QuickSort::resetAll() {
  reset();
  generateArrays();
}

void QuickSort::quickSortBasic(int *arr, int l, int r) {
  if (l < r) {
    int pivot = partition(arr, l, r);
    quickSortBasic(arr, l, pivot - 1);
    quickSortBasic(arr, pivot + 1, r);
  }
}

int QuickSort::median(int *arr, int l, int r) {
  int mid = (l + r) / 2;
  if (arr[l] > arr[mid]) {
    swap(arr[l], arr[mid]);
    nComparisons++;
  }
  if (arr[mid] > arr[r]) {
    swap(arr[mid], arr[r]);
    nComparisons++;
  }
  if (arr[l] > arr[mid]) {
    swap(arr[l], arr[mid]);
    nComparisons++;
  }
  return mid;
}

void QuickSort::median_of_three(int *arr, int l, int r) {
  if (l < r) {
    int pivot = median(arr, l, r);
    swap(arr[pivot], arr[r]);
    nComparisons++;
    pivot = partition(arr, l, r);
    median_of_three(arr, l, pivot - 1);
    median_of_three(arr, pivot + 1, r);
  }
}

int QuickSort::randomPivot(int *arr, int l, int r) {
  int pivot_index = rand() % (r - l + 1) + l;
  return pivot_index;
}

void QuickSort::sortRandomPivot(int *arr, int l, int r) {
  if (l < r) {
    int pivot = randomPivot(arr, l, r);
    swap(arr[pivot], arr[r]);
    pivot = partition(arr, l, r);
    sortRandomPivot(arr, l, pivot - 1);
    sortRandomPivot(arr, pivot + 1, r);
  }
}
