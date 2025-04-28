// importar as funções criadas em servico o crud import {}

import { criarUsuario, listarUsuarios, alterarUsuario, excluirUsuario} from "../servicos/usuarios.js";

export function rotasUsuarios(app){
    // GET - rota para obter todos os usuarios
    app.get("/api/usuarios", async (req, res) =>{
        return res.json(await listarUsuarios());
        
    });

    // get por id - rota para obter um usuário por id
    app.get("/api/usuarios/:id", async(req, res) =>{
        return res.json(await listarUsuarios({_id: req.params.id}));
    });

    //post incluir um usuario

    app.post("/api/usuarios", async (req, res) =>{
        try {
            const username = await listarUsuarios({"username" : req.body.username});

            //listar usuarios sempre retorna um vetor, com isso verifica se o vetor é maior que 0, significa que foi encontrado o username

            //no projeto final acho interessante capturar 
            if(username.lenght > 0){
                //
                return res.status(409).json({
                    error : "Usuario já Existente no Banco de Dados"
                })
            }
            const usuarioIncluido = await criarUsuario(req.body);
            return res.json(usuarioIncluido);
        } catch(erro){
            return res.status(500).json({"error" : erro});
        }
    })

    //falta o patch para fazer a alteração do usuário

    // deletar um usuário
    app.delete("/api/usuarios/:id", async (req, res) =>{
        try{
            const {deletedCount} = await excluirUsuario(req.params.id);
            if(deletedCount > 0){
                return res.json({"excluído" : true})
            }
            return res.json({"excluido" : false});
        } catch (erro){
            return res.status(500).json({"erro" : erro});
        }
    })
}
