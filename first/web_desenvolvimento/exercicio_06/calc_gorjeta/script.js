function calcularGorjeta(){
    let vconta = parseFloat(document.getElementById("valorconta").value);
    let pgorjeta = parseFloat(document.getElementById("valorgorjeta").value);
    let resultado = document.getElementById("valorfinal");
    resultadofinal = ((vconta * pgorjeta) / 100) + vconta;
   
   resultado.innerText = "Valor a ser pago: " + resultadofinal.toFixed(2); //toFixed equivale ao %.2f do C
}
