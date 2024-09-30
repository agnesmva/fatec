<?php
$aluno = [
    "RA" => 108,
    "nome" => "Agnes Maria",
    "curso" => "DSM",
    "media" => 5,
];

if ($aluno['media'] >= 6) {
    $resultado = "<span style='color: green;'>Aprovado! :D</span>";
} else {
    $resultado = "<span style='color: red;'>Reprovado infelizmente :C</span>";
}
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Aluno RA Prova</title>
    <style>
        body {
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
            <tr ><td colspan="2">Situação Aluno</td></tr>
        </thead>
        <tr>
            <td>RA</td>
            <td><?php echo $aluno["RA"]; ?></td>
        </tr>
        <tr>
            <td>Nome</td>
            <td><?php echo $aluno["nome"]; ?></td>
        </tr>
        <tr>
            <td>Curso</td>
            <td><?php echo $aluno["curso"]; ?></td>
        </tr>
        <tr>
            <td>Média</td>
            <td><?php echo $aluno["media"]; ?></td>
        </tr>
        <tr>
            <td colspan="2">Resultado: <?php echo $resultado; ?></td>
        </tr>
    </table>
</body>
</html>
