class Pessoa {
	String nome;
	int idade;

	Pessoa(String nome, int idade) {
		setNome(nome);
		setIdade(idade);
	}

	void setNome(String pnome) {
		this.nome = pnome;
	}

	String getNome() {
		return nome;
	}

	void setIdade(int pidade) {
		this.idade = pidade;
	}

	int getIdade() {
		return idade;
	}
	
	public String toString() {
		return "NOME: " + nome + ", IDADE: " + idade;
	}
}
