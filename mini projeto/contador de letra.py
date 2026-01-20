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
valores=[]

texto=leitor("/home/asc/Downloads/internet/A-ARTE-DA-GUERRA.pdf")

#coloquei em letras maiúscula para simplificar
PalavraNormalizada=texto.upper()
#chamando a função para limpar o pdf
PalavraNormalizada=limpar_Vogais(PalavraNormalizada)

#conta quantos caracteres totais foam separados
quantidade=int(len(PalavraNormalizada))

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

#for para pegar os valores do dic e usar no gráfico de valores absolutos
for z in contagem.values():
    valores.append(z)

#cria uma figura com dois eixos para dois gráficos
fig, axs = plt.subplots(2, 1, figsize=(8, 8))

# -------- PORCENTAGEM --------
axs[0].set_ylim(0, 35) #define os limitos do gráfico
axs[0].set_yticks(range(0, 36, 5),[f'{i}%' for i in range(0, 36, 5)]) #define as marcações

axs[0].set_title('Porcentagem relativa das vogais')
axs[0].set_xlabel('Vogais', loc='right') #loc define o alinhamento do texto
axs[0].set_ylabel('Porcentagem (%)')
barras = axs[0].bar(vogais, porcentagem)

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
axs[1].set_ylim(0, 12000)
axs[1].set_yticks(range(0, 12001, 2000),range(0, 12001, 2000))

axs[1].set_title('Número absoluto das vogais')
axs[1].set_xlabel('Vogais', loc='right')
axs[1].set_ylabel('Quantidade')

barras = axs[1].bar(vogais, valores)
axs[1].text(
    0.95, 0.95,
    f'Total de vogais: {quantidade}',
    transform=axs[1].transAxes,
    ha='right',
    va='top',
    bbox=dict(boxstyle='round', alpha=0.1)
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
axs[0].bar(vogais, porcentagem, color="#e1730c")
axs[1].bar(vogais, valores, color="#dbdb07")

#mostra os gráficos
plt.show()