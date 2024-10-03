<?php 
session_start();
$_SESSION["user"] = "agnes";
$_SESSION['contador'] = 0;


?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sessões PHP</title>
</head>
<body>
    <p>Id da sessão</p>
    <?= session_id();?>
    <p>Id do usuario</p>
    <?= $_SESSION['user']; ?>
</body>
</html>