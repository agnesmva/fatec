<?php 
    include "adm/conection.php";
    session_start();

    $sql = "SELECT p.nome as nomeproduto, p.preco_unitario AS preco, p.categoria AS categoria, c.quantidade as quantidade, p.codigo AS codigo
    FROM carrinho c INNER JOIN produtos p
    ON c.produto = p.codigo
    WHERE c.sessao = :sessao;";

    $id = session_id();

    $comando = $pdo->prepare($sql);
    $comando->bindParam(":sessao", $id);
    $comando->execute();
    $res = $comando->fetchAll();

?>
<?php include "include/cabecalho.php";?>

<?php include "include/rodape.php";?>
<main>
    <h2>Seu Carrinho de Compras</h2>
    <table>
        <tr>
            <td>Nome produto</td> <td>Tipo</td> <td>Quantidade</td> <td>Preço</td>
        </tr>
        <?php foreach($res as $produto) { ?>
                    <td><?= $produto["nomeproduto"]?></td>
                    <td><?= $produto["categoria"]?></td>
                    <td><?= $produto["quantidade"]?></td>
                    <td><?= number_format($produto["preco_unitario"])?></td>
                    <td><a href="excluir_carrinho.php?codigo=<?=$produto["codigo"]?>">Deletar</a></td>
                </tr>
        <?php } ?>
    </table>
</main>