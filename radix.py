import time
#Loon suvalise listi, n on listi pikkus, k on suvaliste arvude vahemik
import random
randomList = []
n = 1000000
k = 1000000
for i in range(n):
    randomList.append(random.randint(0,k))

def countingSort(arr, kohaline):

    #Koostan loendusmassiivi ja väljundmassiivi
    output = [0] * len(arr)
    count = [0] * (10)

    #Loen kokku iga liikme esinemissageduse
    for i in arr:
        indeks = i//kohaline
        count[indeks % 10]+= 1

    #Töötlen jada akumulatiivsele kujule
    for i in range(1,10):
        count[i] += count[i-1]

    #Paigutan iga liikme väljundmassiivi
    for i in range(len(arr)-1, -1, -1):
        indeks = arr[i] // kohaline
        output[count[indeks % 10]-1] = arr[i]
        count[indeks % 10] -= 1

    for i in range(0, len(arr)):
        arr[i] = output[i]

def radixSort(arr):
    suurim = max(arr)

    kohaline = 1
    while suurim/kohaline >= 1:
        countingSort(arr, kohaline)
        kohaline *= 10
    

start = time.time()
radixSort(randomList)
print(time.time()-start)
#print(randomList)
