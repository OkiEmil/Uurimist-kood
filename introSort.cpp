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
void introKuhjaSortimine(vector<int> &arr, int algus, int lopp) {

    vector<int> arr1 (arr.begin() + algus, arr.begin() +lopp);
    kuhjaSortimine(arr1);
    for (auto i = algus; i < arr1.size(); i++) {
        arr[i] = arr1[algus-i];
    }
}

int jaotus(vector<int> &arr, int algus, int lopp) {
    int tugi = arr[lopp];
    int x = algus - 1;
    for (int i = algus; i <lopp; i++) {
        if (arr[i] <= tugi) {
            x++;
            swap(arr[i], arr[x]);
        }
    }
    
    swap(arr[x+1], arr[lopp]);

    return x+1;
}
void vahelepanemisegaSortimine(vector<int> &arr, int algus, int lopp) {
    for (int j = algus; j < lopp; ++j) {
        //int arv = arr[i];
        //int j = i - 1;
        int i = j;
        while (arr[i+1] < arr[i] && i != algus-1){
            swap(arr[i], arr[i+1]);
            i--;
        }
        
    }
    

}

void introSortimine(vector<int> &arr, int algus, int lopp, int sugavuslimiit){
    int n = lopp - algus;

    if (n <= 1) {
        return;
    }
    if (n < 16 ) {

        vahelepanemisegaSortimine(arr, algus, lopp);
        return;
    }
    if (sugavuslimiit == 0) {
        introKuhjaSortimine(arr, algus, lopp);
        return;
    }
    int median = max(min(arr[algus], arr[algus +floor(n /2)]), min(max(arr[algus],arr[algus +floor(n /2)]), arr[lopp]));
    swap(arr[median], arr[lopp]);

 
    int jaotuskoht = jaotus(arr, algus, lopp);

    introSortimine(arr, algus, jaotuskoht-1, sugavuslimiit-1);
    introSortimine(arr, jaotuskoht+1, lopp, sugavuslimiit-1);

}

void introspektiivneSortimine (vector<int> &arr, int algus, int lopp) {
  int sugavus = 2 * floor(log2(lopp-algus)) ;

  introSortimine(arr, algus, lopp, sugavus) ;
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
    introspektiivneSortimine(vect, 0, n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, n);
    return 0;
}