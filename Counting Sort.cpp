#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> counting_sort(vector<int> &arr) {
    if (arr.empty())
        return arr;

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range_val = max_val - min_val + 1;

    vector<int> count(range_val, 0), output(arr.size());

    // Count occurrences
    for (int num : arr) {
        count[num - min_val]++;
    }

    // Cumulative count
    for (int i = 1; i < range_val; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (traverse backwards for stability)
    for (int i = arr.size() - 1; i >= 0; i--) {
        count[arr[i] - min_val]--;
        output[count[arr[i] - min_val]] = arr[i];
    }

    return output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    vector<int> sorted_arr = counting_sort(arr);

    cout << "Sorted array: ";
    for (int num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
