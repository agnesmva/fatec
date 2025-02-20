/*
Fazer atividade de consumir api
*/

const api = "https://fakestoreapi.com/products"

const table = document.querySelector("table");

fetch(api).then((resposta) => resposta.json()).then((dados) => {
    const products = dados;
    return products.map((produto_item) => {
        const linha = document.createElement("tr");
        table.appendChild(linha);

        // imagem
        
        const imagem = document.createElement("td");
        imagem.innerHTML = `<img src="${produto_item.image}" alt="texto alternativo">`;
        linha.appendChild(imagem);

        // título
        const celula_nome = document.createElement("td");
        celula_nome.className = "negrito"
        celula_nome.innerHTML = produto_item.title;
        linha.appendChild(celula_nome);

        // Classificação (Estrelas)
        const celula_rate = document.createElement("td");
        celula_rate.className = "estrelas"
        const rating = Math.round(produto_item.rating.rate);

        if (rating == 5) {
            celula_rate.innerHTML = "⭐ ⭐ ⭐ ⭐ ⭐";
        } else if (rating == 4) {
            celula_rate.innerHTML = "⭐ ⭐ ⭐ ⭐";
        } else if (rating == 3) {
            celula_rate.innerHTML = "⭐ ⭐ ⭐";
        } else if (rating == 2) {
            celula_rate.innerHTML = "⭐ ⭐";
        } else if (rating == 1) {
            celula_rate.innerHTML = "⭐";
        } else {
            celula_rate.innerHTML = "Sem avaliação";
        }

        linha.appendChild(celula_rate);

        //descricao

        const celula_descricao = document.createElement("td");
        celula_descricao.innerHTML = produto_item.description;
        linha.appendChild(celula_descricao);

        // preço
        const celula_preco = document.createElement("td");
        celula_preco.innerHTML = produto_item.price;
        linha.appendChild(celula_preco);
        



    })

}).catch((erro) => {
    console.log(`Error ${erro}`);

})