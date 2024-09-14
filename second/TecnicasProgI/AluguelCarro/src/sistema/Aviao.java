package sistema;

public class Aviao extends Veiculo {

    private int numeroMotores; 

    public Aviao(int vd, String plc, int numeroMotores) {
        super(vd, plc);
        this.numeroMotores = numeroMotores;
    }

    public int getNumeroMotores() {
        return numeroMotores;
    }

    public void setNumeroMotores(int numeroMotores) {
        this.numeroMotores = numeroMotores;
    }
}