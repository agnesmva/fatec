// criar funcoes cruds para o usuário

import { Usuario } from '../models/usuario.js';

//função para criação de um usuário
export async function criarUsuario({userName, email, senha, nome}) {
    const usuario = new Usuario({
        userName,
        email,
        senha,
        nome
    });
    return await usuario.save();
}

//funcao para listar usuarios em ordem decrescente pela data de criação
export async function listarUsuarios(query = {}, {sortBy = 'criado', sortOrder = 'desc'} = {}) {

    return await Usuario.find(query).sort( { [sortBy]: sortOrder} );
}

//funcao para alterar o usuario com base no id passado
export async function alterarUsuario(userId, {username, email, senha, nome}) {
    return await Usuario.findOneAndUpdate(
        {_id: userId},
        { $set: {username, email, senha, nome} },
        { new: true }
    );
}

//funcao para buscar e excluir o usuario com base no id fornecido
export async function excluirUsuario(userId) {
    return await Usuario.findByIdAndDelete({_id: userId});
}