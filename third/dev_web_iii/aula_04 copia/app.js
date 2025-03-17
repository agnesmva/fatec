// Importando o módulo Express
const express = require("express");
const app = express(); // Criando uma instância do Express
const porta = 3000; // Definição da porta onde o servidor será executado


let produtos = []
//inicializando uma lista vazia




//inicializa um objeto vazio
let produto1 = {};
produto1.id = 1;
produto1.nome = "Iphone Apple";
produto1.preco = 3134.70;
produto1.image = "/imagem.png";

// adicicionar o produto a lista
produtos.push(produto1) //push acrescenta na lista em js, pop retira


// criando um produto via json
let produto2 = {
    "id" : 2,
    "nome" : "Violão",
    "preco" : 389.00,
    "image" : "/violao.png"
}

produtos.push(produto2)

app.get("/", (req, res) => {
    res.send("Acessando a API em /api/produtos");
});

// Inicializando o servidor e ouvindo na porta especificada
app.listen(porta, () => {
    console.log("Servidor rodando na porta: " + porta);
});