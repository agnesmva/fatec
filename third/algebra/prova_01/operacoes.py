import numpy as np

class MatrixAddition:
    def execute(self, matrix1, matrix2):
        if matrix1.shape != matrix2.shape:
            raise ValueError("As matrizes devem ter o mesmo tamanho para soma.")
        return matrix1 + matrix2

class MatrixSubtraction:
    def execute(self, matrix1, matrix2):
        if matrix1.shape != matrix2.shape:
            raise ValueError("As matrizes devem ter o mesmo tamanho para subtração.")
        return matrix1 - matrix2

class MatrixMultiplication:
    def execute(self, matrix1, matrix2):
        if matrix1.shape[1] != matrix2.shape[0]:
            raise ValueError("O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda.")
        return np.dot(matrix1, matrix2)

class Determinant:
    def execute(self, matrix):
        if matrix.shape[0] != matrix.shape[1]:
            raise ValueError("A matriz deve ser quadrada para calcular o determinante.")
        return np.linalg.det(matrix)
