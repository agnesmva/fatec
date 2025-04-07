import { conectarBanco } from "./bd/conexao.js";
import { Usuario} from "./models/usuarios.js";
import { Postagem } from "./models/postagem.js";

async function testar() {
    await conectarBanco();

    const novoUsuario = new Usuario({
        username : "teste",
        email : "teste@email.com",
        password : "0101",
        name : "Teste Nome", 
    });

    const usuario = await novoUsuario.save();


    const PostagemTeste = new Postagem({
            title : "nova postagem",
            conten : "conteudo",
            author : usuario,
            likes : Number,
            tags : [String],
    })
};

testar()