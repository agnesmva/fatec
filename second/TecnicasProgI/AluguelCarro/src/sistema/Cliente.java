package sistema;

import java.util.LinkedList;

public class Cliente {
    private String nome;
    private int rg;
    private String email;
    private LinkedList<Aluguel> alugueis; 

    public Cliente(String n, int d, String e) {
        this.setNome(n);
        this.setRg(d);
        this.setEmail(e);
        this.alugueis = new LinkedList<>(); 
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getRg() {
        return rg;
    }

    public void setRg(int rg) {
        this.rg = rg;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public LinkedList<Aluguel> getAlugueis() {
        return alugueis;
    }
}