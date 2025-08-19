#region Funções de Conjuntos

def uniao(conjuntoA, conjuntoB):
    uniao = []
    for elementoA in conjuntoA:
        uniao.append(elementoA)

    for elementoB in conjuntoB:
        if elementoB not in uniao:
            uniao.append(elementoB)
            
    return uniao

def intersecao(conjuntoA, conjuntoB):
    intersecao = []
    for elementoA in conjuntoA:
        if elementoA in conjuntoA and elementoA in conjuntoB:
            intersecao.append(elementoA)
    
    return intersecao

def diferenca_A(conjuntoA, conjuntoB):
    dif_A = []
    for elementoA in conjuntoA:
        if elementoA not in conjuntoB:
            dif_A.append(elementoA)

    return dif_A

def diferenca_B(conjuntoA, conjuntoB):
    dif_B = []
    for elementoB in conjuntoB:
        if elementoB not in conjuntoA:
            dif_B.append(elementoB)

    return dif_B

def diferenca_simetrica(conjuntoA, conjuntoB):
    dif_simetrica = []
    dif_a = diferenca_A(conjuntoA, conjuntoB)
    dif_b = diferenca_B(conjuntoA, conjuntoB)

    for elementoA in dif_a:
        dif_simetrica.append(elementoA)
    for elementoB in dif_b:
        dif_simetrica.append(elementoB)
    
    return dif_simetrica

def produto_cartesiano(conjuntoA, conjuntoB):
    pro_cartesiano = []
    i = 0
    while i < len(conjuntoA):
        dupla = ()
        for elemento in conjuntoB:
            dupla = (conjuntoA[i], elemento)
            pro_cartesiano.append(dupla)     
        i+= 1
    
    return pro_cartesiano 
    
def definindo_conjuntos(conjuntoA, conjuntoB):

    conjuntoA.clear()
    conjuntoB.clear()

    print("\n\t Definir Conjuntos")
    vezes_a_repetir = repeticao("A")
    entrada_de_dados("A", vezes_a_repetir, conjuntoA)
    print("\n")
    vezes_a_repetir = repeticao("B")
    entrada_de_dados("B", vezes_a_repetir, conjuntoB)

#endregion

#region Validações/Entradas 

def validar_numero_inteiro(numero):
    try:
        if numero == int(numero):
            return True
    except ValueError:
        return False 

def entrada_de_dados(entrada, repeticao, conjunto):
    contador = repeticao
    while contador != 0:
        numero = input(f"{contador} - Adicionar a conjunção {entrada} = ")
        while validar_numero_inteiro(numero) == False:
            numero = input(f"Valor Invalido\n{contador} - Adicionar a conjunção {entrada} = ")
        conjunto.append(int(numero))
        contador -= 1

def repeticao(entrada):
    while True:

        numero = input(f"Quantos numeros você quer adicionar no conjunto {entrada}?\n --> ")
        while validar_numero_inteiro(numero) == False:
            numero = input(f"Quantos numeros você quer adicionar no conjunto {entrada}?\n --> ")
        break

    return int(numero)

 #endregion

def menu():
    print("\n\t\tMENU\n")
    print("\t1. União")
    print("\t2. Interseção")
    print("\t3. Diferença A - B")
    print("\t4. Diferença B - A")
    print("\t5. Diferença Simétrica")
    print("\t6. Produto Cartesiano")
    print("\t7. Redefinir Conjuntos\n")
    print(". Digite outra opção não listada para sair .")

def main():
    
    conjunto_A = []
    conjunto_B = []
    
    definindo_conjuntos(conjunto_A, conjunto_B)

    while True:

        menu()
        op = input("OP:" )
        match op:

            case "1":
                print("\n\tUnião dos Conjuntos")
                conjunto = uniao(conjunto_A, conjunto_B)
                print(conjunto)
                

            case "2":
                print("\n\tInterseção dos Conjuntos")
                conjunto = intersecao(conjunto_A, conjunto_B)
                print(conjunto)
                

            case "3":
                print("\n\tDiferença A-B dos Conjuntos")
                conjunto = diferenca_A(conjunto_A, conjunto_B)
                print(conjunto)
                

            case "4":
                print("\n\tDiferença B-A dos Conjuntos")
                conjunto = diferenca_B(conjunto_A, conjunto_B)
                print(conjunto)
                

            case "5":
                print("\n\tDiferença Simétrica dos Conjuntos")
                conjunto = diferenca_simetrica(conjunto_A, conjunto_B)
                print(conjunto)
                

            case "6":
                print("\n\tProduto Cartesiano dos Conjuntos")
                conjunto = produto_cartesiano(conjunto_A, conjunto_B)
                print(conjunto)
                

            case "7":
                print("\n\tRedefinindo Conjuntos")
                definindo_conjuntos(conjunto_A, conjunto_B)
                
            case _:
                print("Saindo...")
                break 
            
main()