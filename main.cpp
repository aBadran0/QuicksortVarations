#include "QuickSort.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

int main() {
  ofstream myfile;
  int nruns = 5;
  myfile.open("data.csv");
  srand(time(0));
  QuickSort impl;
  myfile << "Basic QS,," << endl;
  for (int i = 0; i < nruns; i++) {
    impl.generateBasic();
    impl.quickSortBasic(impl.best, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.best))
      return 0;
    impl.quickSortBasic(impl.avg, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.avg))
      return 0;
    impl.quickSortBasic(impl.worst, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.worst))
      return 0;
    myfile << endl;
  }

  impl.resetAll();
  myfile << "Median of Three QS,," << endl;
  for (int i = 0; i < nruns; i++) {
    impl.generateMedian();
    impl.median_of_three(impl.best, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.best))
      return 0;
    impl.median_of_three(impl.avg, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.avg))
      return 0;
    impl.median_of_three(impl.worst, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.worst))
      return 0;
    myfile << endl;
  }
  impl.resetAll();

  myfile << "Random Pivot QS:" << endl;
  for (int i = 0; i < nruns; i++) {
    impl.generateArrays();
    impl.sortRandomPivot(impl.best, 0, impl.arr_size - 1);
    if (!impl.testSorted(impl.best))
      return 0;
    impl.print(myfile);
    impl.sortRandomPivot(impl.avg, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.avg))
      return 0;
    impl.sortRandomPivot(impl.worst, 0, impl.arr_size - 1);
    impl.print(myfile);
    if (!impl.testSorted(impl.worst))
      return 0;
    myfile << endl;
  }

  myfile.close();
}
