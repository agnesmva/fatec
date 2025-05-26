import { useState } from "react";

export default function BotaoCurtidor() {
    const [curtidas, setCurtidas] = useState(0); // é necessário iniciar a variável como useState, o parametro que é passado 

    function incrementarCurtidas() {
        setCurtidas(curtidas + 1);
    }

    return (
        <>
            <button type="button" onClick={incrementarCurtidas}>
            ❤️ {curtidas}
            </button>
        </>
    );
}
