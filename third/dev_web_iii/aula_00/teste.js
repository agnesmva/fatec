// adicionar biblioteca http do node 
// usando a função de declaração do do node

const { createServer } = require("node:http");
// o require é uma função do JS adiciona um módulo, biblioteca, pacote, etc. Tipo o include do C ou PHP; chamar a função de forma mais simples de modo mais econômico. 

// precisamos confirgurar em variáveis as portas, host
const hostName = "localhost"; //nome ou domínio da aplicação web ou site
const porta = 3000; //deve ser maior que 1024 para segurança, portas menores são controladas na internet, para um servidor é utilizada a 80 (sem certificado / http) ou 443 (certificado / https)


//criamos o nosso servidor e definimos uma função de CALLBACK que será executada sempre que houver uma conexão
//a função de callback é configurada o objeto de uma requisição e o objeto de uma resposta


const serve = createServer((requisicao, resposta) => {
    resposta.statusCode = 200; //indica que a conexão está Ok e pronta
    resposta.setHeader("Content-Type", "text/plain; charset=UTF-8"); //indicar uma resposta como texto puro
    resposta.end("Olá, mundo"); //termina a resposta mandando o valor em parâmetro


});

// começamos a receber conexões 
serve.listen(porta, hostName, () => {
    console.log(`Aguardando por conexões em http://${hostName}:${porta}`); 
    //console log funciona no navegador, aparece no F12 
    // pode ser utilizado  crases para inserir direto `Aguardando por conexões em http://${hostName}:${porta}`
})

/*

    a função callback é chamada posteriomente a leitura do script
    
*/ 