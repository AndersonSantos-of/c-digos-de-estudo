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
    return re.sub(r'[^A-Z]', '', texto)#tudo que não for vogal é trocado por nulo

contagem={}
maximo=0
porcentagem=[]
referencia=0
alfabeto=[]
valores=[]

texto=leitor("/home/asc/Downloads/internet/" \
"A-ARTE-DA-GUERRA.pdf")

#coloquei em letras maiúscula para simplificar
PalavraNormalizada=texto.upper()
#chamando a função para limpar o pdf
PalavraNormalizada=limpar_Vogais(PalavraNormalizada)

#conta quantos caracteres totais foam separados
quantidade=int(len(PalavraNormalizada))

if quantidade>10000:
    referencia=round(quantidade,-3)
elif quantidade>100:
    referencia=round(quantidade,-2)
else:
    referencia=round(quantidade)

#for para contar as vogais
for letra in PalavraNormalizada:
    if letra in contagem:
        contagem[letra]+=1
    else:
        contagem[letra]=1

# ordena o dicionário em ordem alfabética (A–Z)
contagem_ordenada = dict(sorted(contagem.items()))

#for para saber a porcentagem de cade vogal
#também cria as classes das vogais
for letra, qtd in contagem_ordenada.items():
    alfabeto.append(letra)
    valores.append(qtd)
    porcentagem.append((qtd / quantidade) * 100)  

#for para pegar os valores do dic e usar no gráfico de valores absolutos

pp=max(porcentagem)/2
pp=int(round(pp))
lsp=pp*4

maximo=max(valores)

if maximo>10000:
    passo=int(round(maximo/2,-3))
elif maximo>100:
    passo=int(round(maximo/2,-2))
else:
    passo=int(round(maximo/2))

ls=passo*4
#-----------------------------

#cria uma figura com dois eixos para dois gráficos
fig, axs = plt.subplots(2, 1, figsize=(8, 8))

# -------- PORCENTAGEM --------
axs[0].set_ylim(0, lsp+1) #define os limitos do gráfico
axs[0].set_yticks(range(0, lsp+1, pp),[f'{i}%' for i in range(0, lsp+1, pp)]) #define as marcações

axs[0].set_title('PORCENTAGEM RELAVITA')
axs[0].set_xlabel('LETRAS', loc='right') #loc define o alinhamento do texto
axs[0].set_ylabel('PORCENTAGEM (%)')

barras = axs[0].bar(alfabeto, porcentagem)
for barra, valor in zip(barras, porcentagem):
    altura = barra.get_height()
    axs[0].text(
        barra.get_x() + barra.get_width() / 2,
        altura,
        f'{valor:.2f}%',
        ha='center',
        va='bottom'
    )

# -------- VALOR ABSOLUTO --------
axs[1].set_ylim(0,ls+1)
axs[1].set_yticks(range(0, ls+1, passo))

axs[1].set_title('NÚMEROS ABSOLUTOS')
axs[1].set_xlabel('LETRAS', loc='right')
axs[1].set_ylabel('QUANTIDADE')

barras = axs[1].bar(alfabeto, valores)
axs[1].text(
    0.97, 0.96,
    f'TOTAL DE LETRAS: {quantidade}',
    transform=axs[1].transAxes,
    ha='right',
    va='top',
)

for barra, valor in zip(barras, valores):
    altura = barra.get_height()
    axs[1].text(
        barra.get_x() + barra.get_width() / 2,
        altura,
        f'{valor}',
        ha='center',
        va='bottom'
    )

# Ajusta o layout dos gráficos na figura
plt.tight_layout()
#definindo as cores das barras
axs[0].bar(alfabeto, porcentagem, color="#e1730c")
axs[1].bar(alfabeto, valores, color="#dbdb07")

#mostra os gráficos
plt.show()