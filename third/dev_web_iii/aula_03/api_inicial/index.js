const express = require("express");
const app = express();

/* PARA GERAR CONTEÚDO HTML DINÂMICO:
   Use uma view engine ou template engine!
   As mais populares são:
   1. EJS (Embedded JavaScript)
   2. Pug (Jade)
   3. Handlebars

   Instale a ejs com:
   npm install ejs
*/

// definimos a ejs como nossa "view engine"
app.set("view engine", "ejs");
// definimos uma pasta onde ficarão os templates (view)
app.set("views", "./views");

// Middleware do express: classe ou função que atua entre a requisição
// a resposta.
// Acrescentamos o middleware que disponibiliza conteúdo estático
// diretamente de uma pasta/diretório do servidor.
app.use(express.static("public"));

// criamos um JSON com três produtos como se tivessem vindo do banco
let produtos = [
    {
        "nome": "Impressora HP Deskjet",
        "preco": "R$ 299,90"
    },
    {
        "nome": "Notebook Lenovo",
        "preco": "R$ 2590,90"
    },
    {
        "nome": "Pen Drive 64 GB",
        "preco": "R$ 39,90"
    },
    {
        "nome": "Tablet Samsung Galaxy",
        "preco": "R$ 1999,90"
    }
];

// rota para visualizar a página dinâmica (template ou view)
// de produtos
app.get("/produtos", (requisicao, resposta) => {
    resposta.render("produtos", {"produtos": produtos});
});

// rota para mensagem de teste
app.get("/hello", (requisicao, resposta) => {
    resposta.send("Teste 123");
});

// acesse no navegador com: localhost:3000/api/aluno
app.get("/api/aluno", (requisicao, resposta) => {
    resposta.json(
        {
            "ra": 1234, 
            "nome": "Querino", 
            "curso": "DMS"
        }
    );
});

app.listen(3000, () => {
    console.log("Aguardando por conexões na porta 3000...");
});