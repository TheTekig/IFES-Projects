import itertools as it

def gerar_permutacoes(lista):
    if len(lista) <= 1:
        return [lista[:]]
    
    permutacoes = []

    for i in range(len(lista)):
        elemento_fixo = lista[i]
        restante = lista[:i] + lista[i+1:]

        for p in gerar_permutacoes(restante):
            permutacoes.append([elemento_fixo] + p)

    return permutacoes

while True:
    a = input("a = ")
    if a == "!0":
        break
    b = input("b = ")
    c = input("c = ")

    lista = [a,b,c]
    resultado = gerar_permutacoes(lista)
    for perm in resultado:
        print(perm)

