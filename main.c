#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


 struct Heapnode {
    int val;

    struct Heapnode *l;
    struct Heapnode *r;
    struct Heapnode *p;

};

void heapify(struct Heapnode **heaplist, int *size) {
    int temp;
    float bound = floor((float) *size / 2);
    for (int i = bound; i >= 0; i--) {
        if (((*(heaplist + i))->l) != NULL  && ((*(heaplist + i))->val < (*(heaplist + i))->l->val) ) {
            temp = (*(heaplist + i))->val;
            (*(heaplist + i))->val = (*(heaplist + i))->l->val;
            (*(heaplist + i))->l->val = temp;

        }
        if (((*(heaplist + i))->r) != NULL  && ((*(heaplist + i))->val < (*(heaplist + i))->r->val)) {
            temp = (*(heaplist + i))->val;
            (*(heaplist + i))->val = (*(heaplist + i))->r->val;
            (*(heaplist + i))->r->val = temp;
        }

    }
}

struct Heapnode** create_maxheap(int *list, int *size){

    // allocate mem to store array with pointers to structs
    struct Heapnode **arr = (struct Heapnode **)malloc(sizeof(struct Heapnode *) * *size);

    for (int i = 0; i < *size; i++) {
        // allocate mem to store structs and store the pointer in the previous mem
        struct Heapnode *n = (struct Heapnode *)malloc(sizeof(struct Heapnode));
        n -> val = list[i];
        arr[i] = n;
    }

    for (int i = 0; i < *size; i++) {
        if (i != 0) {
        arr[i] -> p = arr[(i - 1) / 2];
    } else {
            arr[i] -> p = NULL;
    }
    if ((2 * i + 2) < *size) {
        arr[i] -> r = arr[2 * i + 2];
    } else {
        arr[i] -> r = NULL;
    }
    if ((2*i + 1) < *size) {
        arr[i] -> l = arr[2 * i + 1];

    } else {
        arr[i] -> l = NULL;
    }

    }
    heapify(arr, size);

    return arr;
}

struct Heapnode **heap_insert(struct Heapnode **arr, int *size, struct Heapnode *node) {
    struct Heapnode **temp = (struct Heapnode **)realloc(arr, sizeof(struct Heapnode *) * (*size + 1));
    if (temp == NULL) {
        printf("Reallocation failed.\n");
        free(arr);
        return arr; //
    } else {
        arr = temp;
        arr[*size] = node;
        int bound = (int)(ceil((float)*size / 2) - 1);
        if (arr[bound]->l == NULL) {
            node->p = arr[bound];
            arr[bound]->l = node;
        } else if (arr[bound]->r == NULL) {
            node->p = arr[bound];
            arr[bound]->r = node;
        }
        *size = *size + 1;
        heapify(arr, size);
        return arr;
    }
}
void heap_pop(){


}


int main(void) {
    int arr[6] = {15, 10, 8, 5, 3, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int *size = &arr_size;

    printf("Initial array size: %d\n", arr_size);

    // Create the max-heap
    struct Heapnode **node_arr = create_maxheap(arr, size);

    printf("\nInitial heap:\n");
    for (int i = 0; i < *size; i++) {
        if (node_arr[i]->p != NULL) {
            printf("Node: %d, Parent: %d\n", node_arr[i]->val, node_arr[i]->p->val);
        } else {
            printf("Node: %d, Parent: NULL (root)\n", node_arr[i]->val);
        }
    }

    // Insertions
    struct Heapnode node1 = {20, NULL, NULL, NULL};
    struct Heapnode node2 = {9, NULL, NULL, NULL};
    struct Heapnode node3 = {1, NULL, NULL, NULL};

    node_arr = heap_insert(node_arr, size, &node1);
    node_arr = heap_insert(node_arr, size, &node2);
    node_arr = heap_insert(node_arr, size, &node3);

    printf("\nHeap after insertions:\n");
    for (int i = 0; i < *size; i++) {
        if (node_arr[i]->p != NULL) {
            printf("Node: %d, Parent: %d\n", node_arr[i]->val, node_arr[i]->p->val);
        } else {
            printf("Node: %d, Parent: NULL (root)\n", node_arr[i]->val);
        }
    }

    // Cleanup
    for (int i = 0; i < *size; i++) {
        free(node_arr[i]);
    }
    free(node_arr);

    return 0;
}

