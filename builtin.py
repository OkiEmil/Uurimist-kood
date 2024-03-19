import time
import random
randomlist = []
for i in range(0,1000000):
    n = random.randint(0,100)
    randomlist.append(n)

start = time.time()
randomlist.sort()
print("--", time.time()-start, "--")