function calcular(){
    let medidas = document.getElementById("medidas").value;
    let inicial = parseFloat(document.getElementById("inicial").value);
    let resultado = document.getElementById("valorfinal");
    var resultadofinal;
    switch(medidas){
        case 'c_f':
            resultadofinal = (inicial * 1.8) + 32;
            break;
        case 'm_p':
            resultadofinal = inicial * 39.37;
            break;
        case 'q_l':
            resultadofinal = inicial * 2.2048; 
            break;
        case 'mc_l':
            resultadofinal = inicial * 1000;
            break;
        default:
            resultadofinal = 0;
    }
   


    resultado.innerText = "Valor convertido: " + resultadofinal.toFixed(2); 
}
