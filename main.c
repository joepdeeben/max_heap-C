#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 struct Heapnode {
    int val;

    struct Heapnode *l;
    struct Heapnode *r;
    struct Heapnode *p;

};
void bubble_sort(int *arr, int size){
    int placeholder;


    for (int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if (arr[j + 1] < arr[j]){
                placeholder = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = placeholder;
            }
        }
    }
}


void create_maxheap(int *list, int size){
    bubble_sort(list, size);

    // allocate mem to store array with pointers to structs
    struct Heapnode **arr = (struct Heapnode **)malloc(sizeof(struct Heapnode *) * size);

    for (int i = 0; i < size; i++) {
        // allocate mem to store structs and store the pointer in the previous mem
        struct Heapnode *n = (struct Heapnode *)malloc(sizeof(struct Heapnode));
        n -> val = list[i];
        arr[i] = n;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] -> p = arr[(i-1) / 2];
        arr[i] -> l = arr[2 * i + 1];
        arr[i] -> r = arr[2 * i + 2];

    }

//    printf("%p", arr[0] -> l);
    printf("%d\n", (arr[0] -> l) -> val);
}

void heap_insert(){


}


int main(void) {

    int arr[5] = {-3, 5, -1, 0, -2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    create_maxheap(arr, arr_size);

    for (int i =0; i < arr_size; i++){
        printf("%d\n", arr[i]);

    }

    return 0;


}

