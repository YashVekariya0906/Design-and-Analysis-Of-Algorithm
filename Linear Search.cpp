#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element Found" << endl;
            return key;
        }
    }
    cout << "Element not Found" << endl;
    return -1;   /
}

int main() {
    int arr[] = {15, 5, 2, 3, 4, 7};
    int key = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    linear_search(arr, n, key);

    return 0;
}

