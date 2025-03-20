#include <stdio.h>
#include <omp.h>

typedef struct { int next, rank; } Node;

void parallel_list_ranking(Node* list, int N) {
    int changed = 1;
    while (changed) {
        changed = 0;
        #pragma omp parallel for
        for (int i = 0; i < N; i++)
            if (list[i].next != -1) {
                list[i].rank += list[list[i].next].rank;
                list[i].next = list[list[i].next].next;
                if (list[i].next != -1) changed = 1;
            }
    }
}

int main() {
    Node list[] = {{1,1}, {2,1}, {3,1}, {4,1}, {-1,1}}; // Example: A->B->C->D->E
    int N = 5;

    parallel_list_ranking(list, N);

    for (int i = 0; i < N; i++)
        printf("Node %d: Rank = %d\n", i, list[i].rank);
    return 0;
}
