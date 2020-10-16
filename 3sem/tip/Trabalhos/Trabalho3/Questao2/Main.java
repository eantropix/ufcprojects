class Main {

	public static void main(String[] args) {
		Sistema s = new Sistema();
		s.criarContaBasic(0);
		s.criarContaPlus(1);
		s.criarContaExtreme(2);

		for (int i = 0; i < s.nContas(); ++i) {
			s.creditar(i, 1000);
			s.debitar(i, 10);
		}

		// s.mostrarConta(0);
		// s.mostrarConta(1);
		// s.mostrarConta(2);

		System.out.println(s.consultarSaldo(0) == 990);
		System.out.println(s.consultarSaldo(1) == 995);
		System.out.println(s.consultarSaldo(2) == 992.02);
	}
}