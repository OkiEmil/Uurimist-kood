#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int kahendOtsing(vector<int> arr, int N, int x){
    int l = 0;
    int r = N-1;

    while (l < r) {
        int mid = int((l+r)/2);
        if (arr[mid] <= x) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    return l;
}

void printArray(vector<int> arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void binInsertionSortimine(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        vector<int> arr1 (arr.begin(), arr.begin() + i);
        int pos = kahendOtsing(arr1, i+1, x);

        int temp = i;
        while (temp > pos) {
            arr[temp] = arr[temp-1];
            --temp;
        }
        arr[pos] = x;
    }
}

int main() {
    
    const int n = 10000;
    const int k = 10;
    vector<int> vect;

    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        
        vect.push_back(rand() %k) ;
    }
    //printArray(vect, n);

    auto start = high_resolution_clock::now();
    binInsertionSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}