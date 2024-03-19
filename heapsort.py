import time
#Loon suvalise listi, n on listi pikkus, k on suvaliste arvude vahemik
import random
randomList = []
n = 1000000
k = 100
for i in range(n):
    randomList.append(random.randint(0,k))

def kuhjasta(arr, pikkus, juur):
    suurim = juur

    left = 2*juur + 1
    right = 2*juur +2

    if left < pikkus and arr[suurim] < arr[left]:
        suurim = left
    if right < pikkus and arr[suurim] < arr[right]:
        suurim = right

    if suurim != juur:
        arr[juur], arr[suurim] = arr[suurim], arr[juur]

        kuhjasta(arr, pikkus, suurim)
    
    return(arr)

#print(randomList)

def maxKuhjasta(arr):
    pikkus = len(arr)
    for i in range(pikkus//2-1, -1, -1):
        kuhjasta(arr, pikkus, i)

def kuhjaSortimine(arr):
    maxKuhjasta(arr)
    pikkus = len(arr)
    for j in range(pikkus-1, 0, -1):
        arr[j], arr[0] = arr[0], arr[j]
        kuhjasta(arr, j, 0)


start = time.time()
kuhjaSortimine(randomList)
print(time.time()-start)


#print(randomList)