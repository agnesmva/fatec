from receiver import Luz
from commands import ComandoLigarLuz, ComandoDesligarLuz
from invoker import ControleRemoto

luz = Luz()
controle = ControleRemoto()

ligar = ComandoLigarLuz(luz)
desligar = ComandoDesligarLuz(luz)

controle.executar_comando(ligar)
controle.executar_comando(desligar)
controle.desfazer_comando()