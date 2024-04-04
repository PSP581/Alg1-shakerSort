#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;


mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());


vector<int> generateRandomVector(int length, int minVal, int maxVal) {
    uniform_int_distribution<int> distribution(minVal, maxVal);
    vector<int> result;
    result.reserve(length);
    for (int i = 0; i < length; ++i) {
        result.push_back(distribution(gen));
    }
    return result;
}


void shakerSort(vector<int>& arr) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        for (int i = arr.size() - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    
    vector<int> randomVector = generateRandomVector(10000, 1, 10000);

    
    auto start = chrono::high_resolution_clock::now();
    shakerSort(randomVector);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken by Shaker sort: " << duration.count() << " seconds" << endl;

    
    start = chrono::high_resolution_clock::now();
    sort(randomVector.begin(), randomVector.end());
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken by std::sort: " << duration.count() << " seconds" << endl;

    return 0;
}
