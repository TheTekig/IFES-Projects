def uniao(conjuntoA, conjuntoB):
    uniao = []
    for elemento in conjuntoA:
        uniao.append(elemento)
        for elemeneto in conjuntoB:
            uniao.append(elemento)
            
    return uniao.sort()
             

def validar_numero_inteiro(numero):
    try:
        if numero == int(numero):
            return True
    except ValueError:
        return False 

def entrada_de_dados(entrada, repeticao, conjunto):
    contador = repeticao
    while contador != 0:
        numero = input(f"{contador} - ADD NUMBER TO THE CONJUNCTION {entrada} = ")
        while validar_numero_inteiro(numero) == False:
            numero = input(f"INVALID VALUE\n{contador} - ADD NUMBER TO THE CONJUNCTION {entrada} = ")
        conjunto.append(int(numero))
        contador -= 1

def repeticao(entrada):
    while True:

        numero = input(f"How many number do you want to add in the conjunction {entrada}?\n --> ")
        while validar_numero_inteiro(numero) == False:
            numero = input(f"How many number do you want to add in the conjunction {entrada}?\n --> ")
        break

    return int(numero)


def main():
    conjunto_A = []
    conjunto_B = []
    print("\n")
    vezes_a_repetir = repeticao("A")
    entrada_de_dados("A", vezes_a_repetir, conjunto_A)
    print("\n")
    vezes_a_repetir = repeticao("B")
    entrada_de_dados("B", vezes_a_repetir, conjunto_B)


    resposta = uniao(conjunto_A, conjunto_B)
    print(f"A = {conjunto_A}")
    print(f"B = {conjunto_B}")
    print(resposta)

main()