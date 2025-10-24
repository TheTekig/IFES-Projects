import random

def gostounico(preferencia, lista1, lista2):
    
    final = set(preferencia)
    conj1 = set(lista1)
    conj2 = set(lista2)

    final = final.difference(conj1)
    final = final.difference(conj2)

def gostoduplo(preferencia1, preferencia2, lista):
    conj1 = set(preferencia1)
    conj2 = set(preferencia2)
    conj3 = set(lista)

    return 0

def main():
    banco_de_pessoas = ["Caio Ventura","Renan Toledo","Ícaro Dantas","Mauro Silveira","Lucas Barreto","Lara Mendonça","Júlia Vasconcelos","Tainá Ribeiro","Bianca Salles","Helena Prado",
                        "Alex Lima","Sam Rocha","Cris Andrade","Dani Souza","Rafa Martins","Elvion Thar","Lysara Venn","Kaedon Dral","Nyssa Toren","Zarek Morn"]

    preferem_cafe = (random.choices(banco_de_pessoas, k=10))
 
    preferem_cha = (random.choices(banco_de_pessoas, k=10))

    preferem_suco = (random.choices(banco_de_pessoas, k=10))

    print("Somente Cafe")
    final = gostounico(preferem_cafe, preferem_cha, preferem_suco)
    print(final)

    print("Gosta de Cafe e suco")
    print(gostoduplo(preferem_cafe, preferem_suco, preferem_cha))

 
    
main()