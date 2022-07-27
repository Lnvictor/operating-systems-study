/**
 * Create an array and stores it in a file
 * Then creates another proccess to ordering and
 * print it in a file
 */
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[]){
    int retval = fork();
    srand(time(NULL));
    FILE *file;
    int pid = getpid();

    if (retval == 0){
        wait(5);
        execve("./integer_sorter", NULL, NULL);
        perror("Erro");
    }
    
    printf("Ola, eu sou o pid: %d. Estou inserindo os inteiros no arquivo...", pid);    

    file = fopen("integers.txt", "w");
    
    for (int i = 0; i < 20; i++){
        int r = rand();
        fprintf(file, "%d\n", r);
    }
    fclose(file);
    return 0;
}
