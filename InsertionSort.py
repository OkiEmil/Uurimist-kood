import time
import random
n = 10000
k = 10
randomlist = []
for i in range(n):
    randomlist.append(random.randint(0, k))

#Defineerin funktsiooni
def insertionSort(arr):
    
    #Vaatan iga elementi massiivis, alustades teisest elemendist
    for i in range(len(arr)-1):
        
        #Seni kuni vaadeldav element i+1 on väiksem kui temast vasakul olev element i
        while arr[i+1] < arr[i] and i != -1:

            #Vaheta elemendid
            arr[i], arr[i+1] = arr[i+1], arr[i]

            #Liigu ühe elemendi võrra vasakule
            i -= 1

    return(arr)

start = time.time()
insertionSort(randomlist)
print(time.time()-start)