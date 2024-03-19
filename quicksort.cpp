#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;
using namespace std::chrono;

void printArray(vector<int> arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

vector<int> joinArrays(vector<int> arr1, vector<int> arr2, int pivot) {
    vector<int> arr;
    arr.insert(arr.end(), arr1.begin(), arr1.end());
    arr.push_back(pivot);
    arr.insert(arr.end(), arr2.begin(), arr2.end());
    return arr;
}

vector<int> kiirSortimine(vector<int> &arr) {
int len = arr.size();
if (len >= 3) {
    int median = max(min(arr[0], arr[floor((len-1) /2)]), min(max(arr[0],arr[floor((len-1) /2)]), arr[len-1]));
    //cout<<"median: " << median << endl;
    auto it = find(arr.begin(), arr.end(), median);
    arr.erase(it);
    vector<int> arr1;
    vector<int> arr2;
    //cout << "arr: ";
    //printArray(arr, arr.size());
    for (auto &i : arr) {
        if (i<median) {
            arr1.push_back(i);
        }
        else {
            arr2.push_back(i);
        }
    }
        
        arr.clear();
        //cout<< "arr1: ";
        //printArray(arr1, arr1.size());
        //cout<< "arr2: ";
        //printArray(arr2, arr2.size());
        arr1 = kiirSortimine(arr1);
        arr2 = kiirSortimine(arr2);
        

        arr = joinArrays(arr1, arr2, median);

        //printArray(arr, arr.size());
       // this_thread::sleep_for(chrono::milliseconds(500));
        }
else if (len == 2) {
    if (arr[0] > arr[1]) {
        swap(arr[0], arr[1]);
    }
    }  
    return arr;
}

int main() {
    
    const int n = 1000000;
    const int k = 1000000;
    vector<int> vect;

    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        
        vect.push_back(rand() %k) ;
    }
    //printArray(vect, n);

    auto start = high_resolution_clock::now();
    kiirSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    
    cout << duration.count() << " microseconds";
    //printArray(vect, n);
    return 0;
}