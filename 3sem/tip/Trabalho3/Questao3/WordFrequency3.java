import java.util.*;

class WordFrequency3 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Insira uma frase: ");
		String sentence = input.nextLine();

		String[] splitwords = sentence.split("\\s+");
		HashMap<String, Integer> register = new HashMap<String, Integer>();
		TreeSet<String> register_keys = new TreeSet<String>();

		for (int i = 0; i < splitwords.length; ++i) {
			String word = splitwords[i];
			if (register.containsKey(word)) {
				register.replace(word, register.get(word) + 1);
			}
			else {
				register.put(word, 1);
				register_keys.add(word);
			}
		}
		// A estrutura do item anterior nos serve, o que devemos mudar é passar as chaves na ordem inversa
		for(String word : register_keys.descendingSet()) {
            System.out.println(word + ": " + register.get(word));
        }
	}
}