const express = require("express");
const app = express();
const PORT = 3000;

function gerarNumerosMegaSena() {
    const numeros = []
    while (numeros.lenght < 6) {
        const numero = Math.random() * 60 + 1;
        numeros.push(numero);
    }

    return numeros.sort();
}

app.get("/api/megasena", (req, res) => {
    const numerosSorteados = gerarNumerosMegaSena();
    res.json({ numeros: numerosSorteados });
});

app.listen(PORT, () => {
    console.log(`Servidor rodando em http://localhost:${PORT}`);
});
