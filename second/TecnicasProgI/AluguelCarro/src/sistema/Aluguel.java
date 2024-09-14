package sistema;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Aluguel {

    private Cliente cliente;
    private Veiculo veiculo;
    private LocalDate dataInicio;
    private LocalDate dataFim;

    public Aluguel(Cliente cliente, Veiculo veiculo, LocalDate dataInicio) {
        this.cliente = cliente;
        this.veiculo = veiculo;
        this.dataInicio = dataInicio;
        this.dataFim = null; 
    }

    public void encerrarAluguel(LocalDate dataFim) {
        this.dataFim = dataFim;
    }

    public long calcularDiasAlugados() {
        if (dataFim == null) {
            return 0;
        }
        return ChronoUnit.DAYS.between(dataInicio, dataFim);
    }

    public double calcularValorTotal() {
        long dias = calcularDiasAlugados();
        return dias * veiculo.getValorDiaria();
    }

    public Cliente getCliente() {
        return cliente;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public LocalDate getDataInicio() {
        return dataInicio;
    }

    public LocalDate getDataFim() {
        return dataFim;
    }
}