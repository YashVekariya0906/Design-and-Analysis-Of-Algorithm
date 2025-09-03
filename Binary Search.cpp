#include <iostream>
using namespace std;

int binary_search(int arr[], int key, int left, int right) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binary_search(arr, key, mid + 1, right);
        else
            return binary_search(arr, key, left, mid - 1);
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]); // size of array
    int key = 3;

    int index = binary_search(arr, key, 0, n - 1);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
