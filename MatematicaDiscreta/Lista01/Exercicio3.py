import math

def combinacoes():
    n = 10
    k = 4

    if n >= k:
        C = math.factorial(n) / (math.factorial(k) * math.factorial(n - k))

    else:
        print("ERROR")

    return C

def combinacoesIn():
    n = 8
    k = 2

    if n >= k:
        I = math.factorial(n) / (math.factorial(k) * math.factorial(n - k))

    else:
        print("Error")
    
    return I

def comite(c,i):
    total = c - i
    return total

def main():
    C = combinacoes()
    print(f"Possuem {C} combinações para o Comitê")
    I = combinacoesIn()
    T = comite(C,I)
    print(f"Possuem {T} combinações para o Comitê sem gerar confusao com os funcionarios que nao se gostam :)")

main()