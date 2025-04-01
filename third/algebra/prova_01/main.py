from data import DataLoader
from operacoes import MatrixAddition, MatrixSubtraction, MatrixMultiplication, Determinant

def main():
    file_path = input("Informe o caminho do arquivo (CSV/XLSX): ")
    
    if file_path.endswith('.csv'):
        matrix = DataLoader.load_from_csv(file_path)
    elif file_path.endswith('.xlsx'):
        matrix = DataLoader.load_from_xlsx(file_path)
    else:
        print("Formato inválido!")
        return

    print("Matriz carregada:")
    print(matrix)

    print("\nEscolha a operação:\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Determinante")
    choice = input("Digite o número da operação: ")

    if choice in ['1', '2', '3']:
        file_path_2 = input("Informe o caminho do segundo arquivo de matriz: ")
        matrix2 = DataLoader.load_from_csv(file_path_2) if file_path_2.endswith('.csv') else DataLoader.load_from_xlsx(file_path_2)
        
        operation = {'1': MatrixAddition(), '2': MatrixSubtraction(), '3': MatrixMultiplication()}[choice]
        result = operation.execute(matrix, matrix2)
    
    elif choice == '4':
        operation = Determinant()
        result = operation.execute(matrix)

    print("\nResultado da operação:")
    print(result)

if __name__ == "__main__":
    main()
