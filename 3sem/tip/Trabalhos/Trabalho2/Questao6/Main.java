class Main {
	public static void main (String[] args) {
		Pessoa p1 = new Pessoa();
		p1.setNome("Ana");
		Pessoa p2 = new Pessoa();
		p2.setNome("Joao");
		System.out.println("Nome1:"+p1.getNome());
		System.out.println(p2.getNome());

		p1.setIdade(30);
		p2.setIdade(21);

		System.out.println("Idade1:"+p1.getIdade());
		System.out.println(p2.getIdade());

	}
}
