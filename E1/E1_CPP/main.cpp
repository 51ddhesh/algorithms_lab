#include <chrono>
#include <random>
#include <iostream>
#include <fstream>
using namespace std;
using namespace chrono;
void merge(vector<int> &v, int low, int mid, int high){
    int left = low, right = mid + 1;
    vector<int> temp;
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
    if (low == high) return;
    int mid = low + (high - low)/2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}

int main(){
    freopen("in.txt", "r", stdin);
    int min = -100000;
    int max = 100000;
    random_device rd;
    default_random_engine engine(rd());
    uniform_int_distribution<int> dist(min, max);
    ofstream file("data.csv");
    file << "Input_Size,Time\n";
    for(int i = 0; i < 50; i++){
        int n;
        cout << "Enter the size of vector: ";
        cin >> n;
        file << n << ",";
        vector<int> v(n);
        for(int &i : v) i = dist(engine);
        auto start = high_resolution_clock::now();
        mergeSort(v, 0, n - 1);
        auto end = high_resolution_clock::now();
        duration<double> dur = end - start;
        file << dur.count() << "\n";
    }
    file.close();
    return 0;
}