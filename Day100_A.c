#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int* idx, int* temp, int* res, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (nums[idx[j]] < nums[idx[i]]) {
            temp[k++] = idx[j++];
            rightCount++;
        } else {
            res[idx[i]] += rightCount;
            temp[k++] = idx[i++];
        }
    }

    while (i <= mid) {
        res[idx[i]] += rightCount;
        temp[k++] = idx[i++];
    }

    while (j <= right) {
        temp[k++] = idx[j++];
    }

    for (i = left; i <= right; i++) {
        idx[i] = temp[i];
    }
}

void mergeSort(int* nums, int* idx, int* temp, int* res, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, idx, temp, res, left, mid);
    mergeSort(nums, idx, temp, res, mid + 1, right);
    merge(nums, idx, temp, res, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)calloc(numsSize, sizeof(int));
    int* idx = (int*)malloc(sizeof(int) * numsSize);
    int* temp = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++)
        idx[i] = i;

    mergeSort(nums, idx, temp, res, 0, numsSize - 1);

    free(idx);
    free(temp);

    *returnSize = numsSize;
    return res;
}
