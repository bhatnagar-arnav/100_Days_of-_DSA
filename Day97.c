/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start, end;
} Interval;

// Comparison for qsort (sort by start time)
int compare(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min-heap functions
void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        int temp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = temp;
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;
        int temp = heap[i]; heap[i] = heap[parent]; heap[parent] = temp;
        i = parent;
    }
}

int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(Interval), compare);

    int heap[n]; // store end times
    int size = 0;
    heap[size++] = intervals[0].end;

    for (int i = 1; i < n; i++) {
        // If earliest ending meeting finished, reuse room
        if (heap[0] <= intervals[i].start) {
            heap[0] = intervals[i].end;
            heapifyDown(heap, size, 0);
        } else {
            heap[size] = intervals[i].end;
            heapifyUp(heap, size);
            size++;
        }
    }
    return size;
}

int main() {
    int n;
    scanf("%d", &n);
    Interval intervals[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    printf("%d\n", minMeetingRooms(intervals, n));
    return 0;
}
