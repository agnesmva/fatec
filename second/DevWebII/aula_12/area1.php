<?php
session_start();
if(isset($_GET["nome"])){
    if(empty($_GET["nome"])){
        $_SESSION["nome"] = "Anônimo";
    } else{
        $_SESSION["nome"] = $_GET["nome"];
    }
}

?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Area de acesso identificação</title>
</head>
<body>
    <?php
    if(isset(($_GET["nome"]))){?>
        <h1>Acesso autorizado</h1>
        <p>Olá, bem vindeeeee <?= $_SESSION["nome"]?></p>
        <a href="area2.php">Vamos acessar a segunda area?</a>
    <?php } else { ?>
        <h1>Acesso negado</h1>
        <a href="form.php">Clique aqui para colocar seu usuario</a>
   <?php }?>
   
    

    
    
</body>
</html>