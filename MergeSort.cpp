#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;
using namespace std::chrono;

//template <class InputIterator> vector ( InputIterator first, InputIterator last, const Allocator& = Allocator() );

void printArray(vector<int> arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mestimisSortimine(vector<int> &arr) {
    int len = arr.size();
    if (len != 1) {
        int mid = floor(len/2);
        vector<int> Left(arr.begin(), arr.begin()+mid);
        vector<int> Right(arr.begin()+mid, arr.end());
        mestimisSortimine(Left);
        mestimisSortimine(Right);

        int i =0, r =0, l=0;
        while (l < Left.size() && r < Right.size()) {
            if(Left[l] <Right[r]) {
                arr[i] = Left[l];
                ++l;
            }
            else {
                arr[i] = Right[r];
                ++r;
            }
            ++i;
        }
        for (int m = 0; m < Right.size()-r; m++) {
            arr[i] = Right[r+m];
            ++i;
        }
        for (int k = 0; k < Left.size()-l; k++) {
            arr[i] = Left[l+k];
            ++i;
        }
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
    mestimisSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}