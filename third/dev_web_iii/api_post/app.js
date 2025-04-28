import express from "express";
import { conectarBanco } from "./bd/conexao.js";
import { rotasUsuarios } from "./rotas/usuarios.js"; 


const app = express();

app.use(express.json());

app.get("/", (req, res =>{
    res.send("Acesse a API em /api/nome_recurso");
}))

try{
    await conectarBanco();
    const PORTA = 3000;
    app.listen(PORTA)
    console.log("Aguardando conexões na porta " + PORTA);
} catch(erro){
    console.log("Erro: " + erro);
}

//exportamos o objeto app para poder criar rotas em outros arquivos

export { app }

rotasUsuarios(app);