from editor import EditorTexto
from comandos_editor import EscreverTexto
from gerenciador_comandos import GerenciadorComandos

editor = EditorTexto()
manager = GerenciadorComandos()

cmd1 = EscreverTexto(editor, "Olá, ")
cmd2 = EscreverTexto(editor, "mundo!")

manager.executar_comando(cmd1)
manager.executar_comando(cmd2)

print(editor)

manager.desfazer()
print(editor)

manager.refazer()
print(editor)