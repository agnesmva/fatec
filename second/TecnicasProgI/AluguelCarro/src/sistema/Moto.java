package sistema;

public class Moto extends Veiculo {

    private boolean temBau;

    public Moto(int vd, String plc, boolean tB) {
        super(vd, plc);
        this.temBau = tB;
    }

    public boolean isTemBauleto() {
        return temBau;
    }

    public void setTemBauleto(boolean tB) {
        this.temBau = tB;
    }
}