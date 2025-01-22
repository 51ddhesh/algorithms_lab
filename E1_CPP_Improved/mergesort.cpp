#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

void merge(vector<int> &v, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high){
        if(v[left] < v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i = low; i <= high; i++) v[i] = temp[i - low];
}

void mergeSort(vector<int> &v, int low, int high){
    if(low == high) return;
    int mid = low + (high - low)/2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}

int main(){
    freopen("out.txt", "r", stdin);
    int min = -100000, max = 100000;
    mt19937 generator;
    uniform_int_distribution<int> distribution(min, max);
    ofstream file("ms_data.csv");
    file << "Ip_Size,Time\n";
    for(int i = 0; i < 50; i++){
        int n; cin >> n;
        file << n << ",";
        vector<int> v(n);
        for(int &i : v) i = distribution(generator);
        auto start = high_resolution_clock::now();
        mergeSort(v, 0, n - 1);
        auto end = high_resolution_clock::now();
        duration<double> d = end - start;
        file << d.count() << "\n";
    }
    file.close();
    return 0;
}