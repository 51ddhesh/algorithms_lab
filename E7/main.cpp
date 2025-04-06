#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
void multiply(int i, const vvi &A, const vvi &B, vvi &res);

void input(vvi &v);

void print(const vvi &v);

int main() {
    cout << "Enter the dimesions: ";
    int n; cin >> n;
    vvi A(n, vi(n, 0)), B(n, vi(n, 0)), result(n, vi(n, 0));
    cout << "Enter A: \n";
    input(A);
    cout << "Enter B: \n";
    input(B);
    vector<thread> threads;
    
    for(int i = 0; i < n; i++) threads.emplace_back(multiply, i, cref(A), cref(B), ref(result));
    
    for(thread &t : threads) t.join();
    cout << "Result: \n";
    print(result);
    return 0;
}

void multiply(int i, const vvi &A, const vvi &B, vvi &res) {
    int n = A.size();
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) res[i][j] += A[i][k] * B[k][j];
    }
}

void input(vvi &v) {
    int n = v.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> v[i][j];
    }
}

void print(const vvi &v) {
    int n = v.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
}