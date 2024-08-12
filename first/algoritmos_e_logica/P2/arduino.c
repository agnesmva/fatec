// C++ code
//
const int ledMenor =13;
const int ledVerm = 2;
float tempo = 0;
int estado = 0; //0 apagado, 1 acesso;
void setup()//configurar a placa
{
	pinMode(ledVerm,OUTPUT);
}

void loop()//função para ser executada enquanto o arduino está ligado
{
  if ((estado == 0)&& (tempo >= 1000))
  {
	digitalWrite(ledVerm,HIGH);
    estado = 1;
    tempo = 0;
  }
  else if ((estado == 1) && (tempo >= 1000))
  {
     digitalWrite(ledVerm,LOW);
     estado = 0;
     tempo = 0;
  }
  tempo += 0.05;
}

//led é um atuador, ou seja, ele mostra para o mundo externo.
//blink é o "hello world!" do arduino
//o led tem uma limitação de corrente para que assim, e ele precisa de um resistor.
//delay é bloqueante
//

/* codigo mais otimizado
void loop()//função para ser executada enquanto o arduino está ligado
{
  if ((estado == 0)&& (tempo >= 1000))
  {
	digitalWrite(ledVerm,!estado);
    estado = !estado;
    tempo = 0;
  }
  tempo += 0.05;
} 