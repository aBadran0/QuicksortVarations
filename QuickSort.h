#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <fstream>
#include <ostream>
#include <string>

class QuickSort {
public:
  static const int arr_size = 1e5;
  int best[arr_size];
  int avg[arr_size];
  int worst[arr_size];

  int nComparisons;
  int nSwaps;

  QuickSort();

  void generateArrays();
  void generateBasic();
  void generateMedian();
  void reset();
  void resetAll();

  void print(std::ofstream &ost);
  void printArray(int arr[]);

  void quickSortBasic(int arr[], int l, int r);

  int median(int arr[], int l, int r);
  void median_of_three(int arr[], int l, int r);

  int randomPivot(int arr[], int l, int r);
  void sortRandomPivot(int arr[], int l, int r);

  bool testSorted(int arr[]) {
    int prev = arr[0];
    for (int i = 1; i < arr_size; i++) {
      if (arr[i] >= prev) {
        prev = arr[i];
      } else
        return false;
    }
    return true;
  }

private:
  int partition(int arr[], int l, int r) {
    int pivot = arr[l];
    int i = l + 1;
    int j = r;

    while (true) {
      while (i <= j && arr[i] <= pivot) {
        i++;
        nComparisons++;
      }
      while (i <= j && arr[j] > pivot) {
        j--;
        nComparisons++;
      }
      if (i <= j) {
        swap(arr[i], arr[j]);
      } else {
        break;
      }
    }
    swap(arr[l], arr[j]);
    return j;
  };

  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    nSwaps++;
  }
};

#endif
