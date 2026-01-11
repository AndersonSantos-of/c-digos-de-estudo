import random

fichas=int(input('Quantas fichas você quer? '))

while fichas > 0:
    
    nm1=random.randint(1,99)
    nm2=random.randint(1,99)
    nm3=nm1+nm2
    nm4=nm1-nm2
    
    escolhas=[nm1, nm3, nm4]
    bot=random.choice(escolhas) # seleciona um item aleatorio da lista

    print(f'\nQual número o bot escolheu? \nA. {nm1} \nB. {nm3} \nC. {nm4}')

    jogador=int(input('Digite o número: '))

    if jogador not in escolhas:
        print('\nEscolha inválida.\nNenhuma ficha foi consumida.')
        print(f'Fichas restantes: {fichas}')
        continue

    if jogador==bot:
        print(f'Você venceu! O número escolhido foi {bot}')
    else:
        print(f'Você perdeu, o número escolhido foi {bot}')
    
    fichas-=1
    print(f'Fichas restantes: {fichas}')

print('\nAs fichas acabaram...\nObrigado por jogar')