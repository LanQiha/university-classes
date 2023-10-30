print("Exercice 1 : ")
for i in range(4):
    print(i)

print("Exercice 2 : ")
a = 8
if a > 4:
    print("a plus grand que 4")
else:
    print("a plus petit ou égal à 4")

print("Exercice 3 : ")
for i in range(10):
    if not (i==4):
        print(i)

print("Exercice 4 : ")
s = sum([1,2,3,4])
print(s)

print("Exercice 5 : ")
import numpy as np

b = np.random.binomial(1,1/2,30)
print(b)

b = np.random.binomial(1,1/2,30)
print(b)

m = np.random.binomial(1,1/2,(4,3))
print(m)