class ContaBasic extends Conta {
	ContaBasic(int id, double saldo) {
		setId(id);
		setTipo(TipoConta.BASIC);
		setSaldo(saldo);
	}

	void setId(int id) {
		this.id = id;
	}

	int getId() {
		return this.id;
	}

	void setTipo(TipoConta tipo) {
		this.tipo = tipo;
	}

	TipoConta getTipo() {
		return this.tipo;
	}

	void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	double getSaldo() {
		return saldo;
	}

	void creditar(double valor) {
		setSaldo(getSaldo() + valor);
	}

	void debitar(double valor) {
		setSaldo(getSaldo() - valor);
	}

	@Override
	public String toString() {
		return ("= Banco Técnico =" + "\n-- Informações da Conta --" + "\nID: " + id + "\nTipo: " + tipo + "\nSaldo: "
				+ saldo);
	}
}