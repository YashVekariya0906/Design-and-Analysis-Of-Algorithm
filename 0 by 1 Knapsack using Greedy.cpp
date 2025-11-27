#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    int wt;
    int val;
    double ratio;
};
int main()
{
    int size;
    cout << "Enter total items:";
    cin >> size;
    item items[size];
    cout << "Enter details of items:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter item[" << i << "] wt: ";
        cin >> items[i].wt;
        cout << "Enter item[" << i << "] val: ";
        cin >> items[i].val;
        items[i].ratio = items[i].val / items[i].wt;
    }
    sort(items, items + size, [](const item &a, const item &b)
         { return a.ratio > b.ratio; });

    int capacity;
    cout << "Enter total capacity";
    cin >> capacity;

    int current_weight = 0;
    int total_value = 0;
    item selected_items[size];
    int sIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (current_weight + items[i].wt <= capacity)
        {
            selected_items[sIndex++] = items[i];
            current_weight += items[i].wt;
            total_value += items[i].val;
        }
    }
    cout << "Selected items:" << endl;
    for (int i = 0; i < sIndex; i++)
    {
        cout << selected_items[i].wt << " " << selected_items[i].val << endl;
    }
    cout << "total value" << total_value;
    cout << "wt picked:" << current_weight;

    return 0;
}
