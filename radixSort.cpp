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

void loendusSortimine(vector<int> &arr, int kohaline) {
    
    int len = arr.size();

    vector<int> output(len, 0);
    vector<int> count(10, 0);

    for (auto i: arr){
        int indeks = floor(i/kohaline);
        ++count[indeks % 10];
    }
    
    for (int i = 1; i < 10; ++i){
        count[i] += count[i-1];
    }
    //count[k] = 0;
 
    for (int i = len-1; i > -1; --i) {
        int indeks = floor(arr[i]/kohaline);
        output[count[indeks % 10]-1] = arr[i];
        count[indeks % 10] -= 1;
    }
    for (int i = 0; i < len; i++) {
        arr[i] = output[i];
    }
}

void radixSortimine(vector<int> &arr) {
    int suurim = *max_element(arr.begin(), arr.end());

    int kohaline = 1;
    while (suurim/kohaline >= 1) {
        loendusSortimine(arr, kohaline);
        kohaline *= 10;
    }
}


int main() {
    
    const int n = 1000000;
    const int k = 100;
    vector<int> vect;

    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        
        vect.push_back(rand() %k) ;
    }
    //printArray(vect, n);

    auto start = high_resolution_clock::now();
    radixSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}