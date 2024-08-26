<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>form</title>
</head>
<body>
    <h1>Cumprimentador 2.0</h1>
    <form action="cmp.php" method="GET">
        <label for="nome">Seu nome:</label>
        <input type="text" name="nome" id="nome">
        <label for="idade">Sua idade:</label>
        <input type="text" name="idade" id="idade">
        <button type="submit">Cumprimentar</button>
    </form>
</body>
</html>