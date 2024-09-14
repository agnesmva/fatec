package sistema;

public class Carro extends Veiculo {

    private int portas;

    public Carro(int vd, String plc, int portas) {
        super(vd, plc);
        this.portas = portas;
    }

    public int getPortas() {
        return portas;
    }

    public void setPortas(int portas) {
        this.portas = portas;
    }
}