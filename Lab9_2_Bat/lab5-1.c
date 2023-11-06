#include <stdio.h>

#define NUM_MONTHS 12

// Function to calculate the average of sales
float calculateAverage(float sales[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sales[i];
    }
    return sum / n;
}

// Function to find the minimum and maximum sales
void findMinAndMaxSales(float sales[], char* monthNames[], int n, float* minSales, char** minMonth, float* maxSales, char** maxMonth) {
    *minSales = sales[0];
    *maxSales = sales[0];
    *minMonth = monthNames[0];
    *maxMonth = monthNames[0];

    for (int i = 1; i < n; i++) {
        if (sales[i] < *minSales) {
            *minSales = sales[i];
            *minMonth = monthNames[i];
        }
        if (sales[i] > *maxSales) {
            *maxSales = sales[i];
            *maxMonth = monthNames[i];
        }
    }
}

// Function to calculate the six-month moving averages
void calculateMovingAverages(float sales[], float movingAverages[], int n) {
    for (int i = 0; i <= n - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        movingAverages[i] = sum / 6;
    }
}

// Function to sort sales in descending order
void sortSales(float sales[], char* monthNames[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sales[i] < sales[j]) {
                float tempSales = sales[i];
                char* tempMonth = monthNames[i];

                sales[i] = sales[j];
                monthNames[i] = monthNames[j];

                sales[j] = tempSales;
                monthNames[j] = tempMonth;
            }
        }
    }
}

int main() {
    char* monthNames[NUM_MONTHS] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    float sales[NUM_MONTHS];
    float minSales, maxSales, avgSales;
    float movingAverages[NUM_MONTHS - 5];

    // Read sales from the input file
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("Plase enter sales data (%i/12): ", i+1);
        if (scanf("%f", &sales[i]) != 1) {
            printf("Error reading sales data.\n");
            return 1;
        }
    }

    // Generate and print the sales report
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s $%.2f\n", monthNames[i], sales[i]);
    }

    // Find minimum and maximum sales
    char* minMonth;
    char* maxMonth;
    findMinAndMaxSales(sales, monthNames, NUM_MONTHS, &minSales, &minMonth, &maxSales, &maxMonth);

    // Calculate average sales
    avgSales = calculateAverage(sales, NUM_MONTHS);

    // Print the sales summary
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, minMonth);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, maxMonth);
    printf("Average sales: $%.2f\n", avgSales);

    // Calculate and print the six-month moving average report
    calculateMovingAverages(sales, movingAverages, NUM_MONTHS);
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        printf("%s - %s $%.2f\n", monthNames[i], monthNames[i + 5], movingAverages[i]);
    }

    // Sort and print the sales report in descending order
    sortSales(sales, monthNames, NUM_MONTHS);
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s $%.2f\n", monthNames[i], sales[i]);
    }

    return 0;
}