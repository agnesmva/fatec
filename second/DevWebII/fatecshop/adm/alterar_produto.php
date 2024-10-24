<?php
include "functions.php";
include "conection.php";

autenticar();

$sql = "UPDATE produtos SET nome = :nameProduct, descricao = :descriptionProduct, categoria = :typeProduct, preco_unitario = :priceProduct WHERE codigo = :cod;";

$codigo = htmlspecialchars($_POST["codigo"]);
$comando = $pdo->prepare($sql);

$comando -> bindParam(":cod", $codigo);
$comando -> bindParam(":nameProduct", $_POST["nameProduct"]);
$comando -> bindParam(":descriptionProduct", $_POST["descriptionProduct"]);
$comando -> bindParam(":typeProduct", $_POST["typeProduct"]);

$price = floatval($_POST["priceProduct"]);
$comando -> bindParam(":priceProduct", $price);

$sucesso = $comando->execute();

if($sucesso){
    header("Location: http://localhost:3030/adm/listar_produtos.php");
}
?>
<h1 style="color: red">Falha na alteração</h1>

