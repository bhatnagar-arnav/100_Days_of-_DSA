/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Comparison for qsort (sort by position descending)
int compare(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleets(int target, Car cars[], int n) {
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = -1.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
        // else merges into previous fleet
    }
    return fleets;
}

int main() {
    int n, target;
    scanf("%d %d", &target, &n);

    Car cars[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].pos);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    printf("%d\n", carFleets(target, cars, n));
    return 0;
}
