import os

def gen_archive(qtd_tarefas,extencao, pasta):
    contador = 0
    while qtd_tarefas != 0:
        contador += 1
        arquivo = (f"Exercicio{contador}.{extencao}") 
        create_archive(arquivo, pasta)
        qtd_tarefas -= 1
    return 0

def create_archive(nome_arquivo,pasta):
    try:
        nome_arquivo = os.path.join(pasta, nome_arquivo)
        with open (nome_arquivo, "w"):
            pass  
    except Exception:
        print(f"Não foi possivel criar {nome_arquivo}")            

def gen_folder(nome_pasta):
    try:
        os.makedirs(nome_pasta)
    except Exception:
        print(f"Pasta {nome_pasta} não pode ser criada!")

def int_validation():
    num = input("- ")
    while num.isdigit() != True:
        num = input("Invalid Value\n- ")
    return int(num)

def option():
    while True:
        op = input("OP: ")
        if op in ["1", "2", "3"]:
            return op
    
def menu():
    print("\nSISTEMA DE LISTAS")
    print("1. Gerar Pasta")
    print("2. Gerar Arquivos")
    print("3. Sair")

def main():
    while True:
        menu()
        op = option()

        match(op):

            case "1":
                pasta = input("Nome da Pasta: ")
                pasta = f".\Programação2\{pasta}"
                gen_folder(pasta)

            case "2":
                print("Quantidade de Tarefas ", end="")
                tarefas = int_validation()
                tipo = input("Extensão - ")
                pasta = input("Pasta a salvar: ")
                pasta = f".\Programação2\{pasta}"
                gen_archive(tarefas, tipo, pasta)
            
            case "3":
                print("Saindo...")
                break

main()