'''
Padrão Singleton

Um padrão do tipo criacional 
possui apenas uma única instância
- acesso global a essa instância
- aplicações principalmente em conexões de banco de dados, arquivos de configuração,etc.

o método __init__() é o método construtor do python - quando se utiliza o singleton ele perde a função de criação do objeto, ele apenas inicializa os parametros
o método __new__() faz a criação do objeto, verificando se o objeto já foi criado, caso tenha sido criado 

Esse código cria uma classe chamada Configuracoes que só pode ter uma única instância — ou seja, independentemente de quantas vezes você tente criar um novo objeto dessa classe, você sempre terminará com o mesmo objeto. Isso é feito usando uma combinação do método new, para controlar a criação da instância, e uma variável de classe privada __instance, que guarda a única instância permitida.

Na prática, quando você cria a primeira instância (config1), o código verifica se já existe uma instância guardada em __instance. Como não existe, ele cria uma e a guarda. Quando você tenta criar outra instância (config2), o código vê que __instance já tem uma instância guardada e retorna essa mesma instância em vez de criar uma nova.

Isso significa que config1 e config2 são, na verdade, o mesmo objeto. Assim, se você alterar um atributo como o volume em config1, essa alteração também será refletida em config2, já que eles são o mesmo objeto. O código demonstra isso mudando o volume de 75 para 90 através de config1 e mostrando que o volume em config2 também se altera para 90.


'''

# Define uma classe chamada Configuracoes
class Configuracoes:
   # Variável de classe privada para armazenar a única instância da classe
   #Uma varivável do tipo protegida
   __instance = None

   # Método especial para criar uma nova instância da classe
   def __new__(cls):
       # Verifica se uma instância já existe
       if Configuracoes.__instance is None:
          # Se não, cria uma nova instância e a armazena na variável __instance
          Configuracoes.__instance = super().__new__(cls)
       # Retorna a instância única
       return Configuracoes.__instance

   # Método inicializador que define os atributos de instância
   def __init__(self):
       # Define o volume padrão
       self.volume = 75
       # Define a dificuldade padrão
       self.dificuldade = "Médio"

# Cria a primeira instância da classe Configuracoes
config1 = Configuracoes()
# Tenta criar uma segunda instância da classe Configuracoes
config2 = Configuracoes()

# Imprime o volume atual da configuração, que é 75 por padrão
print(config2.volume)

# Verifica se config1 e config2 são exatamente a mesma instância
print(config1 is config2)

# Altera o valor do volume na instância config1 para 90
config1.volume = 90

# Imprime o volume de config2, que também será 90, mostrando que config1 e config2 são a mesma instância
print(config2.volume) # A saída será 90, refletindo a alteração feita por meio de config1

'''
### O que é esse tal de \_\_new\_\_???

O método **\_\_new\_\_** é um método especial em Python, usado para controlar a criação de uma nova instância de uma classe. Ele é chamado automaticamente antes do método **`__init__`** durante a criação de um objeto e tem a responsabilidade única de retornar uma nova instância do objeto solicitado. Isso o torna especialmente útil para padrões de design como o Singleton, onde você precisa garantir que apenas uma instância de uma classe seja criada.

Aqui está o que acontece com **\_\_new\_\_**:

1. **Definição**: O método **`__new__`** é definido na classe com o primeiro argumento sendo **`cls`**, que representa a classe em si. Isso é semelhante ao **`self`**, mas `self` refere-se à instância enquanto **`cls`** refere-se à classe.

2. **Controle de Criação de Instâncias**: Quando você chama a classe para criar uma nova instância, Python automaticamente invoca o `__new__` antes de `__init__`. Isso dá ao `__new__` a chance de decidir se uma nova instância deve ser criada ou não.

3. **Retornando a Instância**: Dentro de `__new__`, você pode criar uma nova instância da classe usando `super().__new__(cls)`, que chama o `__new__` da superclasse (geralmente `object.__new__`) para realmente criar uma instância da classe. Em seguida, você pode retornar essa instância para que seja inicializada pelo `__init__`.

4. **Uso no Singleton**: No contexto do padrão Singleton, o `__new__` verifica se uma instância já existe. Se não existir, ele cria uma nova e a armazena em uma variável de classe, como `__instance`. Se uma instância já existir, ele simplesmente retorna essa instância, sem criar uma nova. Dessa forma, todas as chamadas subsequentes à classe retornarão a mesma instância.

Em resumo, o `__new__` é fundamental para controlar a criação de instâncias em Python, permitindo implementações avançadas como o padrão Singleton, onde é necessário limitar a criação de instâncias a apenas uma única instância de uma classe específica.
'''

class AppConfig:
    __instance = None

    def __new__(cls):
        if not cls.__instance:
            cls.__instance = super(AppConfig, cls).__new__(cls)
            # Inicialização de atributos de instância vai aqui
            cls.__instance.theme = "Claro"
            cls.__instance.language = "Português"
            cls.__instance.version = "1.0.0"
        return cls.__instance

    def show_config(self):
        print(f"Tema: {self.theme}, Idioma: {self.language}, Versão: {self.version}")

# Teste do Singleton
if __name__ == "__main__":
    # Cria a primeira instância
    config1 = AppConfig()
    config1.show_config()  # Tema: Claro, Idioma: Português, Versão: 1.0.0

    # Modifica a configuração na primeira instância
    config1.theme = "Escuro"

    # Cria uma "nova" instância
    config2 = AppConfig()
    config2.show_config()  # Tema: Escuro, Idioma: Português, Versão: 1.0.0

    # Verifica se ambas as instâncias são de fato a mesma
    print(f"config1 é config2: {config1 is config2}")  # True
