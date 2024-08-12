#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* prefixProduct = (int*)malloc(numsSize * sizeof(int));
    int* suffixProduct = (int*)malloc(numsSize * sizeof(int));
    int* answer = (int*)malloc(numsSize * sizeof(int));
    prefixProduct[0] = 1, suffixProduct[numsSize - 1] = 1;

    for (int i = 1; i < numsSize; i++) {
        prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
    }

    for (int i = numsSize - 2; i > -1; i--) {
        suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefixProduct[i] * suffixProduct[i];
    }

    *returnSize = numsSize;
    free(prefixProduct);
    free(suffixProduct);
    return answer;
}