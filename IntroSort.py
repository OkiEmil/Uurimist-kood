import random
import time
import statistics
import math
randomlist = []

#Koostan suvalise massiivi, milles on 100 numbrit, millest igaüks on vahemikus 0 kuni 9
k = 100
l = 1000000
for i in range(0,l):
    n = random.randint(0,k)
    randomlist.append(n)



#Vahelepanemisega sortimine
def insertionSort(arr, algus, lopp):
    
    #Vaatan iga elementi massiivis, alustades teisest elemendist
    for i in range(algus, lopp):
        
        #Seni kuni vaadeldav element i+1 on väiksem kui temast vasakul olev element i
        while arr[i+1] < arr[i] and i != algus-1:

            #Vaheta elemendid
            arr[i], arr[i+1] = arr[i+1], arr[i]

            #Liigu ühe elemendi võrra vasakule
            i -= 1

    return(arr)


#Kuhjasortimiseks vajalikud funktsioonid
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

def introKuhjaSortimine(arr, algus, lopp):
    b = arr[algus:lopp]
    kuhjaSortimine(b)
    for i in range(0,len(b)):
        arr[algus+i] = b[i]
#Kiirsortimine partition funktsioon

def jaotus(arr, algus, lopp):

    tugielement = arr[lopp]

    i = algus -1

    for j in range(algus, lopp):

        if arr[j] <= tugielement:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[lopp] = arr[lopp], arr[i+1]
    return(i+1)

#Siin jooksutan peamist koodi
def introspektiivneSortimine(arr, algus, lopp, sügavuslimiit):
    
    n = lopp - algus
    if n <= 1:
        return
    if n < 16:
        
        return(insertionSort(arr, algus, lopp))

    if sügavuslimiit == 0:
        
        return(introKuhjaSortimine(arr, algus, lopp))
    
    #Leian tugielemendi positsiooni median of 3 taktikaga
    tugielement = statistics.median([arr[algus], arr[algus + n//2], arr[lopp]])
    arr[tugielement], arr[lopp] = arr[lopp], arr[tugielement]
    
    jaotuskoht = (jaotus( arr, algus, lopp))
    
    introspektiivneSortimine(arr, algus, jaotuskoht-1, sügavuslimiit-1 )
    introspektiivneSortimine(arr, jaotuskoht+1, lopp, sügavuslimiit-1)


def jooksutamine(arr, algus, lopp):
    sügavuslimiit = 2 * math.floor(math.log2(lopp-algus))
   
    introspektiivneSortimine(arr, algus, lopp, sügavuslimiit)

#print(randomlist)
start = time.time()
jooksutamine(randomlist, 0, len(randomlist) -1)
print(time.time()- start)
#print(randomlist)
