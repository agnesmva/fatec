<?php
include "functions.php";
include "conection.php";

autenticar();

$sql = "INSERT INTO clientes (nome, endereco, cidade, estado, cep, telefone, email, senha) VALUES(:nomeCliente, :enderecoCliente, :cidadeCliente, :estadoCliente, :cepCliente, :telefoneCliente, :emailCliente, :senhaCliente);";


$nome = htmlspecialchars($_POST["nome"]);
$end = htmlspecialchars($_POST["endereco"]);
$cid = htmlspecialchars($_POST["estado"]);
$est = htmlspecialchars($_POST["cidade"]);
$cep = htmlspecialchars($_POST["cep"]);
$tel = htmlspecialchars($_POST["cidade"]);
$email = htmlspecialchars($_POST["email"]);
$senha = htmlspecialchars($_POST["senha"]);
$comando = $pdo->prepare($sql);

$comando -> bindParam(":nomeCliente", $nome);
$comando -> bindParam(":enderecoCliente", $end);
$comando -> bindParam(":cidadeCliente", $cid);
$comando -> bindParam(":estadoCliente", $est);
$comando -> bindParam(":cepCliente", $cep);
$comando -> bindParam(":telefoneCliente", $tel);
$comando -> bindParam(":emailCliente", $email);
$comando -> bindParam(":senhaCliente", $senha);

$comando -> bindParam(":priceProduct", $price);

/* htmlspecialchars deve ser utilizado para evitar cross site script, xss, é um tipo de ataque que inclui um script no campo de texto do formulario */

$sucesso = $comando->execute();

if($sucesso){
    header("Location: http://localhost:3030/adm/listar_produtos.php");
}



?>
<h1 style="color: red">Falha de Conexão</h1>