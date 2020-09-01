class ContaPlus extends ContaBasic {
		ContaPlus(int id, double saldo) {
			super(id, saldo);
			setTipo(TipoConta.PLUS);
		}

		void creditar(double valor) {
			valor += 0.5 / 100 * valor;
			setSaldo(getSaldo() + valor);
		}
	}