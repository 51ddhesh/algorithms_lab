#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;
using namespace chrono;
int partition(vector<int>& arr, int s, int e) {
    int i = s - 1;

    for(int j = s; j < e; j++) {
        if(arr[j] < arr[e]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[e]);
    return i;
}

void quickSort(vector<int> &arr, int s, int e) {
    if(s >= e)
        return;

    int pivot = partition(arr, s, e);

    quickSort(arr, s, pivot - 1);
    quickSort(arr, pivot + 1, e);
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
        quickSort(v, 0, n - 1);
        auto end = high_resolution_clock::now();
        duration<double> dur = end - start;
        file << dur.count() << "\n";
    }
    file.close();
    return 0;
}
