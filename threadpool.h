#ifndef __THREADPOOL__
#define __THREADPOOL__

#include <pthread.h>

typedef struct ThreadPool {
    pthread_t *threads;
    int num_threads;
} ThreadPool;

void threadpool_init(ThreadPool *tp, int num_threads);
void threadpool_destroy(ThreadPool *tp);
void threadpool_wait(ThreadPool *tp);

#endif
