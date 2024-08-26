<?php

    // é preciso receber o valor digitado no campo
    $nome = $_GET["nome"];
    $idade = $_GET["idade"];
?>
<!DOCTYPE html>
<html lang="pt">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Reposta</title>
</head>
<body>
    <h1>Cumprimentando...</h1>
    <h2>Prazer em te conhecer, <?php echo $nome;?>!!</h2>
    <h3>A sua idade é: <?php echo $idade;?></h3>
</body>
</html>