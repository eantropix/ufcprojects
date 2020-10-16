import java.util.*;

class Conjunto {
	ArrayList<Integer> c = new ArrayList<>();

	Conjunto() {
		ArrayList<Integer> d = new ArrayList<>();
		this.c = d;
	}

	Conjunto(ArrayList<Integer> d) {
		this.c = d;
	}

	void inserir(int n) {
		this.c.add(Integer.valueOf(n));
	}
	boolean pertence(int n) {
		return this.c.contains(n);
	}

	boolean ehSub(Conjunto d) {
		for (int i : this.c) {
			if (!d.pertence(i)) {
				return false;
			}
		}
		return true;
	}
	// Retorna o Conjunto C v D
	Conjunto uniao(Conjunto d) {
		Conjunto un = new Conjunto();
		for (int i : this.c) {
			un.inserir(i);
		}
		for (int i : d.c) {
			if (!(un.pertence(i))) {
				un.inserir(i);
			}
		}
		return un;
	}
	// Retorna o Conjunto C ^ D
	Conjunto intersecao(Conjunto d) {
		Conjunto in = new Conjunto();
		for (int i : this.c) {
			if (d.pertence(i)) {
				in.inserir(i);
			}
		}
		return in;
	}
	// Retorna o Conjunto C - D
	Conjunto diferenca(Conjunto d) {
		Conjunto dif = new Conjunto();
		for (int i : this.c) {
			if (!d.pertence(i)) {
				dif.inserir(i);
			}
		}
		return dif;
	}
	// Retorna se C = D
	boolean igualdade(Conjunto d) {
		return (this.ehSub(d) && d.ehSub(this));
	}
}
