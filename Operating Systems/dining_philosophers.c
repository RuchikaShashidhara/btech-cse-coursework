#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct info {
    pthread_mutex_t *locks;
    int id;
    int n;
};

typedef struct info info_t;

void *run(void *inp) {

    info_t *info = (info_t *)inp;
    pthread_mutex_t *locks = info -> locks;
 
    int n = info -> n;   
    int id = info -> id;


    while (1) {
    
        printf("Philosopher %d is thinking\n", 1 + id);
        sleep(1);

        printf("Philosopher %d is Hungry\n", 1 + id);
        
        while (1) {
            pthread_mutex_lock(&(locks[id]));
            
            if (pthread_mutex_trylock(&(locks[(id + 1) % n])) == 0) 
                break;
            
            pthread_mutex_unlock(&(locks[id]));
            
            sleep(1);
        }
        
        printf("Philosopher %d takes fork %d and %d\n", id + 1, id + 1, (id + 1) % n + 1);

        printf("Philosopher %d is Eating\n", id + 1);
        sleep(1);
        
        printf("Philosopher %d putting fork %d and %d down\n", id + 1, id + 1, (id + 1) % n + 1);
        
        pthread_mutex_unlock(&(locks[id]));        
        pthread_mutex_unlock(&(locks[(id + 1) % n]));
    }
}

int main() {

    int n = 5;
    
    pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
    pthread_mutex_t *locks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
    
    for(int i = 0; i < n; ++i) 
        pthread_mutex_init(&locks[i], NULL);
        
    for(int i = 0; i < n; ++i) {
        info_t *info = (info_t *)malloc(sizeof(info_t));
        info->id = i;
        info->locks = locks;
        info->n = n;
        
        pthread_create(&threads[i], NULL, run, (void *)info);
    }
    
    for(int i = 0; i < n; ++i) 
        pthread_join(threads[i], NULL);

    return 0;
}
