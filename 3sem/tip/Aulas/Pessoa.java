class Main {
	public static void main (String[] args) {
		System.out.println("Hello world!");

		Pessoa p1;

		p1 = new Pessoa();

		p1.setNome("Ana");
		p1.setIdade(18);

		p1.mostrarPessoa();

	}
}

class Pessoa {
	private String nome;
	private int idade;

	void setNome (String nome) {
		this.nome = nome;	
	}

	void setIdade (int idade) {
		if (idade > 0 && idade < 120) {
			this.idade = idade;
		}
		else {
			this.idade = 1;
		}

	}

	void mostrarPessoa() {
		System.out.println("PESSOA: " + this.nome + " - " + this.idade);
	}
}
