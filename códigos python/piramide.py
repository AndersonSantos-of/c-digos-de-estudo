linha= 9

for i in range(1, linha+1):
    print(" " * (linha-i), end='')
    
    for j in range(1, i+1):
        print(j, end=' ')
    
    print()