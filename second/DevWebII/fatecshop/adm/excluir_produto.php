<?php
include "functions.php";
include "conection.php";
autenticar();

// $sql = "DELETE FROM produtos WHERE codigo = :cod;";
$sql = "UPDATE produtos SET deleted_at = NOW() WHERE codigo = :cod;";

$codigo = intval(htmlspecialchars($_GET["codigo"])); //preciso colocar uma ação na tabela de excluir

$comando = $pdo->prepare($sql);
$comando -> bindParam(":cod", $codigo);
$sucesso = $comando -> execute();

if($sucesso){
    header("Location: http://localhost:3030/adm/listar_produtos.php");
}
?>