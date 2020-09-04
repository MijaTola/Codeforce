import math as mp

key = raw_input()

a,b = raw_input().split()

a = int(a)
b = int(b)
sz = len(key)
i = 1

while i <= sz:
    m = int(key[0:i+1])
    n = int(key[i:sz])
    if m%a==0 and n%b==0:
        print("YES\n"+ str(m) + " " + str(n))
        exit()
    i+= 1
print("NO\n")
    
    
