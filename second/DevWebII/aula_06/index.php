<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculadora</title>
</head>
<body>
    <h1>Calculadora</h1>
    <p>Essa calculadora é utilizada para realizar operações matemáticas simples.</p>
    
    <form action="calcular.php" method="get">
        <label for="numberA">Digite o primeiro número:</label>
        <input type="number" id="numberA" name="numeroA" placeholder="Primeiro número">
        
        <label for="numberB">Digite o segundo número:</label>
        <input type="number" id="numberB" name="numeroB" placeholder="Segundo número">
        
        <label for="op">Escolha a operação:</label>
        <select name="operacao" id="op">
            <option value="+">+</option>
            <option value="-">-</option>
            <option value="*">*</option>
            <option value="/">/</option>
        </select>
        
        <button type="submit" name="cal">Calcular</button>
    </form>
</body>
</html>
