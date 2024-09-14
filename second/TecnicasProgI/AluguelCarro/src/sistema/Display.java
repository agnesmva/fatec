package sistema;

import java.util.Scanner;

public class Display {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SistemaAluguel sistema = new SistemaAluguel();

        int op = 1; 
        while (op != 0) {
            System.out.println("\nEscolha uma opção:");
            System.out.println("1. Cadastrar Cliente");
            System.out.println("2. Alugar Veículo");
            System.out.println("3. Devolver Veículo");
            System.out.println("4. Listar Veículos Disponíveis");
            System.out.println("0. Sair");
            op = scanner.nextInt();
            scanner.nextLine(); 
            switch (op) {
                case 1:
                    sistema.cadastrarCliente(scanner);
                    break;
                case 2:
                    sistema.realizarAluguel(scanner);
                    break;
                case 3:
                    sistema.devolverVeiculo(scanner);
                    break;
                case 4:
                    sistema.listarVeiculosDisponiveis();
                    break;
                case 0:
                    System.out.println("Saindo do sistema...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente");
            }
        }

        scanner.close();
    }
}