import java.util.*;

class WordFrequency2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Insira uma frase: ");
		String sentence = input.nextLine();

		String[] splitwords = sentence.split("\\s+");
		HashMap<String, Integer> register = new HashMap<String, Integer>();
		// A estrutura do item anterior nos serve, e agora vamos guardar as chaves em um TreeSet para termos elas ordenadas
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

		for(String word : register_keys) {
            System.out.println(word + ": " + register.get(word));
        }
	}
}