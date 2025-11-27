#include <iostream>
using namespace std;

int recursive_function(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * recursive_function(base, exponent - 1);
    }
}

int main() {
    int base = 5;
    int exponent = 5;

    cout << recursive_function(base, exponent) << endl;

    return 0;
}
