#include <vector>

void bubbleSort(std::vector<int>& array);

void merge(std::vector<int>& array, int left, int mid, int right);

void mergeSort(std::vector<int>& array, int left, int right);

int partition(std::vector<int>& array, int low, int high);

void quickSort(std::vector<int>& array, int low, int high);