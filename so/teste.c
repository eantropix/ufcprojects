#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int quantum = 0;
int thread_atual = 0;

void *count(void *arg)
{
    int nthr = *(int*)arg;

    for (int i = 0; i < 1000; i++)
    {   
        *s += i;
        printf("%d: %d\n", nthr, i);
    }
    
    return (void*)s;
}

int main()
{
    pthread_t tid[2];
    int nthread[2] = {0, 1};

    pthread_create(&tid[0], NULL, count, &nthread[0]);
    pthread_create(&tid[1], NULL, count, &nthread[1]);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;

}