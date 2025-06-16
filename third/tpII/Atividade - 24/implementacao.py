from abc import ABC, abstractmethod

# 1. Interface de Estratégia
class PaymentStrategy(ABC):
    @abstractmethod
    def process_payment(self, amount):
        pass

# 2. Estratégias Concretas

class CreditCardPayment(PaymentStrategy):
    def process_payment(self, amount):
        print(f"💳 Processando pagamento de R${amount:.2f} com Cartão de Crédito... Pagamento aprovado!")

class PayPalPayment(PaymentStrategy):
    def process_payment(self, amount):
        print(f"💻 Processando pagamento de R${amount:.2f} via PayPal... Pagamento confirmado!")

class PIXPayment(PaymentStrategy):
    def process_payment(self, amount):
        print(f"📱 Processando pagamento de R${amount:.2f} via PIX... Pagamento efetuado com sucesso!")

# 3. Contexto
class PaymentProcessor:
    def __init__(self):
        self._strategy = None

    def set_strategy(self, strategy: PaymentStrategy):
        self._strategy = strategy

    def pay(self, amount):
        if self._strategy is None:
            print("⚠️ Nenhuma estratégia de pagamento foi definida.")
        else:
            self._strategy.process_payment(amount)

# 4. Simulação do uso do sistema
if __name__ == "__main__":
    processor = PaymentProcessor()

    print("=== Pagamento com Cartão de Crédito ===")
    processor.set_strategy(CreditCardPayment())
    processor.pay(150.00)

    print("\n=== Pagamento com PayPal ===")
    processor.set_strategy(PayPalPayment())
    processor.pay(75.50)

    print("\n=== Pagamento com PIX ===")
    processor.set_strategy(PIXPayment())
    processor.pay(23.90)
