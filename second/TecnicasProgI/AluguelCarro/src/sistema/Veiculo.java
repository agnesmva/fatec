package sistema;

public class Veiculo {

	private int valorDiaria;
	private String placa;
	
	public Veiculo(int vd, String plc) {
		this.setValorDiaria(vd);
		this.setPlaca(plc);
	}

	public String getPlaca() {
		return placa;
	}

	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public int getValorDiaria() {
		return valorDiaria;
	}

	public void setValorDiaria(int valorDiaria) {
		this.valorDiaria = valorDiaria;
	}
		
		
}


