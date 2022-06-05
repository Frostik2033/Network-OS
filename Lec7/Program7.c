#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>


void* thread_func (void*); //потоковая функция

int main (int argc, char *argv[], char *envp[]) {
    pthread_t thread; //дескриптор потока
    //создание нового потока и вызова потоковой функции
    if (pthread_create(&thread,NULL,thread_func,NULL)) return EXIT_FAILURE;
    for (unsigned int i = 0; i < 20; i++) {
        puts("a");
    }
    //ожидание завершения потока
    if (pthread_join(thread,NULL)) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

//реализация потоковой функции
void* thread_func (void* vptr_args) {
    for (unsigned int i = 0; i < 20; i++) {
        fputs("b\n",stderr);
        void wait_thread();
    }
    return NULL;
}
