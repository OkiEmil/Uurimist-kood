#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void printArray(vector<int> arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void loendusSortimine(vector<int> &arr, int k) {
    
    int len = arr.size();

    vector<int> output(len, 0);
    vector<int> count(k+1, 0);

    for (auto i: arr){
        ++count[i];
    }
    
    for (int i = 1; i < k; ++i){
        count[i] += count[i-1];
    }
    count[k] = 0;
 
    for (auto i : arr) {
        auto j = i;
        if (i == 0){
            j = k+1;
        }
        output[count[j-1]] = i;
        ++count[j-1];
    }
    arr = output;
}


int main() {
    const int n = 1000000;
    const int k = 100000;
    vector<int> vect;

    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        
        vect.push_back(rand() %k) ;
    }
    //printArray(vect, n);

    auto start = high_resolution_clock::now();
    loendusSortimine(vect, k);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}