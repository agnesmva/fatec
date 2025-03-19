// Importando o módulo Express
const express = require("express");
const app = express(); // Criando uma instância do Express
const porta = 3000; // Definição da porta onde o servidor será executado

// é necessário fazer esse "import" para conseguir receber dados em json
app.use(express.json())

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
    res.send("Acesse a API em /api/produtos");
});


app.get("/api/produtos", (req, res) => {
    res.json(produtos);
});

//Get na rota /api/produtos específico por ID
app.get("/api/produtos/:id", (req, res) => {

    //buscamos dentro da lista produtos[] utilizando o método find do próprio javascript, poderiamos percorrer com um for ou fazer outra forma de busca
    // é procurado o id que seja igual ao id passado no endereço do GET
    // se for encontrado será copiado para a constante "produto"
    const produto = produtos.find((elemento) => elemento.id == parseInt(req.params.id));

    //se o produto for encontrado, retornamos ela com o codigo de status 200
    if(produto){
        res.status(200).json(produto);
    }else{
        res.status(404).json({"error" : "produto inexistente"});
    }
}) 


//Post fazendo a inclusão
app.post("/api/produtos", (req, res) =>{
    // precisamos adicionar um middlewhere - adicionar o suporte para dar suporte a json, pois pelo padrão é form-encoded
    //form-encoded é quando se envia o formulário via post possui a mesma sintaxe da query string

    let novoProduto = {
        "id": req.body.id,
        "nome": req.body.nome,
        "preco": req.body.preco,
        "image": req.body.image
    };
    //body é o corpo da requisição 

    //aqui para adicionar a lista
    produtos.push(novoProduto);

    //retornamos como reposta o codigo http 201 (Created) junto dos dados do produto
    res.status(201).json(novoProduto);

});


// fazendo um delete

app.delete("api/produtos/:id", (req, res) =>{
    // em javascript para remoção de uma lista é necessário usar o index para remover utilizando a função splice
    const indice = produtos.findIndex((elemento) => elemento.id == parseInt(req.params.id));

    //se ele n
    if(indice < 0){
        res.status(404).json({"erro": "o indice do elemento não foi encontrado, logo ele não existe dentro da lista"});
    }else{
        // remove os elemento de acordo com o parametro passado, a partir do indice dado
        // por exemplo eu quero remover o produto do indice 2 e apenas esse produto
        //produtos.splice(2, 1)
        //se eu quiser excluir os cinco próximos produtos a partir do 2 passo dessa forma
        //produtos.splice(2, 5) 
        produtos.splice(indice, 1);
        res.status(200).json({"Mensagem" : "Produto excluído com sucesso"});
    }
})

//PUT altera os dados do produto - alterando todos os dados

app.put("/api/produtos/:id", (req, res) =>{
    // em javascript para remoção de uma lista é necessário usar o index para alteracao utilizando a função splice
    const indice = produtos.findIndex((elemento) => elemento.id == parseInt(req.params.id));

    //se ele n
    if(indice < 0){
        res.status(404).json({"erro": "o indice do elemento não foi encontrado, logo ele não existe dentro da lista"});
    }else{
        //produto encontrado
        //
        const produtoAlterado = {
            "id": req.body.id,
            "nome": req.body.nome,
            "preco": req.body.preco,
            "image": req.body.image
        }
    }
    //alteramos o produto com base no indice, o inde recebe o json do produto alterado
    produtos[indice] = produtoAlterado
    
    res.status(200).json({"mensagem":"produto alterado"});
});

// Inicializando o servidor e ouvindo na porta especificada
app.listen(porta, () => {
    console.log("Servidor rodando na porta: " + porta);
});