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
        table {
            width: 50%;
            border-collapse: collapse;
        }
        td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }
    </style>
</head>
<body>
    <table>
        <thead>
            <tr>
                <td>Código</td> 
                <td>Nome</td>
            </tr> 
        </thead>
        <tbody>
            <?php
          
            $codigos = [];
            $nomes = [];
            
            foreach ($_GET as $chave => $valor) {
                if (strpos($chave, 'codigo') === 0) {
                    $codigos[] = $valor;
                }
                if (strpos($chave, 'nome') === 0) {
                    $nomes[] = $valor;
                }
            }
            foreach ($codigos as $index => $codigo) {
                if (isset($nomes[$index])) {
                    $nome = $nomes[$index];
                    echo "<tr><td>$codigo</td><td>$nome</td></tr>";
                }
            }
            ?>
        </tbody>
    </table>
</body>
</html>
