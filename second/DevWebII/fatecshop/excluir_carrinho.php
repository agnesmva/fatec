<?php
include "functions.php";
include "conection.php";
autenticar();
session_start();

// $sql = "DELETE FROM produtos WHERE codigo = :cod;";
$sql = "UPDATE carrinho SET deleted_at = NOW() WHERE produto = :cod AND sessao = :sessao";

$codigo = intval(htmlspecialchars($_GET["codigo"])); //preciso colocar uma ação na tabela de excluir

$id = session_start();

$comando = $pdo->prepare($sql);
$comando -> bindParam(":cod", $codigo);
$comando -> bindParam(":sessao", $id);
$sucesso = $comando -> execute();

if($sucesso){
    header("Location: http://localhost:3030/adm/listar_produtos.php");
}
?>