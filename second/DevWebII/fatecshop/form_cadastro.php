<?php

include "cabecalho.php";

?>
<main>
    <form action="cadastrar_cliente.php" method="POST">
        <div>
            <label for="nome">Nome</label>
            <input type="text" id="nome" name="nome" size="50" maxlength="50" required>
        </div>
        <div>
            <label for="endereco">Endereço</label>
            <input type="text" id="endereco" name="endereco" size="50" maxlength="50" required>
        </div>
        <div>
            <label for="estado">Estado</label>
            <input type="text" id="estado" name="estado" size="50" maxlength="50" required>
    
        </div>
        <div>
            <label for="cidade">Cidade</label>
            <input type="text" id="cidade" name="cidade" size="50" maxlength="50" required>
        </div>
        <div>
            <label for="cep">CEP</label>
            <input type="text" id="cep" name="cep" size="50" maxlength="50" required>
        </div>
        <div>
            <label for="cidade">Cidade</label>
            <input type="text" id="cidade" name="cidade" size="30" maxlength="30" required>
        </div>
        <div>
            <label for="telefone">Telefone</label>
            <input type="tel" pattern="[0-9]{3}-[0-9]{3}-[0-9]{4}" id="telefone" name="telefone" size="15" maxlength="15" required>
        </div>
        <div>
            <label for="email">E-mail</label>
            <input type="email" id="email" name="email" size="15" maxlength="15" required>
        </div>
        <div>
            <label for="senha">Senha</label>
            <input type="password" id="senha" name="senha" size="15" maxlength="15" required>
        </div>
        <div id="div_botao">
            <button>Cadastrar</button>
        </div>
    </form>
</main>
<?php

include "rodapé.php";

?>