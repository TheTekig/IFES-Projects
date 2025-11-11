import random

def gostounico(preferencia, lista1, lista2):
    final = set(preferencia)
    final = final.difference(lista1)
    final = final.difference(lista2)
    return final

def gostoduplo(preferencia1, preferencia2, lista):
    final = set(preferencia1).intersection(preferencia2)
    final = final.difference(lista)
    return final

def gostotriplo(cafe, cha, suco):
    return set(cafe).intersection(cha).intersection(suco)

def menu():
    print("\n===== MENU =====")
    print("1 - Ver quem gosta somente de café")
    print("2 - Ver quem gosta somente de chá")
    print("3 - Ver quem gosta somente de suco")
    print("4 - Ver quem gosta de café e chá (mas não suco)")
    print("5 - Ver quem gosta de café e suco (mas não chá)")
    print("6 - Ver quem gosta de suco e chá (mas não café)")
    print("7 - Ver quem gosta de café, chá e suco")
    print("0 - Sair")
    return int(input("Escolha uma opção: "))

def main():
    banco_de_pessoas = ["Caio Ventura","Renan Toledo","Ícaro Dantas","Mauro Silveira","Lucas Barreto","Lara Mendonça",
                        "Júlia Vasconcelos","Tainá Ribeiro","Bianca Salles","Helena Prado","Alex Lima","Sam Rocha",
                        "Cris Andrade","Dani Souza","Rafa Martins","Elvion Thar","Lysara Venn","Kaedon Dral",
                        "Nyssa Toren","Zarek Morn"]
    
    preferem_cafe = random.sample(banco_de_pessoas, k=10)
    preferem_cha = random.sample(banco_de_pessoas, k=10)
    preferem_suco = random.sample(banco_de_pessoas, k=10)

    while True:
        op = menu()
        if op == 0:
            print("Saindo...")
            break

        if op == 1:
            resultado = gostounico(preferem_cafe, preferem_cha, preferem_suco)
            print(f"\nPessoas que gostam apenas de café: {len(resultado)}\nNomes: {list(resultado)}")

        elif op == 2:
            resultado = gostounico(preferem_cha, preferem_cafe, preferem_suco)
            print(f"\nPessoas que gostam apenas de chá: {len(resultado)}\nNomes: {list(resultado)}")

        elif op == 3:
            resultado = gostounico(preferem_suco, preferem_cafe, preferem_cha)
            print(f"\nPessoas que gostam apenas de suco: {len(resultado)}\nNomes: {list(resultado)}")

        elif op == 4:
            resultado = gostoduplo(preferem_cafe, preferem_cha, preferem_suco)
            print(f"\nPessoas que gostam de café e chá (mas não suco): {len(resultado)}\nNomes: {list(resultado)}")

        elif op == 5:
            resultado = gostoduplo(preferem_cafe, preferem_suco, preferem_cha)
            print(f"\nPessoas que gostam de café e suco (mas não chá): {len(resultado)}\nNomes: {list(resultado)}")

        elif op == 6:
            resultado = gostoduplo(preferem_suco, preferem_cha, preferem_cafe)
            print(f"\nPessoas que gostam de suco e chá (mas não café): {len(resultado)}\nNomes: {list(resultado)}")

        elif op == 7:
            resultado = gostotriplo(preferem_cafe, preferem_cha, preferem_suco)
            print(f"\nPessoas que gostam de café, chá e suco: {len(resultado)}\nNomes: {list(resultado)}")

        else:
            print("Opção inválida! Tente novamente.")

main()
