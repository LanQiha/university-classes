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

print("Exercice 6 : ")
b = np.cos(1); print("b = %s" % b)
bb = np.sin(4); print("bb = %s" % bb)

print("Exercice 7 : ")
u = [1,9,-4,0.5]
print(2*u)

v = np.array([1,9,-4,0.5])
print(2*v)
print(v[2])
print(v[0])
print(v.size)
print(np.size(v))
print(v.shape)
w = np.array([[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12]])

print(w.shape)  # Output: (3, 4)

print("Exercice 8 : ")
print(np.linspace(0,2*np.pi,10))
print(np.linspace(20,1,10))
x,dx = np.linspace(0,6.3,10,retstep=True)
print("x = %s" % x)
print("dx = %s (step size)" % dx)

x = np.arange(0,10,0.5)
print(x)

dx = 0.5
x = np.arange(0, 10+dx/2, dx)
print(x)

y=np.arange(10, -dx/2, -dx)
print(y)

print(np.repeat(3.2,4))
x = np.array([[1,2],[3,4]])
result = np.repeat(x, 2)
print(result)
print(np.repeat(x,3,axis=1))
print(np.repeat(x,3,axis=0))

# Opérations sur les vecteurs