#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void selectionSort(vector<T>& arr, bool ascending = true) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minMaxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && arr[j] < arr[minMaxIndex]) || (!ascending && arr[j] > arr[minMaxIndex]))
                minMaxIndex = j;
        }
        swap(arr[i], arr[minMaxIndex]);
    }
}