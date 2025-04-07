class NotificationInterface:
    def send(self, message):
        """Método para enviar uma mensagem."""
        pass

class EmailService:
    def send_email(self, subject, body):
        """Método específico para enviar emails."""
        print(f"Enviando email - Assunto: {subject}, Corpo: {body}")

class EmailAdapter(NotificationInterface):
    def __init__(self, email_service):
        self.email_service = email_service

    def send(self, message):
        """Adapta a interface da NotificationInterface para a interface do EmailService."""
        subject = "Você tem uma nova notificação"
        self.email_service.send_email(subject, message)

# Criando uma instância do serviço de email
email_service = EmailService()

# Criando o adapter para o serviço de email
email_adapter = EmailAdapter(email_service)

# Agora, podemos usar o adapter para enviar mensagens
email_adapter.send("Olá! Esta é uma notificação de teste.")
