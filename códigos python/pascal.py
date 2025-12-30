def pascal(n, k):
    if k==0 or k==n:
        return 1
    return pascal(n-1, k-1)+pascal(n-1,k)

def pascal_piramide(linha):
    for n in range(linha):
        print(' ' * (linha-n), end="")

        for k in range(n+1):
            print(pascal(n,k), end=' ')
        print()

pascal_piramide(5)