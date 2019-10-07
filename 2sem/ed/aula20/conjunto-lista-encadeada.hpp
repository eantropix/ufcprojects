#ifndef SET_LL_HPP
#define SET_LL_HPP
struct Set
{
    template <typename T>
    struct Node
    {
        T element; Node* prev, next;
    };
    struct Iterator
    {
        Node* p;
    };

    Iterator search_for (T e)
    {
        //Version 1
        /*
        Node *n = sent.next;
        for ( ; n != &sent; )
        {
            if (n->element == e) 
            {
                Iterator i; i.p = n;
                return i;
            }
        }
        return fim();
        */
    //Version 2
    Node *n = sent.next;
    sent.element = e;
    while (n->element != e) {n = n->next;}
    //if (n == &sent) {return fim();} -- This statement is not necessary, as both "i" and "fim()"
    //will return an iterator
    Iterator i; i.p = n; return i;
    }

    bool is_in (T e)
    {
        Iterator i = search_for(e);
        return (i.p != &sent); // If "e" was inside "sent", "e" was not in the set.
    }

    void finish()
    {
        Node *n = sent.prox;
        while (n != &sent)
        {
            Node *aux = n; // Auxiliar pointer gets (n)'s current node, so "n" can move on
            n = n->prox; 
            delete aux; //And node (now pointed by aux) can be deleted
        }

    }
};
#endif