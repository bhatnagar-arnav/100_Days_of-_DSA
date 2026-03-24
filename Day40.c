/*Implement Heap Sort using a Max Heap to sort an array in ascending order. 
First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/

#include <stdio.h>
static inline void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void sift_down(int *arr, int i, int n) {
    while (1) {
        int largest = i;
        int l = 2 * i + 1;   
        int r = 2 * i + 2;   

        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest == i) break;

        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

static void build_max_heap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        sift_down(arr, i, n);
}

static void sort_phase(int *arr, int n) {
    for (int end = n - 1; end > 0; end--) {
        swap(&arr[0], &arr[end]);   
        sift_down(arr, 0, end);     
    }
}

void heap_sort(int *arr, int n) {
    if (n < 2) return;
    build_max_heap(arr, n);   
    sort_phase(arr, n);       
}

static void print_array(const char *label, const int *arr, int n) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++)
        printf("%d%s", arr[i], i < n - 1 ? " " : "\n");
}
int main(void) {
    int arr[] = {40, 10, 30, 5, 20, 25, 15};
    int n = sizeof arr / sizeof arr[0];

    print_array("Before", arr, n);
    heap_sort(arr, n);
    print_array("After ", arr, n);
    return 0;
}