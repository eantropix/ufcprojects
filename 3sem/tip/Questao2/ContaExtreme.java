class ContaExtreme extends ContaBasic {
	ContaExtreme(int id, double saldo) {
			super(id, saldo);
			setTipo(TipoConta.EXTREME);
		}

	void creditar(double valor) {
		valor += 0.2/100*valor;
		setSaldo(getSaldo() + valor);
	}

	void debitar(double valor) {
		valor -= 0.2/100*valor;
		setSaldo(getSaldo() - valor);
	}
}