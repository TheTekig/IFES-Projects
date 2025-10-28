import random

def gostounico(preferencia, lista1, lista2):
    
    final = set(preferencia)
    conj1 = set(lista1)
    conj2 = set(lista2)

    final = final.difference(conj1)
    final = final.difference(conj2)
    return final

def gostoduplo(preferencia1, preferencia2, lista):
    conj1 = set(preferencia1)
    conj2 = set(preferencia2)
    conj3 = set(lista)
    final = conj1.intersection(conj2)
    final = final.difference(conj3)
    return final

def menu():
    print("1 - Ver quem gosta somente de café")
    print("2 - Ver quem gosta de café e suco")
    print("3 - Ver quem gosta de suco e chá")
    print("4 - Ver quem gosta de café e chá")
    print("5 - Ver quem gosta de café, suco e chá")
    print("0 - Sair")
    
    return 0

def main():
    banco_de_pessoas = ["Caio Ventura","Renan Toledo","Ícaro Dantas","Mauro Silveira","Lucas Barreto","Lara Mendonça","Júlia Vasconcelos","Tainá Ribeiro","Bianca Salles","Helena Prado",
                        "Alex Lima","Sam Rocha","Cris Andrade","Dani Souza","Rafa Martins","Elvion Thar","Lysara Venn","Kaedon Dral","Nyssa Toren","Zarek Morn"]
<<<<<<< HEAD
    
=======

>>>>>>> 6d3e7331c3cc88cc863351e7f34579316f965f07
    preferem_cafe = (random.choices(banco_de_pessoas, k=10))
 
    preferem_cha = (random.choices(banco_de_pessoas, k=10))

    preferem_suco = (random.choices(banco_de_pessoas, k=10))
<<<<<<< HEAD
    
    while True:
        menu()
        op = input("Escolha uma opção:\n")
        while op.isnumeric() == False or int(op) < 0 or int(op) > 5:
            op = input("Escolha uma opção válida:\n")
        op = int(op)
=======

    print("Somente Cafe")
    final = gostounico(preferem_cafe, preferem_cha, preferem_suco)
    print(final)
>>>>>>> 6d3e7331c3cc88cc863351e7f34579316f965f07

        while op != 0:
            if op == 1:
                print(gostounico(preferem_cafe, preferem_cha, preferem_suco))
            elif op == 2:
                print(gostoduplo(preferem_cafe, preferem_suco, preferem_cha))
            elif op == 3:
                print(gostoduplo(preferem_suco, preferem_cha, preferem_cafe))
            elif op == 4:
                print(gostoduplo(preferem_cafe, preferem_cha, preferem_suco))
            elif op == 5:
                pass
            break
        
        if op == 0:
            print("Saindo...")
            break

 
    
main()