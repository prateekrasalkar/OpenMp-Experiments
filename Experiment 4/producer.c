#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0, in = 0, out = 0;

void produce(int item) {
    #pragma omp critical
    {
        if (count < BUFFER_SIZE) {
            buffer[in] = item;
            in = (in + 1) % BUFFER_SIZE;
            count++;
            printf("Produced: %d\n", item);
        }
    }
}

void consume() {
    #pragma omp critical
    {
        if (count > 0) {
            int item = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            count--;
            printf("Consumed: %d\n", item);
        }
    }
}

int main() {
    int n = 1000000; 

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for (int i = 0; i < n; i++) {
                produce(i);
            }
        }

        #pragma omp section
        {
            for (int i = 0; i < n; i++) {
                consume();
            }
        }
    }
    return 0;
}

