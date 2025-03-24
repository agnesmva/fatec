class DatabaseConnection:
    _instances = {}
    
    def __new__(cls, db_type):
        if db_type not in cls._instances:
            cls._instances[db_type] = super(DatabaseConnection, cls).__new__(cls)
            cls._instances[db_type].db_type = db_type
        return cls._instances[db_type]
    
    def connect(self):
        return f"Conectado ao banco de dados {self.db_type}"
