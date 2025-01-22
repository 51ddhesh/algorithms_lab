#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(vector<int> &v, int low, int high){
    int pivot = v[low];
    int i = low, j = high;
    while(i < j){
        while(v[i] <= pivot && i < high) i++;
        while(v[j] >= pivot && j > low) j--;
        if(i < j) swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}

void quickSort(vector<int> &v, int low, int high){
    if(low < high){
        int p = partition(v, low, high);
        quickSort(v, low, p - 1);
        quickSort(v, p + 1, high);
    }
}

int main(){
    freopen("out.txt", "r", stdin);
    int min = -100000, max = 100000;
    mt19937 generator;
    uniform_int_distribution<int> distribution(min, max);
    ofstream file("qs_data.csv");
    file << "Ip_Size,Time\n";
    for(int i = 0; i < 50; i++){
        int n; cin >> n;
        file << n << ",";
        vector<int> v(n);
        for(int &i : v) i = distribution(generator);
        auto start = high_resolution_clock::now();
        quickSort(v, 0, n - 1);
        auto end = high_resolution_clock::now();
        duration<double> d = end - start;
        file << d.count() << "\n";
    }
    file.close();
    return 0;
}