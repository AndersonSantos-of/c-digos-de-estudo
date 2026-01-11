print('\t\t   Feliz Natal!\n')

linha=25
for i in range(linha):
    for j in range(linha-i-1):
        print(' ', end='')
    for j in range(2*i+1):
        print('*', end='')
    print()