#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int index;
    int start;
    int finish;
};

vector<int> activitySelection(vector<int> start_times, vector<int> finish_times) {
    int n = start_times.size();
    vector<Activity> activities(n);

    // Prepare list of activities with index, start, and finish
    for (int i = 0; i < n; i++) {
        activities[i] = {i, start_times[i], finish_times[i]};
    }

    // Sort by finish time
    sort(activities.begin(), activities.end(),
         [](Activity a, Activity b) {
             return a.finish < b.finish;
         });

    vector<int> selected;
    int last_finish_time = 0;

    for (auto &act : activities) {
        if (act.start >= last_finish_time) {
            selected.push_back(act.index);
            last_finish_time = act.finish;
        }
    }
    return selected;
}

int main() {
    vector<int> start_times = {1, 3, 0, 5, 8, 5};
    vector<int> finish_times = {6, 3, 8, 2, 0, 7};

    vector<int> selected = activitySelection(start_times, finish_times);

    cout << "Selected Activities (by index): ";
    for (int idx : selected)
        cout << idx << " ";
    cout << endl;

    return 0;
}
