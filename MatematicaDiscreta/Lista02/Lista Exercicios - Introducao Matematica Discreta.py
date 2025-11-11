from math import factorial
from collections import Counter


#region Funções dos Exercícios
# Exercício 1 - Combinação
def combinacao(n, k):
    if n < k:
        return "Erro: n deve ser maior ou igual a k."
    return factorial(n) // (factorial(k) * factorial(n - k))

# Exercício 2 - Permutações (recursivo)
def gerar_permutacoes(lista):
    if len(lista) <= 1:
        return [lista]
    resultado = []
    for i in range(len(lista)):
        atual = lista[i]
        resto = lista[:i] + lista[i+1:]
        for p in gerar_permutacoes(resto):
            resultado.append([atual] + p)
    return resultado

# Exercício 3 - Comitê
def comites_possiveis(total_func, tamanho_comite, incompatíveis=False):
    total = combinacao(total_func, tamanho_comite)
    if incompatíveis:
        invalidas = combinacao(total_func - 2, tamanho_comite - 2)
        return total - invalidas
    return total

# Exercício 4 - Permutações com Repetição
def perm_com_repeticao(string):
    n = len(string)
    contagens = Counter(string)
    denominador = 1
    for c in contagens.values():
        denominador *= factorial(c)
    return factorial(n) // denominador

# Exercício 5 - Combinações (recursivo)
def gerar_combinacoes(lista, k):
    if k == 0:
        return [[]]
    if k > len(lista):
        return []
    if k == len(lista):
        return [lista]
    resultado = []
    for i in range(len(lista)):
        for c in gerar_combinacoes(lista[i+1:], k-1):
            resultado.append([lista[i]] + c)
    return resultado

# Exercício 6 - Loteria
def analise_loteria():
    total = combinacao(60, 6)
    prob = 1 / total
    return total, prob

# Exercício 7 - Permutação Circular
def permutacao_circular(n):
    return factorial(n - 1) if n > 1 else 1

# Exercício 8 - Anagramas
def encontrar_anagramas(palavra):
    lista_palavras_validas = ['amor', 'roma', 'ramo', 'mora', 'maro', 'barco']
    letras = list(palavra)
    perms = gerar_permutacoes(letras)
    anagramas = []
    for p in perms:
        palavra_nova = ''.join(p)
        if palavra_nova in lista_palavras_validas and palavra_nova != palavra:
            anagramas.append(palavra_nova)
    return list(set(anagramas))

# Exercício 9 - Power Set
def power_set(lista):
    resultado = []
    for k in range(len(lista) + 1):
        resultado.extend(gerar_combinacoes(lista, k))
    return resultado

# Exercício 10 - Senhas
def problema_senhas():
    letras, digitos = 26, 10
    total_caracteres = letras + digitos
    com_repeticao = total_caracteres ** 8
    sem_repeticao = 1
    for i in range(8):
        sem_repeticao *= (total_caracteres - i)
    return com_repeticao, sem_repeticao


#endregion

def menu():
    print("\n==============================")
    print("  LISTA 1 - MATEMÁTICA DISCRETA")
    print("==============================")
    print("1 - Cálculo de Combinação")
    print("2 - Gerar Permutações de uma Lista")
    print("3 - Problema do Comitê")
    print("4 - Permutações com Repetição")
    print("5 - Gerar Combinações de uma Lista")
    print("6 - Analisar Jogo da Loteria")
    print("7 - Permutações Circulares")
    print("8 - Encontrar Anagramas")
    print("9 - Power Set (Conjunto das Partes)")
    print("10 - Problema das Senhas")
    print("0 - Sair")
    return input("Escolha uma opção: ")


def main():
    while True:
        opcao = menu()
        
        if opcao == "0":
            print("\nEncerrando o programa. Até logo!")
            break
        
        elif opcao == "1":
            n = int(input("Digite o valor de n: "))
            k = int(input("Digite o valor de k: "))
            print(f"Resultado: C({n},{k}) = {combinacao(n, k)}")

        elif opcao == "2":
            lista = input("Digite os elementos separados por vírgula: ").split(',')
            resultado = gerar_permutacoes(lista)
            print(f"\nTotal de permutações: {len(resultado)}")
            print("Exemplo:", resultado[:5])

        elif opcao == "3":
            total = int(input("Total de funcionários: "))
            comite = int(input("Tamanho do comitê: "))
            conflito = input("Há dois funcionários incompatíveis? (s/n): ").lower() == 's'
            print(f"Total de comitês possíveis: {comites_possiveis(total, comite, conflito)}")

        elif opcao == "4":
            palavra = input("Digite uma string (ex: AAB): ")
            print(f"Permutações únicas: {perm_com_repeticao(palavra)}")

        elif opcao == "5":
            lista = input("Digite os elementos separados por vírgula: ").split(',')
            k = int(input("Tamanho das combinações: "))
            resultado = gerar_combinacoes(lista, k)
            print(f"\nTotal de combinações: {len(resultado)}")
            print("Exemplo:", resultado[:5])

        elif opcao == "6":
            total, prob = analise_loteria()
            print(f"\nTotal de combinações possíveis: {total}")
            print(f"Probabilidade de acerto (1 bilhete): {prob:.20f}")

        elif opcao == "7":
            n = int(input("Quantidade de elementos no círculo: "))
            print(f"Permutações circulares: {permutacao_circular(n)}")

        elif opcao == "8":
            palavra = input("Digite uma palavra: ").lower()
            resultado = encontrar_anagramas(palavra)
            print("Anagramas encontrados:", resultado if resultado else "Nenhum válido encontrado.")

        elif opcao == "9":
            lista = input("Digite os elementos separados por vírgula: ").split(',')
            resultado = power_set(lista)
            print(f"\nTotal de subconjuntos: {len(resultado)}")
            print("Exemplo:", resultado[:8])

        elif opcao == "10":
            com_r, sem_r = problema_senhas()
            print(f"\nSenhas com repetição: {com_r}")
            print(f"Senhas sem repetição: {sem_r}")
            print("➡ O cenário com repetição é maior, pois permite reutilizar caracteres.")

        else:
            print("Opção inválida! Tente novamente.")

main()
