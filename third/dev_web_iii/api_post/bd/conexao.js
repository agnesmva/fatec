import mongoose from "mongoose";
const mg = mongoose;

const serve = "mongodb";
const port = "27017"
const dataBase = "post"

//exportando a funcao de conexão com o banco
export function conectarBanco(){

    const urlBanco = `${serve}:${port}/${dataBase}`;
    
    mg.connection.on("open", () =>{
        console.log("Conectado ao Banco com Sucesso");
    });
}