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

void gravitatsiooniSortimine(vector<int> &arr) {
    int len = arr.size();
    int suurim = *max_element(arr.begin(), arr.end());
    
    vector<vector<int>> nupud(len, vector<int>(suurim, 0));
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < arr[i] ; j++) {
            nupud[i][j] = 1;
        }
    }

    for (int i = 0; i <suurim ; i++) {
        int kogus =0;
        for (int j = 0; j < len; j++) {
            kogus += nupud[j][i];
            nupud[j][i] = 0;
        }
        for (int j = len-kogus; j < len; j++){
            nupud[j][i] = 1;
        }
    }
    vector<int> output(len, 0);
    for (int i = 0; i<len; i++){
        
        output[i] = count(nupud[i].begin(), nupud[i].end(), 1);
    }
    arr = output;
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
    gravitatsiooniSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}