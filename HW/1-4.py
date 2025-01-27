# By Mohamad French for CS 673 Software Engineering at BU MET
nPrev = 0
n = 1
nNext = 0 # "Temp" variable to manage the handover of values to the "previous n" or nPrev
print(f"Fibonacci number 1: {n}")
for i in range (2,101):
    nNext = n + nPrev
    nPrev = n
    n = nNext
    print(f"Fibonacci number {i}: {n}")