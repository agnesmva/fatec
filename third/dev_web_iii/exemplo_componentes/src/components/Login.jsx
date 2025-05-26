import { useState } from "react";

export default function Login(){
    const [nome, setNome] = useState("");
    const [mensagem, setMensagem] = useState("Faça seu login");

    function logar(){
        setMensagem("Seja bem vinde " + nome + "!!")
    }

    return(
        <>
            <form action="">
                <label htmlFor="">Nome</label>
                <input type="text" value={nome} onChange={evento => (setNome(evento.target.value))} />
                <button type="button" onClick={logar}>Entrar</button>
            </form>
            <p>{mensagem}</p>
        </>
    )
}