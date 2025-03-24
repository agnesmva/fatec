from database_factories import MySQLFactory, PostgreSQLFactory, SQLServerFactory

def get_factory(db_choice):
    factories = {
        "mysql": MySQLFactory(),
        "postgresql": PostgreSQLFactory(),
        "sqlserver": SQLServerFactory(),
    }
    return factories.get(db_choice.lower())

if __name__ == "__main__":
    db_choice = input("Escolha um banco de dados (MySQL, PostgreSQL, SQLServer): ")
    factory = get_factory(db_choice)
    
    if factory:
        connection = factory.create_connection()
        connection_string = factory.create_connection_string()
        print(connection.connect())
        print(f"String de conexão: {connection_string}")
    else:
        print("Banco de dados não reconhecido.")