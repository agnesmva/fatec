import pandas as pd
import numpy as np

class DataLoader:
    @staticmethod
    def load_from_csv(file_path):
        """Carrega matriz de um arquivo CSV"""
        return pd.read_csv(file_path, header=None).values  # Converte para array NumPy

    @staticmethod
    def load_from_xlsx(file_path):
        """Carrega matriz de um arquivo XLSX (Excel)"""
        return pd.read_excel(file_path, header=None).values

    @staticmethod
    def load_from_ods(file_path):
        """Carrega matriz de um arquivo ODS (OpenDocument Spreadsheet)"""
        return pd.read_excel(file_path, engine="odf", header=None).values

    @staticmethod
    def load_from_txt(file_path):
        """Carrega matriz de um arquivo TXT, assumindo valores separados por espaços ou tabulação"""
        return np.loadtxt(file_path)  # Converte diretamente para um array NumPy