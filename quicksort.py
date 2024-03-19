import time
import statistics
#Loon suvalise listi, n on listi pikkus, k on suvaliste arvude vahemik
import random
randomList = []
n = 1000000
k = 100000
for i in range(n):
    randomList.append(random.randint(0,k))

def kiirsortimine(arr):
    #valin median of 3 strateegiaga tugielemendi
    if len(arr) >= 3:
        pivot = statistics.median([arr[0], arr[(len(arr)-1)//2], arr[len(arr)-1]]) 
        arr.remove(pivot)
        arr1 = []
        arr2 = []
        for i in arr:
            
            if i < pivot:
                arr1.append(i)
                 
            else:
                arr2.append(i)
        

        arr = kiirsortimine(arr1) + [pivot] + kiirsortimine(arr2) 
    elif len(arr) == 2:
        if arr[0] > arr[1]:
            arr[0], arr[1] = arr[1], arr[0]
    return(arr)
    
#print(randomList)
start = time.time()
kiirsortimine(randomList)
print(time.time()-start)
