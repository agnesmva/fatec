var mostrarHoras = document.getElementById("horas");
var mostrarMinutos = document.getElementById("minutos");
var mostrarSegundos = document.getElementById("segundos");
var correndo = false; //precisa criar essa variavel boleana pois ao clicar varias vezes no botao ele chama a função IniciarCronometro()
var Horas = 0;
var Minutos = 0;
var Segundos = 0;
var intervalo;

function atualizarDisplay() {
    mostrarHoras.innerHTML = Horas.toString().padStart(2, '0');
    mostrarMinutos.innerHTML = Minutos.toString().padStart(2, '0');
    mostrarSegundos.innerHTML = Segundos.toString().padStart(2, '0');
}

function iniciarCronometro() {           
    if (!correndo){
        correndo = true;
        intervalo = setInterval(function() {
            Segundos++;
            if (Segundos >= 60) {
                Segundos = 0;
                Minutos++;
            }
            if (Minutos >= 60) {
                Minutos = 0;
                Horas++;
            }
            atualizarDisplay();
        }, 1000);
    }
    
}

function pararCronometro() {
    clearInterval(intervalo);
    correndo = false;
}

function zerarCronometro() {
    pararCronometro();
    Horas = 0;
    Minutos = 0;
    Segundos = 0;
    atualizarDisplay();
}

atualizarDisplay();
