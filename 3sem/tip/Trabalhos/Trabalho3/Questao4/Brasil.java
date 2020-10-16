import java.util.*;

class Brasil {

    public static void main(String[] args) {
        HashMap<String, String> brasil = new HashMap<>();
        brasil.put("SP", "São Paulo");
        brasil.put("CE", "Ceará");
        brasil.put("MG", "Minas Gerais");
        brasil.put("PR", "Curitiba");
        brasil.put("RR", "Roraima");

        if(brasil.containsKey(args[0])) {
            System.out.println(args[0] + " -> " + brasil.get(args[0]));
        }
    }
}