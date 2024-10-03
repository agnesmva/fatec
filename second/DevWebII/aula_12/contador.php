<?php
    session_start();
    if(!isset($_SESSION['contador'])){
        $_SESSION['contador'] = 0;

    }
    $_SESSION['contador'] ++;
?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contador de Sessão</title>
</head>
<body>
    <h2>Quantas sessões</h2>
    <li><?= $_SESSION['contador']?></li>
    <p><a href="reset.php">Clique aqui para reiniciar o contador</a></p>
</body>
</html>