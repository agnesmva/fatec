
// importando os modulos que 
const express = require("express");
const mongoose = require("mongoose");

// importando o produto.js, para o javascript entender onde está o arquivo é feito dessa forma, não coloca  extensão do arquivo

const Produto = require("./produto");

const app = express();
const porta = 3000;

// esse módulo possibilida que a API receba dados de POST ou PUT em JSON
// pois, por padrão a api recebe por formenconded
app.use(express.json())


//o endereço do servidor junto do nome do banco ("api") - esse nome pode ser mudado
//se o banco não existir será criado na primeira conexão
const URL_MONGODB = "mongodb://localhost:27017/api";

//iniciar conexão
mongoose.connect(URL_MONGODB);


//obtemos o objeto de acesso ao banco
const db = mongoose.connection;

// verificamos  se houve erro na conexão 
db.on("error", console.error.bind(console, "falha na conexão"));

// no caso de sucesso na conexão, aparece isso no console
db.once("open", () =>{
    console.log("Conectado com sucesso ao MongoDB");
});
//GET - Consulta de todos os produtos
app.get("/api/produtos", async (req, res) => {
    try{
        const produtos = await Produto.find();
        res.json(produtos);
    } catch(erro){
        res.status(500).json({"error" : erro});
    }
})

// POST
app.post("/api/produtos", async (req, res) =>{
    // criamos o novo objeto produto com baase nos dados enviados
    // no corpo da requsição 
    const novoProduto = new Produto(req.body)

    // fazemos um try/catch 
    try{
        const produtoIncluido = await novoProduto.save();
        res.json(produtoIncluido);
    
    }catch (erro){
        res.status(500).json({"error" : erro});
    }
});


app.listen(porta, () =>{
    console.log("Aguardando por conexões na porta" + porta);
})