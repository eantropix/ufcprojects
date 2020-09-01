public class Ponto {
	double x;
	double y;

	Ponto(double x, double y) {
		this.x = x;
		this.y = y;
	}

	// Sobrescreve as coordenadas atuais do ponto
	void mover(double x, double y) {
		this.x = x;
		this.y = y;
	}
	//Incrementa ou decrementa os valores das coordenadas 
	void moverDelta(double x, double y) {
		this.x += x;
		this.y += y;
	}
	//Retorna o valor do eixo x ou y
	double getEixo(char eixo) {
		if (eixo == 'x' || eixo == 'X') {
			return this.x;
		}

		else if (eixo == 'y' || eixo == 'Y') {
			return this.y;
		}
		else {return 0;}
	}
	public String toString() {
		return "X: " + this.x + " Y: " + this.y;
	}
}