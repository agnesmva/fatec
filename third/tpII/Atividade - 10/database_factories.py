from abstract_factory import DatabaseFactory
from database_conections import DatabaseConnection

class MySQLFactory(DatabaseFactory):
    def create_connection(self):
        return DatabaseConnection("MySQL")
    
    def create_connection_string(self):
        return "mysql://user:password@host:port/database"

class PostgreSQLFactory(DatabaseFactory):
    def create_connection(self):
        return DatabaseConnection("PostgreSQL")
    
    def create_connection_string(self):
        return "postgresql://user:password@host:port/database"

class SQLServerFactory(DatabaseFactory):
    def create_connection(self):
        return DatabaseConnection("SQL Server")
    
    def create_connection_string(self):
        return "sqlserver://user:password@host:port/database"
