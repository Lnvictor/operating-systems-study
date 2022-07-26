#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int cmp(const void *x, const void *y)
{
    int *xa = (int *)x;
    int *ya = (int *)y;

    if (*xa == *ya)
        return 0;
    if (*xa > *ya)
        return 1;
    if (*xa < *ya)
        return -1;
}


int main(){
    int pid = getpid();
    printf("Ola, eu sou o pid %d, vou começar a ordenar os inteirosn\n", pid);    


    FILE *file;
    file = fopen("integers.txt", "r");
    int buf;
    int int_arr[20];

    int counter = 0;
    while (fscanf(file, "%d", &buf) != EOF){
        int_arr[counter++] = buf;
    }
    
    qsort(int_arr, 20, sizeof(int), cmp);
    fclose(file);

    file = fopen("integers.txt", "w");

    for (int i = 0; i < 20; i++)
        fprintf(file, "%d\n", int_arr[i]);

    fclose(file);

    return 0;
}
