import time
#Loon suvalise listi, n on listi pikkus, k on suvaliste arvude vahemik
import random
randomList = []
n = 1000000
k = 100
for i in range(n):
    randomList.append(random.randint(0,k))

def mestimisSortimine(arr):
    #Rekursiivselt jagan listi väiksemaks, kuni on 2 elemendi pikkune list
    
    if len(arr) != 1:
        mid = len(arr)//2
        Left = arr[:mid]
        Right = arr[mid:]
        mestimisSortimine(Left)
        mestimisSortimine(Right)
        #Siin hakkab mestimisprotsess, algselt võrdlen elemente kuni kas vasak või parem pool saab otsa
        i = r = l = 0
        while l < len(Left) and r < len(Right):
            #Kui vasakul poolel vaadeldav element on paremal poolel vaadeldavast elemendist väiksem
            #Järgmise rekursioonikorduse jaoks pannakse vasakult element massiivi sisse, puhvrit l suurendatakse ühe võrra
            if Left[l] < Right[r]:
                arr[i] = Left[l]
                l += 1
            #Kui vasakul poolel vaadeldav element on paremal poolel vaadeldavast elemendist suurem
            #Järgmise rekursioonikorduse jaoks pannakse paremalt element massiivi sisse, puhvrit r suurendatakse ühe võrra    
            else:
                arr[i] = Right[r]
                r += 1
            i += 1

        #Kõik elemendid, mida ei jõutud lisada kas vasakult poolt või paremalt poolt kuuluvad massiivi lõppu.
        #Sest näiteks kui viimane element vasakul on väiksem kui esimene element paremal, siis kõik elemendid, mis on paremal
        #käivad massiivi lõppu, sest nad on suuremad kui kõik vasakul olevad elemendid
        for m in range(len(Right)-r):
            arr[i] = Right[r+m]
            i += 1
        for k in range(len(Left)-l):
            arr[i] = Left[l+k]
            i += 1
   
start = time.time()
mestimisSortimine(randomList)
print(time.time()-start)


