#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/threadpool.h"

void example_task(void* arg) {
    int* num = (int*)arg;
    printf("Processing task %d\n", *num);
    sleep(1);
}

int main() {
    threadpool_t pool;
    threadpool_init(&pool);

    for (int i = 0; i < 15; i++) {
        int* task_num = malloc(sizeof(int));
        *task_num = i;
        threadpool_add_task(&pool, example_task, task_num);
    }

    sleep(5);

    threadpool_destroy(&pool);

    return 0;
}
