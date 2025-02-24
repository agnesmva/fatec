# Aluna: Agnes Maria Varela
# Disciplina: Tec. de Programação II

#Atividade:Implementar ClientePessoaInternacional



class Cliente:
    def exibir_informacoes(self):
        pass

class ClientePessoaFisica(Cliente):
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf

    def exibir_informacoes(self):
        print(f"Cliente Pessoa Física: {self.nome}, CPF: {self.cpf}")

class ClientePessoaJuridica(Cliente):
    def __init__(self, nome, cnpj):
        self.nome = nome
        self.cnpj = cnpj

    def exibir_informacoes(self):
        print(f"Cliente Pessoa Jurídica: {self.nome}, CNPJ: {self.cnpj}")

class ClientePessoaInternacional(Cliente):
    def __init__(self, nome, nif):
        self.nome = nome
        self.nif = str(nif)  

    def exibir_informacoes(self):
        print(f"Cliente Pessoa Internacional: {self.nome}, NIF: {self.nif}")

    def verificarNIF(self):
        return len(self.nif) == 9 

class ClienteFactory:
    def criar_cliente(self, tipo, nome, documento):
        if tipo == 'pessoa_fisica':
            return ClientePessoaFisica(nome, documento)
        elif tipo == 'pessoa_juridica':
            return ClientePessoaJuridica(nome, documento)
        elif tipo == 'pessoa_internacional':
            cliente = ClientePessoaInternacional(nome, documento)
            if cliente.verificarNIF():
                return cliente
            else:
                raise ValueError("NIF inválido. Deve conter 9 dígitos.")
        else:
            raise ValueError("Tipo de cliente não suportado")



factory = ClienteFactory()
cliente1 = factory.criar_cliente("pessoa_fisica", "Agnes Maria", "123.456.789-00")
cliente2 = factory.criar_cliente("pessoa_juridica", "Empresa XYZ", "12.345.678/0001-99")
cliente3 = factory.criar_cliente("pessoa_internacional", "Internacional", "987654321")


cliente1.exibir_informacoes()
cliente2.exibir_informacoes()
cliente3.exibir_informacoes()
