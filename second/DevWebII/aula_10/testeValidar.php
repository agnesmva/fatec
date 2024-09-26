<?php
// Array de usuários cadastrados
$usuarios = [
    "agnes" => "12345678",
    "melissa" => "12345678",
    "teste" => "12345678",
    "kelvin" => "12345678",
    "monas" => "12345678",
];

function validarUsuario($usuario, $usuarios) {
    return array_key_exists ($usuario, $usuarios);
}

function validarSenha($usuario, $senha, $usuarios) {
    
    if (validarUsuario($usuario, $usuarios)) {
        // Comparação da senha exata
        if ($usuarios[$usuario] == $senha) {
            return "Seja bem vinde!  " . ucfirst($usuario);
        } else {
            return "Senha Incorreta";
        }
    }
    return "Usuário inexistente";
}

// Inicializa a mensagem
$mensagem = "";

// Verifica se o formulário foi enviado
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $usuario = $_POST['username'];
    $senha = $_POST['password'];

    // Valida o usuário e a senha
    $mensagem = validarSenha($usuario, $senha, $usuarios);
}
?>

<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Validação de Usuário</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <header>
        <h1>Validação de Usuário</h1>
    </header>
    <main>
        <p><?php echo htmlspecialchars($mensagem); ?></p>
    </main>
    <footer>
        <p>Site desenvolvido para aprender PHP</p>
    </footer>
</body>
</html>
