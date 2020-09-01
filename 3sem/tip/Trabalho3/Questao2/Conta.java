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