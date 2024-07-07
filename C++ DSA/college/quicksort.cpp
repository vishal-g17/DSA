#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int choosePivot(vector<int>& arr, int low, int high) {
    int middle = low + (high - low) / 2;
    int pivotIndex = (arr[low] + arr[middle] + arr[high]) / 3;
    return pivotIndex;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = choosePivot(arr, low, high);
        int pivot = arr[pivotIndex];
        int i = low;
        int j = high;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }
}

int main() {
    // srand(time(nullptr));

    // ofstream outputFile("sorting_results.txt");

    // for (int n = 100; n <= 1000; n += 100) {
    //     vector<int> arr(n);
    //     for (int i = 0; i < n; i++) {
    //         arr[i] = rand() % 1000;
    //     }

    //     auto start = chrono::steady_clock::now();
    //     quickSort(arr, 0, n - 1);
    //     auto end = chrono::steady_clock::now();

    //     outputFile << "Time taken to sort " << n << " elements using quick sort: "
    //                << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    //                << " milliseconds" << endl;
    // }

    // outputFile.close();
    

    return 0;
}
