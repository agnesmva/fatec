const mongoose = require("mongoose");

//aqui tá sendo criado um novo Schema - o esquema é um esqueleto do banco de dados, 
const produtoSchema = new mongoose.Schema({
    nome:{
        type: String,
        require : true
    },
    preco:{
        type: Number,
        require: true
    },
    descricao:{
        type: String,
        require: false //não há necessidade de colocar, mas coloquei pra legibilidade
    },
    create_at:{
        type: Date,
        default: Date.now
    }


});

// Criando uma classe baseada no esquema, e ela vai ser criada como "Produto"
// Em javascript a convenção é falar "protótipo" ao invés de classe
const Produto = mongoose.model("Produto", produtoSchema);

// é necessário exportar Produto para ele ser utilizado por outros arquivos
module.exports = Produto;