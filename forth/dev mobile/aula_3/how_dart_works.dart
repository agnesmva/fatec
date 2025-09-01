void testFuncao(String nome, {int? idade, int? peso}) {
  if (idade != null && peso != null) {
    print("$nome e minha idade é $idade e meu peso é $peso");
  } else {
    print("Meu nome $nome");
  }
}

void main() {
  testFuncao("Agnes", peso: 79, idade: 24);
  testFuncao("Maria", idade: 30);
  testFuncao("João", peso: 70, idade:40);
  testFuncao("Carlos");
}

// dart é uma linguagem Null Safety 
// Null safety is a programming language feature that ensures variables can't hold null values unless explicitly allowed