import redis

r = redis.Redis(host='localhost', port=6379, decode_responses=True)

menu = """
        1 - Entrar na fila
        2 - Atender primeiro da fila
        3 - Imprimir fila 
        4 - SAIR
       """

print(menu)
opcao = int(input("Digite sua opção: "))

while opcao != 4:
    
    if opcao == 1:
        nome = input("Informe o nome de quem entrará na fila: ")
        if nome != "":
            r.rpush("fila", nome)  # Adiciona à fila no Redis
    
    elif opcao == 2:
        if r.llen("fila") > 0:
            atendido = r.lpop("fila")  # Remove o primeiro da fila
            print(f"{atendido} foi removido!")
        else:
            print("A fila está vazia.")

    elif opcao == 3:
        fila = r.lrange("fila", 0, -1)  # Obtém todos os elementos da fila
        print("Fila atual: ")
        print(fila if fila else "A fila está vazia.")

    print(menu)
    opcao = int(input("Digite sua opção: "))
