#include <iostream>
#include <chrono>
#include <cstdlib>
#include <iomanip>
using namespace std;

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    const int size = 10000;
    int arr[size];

    // Generating an array with random values
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000; // Generating random values between 0 and 9999
    }

    // Measuring the time for sorting
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();

    // Calculating the total sorting time
    chrono::duration<double> time_taken = chrono::duration_cast<chrono::duration<double>>(end - start);

    // Displaying the time with 4 decimal places
    cout << fixed << setprecision(5);
    cout << "Time taken by merge sort: " << time_taken.count() << " seconds" << endl;

    return 0;
}
