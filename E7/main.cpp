#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the text: ";
    string s; cin >> s;
    cout << "Enter the pattern to search: ";
    string p; cin >> p;
    vector<int> pos;
    int n = s.size(), m = p.size();
    for(int i = 0; i <= n - m; i++) {
        int c = 0;
        for(c = 0; c < m; c++) {
            if(s[i + c] != p[c]) break;
        }
        if(c == m) pos.push_back(i);
    }
    if(pos.empty()) cout << "No matches\n";
    else {
        cout << "Matches found at: ";
        for(int &i : pos) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}