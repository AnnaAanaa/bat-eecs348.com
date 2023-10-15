#include <stdio.h>

// Function to print possible combinations
void printCombinations(int score) {
    printf("Possible combinations of scoring plays:\n");
    for (int td1 = 0; td1 * 6 <= score; td1++) {
        for (int td2 = 0; td2 * 6 <= score; td2++) {
            for (int fg = 0; fg * 3 <= score; fg++) {
                for (int safety = 0; safety * 2 <= score; safety++) {
                    int total = (td1 * 6) + (td2 * 6) + (fg * 3) + (safety * 2);
                    if (total == score) {
                        printf("%d TD + %d TD + %d FG + %d Safety\n", td1, td2, fg, safety);
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Enter 0 or 1 to STOP\n");
            break;
        }

        printCombinations(score);
    }

    return 0;
}
