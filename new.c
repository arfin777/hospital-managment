#include <stdio.h>

int main() {
    char name[50];
    float math, english, science;
    float total, average;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter Math marks: ");
    scanf("%f", &math);

    printf("Enter English marks: ");
    scanf("%f", &english);

    printf("Enter Science marks: ");
    scanf("%f", &science);

    total = math + english + science;
    average = total / 3;

    printf("\n--- Student Result ---\n");
    printf("Name: %s\n", name);
    printf("Total Marks: %.2f\n", total);
    printf("Average: %.2f\n", average);

    if (average >= 80) {
        printf("Grade: A+\n");
    }
    else if (average >= 70) {
        printf("Grade: A\n");
    }
    else if (average >= 60) {
        printf("Grade: B\n");
    }
    else if (average >= 50) {
        printf("Grade: C\n");
    }
    else if (average >= 40) {
        printf("Grade: D\n");
    }
    else {
        printf("Grade: F\n");
    }

    return 0;
}