#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int dir[], int n) {
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT)
            printf("<-%d ", perm[i]);
        else
            printf("%d-> ", perm[i]);
    }
    printf("\n");
}

int getMobile(int perm[], int dir[], int n) {
    int mobile = -1, index = -1;

    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i > 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                index = i;
            }
        }
        if (dir[i] == RIGHT && i < n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                index = i;
            }
        }
    }
    return index;
}

void johnsonTrotter(int n) {
    int perm[n], dir[n];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, dir, n);

    while (1) {
        int mobileIndex = getMobile(perm, dir, n);

        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];
        printf("Swap %d and %d\n", perm[mobileIndex], perm[swapIndex]);

        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;
        int mobileValue = perm[mobileIndex];

        for (int i = 0; i < n; i++) {
            if (perm[i] > mobileValue)
                dir[i] = -dir[i];
        }

        printPermutation(perm, dir, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}

