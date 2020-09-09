import java.util.*;

class Conjunto {
	ArrayList<int> c = new ArrayList<>();

	Conjunto() {
		ArrayList<int> d = new Arraylist<>();
		this.c = d;
	}

	Conjunto(ArrayList<int> d) {
		this.c = d;
	}

	void inserir(int n) {
		this.c.add(n);
	}
	boolean pertence(int n) {
		return this.c.contains(n);
	}

	boolean ehSub(Conjunto d) {
		for (int i : this.c) {
			if (!d.pertence(i) {
				return false;
			}
		}
		return true;
	}
	// Retorna o Conjunto C v D
	Conjunto uniao(Conjunto d) {
		Conjunto un = new Conjunto()
		for (i : this.c) {
			u.inserir(i);
		}
		for (int i : d) {
			if (!u.pertence(i)) {
				u.inserir(i);
			}
		}
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
}
