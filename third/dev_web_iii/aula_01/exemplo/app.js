// api do tipo Rest
/**
 * 
 Formulário pode ser do tipo POST ou GET
 HTTP metodos:
 put and delete
 get = para pegar/ler
 post = enviar
 put = update
 delete = apagar no servidor

 recurso no servidor web
 com o passar do tempo os metodos do http é equivalente ao CRUD - Create, Read, Update and Delete

 antigamente tinhamos o padrão SOAP Simple Open  (sabão) - criado na virada dos anos 1990  - 2000, criado pela microsoft
 utilizava xml


 o termo api é antiga e significa "qualquer grupo de recursos que seja acessável"
 significa Application Programing Interface

 - por exemplo, uma biblioteca que você usa localmente


 fetch é uma função que do tipo callback
 fetch significa pegar no contexto de você falar "Pega" para um cachorro

 -
 
 - pega a resposta e usa o metodo json() que cria o objetivo e depois (.then) pega os dados da api 

 - pessoas é uma lista/vetor dos objetos obitidos 

 - .map() do javascript faz algo parecido com o for each do php

 - é importante colocar um tratamento de erros um try catch é importante ser utilizado
 */

const api = "https://randomuser.me/api/"; //caminho da api

const table = document.querySelector("table");

fetch(api).then((resposta) => resposta.json()).then((dados) => {
    const pessoas = dados.results;
    return pessoas.map((uma_pessoa) => {
        const linha = document.createElement("tr");
        table.appendChild(linha);

        const celula_foto = document.createElement("tr");
        celula_foto = `<img src= '${uma_pessoa.picture.medium}'> alt='texto alternativo'`;
        linha.appendChild(celula_foto);

        const celula_nome = document.createElement("tr");
        celula_nome.innerHTML = uma_pessoa.name.first + " " + uma_pessoa.name.last;
        linha.appendChild(celula_nome);

        const celula_cidade = document.createElement("tr");
        celula_cidade.innerHTML = uma_pessoa.location.city;
        linha.appendChild(celula_cidade);

        const celula_pais = document.createElement("tr");
        cidade_pais.innerHTML = uma_pessoa.location.country;
        linha.appendChild(celula_cidade);

    })

}).catch((erro) => {
    console.log(`Error ${erro}`);

})