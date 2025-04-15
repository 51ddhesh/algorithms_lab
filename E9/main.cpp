#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
const int d = 256;
// q is a prime number used for mod to reduce the hash value size
const int q = 101;

// Rabin-Karp search function: returns the starting indices of each match
vector<int> rabinKarp(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> result;
    
    // If pattern length is greater than text length, no match is possible.
    if(m > n) return result;
    
    int h = 1;  // The value of h would be "pow(d, m-1)%q"
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;
    
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text window

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check if hash values of current window and pattern match.
        // If the hash values match then only check for characters one by one
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                result.push_back(i); // Pattern found at index i
        }
        
        // Calculate hash value for next window: Remove leading digit, add trailing digit
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            // We might get negative t, convert it to positive
            if (t < 0)
                t = t + q;
        }
    }
    
    return result;
}
