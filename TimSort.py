import time
#Loon suvalise listi, n on listi pikkus, k on suvaliste arvude vahemik
import random
randomList = []
n = 1000000
k = 100
for i in range(n):
    randomList.append(random.randint(0,k))

def leiaRunSize(pikkus, minimum):
    a = 0
    while pikkus >= minimum: 
        a |= pikkus & 1
        pikkus >>= 1
    return pikkus + a

def mesti(arr, vasak, keskmine, parem):

    pikkus1 = keskmine-vasak +1
    pikkus2 = parem - keskmine
    Vasak, Parem = [], []
    for i in range(pikkus1):
        Vasak.append(arr[vasak+i])
    for i in range(pikkus2):
        Parem.append(arr[keskmine+1+i])
    
    v = p = 0
    k = vasak

    while v < pikkus1 and p < pikkus2:
        if Vasak[v] <= Parem[p]:
            arr[k] = Vasak[v]
            v = v + 1
        else:
            arr[k] = Parem[p]
            p = p + 1
        k = k + 1

    for i in range(len(Parem)-p):
        arr[k] = Parem[p+i]
        k += 1
    for i in range(len(Vasak)-v):
        arr[k] = Vasak[v+i]
        k += 1

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
    
def insertionSort(arr, vasak, parem):
    b = arr[vasak:parem] 
    for i in range(len(b)):
        x = b[i]

        #Leian for-loopi sees positsiooni
        pos = binarySearch(b[0:i], i+1, x)
        
        #Nihutan iga elementi, mis on positsioonist paremal ühe võrra edasi
        temp = i
        while temp > pos:
            b[temp] = b[temp-1]
            temp -= 1
        
        #Asetan elemendi õigele positsioonile sorteeritud jadas
        b[pos] = x

    for i in range(0, len(b)):
        arr[vasak+i] = b[i]       
    return(arr)

def timSortimine(arr):
    pikkus = len(arr)
    minimum = 32
    run = leiaRunSize(pikkus, minimum)
    
    runcount = pikkus//run + 1
    k = 0
    l = run
    while k < pikkus:
        if l > pikkus:
            l = pikkus
        insertionSort(arr, k, l)
        k += run
        l += run

    suurus = run
    while suurus < pikkus:
        
        for vasak in range(0, pikkus, suurus *2):
            kesk = min(vasak+suurus-1, pikkus-1)
            parem = min(vasak+ suurus*2 -1, pikkus-1)

            if kesk != parem:
                mesti(arr,vasak,kesk,parem)
        
        suurus *= 2



start = time.time()
timSortimine(randomList)
print(time.time()-start)