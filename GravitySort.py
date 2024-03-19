import time
#Loon suvalise listi, n on listi pikkus, k on suvaliste arvude vahemik
import random
randomList = []
n = 10000
k = 10
for i in range(n):
    randomList.append(random.randint(0,k))

def gravitatsiooniSortimine(arr):
    pikkus = len(arr)
    suurim = max(arr)
    
    nupud = [[0]*suurim for j in range(pikkus)]
    
    for i in range(pikkus):
        for j in range(arr[i]):
            nupud[i][j] = 1
    
    for n in range(suurim):
        kogus = 0
        for i in range(pikkus):
            kogus += nupud[i][n]
            nupud[i][n] = 0
        for i in range(pikkus-1, pikkus-kogus-1, -1):
            nupud[i][n] = 1


    output = [0]*pikkus
    for i in range(pikkus):
        output[i] = nupud[i].count(1)
    return(output)
        
    

start = time.time()
gravitatsiooniSortimine(randomList)
print(time.time()-start)