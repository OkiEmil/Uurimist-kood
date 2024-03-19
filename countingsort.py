import random
import time
randomlist = []

#Koostan suvalise massiivi, milles on 100 numbrit, millest igaüks on vahemikus 0 kuni 9
k = 100
for i in range(0,1000000):
    n = random.randint(0,k)
    randomlist.append(n)

#Defineerin sortimisfunktsiooni
def countingSort(arr, k):

    #Koostan loendusmassiivi ja väljundmassiivi
    output = [0] * len(arr)
    count = [0] * (k+1)

    #Loen kokku iga liikme esinemissageduse
    for i in arr:
        count[i] += 1

    #Töötlen jada akumulatiivsele kujule
    for i in range(1,k):
        count[i] += count[i-1]

    count[k] = 0

    #Paigutan iga liikme väljundmassiivi
    for i in arr:
        
        output[count[i-1]] = i
        count[i-1] += 1
    
    return(output)

#Jooksutan funktsiooni ja jälgin, kaua see võtab
start = time.time()

countingSort(randomlist, k)
print(time.time()-start)

