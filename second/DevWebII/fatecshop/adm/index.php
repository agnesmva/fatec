<?php 
    session_start();

    // verificando a variavel de sessão para o administrador está configurada, caso não esteja configurada, redirecionamos o usuário para a página de login
    if(!isset($_SESSION["admin"])){
        header("Location: http://localhost:3030/adm/login.php");
    }

?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="/css/style.css">
    <title>FatecShop - Admin</title>
</head>
<body>
    <header><h1>FATEC Shop - Área Administrativa</h1></header>
    <nav></nav>
    <main>
        
        <ul>
            <li>Cadastrar Produtos</li>
            <form action="form_product.php" method="$_POST">
                <div>
                    <label for="nameProduct">Nome do Produto</label>
                    <input type="text" name="nameProduct" maxlength="50" require>
                </div>
                <div>
                    <label for="descriptionProduct">Descrição do Produto</label>
                    <textarea name="descriptionProduct" maxlength="200" id="descriptionProduct" col></textarea>
                </div>
                <div>
                    <label for="priceProduct">Preço: </label>
                    <input type="number" name="priceProduct" id="priceProduct">
                </div>
                <div>
                    <label for="typeProduct">Tipo do Produto</label>
                    <select name="typeProduct" id="typeProduct"></select>
                </div>
                <div>
                    <button>Cadastrar Produto</button>
                </div>
            </form>
            <li><a href="">Listar produtos cadastros</a></li>
        </ul>
    </main>
    <footer></footer>
</body>
</html>