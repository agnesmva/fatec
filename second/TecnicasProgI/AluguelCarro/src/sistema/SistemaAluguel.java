package sistema;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.LinkedList;
import java.util.Scanner;

public class SistemaAluguel {
    private LinkedList<Veiculo> veiculosDisponiveis = new LinkedList<>();
    private LinkedList<Cliente> clientes = new LinkedList<>();

    public SistemaAluguel() {
        
        veiculosDisponiveis.add(new Carro(250, "ABC-1234", 4));
        veiculosDisponiveis.add(new Moto(150, "XYZ-5678", true));
        veiculosDisponiveis.add(new Aviao(8000, "JKS-6789", 2));
        
        clientes.add(new Cliente("Agnes Maria", 870741, "agnesmorganav@gmail.com"));
        clientes.add(new Cliente("Rafaela Santos", 745162, "thithi@gmail.com"));
        clientes.add(new Cliente("Priscila Senna", 745162, "rainhadoBrega@gmail.com"));
    }
   
    public void cadastrarCliente(Scanner scanner) {
        System.out.println("Cadastro de Cliente:");
        System.out.print("Nome: ");
        String nome = scanner.nextLine();

        System.out.print("RG: ");
        int rg = scanner.nextInt();
        scanner.nextLine(); 

        System.out.print("Email: ");
        String email = scanner.nextLine();

        Cliente cliente = new Cliente(nome, rg, email);
        clientes.add(cliente);
        System.out.println("Cliente cadastrado com sucesso.");
    }

    public void realizarAluguel(Scanner scanner) {
        if (clientes.isEmpty()) {
            System.out.println("Não há clientes cadastrados.");
            return;
        }

        if (veiculosDisponiveis.isEmpty()) {
            System.out.println("Não há veículos disponíveis para aluguel.");
            return;
        }

        System.out.println("Selecione o cliente pelo número:");
        for (int i = 0; i < clientes.size(); i++) {
            System.out.println(i + ": " + clientes.get(i).getNome());
        }

        int indiceCliente = scanner.nextInt();
        if (indiceCliente < 0 || indiceCliente >= clientes.size()) {
            System.out.println("Índice inválido. Tente novamente.");
            return;
        }
        Cliente cliente = clientes.get(indiceCliente);

        System.out.println("Selecione o veículo para aluguel pelo número:");
        for (int i = 0; i < veiculosDisponiveis.size(); i++) {
            System.out.println(i + ": " + veiculosDisponiveis.get(i).getPlaca());
        }

        int indiceVeiculo = scanner.nextInt();
        if (indiceVeiculo < 0 || indiceVeiculo >= veiculosDisponiveis.size()) {
            System.out.println("Índice inválido. Tente novamente.");
            return;
        }
        Veiculo veiculo = veiculosDisponiveis.get(indiceVeiculo);

        scanner.nextLine(); 
        System.out.print("Data de início do aluguel (dd/MM/yyyy): ");
        String dataInicioStr = scanner.nextLine();
        LocalDate dataInicio = LocalDate.parse(dataInicioStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

        Aluguel aluguel = new Aluguel(cliente, veiculo, dataInicio);
        cliente.getAlugueis().add(aluguel); 
        veiculosDisponiveis.remove(indiceVeiculo);

        System.out.println("Veículo alugado com sucesso.");
    }
    
    public void devolverVeiculo(Scanner scanner) {
        System.out.println("Selecione o cliente pelo número:");
        for (int i = 0; i < clientes.size(); i++) {
            System.out.println(i + ": " + clientes.get(i).getNome());
        }
        int indiceCliente = scanner.nextInt();
        Cliente cliente = clientes.get(indiceCliente);

        LinkedList<Aluguel> alugueis = cliente.getAlugueis();
        if (alugueis.isEmpty()) {
            System.out.println("Este cliente não possui veículos alugados.");
            return;
        }

        System.out.println("Selecione o aluguel a ser encerrado:");
        for (int i = 0; i < alugueis.size(); i++) {
            System.out.println(i + ": Veículo " + alugueis.get(i).getVeiculo().getPlaca());
        }
        int indiceAluguel = scanner.nextInt();
        Aluguel aluguel = alugueis.get(indiceAluguel);

        scanner.nextLine(); 
        System.out.print("Data de devolução do veículo (dd/MM/yyyy): ");
        String dataFimStr = scanner.nextLine();
        LocalDate dataFim = LocalDate.parse(dataFimStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

        aluguel.encerrarAluguel(dataFim);
        veiculosDisponiveis.add(aluguel.getVeiculo());

        System.out.println("Valor total do aluguel: R$ " + aluguel.calcularValorTotal());
        System.out.println("Veículo devolvido com sucesso.");
    }

    public void listarVeiculosDisponiveis() {
        System.out.println("Veículos disponíveis:");
        for (Veiculo veiculo : veiculosDisponiveis) {
            System.out.println(veiculo.getPlaca() + " - Diária: R$ " + veiculo.getValorDiaria());
        }
    }
}