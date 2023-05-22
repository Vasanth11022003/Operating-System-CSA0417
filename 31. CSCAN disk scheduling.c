#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

void cscan(int tracks[], int n, int start) {
    int i, j, total_head_movement = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tracks[i] > tracks[j]) {
                int temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }


    int start_index = 0;
    for (i = 0; i < n; i++) {
        if (tracks[i] >= start) {
            start_index = i;
            break;
        }
    }

    for (i = start_index; i < n; i++) {
        printf("%d ", tracks[i]);
        total_head_movement += abs(tracks[i] - start);
        start = tracks[i];
    }
    if (start_index > 0) {
        printf("%d ", tracks[0]);
        total_head_movement += abs(tracks[0] - start);
        start = tracks[0];
    }

    printf("\n");

    double average_head_movement = (double)total_head_movement / n;
    printf("Average head movement: %.2lf\n", average_head_movement);
}

int main() {
    int tracks[MAX_TRACKS];
    int n, start;
    int i;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the track positions:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter the starting position: ");
    scanf("%d", &start);

    printf("Order of track positions visited:\n");
    cscan(tracks, n, start);

    return 0;
}

