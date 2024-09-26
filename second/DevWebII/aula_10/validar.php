<?php
    $usuarios = [
        "agnes" => "12345678",
        "melissa" => "12345678",
        "teste" => "12345678",
        "kelvin" => "12345678",
        "monas" => "12345678",
    ];

    function validarUsuario($usuario, $usuarios){
       return array_key_exists($usuario, $usuarios);
    }
    function validarSenha($usuario, $senha, $usuarios){
        if($usuarios[$usuario]== $senha){
            return true;
        }
        return false;
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tela de Entrada</title>
</head>
<body>
    
</body>
</html>