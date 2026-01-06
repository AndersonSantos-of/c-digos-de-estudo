import random as rd

x=1

while x!=0:
    print('\nEscolha uma opção: \n1. Pedra' \
    '\n2. Papel \n3. Tesoura \n0. Sair')
    
    x=int(input('Digite um número: '))
    bot=rd.randint(1,3)
#-----------------------------------------
    print()

    if x==1:
        print('Você escolheu Pedra')
    elif x==2:
        print('Você escolheu Papel')
    elif x==3:
        print('Você escolheu Tesoura')
    elif x==0:
        print('Saindo...')
    else:
        print('Escolha inválida')
        continue
    
    print('------------------')

    if bot==1:
        print('O bot escolheu Pedra')
    elif bot==2:
        print('O bot escolheu Papel')
    else:
        print('O bot escolheu Tesoura')
#----------------------------------------
    print()
    
    if x==1:
        if bot==1:
            print('Empatou')
        elif bot==2:
            print('O bot ganhou')
        else:
            print('Você ganhou')
    elif x==2:
        if bot==1:
            print('Você ganhou')
        elif bot==2:
            print('Empatou')
        else:
            print('O bot ganhou')
    else:
        if bot==1:
            print('O bot ganhou')
        elif bot==2:
            print('Você ganhou')
        else:
            print('Empatou')

print('Obrigado por jogar!')