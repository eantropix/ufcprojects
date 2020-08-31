interface Figura {  
	abstract void desenhar();
	abstract void mover(double x, double y);
	abstract double calcularArea();
}

interface FiguraColorida extends Figura {
	
}


class Circulo extends Figura {
	private double pi = 3.1415;
	private double raio;

	Circulo(Ponto centro, double raio) { 		
		double x = centro.getEixo('x');
		double y = centro.getEixo('y');
		this.centro = new Ponto(x, y);
		this.raio = raio;
	}

	Circulo(double x, double y, double raio) {
		this.centro = new Ponto(x, y);
		this.raio = raio;
	}

	void desenhar() {
		toString();
	}

	void mover(double x, double y) {
		centro.moverDelta(x, y);
	}

	double calcularArea() {
		return pi * raio * raio;
	}
	@Override
	public String toString() {
		return String.format("-- Circulo --\nCentro - " + centro.toString() + "\nRaio - " + raio + "\nArea - " + calcularArea());
	}
}

class Quadrado extends Figura {
	private double lado;
	// private double[] vertices = new double[4];

	Quadrado(Ponto centro, double lado) {
		double x = centro.getEixo('x');
		double y = centro.getEixo('y');
		this.centro = new Ponto(x, y);
		this.lado = lado;
	}

	Quadrado(double x, double y, double lado) {
		this.centro = new Ponto(x, y);
		this.lado = lado;
	}

	void desenhar() {
		toString();
	}

	void mover(double x, double y) {
		centro.moverDelta(x, y);
	}

	double calcularArea() {
		return lado * lado;
	}

	@Override
	public String toString() {
		return String.format("-- Quadrado --\nCentro - " + centro.toString() + "\nLado - " + lado + "\nArea - " + calcularArea());
	}
}