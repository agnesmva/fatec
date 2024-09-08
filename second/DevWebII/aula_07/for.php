<?php
$inicial = intval($_GET["inicio"]);
$fim = intval($_GET["fim"]);
?>
<!DOCTYPE html>
<html lang="pt-br">
  <head>
    <meta charset="utf-8">
    <title>Laços em PHP</title>
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
    <header>SAÍDA PHP</header>
    <main>
    <p>Exemplo Do While</p>
            <?php 
                 if ($inicial > $fim) {
                    for ($i = $inicial; $i >= $fim; $i--) {
                        echo "<p>" . $i . "</p>"; 
                    }
                } else if ($inicial < $fim) {
                    for ($i = $inicial; $i <= $fim; $i++) {
                        echo "<p>" . $i . "</p>"; 
                    }
                } else {
                    echo "<p>Impossível resolver!!</p>";
                }
                
            ?>
    </main>
    <footer>
      <p>Site desenvolvido para aprender PHP</p>
    </footer>
  </body>
</html>