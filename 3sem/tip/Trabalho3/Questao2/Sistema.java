import java.util.*;

class Sistema {
	ArrayList<Conta> banco = new ArrayList<Conta>();

	int nContas() {
		return banco.size();
	}

	void criarContaBasic(int id) {
		ContaBasic cb = new ContaBasic(id, 0);
		banco.add(cb);
	}

	void criarContaPlus(int id) {
		ContaPlus cp = new ContaPlus(id, 0);
		banco.add(cp);
	}

	void criarContaExtreme(int id) {
		ContaExtreme ce = new ContaExtreme(id, 0);
		banco.add(ce);
	}

	double consultarSaldo(int id) {
		return banco.get(id).getSaldo();
	}

	void creditar(int id, double valor) {
		banco.get(id).creditar(valor);
	}

	void debitar(int id, double valor) {
		banco.get(id).debitar(valor);
	}

	void mostrarConta(int id) {
		System.out.println(banco.get(id).toString());
	}
}	