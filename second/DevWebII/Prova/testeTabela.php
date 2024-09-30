<?php
$codigo = [
    "codigo1" => 1,
    "codigo2" => 2,
    "codigo3" => 3,
];

$nome = [
    "codigo1" => "Ana",
    "codigo2" => "Carlos",
    "codigo3" => "Maria",
];
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tabela Exercício</title>
    <style>
        thead {
            border: solid 2px black;
        }
        td {
            border: solid 1px black;
            padding: 8px;
            text-align: center;
        }
    </style>
</head>
<body>
    <table>
        <thead>
            <tr><td>Código</td> <td>Nome</td></tr> 
        </thead>
        <tbody>
            <?php
            foreach ($codigo as $chave => $valorCodigo) {
                // O índice $chave é o mesmo para ambos $codigo e $nome
                $valorNome = $nome[$chave];
                echo "<tr> <td>$valorCodigo</td> <td>$valorNome</td> </tr>";
            }
            ?>
        </tbody>
    </table>
</body>
</html>
