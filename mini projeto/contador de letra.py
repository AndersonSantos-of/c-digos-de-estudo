#importando as bibliotecas
import unicodedata
import re
import PyPDF2
import matplotlib.pyplot as plt

#função para ler o pdf
def leitor(pdf):
    texto = "" #cria a variavel que vai receber a string
    with open(pdf, "rb") as arquivo: #abre o pdf como um binario
        leitor = PyPDF2.PdfReader(arquivo) #o leitor vai ganhar a forma do pdf, porem em formato binario
        for pagina in leitor.pages: #percorre as paginas do leitor
            texto += pagina.extract_text() #extrai essas paginas e concatena no texto como string
    return texto #retorna a string

#função para limpar o texto
#tira tudo deixa só as vogais
def limpar_Vogais(texto):
    texto = ''.join(#junta todos os caracteres em uma string só
        c for c in unicodedata.normalize('NFD', texto) #separa os caracteres especiais, se for á vira a+´
        if unicodedata.category(c) != 'Mn'#tudo q não for acento vai parar dentro do c
    )
    return re.sub(r'[^AEIOUaeiou]', '', texto)#tudo que não for vogal é trocado por nulo

contagem={}
porcentagem=[]
vogais=[]

texto=leitor("/home/asc/Downloads/internet/A-ARTE-DA-GUERRA.pdf")

#coloquei tudo em maiúscula para ficar melhor
PalavraNormalizada=texto.upper()
#agora chamei a função para limpar
PalavraNormalizada=limpar_Vogais(PalavraNormalizada)

#conta quantos caracteres totais foam separados
quantidade=int(len(PalavraNormalizada))
print(quantidade)

#for para contar as vogais
for letra in PalavraNormalizada:
    if letra in contagem:
        contagem[letra]+=1
    else:
        contagem[letra]=1

#for para saber a porcentagem de cade vogal
#também cria as classes das vogais
for y,x in contagem.items():
    x=(x/quantidade)*100
    porcentagem.append(x)
    vogais.append(y)    

print(porcentagem)
print(vogais)

#cria o gráfico
plt.ylim(0, 35)
plt.yticks(range(0, 36, 5), [f'{i}%' for i in range(0, 36, 5)])

plt.bar(vogais,porcentagem)

plt.title('Porcentagem relativa das vogais')
plt.xlabel('Vogais')
plt.ylabel('Porcentagem(%)')

plt.show()

