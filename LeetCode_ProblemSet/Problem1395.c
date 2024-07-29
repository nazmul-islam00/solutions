#include <stdlib.h>

int getTeams(int** count, int countSize) {
    int teams = 0;

    for (int idx = 0; idx < countSize; idx++) {
        teams += count[idx][0] * count[idx][3];
        teams += count[idx][1] * count[idx][2];
    }

    return teams;
}

int** getCount(int* rating, int ratingSize) {
    int** count = (int**)malloc(ratingSize * sizeof(int*));
    for (int idx = 0; idx < ratingSize; idx++) {
        count[idx] = (int*)malloc(4 * sizeof(int));
    }

    for (int idx = 0; idx < ratingSize; idx++) {
        int cur = 0, lesser = 0, greater = 0;
        
        while (cur < idx) {
            if (rating[cur] < rating[idx]) {
                lesser++;
            } else {
                greater++;
            }
            cur++;
        }

        count[idx][0] = lesser, count[idx][1] = greater;
        lesser = 0, greater = 0;
        cur++;

        while (cur < ratingSize) {
            if (rating[cur] < rating[idx]) {
                lesser++;
            } else {
                greater++;
            }
            cur++;
        }

        count[idx][2] = lesser, count[idx][3] = greater;
    }

    return count;
}

int numTeams(int* rating, int ratingSize) {
    int** count = getCount(rating, ratingSize);
    return getTeams(count, ratingSize);
}
