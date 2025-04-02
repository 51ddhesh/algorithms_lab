#include <bits/stdc++.h>
using namespace std;

struct City {
    int x, y;
};

double distance(const City& a, const City& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double nearestNeighborTSP(const vector<City>& cities, vector<int>& path) {
    int n = cities.size();
    vector<bool> visited(n, 0);
    visited[0] = 1;
    int currentCity = 0;
    double totalDistance = 0.0;
    path.push_back(currentCity);
    for (int i = 1; i < n; ++i) {
        double minDist = numeric_limits<double>::infinity();
        int nextCity = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double dist = distance(cities[currentCity], cities[j]);
                if (dist < minDist) minDist = dist, nextCity = j;
            }
        }
        visited[nextCity] = 1;
        path.push_back(nextCity); 
        totalDistance += minDist, currentCity = nextCity;
    }

    totalDistance += distance(cities[currentCity], cities[0]);
    path.push_back(0); 
    return totalDistance;
}

double calculateTourLength(const vector<int>& tour, const vector<City>& cities) {
    double totalLength = 0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        totalLength += distance(cities[tour[i]], cities[tour[i + 1]]);
    }
    totalLength += distance(cities[tour.back()], cities[tour[0]]);
    return totalLength;
}

double calculateApproximationError(double approx, double optimal) {
    return (approx - optimal) / optimal;
}

int main() {
    vector<City> cities = {
        {0, 0}, {1, 2}, {2, 4}, {3, 1}, {5, 0}
    };
    vector<int> path;
    double approxSolution = nearestNeighborTSP(cities, path);
    double optimalSolution = 10.0;
    double error = calculateApproximationError(approxSolution, optimalSolution);
    cout << "Approximate Solution: " << approxSolution << '\n';
    cout << "Optimal Solution: " << optimalSolution << '\n';
    cout << "Error of Approximation: " << error * 100 << "%" << '\n';
    cout << "Path Traveled: ";
    for (int cityIndex : path) cout << cityIndex << " ";
    cout << '\n';
    return 0;
}