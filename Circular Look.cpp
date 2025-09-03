#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int circular_lock(string start, string target) {
    int moves = 0;

    for (size_t i = 0; i < start.size(); i++) {
        int s = start[i] - '0';   // convert char to int
        int t = target[i] - '0';
        int diff = abs(s - t);
        moves += min(diff, 10 - diff);
    }

    return moves;
}

int main() {
    string start, target;
    cout << "Enter starting combination: ";
    cin >> start;
    cout << "Enter target combination: ";
    cin >> target;

    cout << "Minimum moves required: " << circular_lock(start, target) << endl;

    return 0;
}
