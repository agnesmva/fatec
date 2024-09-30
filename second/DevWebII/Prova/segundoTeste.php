<?php
// Capturando os dados da query string e montando os vetores
$codigo = [
    "codigo1" => $_GET['codigo1'],
    "codigo2" => $_GET['codigo2'],
    "codigo3" => $_GET['codigo3'],
];

$nome = [
    "nome1" => $_GET['nome1'],
    "nome2" => $_GET['nome2'],
    "nome3" => $_GET['nome3'],
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
            // Iterando pelos vetores $codigo e $nome
            foreach ($codigo as $chave => $valorCodigo) {
                $valorNome = $nome[$chave];
                if ($valorCodigo && $valorNome) {
                    echo "<tr> <td>$valorCodigo</td> <td>$valorNome</td> </tr>";
                }
            }
            ?>
        </tbody>
    </table>
</body>
</html>
