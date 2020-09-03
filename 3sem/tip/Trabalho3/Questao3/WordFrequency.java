import java.util.*;

class WordFrequency {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Insira uma frase: ");
		String sentence = input.nextLine();

		String[] splitwords = sentence.split("\\s+");
		HashMap<String, Integer> register = new HashMap<String, Integer>();

		for (int i = 0; i < splitwords.length; ++i) {
			String word = splitwords[i];
			if (register.containsKey(word)) {
				register.replace(word, register.get(word) + 1);
			}
			else {
				register.put(word, 1);
			}
		}
		// A estrutura do item anterior já nos serve, o que deve mudar é o que vamos mostrar ao usuário
		register.forEach((word, count) -> {
			System.out.print(word + ": ");
			System.out.println(count);
		});
	}
}