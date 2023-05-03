#include "threadpool.h"
#include <stdlib.h>

void *worker_thread(void *arg) {
    pthread_exit(NULL);
}

void threadpool_init(ThreadPool *tp, int num_threads) {
    tp->num_threads = num_threads;
    tp->threads = malloc(num_threads * sizeof(pthread_t));

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&tp->threads[i], NULL, worker_thread, NULL);
    }
}

void threadpool_destroy(ThreadPool *tp) {
    for (int i = 0; i < tp->num_threads; i++) {
        pthread_join(tp->threads[i], NULL);
    }
    free(tp->threads);
}

void threadpool_wait(ThreadPool *tp) {
    for (int i = 0; i < tp->num_threads; i++) {
        pthread_join(tp->threads[i], NULL);
    }
}