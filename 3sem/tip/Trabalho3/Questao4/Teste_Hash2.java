import java.util.*;

class Teste_Hash2 {

    void listar(Set s) {
        Iterator i = s.iterator();
        while (i.hasNext()) {
            System.out.println(i.next());
        }
    }

    static void listar2(Collection c) {
        System.out.println("*** Listar 2 ***");
        for (Object o : c) {
            System.out.println(o);
        }
    }
}