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
void binInsertionSortimine(vector<int> &arr, int left, int right){
    vector<int> arr1 (arr.begin()+ left, arr.begin() + right+1);
    int len2 = arr1.size();

    for (int i = 0; i < len2; i++) {
        int x = arr1[i];
        
        int pos = kahendOtsing(arr1, i+1, x);

        int temp = i;
        while (temp > pos) {
            arr1[temp] = arr1[temp-1];
            --temp;
        }
        arr1[pos] = x;
    }
    for (int i = 0; i < len2; i++) {
        arr[left+i] = arr1[i];
    }

}

void mesti(vector<int> &arr, int vasak, int kesk, int parem) {
    int pikkus1 = kesk -vasak+1;
    int pikkus2 = parem - kesk;
    vector<int> Vasak;
    vector<int> Parem;

    for (int i = 0; i < pikkus1; i++) {
        Vasak.push_back(arr[vasak+i]);
    }
    for (int i = 0; i < pikkus2; i++) {
        Parem.push_back(arr[kesk+i+1]);
    }
    int v = 0;
    int p = 0;
    int k = vasak;

    while (v < pikkus1 && p < pikkus2) {
        if (Vasak[v] <= Parem[p]) {
            arr[k] = Vasak[v];
            v++;
        }
        else {
            arr[k] = Parem[p];
            p ++;
            
        }
        k++;
    }

    for (int i = p; i < Parem.size(); i++) {
        arr[k] = Parem[i];
        k++;
    }
    for (int i = v; i < Vasak.size(); i++) {
        arr[k] = Vasak[i];
        k++;
    }

    
    }

void timSortimine(vector<int> &arr) {
    int len = arr.size();
    int runsize = 32;

    for (int i = 0; i < len; i += runsize) {
        binInsertionSortimine(arr, i, min((i + runsize - 1), (len - 1))); 
    } 


    for (int size = runsize; size < len; size = 2 * size) { 

        for (int vasak = 0; vasak < len; vasak += 2 * size) { 

            int mid = min(vasak + size - 1, len-1);
            int right = min((vasak + 2 * size - 1), (len - 1)); 

        
            if (mid < right) {
                mesti(arr, vasak, mid, right); 
        } 
    
        } 
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
    timSortimine(vect);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}