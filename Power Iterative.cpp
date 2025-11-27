#include <iostream>
using namespace std;

int power_function(int base, int exponent) {
    int result = 1;
    
    for (int i = 0; i < exponent; i++) {
        result = base * result;
    }
    
    return result;
}

int main() {
    int base = 2;
    int exponent = 5;

    cout << power_function(base, exponent);
    return 0;
}
