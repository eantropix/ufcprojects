class Casamento {
	Pessoa a, b;
	String data;
	int numeroDocumento;
	
	Casamento (Pessoa p1, Pessoa p2) {
		if (!p1.ehCasado() && !p2.ehCasado() && p1 != p2) {
			this.a = p1;
			this.b = p2;
			p1.setCasamento(this);
			p2.setCasamento(this);	
		}

			
		
}
