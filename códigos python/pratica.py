for i in range (0, 60, 5):
    if i==30: # vai parar no 25
        break
    print(i)

print('----------')
for i in range (0, 60, 5):
    if i==15: # vai pular o 15
        continue # usado para pular determinada coisa
    print(i)

print('----------')
for letra in 'Anderson':
    print(letra)

print('----------')
x=['Anderson', 5, 3.14]
for y in x:
    print(y)

dicionario= {
    'E':5,
    'A':1,
    'I':9
}

print('----------')
for letra, posição in dicionario.items(): # tô pegando o conjunto chave e valor do dic
    print(f'A letra {letra} está na posição {posição}')

print('----------')
for chave in dicionario: # tô pegando só as chaves
    print(chave)

print('----------')
for chave in dicionario.keys(): # aqui também tô pegando só as chaves
    print(chave)

print('----------')
for valor in dicionario.values(): # aqui eu tô pegando o valor das chaves
    print(valor)

print("\nfinalizado")