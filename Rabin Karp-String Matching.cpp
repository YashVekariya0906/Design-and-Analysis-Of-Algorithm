#include <iostream>
#include <string>
using namespace std;

string rabin_karp(string text, string pattern) {
    int d = 256;
    int q = 101;

    int n = text.length();
    int m = pattern.length();

    int p_hash = 0;
    int t_hash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        p_hash = (d * p_hash + pattern[i]) % q;
        t_hash = (d * t_hash + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {

        if (p_hash == t_hash) {
            if (text.substr(i, m) == pattern) {
                return "Pattern found at index " + to_string(i);
            }
        }

        if (i < n - m) {
            t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;

            if (t_hash < 0)
                t_hash += q;
        }
    }

    return "Pattern not found";
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";

    cout << rabin_karp(text, pattern) << endl;

    return 0;
}

