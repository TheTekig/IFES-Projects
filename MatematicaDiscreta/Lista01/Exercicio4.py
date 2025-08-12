import math

def perm_com_repeticao(string):
    lista = list(string)
    n = len(lista)
    i = 0
    caracteres_unicos  = set(string)

    for letra in lista:
        if string.count(letra) > 1:
            
            print(letra)
            

        

def main():
    perm_com_repeticao("AAAAAABBBBBC")
main()