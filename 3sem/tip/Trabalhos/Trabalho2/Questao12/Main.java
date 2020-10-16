import java.util.*;

class Main {
	public static void main(String[] args) {
		ArrayList<Integer> naturais = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
		ArrayList<Integer> pares = new ArrayList<Integer>(Arrays.asList(2, 4, 6, 8, 10));
		ArrayList<Integer> impares = new ArrayList<Integer>(Arrays.asList(1, 3, 5 ,7, 9));
		ArrayList<Integer> primos = new ArrayList<Integer>(Arrays.asList(2, 3, 5, 7, 11));

		Conjunto c_naturais = new Conjunto(naturais); // Conjunto 1
		Conjunto c_pares = new Conjunto(pares); // Conjunto 2
		Conjunto c_impares = new Conjunto(impares); // Conjunto 3
		Conjunto c_primos = new Conjunto(primos); // Conjunto 4
		Conjunto c_vazio = new Conjunto(); // Conjunto 5

		System.out.println("Item a: " + c_naturais.ehSub(c_naturais));
		System.out.println("Item b: " + (c_pares.ehSub(c_naturais) && c_impares.ehSub(c_naturais) && c_primos.ehSub(c_naturais)));
		System.out.println("Item c: " + c_naturais.igualdade(c_pares.uniao(c_impares)));
		System.out.println("Item d: " + c_vazio.igualdade(c_naturais.intersecao(c_pares)));
		System.out.println("Item e: " + c_naturais.diferenca(c_pares).c);

	}
}
