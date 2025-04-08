import tkinter as tk
from tkinter import messagebox
import numpy as np
from operacoes import MatrixAddition, MatrixSubtraction, MatrixMultiplication, Determinant

def parse_matrix(text):
    try:
        return np.array([[float(num) for num in row.split()] for row in text.strip().split('\n')])
    except ValueError:
        raise ValueError("Erro ao converter a matriz. Verifique se os valores estão corretos.")

def calcular_operacoes():
    try:
        mat1 = parse_matrix(input_matrix1.get("1.0", tk.END))
        mat2_text = input_matrix2.get("1.0", tk.END).strip()
        mat2 = parse_matrix(mat2_text) if mat2_text else None

        resultados = []

        if mat2 is not None:
            resultados.append("Soma:\n" + str(MatrixAddition().execute(mat1, mat2)))
            resultados.append("Subtração:\n" + str(MatrixSubtraction().execute(mat1, mat2)))
            resultados.append("Multiplicação:\n" + str(MatrixMultiplication().execute(mat1, mat2)))
        else:
            resultados.append("Soma/Subtração/Multiplicação: Necessário inserir a segunda matriz.")

        resultados.append("Determinante (Matriz 1):\n" + str(Determinant().execute(mat1)))
        resultados.append("Determinante (Matriz 2):\n" + str(Determinant().execute(mat2)))

        output.delete("1.0", tk.END)
        output.insert(tk.END, "\n\n".join(resultados))

    except Exception as e:
        messagebox.showerror("Erro", str(e))

root = tk.Tk()
root.title("Operações com Matrizes")

tk.Label(root, text="Matriz 1 (valores separados por espaço):").pack()
input_matrix1 = tk.Text(root, height=5, width=40)
input_matrix1.pack()

tk.Label(root, text="Matriz 2 (opcional):").pack()
input_matrix2 = tk.Text(root, height=5, width=40)
input_matrix2.pack()

tk.Button(root, text="Calcular Operações", command=calcular_operacoes).pack(pady=10)

tk.Label(root, text="Resultados:").pack()
output = tk.Text(root, height=15, width=60)
output.pack()

root.mainloop()
