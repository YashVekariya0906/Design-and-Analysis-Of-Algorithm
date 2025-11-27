#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int wt;
    int val;
    double ratio;
};

int main() {
    int size;
    cout << "Enter total items: ";
    cin >> size;

    item items[size];
    cout << "Enter details of items:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter item[" << i << "] wt: ";
        cin >> items[i].wt;
        cout << "Enter item[" << i << "] val: ";
        cin >> items[i].val;
        items[i].ratio = (double)items[i].val / items[i].wt; // FIXED
    }

    // Sort items by value/weight ratio (descending order)
    sort(items, items + size, [](const item &a, const item &b) {
        return a.ratio > b.ratio;
    });

    int capacity;
    cout << "Enter total capacity: ";
    cin >> capacity;

    double total_value = 0.0;
    int current_weight = 0;

    cout << "\nSelected items (including fractions):" << endl;

    for (int i = 0; i < size; i++) {
        if (current_weight + items[i].wt <= capacity) {
            // take full item
            current_weight += items[i].wt;
            total_value += items[i].val;
            cout << "Item (wt=" << items[i].wt << ", val=" << items[i].val << ") taken fully\n";
        } else {
            // take fraction of item
            int remain = capacity - current_weight;
            if (remain > 0) {
                double fraction = (double)remain / items[i].wt;
                total_value += items[i].val * fraction;
                current_weight += remain;
                cout << "Item (wt=" << items[i].wt << ", val=" << items[i].val
                     << ") taken fraction = " << fraction << endl;
            }
            break; // bag full
        }
    }

    cout << "\nTotal value in Knapsack = " << total_value << endl;
    cout << "Total weight used = " << current_weight << endl;

    return 0;
}
