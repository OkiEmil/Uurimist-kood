#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <chrono>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void printArray(vector<int> arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void kuhjasta(vector<int> &arr, int pikkus, int juur) {
    int suurim = juur;

    int left = 2*juur +1;
    int right = 2*juur +2;

    if (left < pikkus && arr[suurim] < arr[left]){
        suurim = left;
    }
    if (right < pikkus && arr[suurim] < arr[right]){
        suurim = right;
    }
    if (suurim != juur) {
        swap(arr[juur], arr[suurim]);
        kuhjasta(arr, pikkus, suurim);
    }
}

void maxKuhjasta(vector<int> &vect) {
    int len = vect.size();
    for ( int i = floor(len/2)-1; i > -1; --i) {
        kuhjasta(vect, len, i);
    }
}
void kuhjaSortimine(vector<int> &arr) {
    maxKuhjasta(arr);
    int len = arr.size();
    for (int j = len-1; j > 0; j--) {
        swap(arr[j], arr[0]);
        kuhjasta(arr, j, 0);


    }
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
    kuhjaSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}