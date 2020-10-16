import java.util.*;

class Teste_Hash {
    public static void main(String args[]) {
        Teste_Hash2 th2 = new Teste_Hash2();
        HashSet<String> mesesHash = new HashSet<>();
        TreeSet<String> mesesHash2 = new TreeSet<>();
        LinkedHashSet<String> mesesHash3 = new LinkedHashSet<>();

        mesesHash.add("Janeiro");
        mesesHash.add("Fevereiro");
        mesesHash.add("Março");
        mesesHash.add("Abril");
        mesesHash.add("Maio");
        mesesHash.add("Fevereiro");

        mesesHash2.add("Janeiro");
        mesesHash2.add("Fevereiro");
        mesesHash2.add("Março");
        mesesHash2.add("Abril");
        mesesHash2.add("Maio");
        mesesHash2.add("Fevereiro");

        mesesHash3.add("Janeiro");
        mesesHash3.add("Fevereiro");
        mesesHash3.add("Março");
        mesesHash3.add("Abril");
        mesesHash3.add("Maio");
        mesesHash3.add("Fevereiro");

        System.out.println("HashSet: ");
        th2.listar(mesesHash);
        th2.listar2(mesesHash);  // HashSet ordenou pelo hash
        th2.listar2(mesesHash2); // TreeSet ordenou alfabeticamente
        th2.listar2(mesesHash3); // LinkedHashSet ordenou pela ordem de inserção
        // System.out.println(mesesHash);
    }
}