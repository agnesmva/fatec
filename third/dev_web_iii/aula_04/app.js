// Importando o módulo Express
const express = require("express");
const app = express(); // Criando uma instância do Express
const porta = 3000; // Definição da porta onde o servidor será executado

/*
 Definição de uma rota GET para a raiz ("/")
req = requisição (request) | res = resposta (response)
a ordem dos parametros não podem ser mudada;

Quando um usuário acessar a rota "/", a API responderá com "Acessando a API"
*/
app.get("/", (req, res) => {
    res.send("Acessando a API");
});

// Inicializando o servidor e ouvindo na porta especificada
app.listen(porta, () => {
    console.log("Servidor rodando na porta: " + porta);
});

/*
 * Informações importantes sobre serialização e desserialização de JSON

Exemplo de uma string JSON válida (representando um objeto em formato textual)
let alunoString = '{"ra":1234567, "nome":"Agnes"}';

// Exemplo de um objeto JavaScript
let alunoObjeto = {
    "ra": 12345, // Identificador do aluno
    "nome": "Agnes" // Nome do aluno
};

Convertendo a string JSON para um objeto JavaScript

var alunoStringConvertidoToObject = JSON.parse(alunoString);
// O método JSON.parse() transforma uma string JSON válida em um objeto JavaScript

// Convertendo um objeto JavaScript para uma string JSON

var alunoObjetoConvertidoToString = JSON.stringify(alunoObjeto);
// O método JSON.stringify() transforma um objeto JavaScript em uma string JSON

// O sufixo "-ify" significa transformar algo em outra coisa, como:
// - simplify (simplificar)
// - beautify (embelezar)

 */
