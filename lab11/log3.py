import math 


N = int(input())
if N==1:
    print(0)
    exit(0)
found = True
powers_of_three = [3]
while powers_of_three[-1] < N:
    powers_of_three.append(powers_of_three[-1]*3)
    
# this is a python comment

if powers_of_three[-1] == N: 
    print(round(math.log(N, 3)))
    exit(0)
else: 
    print(-1)
    exit(0)
