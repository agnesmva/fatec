from GerenciadorImpressoes import *
if __name__ == "__main__":
    inicia = input("Programa Iniciado\nDigite 0 para sair\n")
    while inicia is not 0:
        gerenciador2 = GerenciadoImpressoes()
        gerenciador1 = GerenciadoImpressoes()

        vontade = int(input("O que você deseja fazer?\nDigite 1 para inserir um documento\nDigite 2 para remover\n"))

        if vontade == 1:
            qtInserir = int(input("Quantos documentos você deseja inserir na fila? "))

            while qtInserir > 0:
                gerenciador1.adicionarFila()
                qtInserir -= 1

        elif vontade == 2:
                
                gerenciador2.removerFila()
        else:
            print(f"Digite um valor valido")
            exit
            
