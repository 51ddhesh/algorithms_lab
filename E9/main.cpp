#include <bits/stdc++.h> 
using namespace std;

const int d = 256; 
const int q = 101;  

int hashValue(string& str, int n) {
    int h = 0;
    for (int i = 0; i < n; i++)  h = (d * h + str[i]) % q;
    return h;
}

void rabinKarpSearch(string& text, string& pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) {
        cout << "Pattern is longer than text." << endl;
        return;
    }
    int patternHash = hashValue(pattern, m);
    int textHash = hashValue(text, m);
    int dm = 1;
    for (int i = 0; i < m - 1; i++) {
        dm = (d * dm) % q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            textHash = (d * (textHash - text[i] * dm) + text[i + m]) % q;
            if (textHash < 0) textHash += q;  
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter Text: "; cin >> text;
    cout << "Enter Pattern: "; cin >> pattern;
    rabinKarpSearch(text, pattern);
    return 0;
}
