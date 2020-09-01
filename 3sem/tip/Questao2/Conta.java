// import Conta.TipoConta;

public abstract class Conta {
	protected enum TipoConta {
		BASIC, PLUS, EXTREME
	};

	protected TipoConta tipo;
	protected int id;
	protected double saldo;

	abstract void setId(int id);

	abstract int getId();

	abstract void setTipo(TipoConta tipo);

	abstract TipoConta getTipo();

	abstract void setSaldo(double saldo);

	abstract double getSaldo();

	abstract void creditar(double valor);

	abstract void debitar(double valor);
}

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
}
