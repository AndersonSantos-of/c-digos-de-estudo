for i in range (0, 60, 5):
    if i==30: # vai parar no 25
        break
    print(i)

print('\n1 ----------\n')
for i in range (0, 60, 5):
    if i==15: # vai pular o 15
        continue # usado para pular determinada coisa
    print(i)

print('\n2 ----------\n')
for letra in 'Anderson':
    print(letra)

print('\n3 ----------\n')
x=['Anderson', 5, 3.14]
for y in x:
    print(y)

dicionario= {
    'E':5,
    'A':1,
    'I':9
}

print('\n4 ----------\n')
for letra, posição in dicionario.items(): # tô pegando o conjunto chave e valor do dic
    print(f'A letra {letra} está na posição {posição}')

print('\n5 ----------\n')
for chave in dicionario: # tô pegando só as chaves
    print(chave)

print('\n6 ----------\n')
for chave in dicionario.keys(): # aqui também tô pegando só as chaves
    print(chave)

print('\n7 ----------\n')
for valor in dicionario.values(): # aqui eu tô pegando o valor das chaves
    print(valor)

print('\n8 ----------\n')
for chave in dicionario: # usando as chaves percorridas pelo for
    print(dicionario[chave]) # para acessar os valors em dicionario

print("\nfinalizado")