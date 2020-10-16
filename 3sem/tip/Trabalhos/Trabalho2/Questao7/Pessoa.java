class Pessoa {
	String nome;
	int idade;

	Pessoa(String nome, int idade) {
		setNome(nome);
		setIdade(idade);
	}

	void setNome(String pnome) {
		nome = pnome;
	}

	String getNome() {
		return nome;
	}

	void setIdade(int pidade) {
		idade = pidade;
	}

	int getIdade() {
		return idade;
	}
}
