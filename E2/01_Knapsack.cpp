#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < wt.size(); i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];  
}
int main() {
    cout << "Enter the number of items: ";
    int n; cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter the weights: ";
    for (int &i : wt) cin >> i;
    cout << "Enter the values of the items: ";
    for (int &i : val) cin >> i;
    cout << "Enter the maximum capacity: ";
    int W; cin >> W;
    cout << "Optimal Profit: " << knapSack(W, wt, val) << "\n";    
    return 0;
}