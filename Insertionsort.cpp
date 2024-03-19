#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void vahelepanemisegaSortimine(vector<int> &arr, int &size) {
  
    for (int i = 1; i < size; ++i) {
        int arv = arr[i];
        int j = i - 1;
        while (arr[j] > arv && j != -1){
            arr[j+1] = arr[j];
            --j;  
        }
        arr[j+1] = arv;
    }
    

}

void printArray(vector<int> arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    
    const int n = 10000;
    const int k = 1000;
    vector<int> vect;
    srand(time(NULL));
    for (int i = 0; i < n; ++i){
        
        vect.push_back(rand() %k) ;
    }

    int size = vect.size();
    //printArray(arr, size);

    
    
    

    //printArray(vect, size);
    auto start = high_resolution_clock::now();
    vahelepanemisegaSortimine(vect, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " microseconds" << endl;
    //printArray(vect, size);
    return 0;
}