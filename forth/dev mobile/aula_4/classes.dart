class Conta{
  
  String descricao;
  double valor;
  DateTime vencimento = DateTime.now();
  DateTime? pagamento;
  double jurosPorDia = 1.0;
  int get diasVencidos => pagamento!.difference(vencimento).inDays;
  // ao invés de precisar declarar getters e setters como em Java fazemos uma função anonima que 
  // o uso de exclamação em pagamento é porque colocamos ele como nullable, com isso, liberamos para o compilador a responsabilidade de saber se existe essa variavel
  // o get vem do C#
  //dentro da própria classe não precisa escrever passar os parametros dentro de um método
  
  
  
  double calcularValor(){
    if(pagamento != null && diasVencidos > 0){
      
      return valor * jurosPorDia / 100 * diasVencidos;
    }
    return valor;
  }
  void detalharConta(){
    print("Conta: $descricao - Valor: ${calcularValor() + valor}");
    print("Vencimento: ${vencimento.toLocal()}");
    print("Pagamento: ${pagamento == null ? "Não paga" : pagamento!.toLocal()}");
    print("Juros: $jurosPorDia - Valor original: $valor");
  }
  
  
  Conta(this.descricao, this.valor);
  
  
}

void main(){
  print("Hoje");
  var contaVen = Conta("Internet", 300);
  contaVen.vencimento=DateTime.parse("2025-08-23");
  contaVen.pagamento=DateTime.parse("2025-08-30");
  contaVen.detalharConta();
}