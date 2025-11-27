#include <iostream>
using namespace std;

long long power(long long x, long long n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    long long left = power(x, n / 2);
    long long right = power(x, n - n / 2);

    return left * right;
}

int main() {
    long long x, n;
    cout << "Enter Base: ";
    cin >> x;

    cout << "Enter Exponent: ";
    cin >> n;

    cout << "Result: " << power(x, n) << endl;

    return 0;
}
