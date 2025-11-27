#include <iostream>
using namespace std;

void in_place_sorting(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int arr[] = {4, 5, 3, 1, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    in_place_sorting(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

