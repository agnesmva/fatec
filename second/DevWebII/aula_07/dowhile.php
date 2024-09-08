<?php
$contador = 10;
?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>While Simples PHP</title>
</head>
<body>
<header>SAÍDA PHP</header>
<main>
    <p>Exemplo Do While</p>
    <ul>
        <?php do { ?>
            <li>Item<?=$contador=1?></li>
        <?php } while($contador >10); ?>
    </ul>
</main>
<footer></footer>
</body>
</html>
