const express = require("express");
const app = express();

const porta = 3000;

app.get("/", (req, res) => {
    res.send("Acesse os recursos da API em /api/recursos")
})
//aqui tem um método get, para solicitação de uma requisição, seja, get/post/delete
// o método send() envia uma resposta

app.get("/api/alunos", (req, res) => {

    //res.send("Aqui você está fazendo um GET no recurso alunos");
    res.json(
        {
            "ra": 10002,
            "nome": "Agnes",
            "curso": "DSM"
            //aqui é um objeto que vai ser convertido e mandado para o usuário da requisição 

            //para manipular objetos temos os métodos json.parse(STRING) e json.stringfy(OBJETO)
            //esse procedimento chama-se serialização mandar como objeto -> string
            //o processo de desserialização é mandar como string -> objeto
            // -> significa converter, seria um "to"
        }
    );
});

app.post("/api/alunos", (req, res) => {
    res.send("Você fez um POST em api/aluno");
    //aqui também é necessário a gente o status code, que são os codigos de status como 200, 201, 404
});

app.put("/api/alunos", (req, res) => {
    res.send("Você fez um PUT em /api/alunos");
});

app.delete("/api/alunos", (req, res) => {
    res.send("Você fez um DELTE em /api/alunos");
});

app.listen(porta, () =>{
    console.log("Aguardando por conexões na porta: " + porta);
});