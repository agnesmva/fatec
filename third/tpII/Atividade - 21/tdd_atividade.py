import unittest

def conversor_temperatura(valor: float, escala_origem: str, escala_destino: str) -> float:
    if escala_origem == escala_destino:
        return valor
    
    if escala_origem == 'C' and escala_destino == 'F':
        return (valor * 9 / 5) + 32
    elif escala_origem == 'F' and escala_destino == 'C':
        return (valor - 32) * 5 / 9
    else:
        raise ValueError("Escalas devem ser 'C' ou 'F'")
    

'''
RED TEST 

def conversor_temperatura(valor: float, escala_origem: str, escala_destino: str) -> float:
    pass  # Ainda não faz nada

class TestConversorTemperatura(unittest.TestCase):
    def test_celsius_para_fahrenheit(self):
        resultado = conversor_temperatura(0, 'C', 'F')
        self.assertAlmostEqual(resultado, 32.0)

    def test_fahrenheit_para_celsius(self):
        resultado = conversor_temperatura(32, 'F', 'C')
        self.assertAlmostEqual(resultado, 0.0)

if __name__ == '__main__':
    unittest.main()

'''

# =======================
# TESTES UNITÁRIOS
# =======================

class TestConversorTemperatura(unittest.TestCase):
    def test_celsius_para_fahrenheit(self):
        self.assertAlmostEqual(conversor_temperatura(0, 'C', 'F'), 32.0)
        self.assertAlmostEqual(conversor_temperatura(100, 'C', 'F'), 212.0)
        self.assertAlmostEqual(conversor_temperatura(-40, 'C', 'F'), -40.0)

    def test_fahrenheit_para_celsius(self):
        self.assertAlmostEqual(conversor_temperatura(32, 'F', 'C'), 0.0)
        self.assertAlmostEqual(conversor_temperatura(212, 'F', 'C'), 100.0)
        self.assertAlmostEqual(conversor_temperatura(-40, 'F', 'C'), -40.0)

    def test_mesma_escala(self):
        self.assertEqual(conversor_temperatura(25, 'C', 'C'), 25)
        self.assertEqual(conversor_temperatura(77, 'F', 'F'), 77)

    def test_escala_invalida(self):
        with self.assertRaises(ValueError):
            conversor_temperatura(100, 'K', 'C')

        with self.assertRaises(ValueError):
            conversor_temperatura(100, 'C', 'K')

# Executa os testes
if __name__ == '__main__':
    unittest.main()
