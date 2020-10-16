import java.util.*;

class Main {
	public static void main(String[] args) {
		ArrayList<Integer> pares = new ArrayList<Integer>(Arrays.asList(2, 4, 6, 8, 10));
		ArrayList<Integer> impares = new ArrayList<Integer>(Arrays.asList(1, 3, 5 ,7, 9));

		Conjunto a = new Conjunto(pares); // Conjunto A
		Conjunto b = new Conjunto(impares); // Conjunto B
		Conjunto u = new Conjunto(); // Conjunto U
		for (int i = 1; i <= 50; ++i) {
			u.inserir(Integer.valueOf(i));
		}
		// Operações básicas para facilitar a leitura
		Conjunto notA = u.diferenca(a);
		Conjunto notB = u.diferenca(b);
		Conjunto AuB = a.uniao(b);
		Conjunto AvB = a.intersecao(b);

		Conjunto not_AuB = u.diferenca(AuB);
		Conjunto notA_v_notB = notA.intersecao(notB);
		System.out.println("Lei de Morgan 1: " + not_AuB.igualdade(notA_v_notB));

		Conjunto not_AvB = u.diferenca(AvB);
		Conjunto notA_u_notB = notA.uniao(notB);
		System.out.println("Lei de Morgan 2: " + not_AvB.igualdade(notA_u_notB));

	}
}
