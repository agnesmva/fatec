// Importando o módulo Express
const express = require("express");
const app = express(); // Criando uma instância do Express
const porta = 3000; // Definição da porta onde o servidor será executado


let produtos = [];
//inicializando uma lista vazia, é nela que iremos armazenar os json, como se fosse "nosso banco de dados"

//inicializa um objeto vazio
let produto1 = {};
produto1.id = 1;
produto1.nome = "Iphone Apple";
produto1.preco = 3134.70;
produto1.image = "/imagem.png";

// adicicionar o produto a lista
produtos.push(produto1); //push acrescenta na lista em js, pop retira


// criando um produto via json
let produto2 = {
    "id" : 2,
    "nome" : "Violão",
    "preco" : 389.00,
    "image" : "/violao.png"
};

produtos.push(produto2);


// outro método

produtos.push({"id":3,"nome":"suco de laranja", "preco":3.50, "image": "/caminho"});

// rotas

app.get("/", (req, res) => {
    res.json("Acesse a API em /api/produtos");
});


app.get("/api/produtos", (req, res) => {
    res.send(produtos);
});

// Inicializando o servidor e ouvindo na porta especificada
app.listen(porta, () => {
    console.log("Servidor rodando na porta: " + porta);
});