<?php
include "functions.php";
include "conection.php";


//função de autenticar toda vez que logar
autenticar();


$sql = "SELECT * FROM produtos WHERE deleted_at IS NULL;"; //string com o comando SQL a ser executado
$comando = $pdo->prepare($sql);
$comando = $pdo->query($sql);   //montamos e deixamos o SQL preparado

$resultado = $comando->fetchAll(); //executamos o comando "pegando tudo", FETCHALL pega todos os registros, o FETCH pega 

?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="/css/style.css">
    <title>Listagem de produtos</title>
</head>
<body>
    <header></header>
    <nav></nav>
    <main>
        <table>
            <thead>
                <tr>
                    <td>COD.</td>
                    <td>NOME</td>
                    <td>CATEGORIA</td>
                    <td>PREÇO</td>
                    <td>DELETAR</td>
                    <td>EDITAR</td>
                </tr>
            </thead>
            <tbody>
                <?php foreach($resultado as $produto){ ?>
                <tr>
                    <td><?= $produto["codigo"]?></td>
                    <td><?= $produto["nome"]?></td>
                    <td><?= $produto["categoria"]?></td>
                    <td><?= $produto["preco_unitario"]?></td>
                    <td><a href="excluir_produto.php?codigo=<?=$produto["codigo"]?>">Deletar</a></td>
                    <td><a href="form_alterar_produto.php?codigo=<?=$produto["codigo"]?>">Editar</a></td>
                </tr>
                <?php } ?>
            </tbody>
        </table>
    </main>
    <footer></footer>
</body>
</html>