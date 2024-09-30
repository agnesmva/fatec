<?php
 $codigo1 =$_GET["codigo1"];
 $codigo2 =$_GET["codigo2"];
 $codigo3 =$_GET["codigo3"];

 $nome1 =$_GET["nome1"];
 $nome2 =$_GET["nome2"];
 $nome3 =$_GET["nome3"];
?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tabela Exercício</title>
    <style>
        body{
            display: flex;
            justify-content: center;
        }
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
            echo "<tr><td>$codigo1</td> <td>$nome1</td></tr>";
            echo "<tr><td>$codigo2 </td> <td>$nome2</td></tr>";
            echo "<tr><td>$codigo3</td> <td>$nome3</td></tr>";
            ?>
        </tbody>
    </table>
</body>
</html>