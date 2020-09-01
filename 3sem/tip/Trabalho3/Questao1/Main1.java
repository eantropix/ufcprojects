class Main {
  public static void main(String[] args) {

	Ponto p1 = new Ponto(3, 5);
	Ponto p2 = new Ponto(6, 7.1);
	Ponto p3 = new Ponto(1, 1);
	Ponto p4 = new Ponto(-3, -2);

    Circulo c1 = new Circulo(p1, 4);
	Circulo c2 = new Circulo(1, 8, 2);

	Quadrado q1 = new Quadrado(p2, 3);
	Quadrado q2 = new Quadrado(1, 1, 6);

	System.out.println(c1.toString());
	System.out.println(q2.toString());
  }
}