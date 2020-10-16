class Main {
	public static void main (String[] args) {
		Pessoa p1 = new Pessoa("Ana", 30);
		Pessoa p2 = new Pessoa("Joao", 21);
		System.out.println(p1.getNome());
		System.out.println(p2.getNome());

		System.out.println(p1.getIdade());
		System.out.println(p2.getIdade());

	}
}
