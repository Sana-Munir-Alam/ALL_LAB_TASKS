#include <stdio.h>
//#include <stdlib.h>

#define MAX_VALUE 10001

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int frequency[MAX_VALUE] = {0};

        // Calculate the frequency of each number in the array
        for (int i = 0; i < N; i++) {
            frequency[A[i]]++;
        }

        // Find the smallest number with the highest frequency
        int maxFreq = 0;
        int result = MAX_VALUE;
        for (int i = 1; i < MAX_VALUE; i++) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
                result = i;
            } else if (frequency[i] == maxFreq && i < result) {
                result = i;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
