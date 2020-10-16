import java.util.*;

class CountWords {
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
		
		String result = "Total de palavras: " + splitwords.length + "\nPalavras distintas: " + register.size();
		System.out.println(result);
	}
}