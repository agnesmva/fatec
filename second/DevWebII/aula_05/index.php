<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Alô, php</title>
</head>
<body>
    <h1>Isso daqui ainda é HTML</h1>
    <?php
    echo "<h2>Isso daqui é PHP, monas</h2>\n";
    ?>
    <p>Este é um paragrafo de texto</p>
    <?php
    echo "<h3>Isso daqui é PHP, novamente</h3>\n";
    print("U wanna guess the color of my underwear? \n");
    $nome = "Maria";
    $idade = 32;
    $altura = 1.45;
    $peso = 39;
    $imc = ($altura*2)/$peso;
    if ($idade > 30){
        echo "<p> $nome tem $idade anos! Você está cracrura</p><br> <p> $imc</p>";
        echo '<p> $nome tem $idade anos! Você está cracrura</p><br> <p> $imc</p>';
    }
    else{
        echo "<p> $nome tem $idade anos! Você está tão jovenzinha tão galera \n</p>";
    }
    ?>
</body>
</html>