import time
import random
n = 10000
k = 10

randomlist = []
for i in range(n):
    randomlist.append(random.randint(0, k))

#Defineerin kahendotsingu.
#arr on vahemik, millest otsin, N on vahemiku pikkus ja x on koht, mida otsin
def binarySearch(arr, N, x):
    l = 0
    r = N-1
    
    while l < r:
        mid = int((l+r)/2)
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid

    #Lõpuks on vasak puhver positsioonil, millele peaks otsitud elemendi paigutama
    return(l)
    
def insertionSort(arr):
     
    for i in range(len(arr)):
        x = arr[i]

        #Leian for-loopi sees positsiooni
        pos = binarySearch(arr[0:i], i+1, x)
        
        #Nihutan iga elementi, mis on positsioonist paremal ühe võrra edasi
        temp = i
        while temp > pos:
            arr[temp] = arr[temp-1]
            temp -= 1
        
        #Asetan elemendi õigele positsioonile sorteeritud jadas
        arr[pos] = x
            
    return(arr)

#Jooksutan algoritmi ja mõõdan ajakulu
start = time.time()
insertionSort(randomlist)
print(time.time()-start)