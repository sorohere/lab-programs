// #include <stdio.h>

// int max(int a, int b) {
//     if (a > b) {
//         return a;
//     }
//     return b;
// }

// int main() {
//     int ans = max(1, 0) == 1;
//     printf("Result: %d\n", ans);
//     return 0;
// }



#include <stdio.h>

#define MAX_STUDENTS 3
#define MAX_SUBJECTS 4

void printGrade(char name[], int marks[]) {
    int sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += marks[i];
    }
    float avg = sum / (float)MAX_SUBJECTS;

    printf("Student: %s\n", name);
    printf("Average: %.2f\n", avg);

    if (avg >= 90) {
        printf("Grade: A\n");
    } else if (avg >= 75) {
        printf("Grade: B\n");
    } else if (avg >= 60) {
        printf("Grade: C\n");
    } else {
        printf("Grade: Fail\n");
    }

    printf("Status: %s\n\n", (avg >= 60) ? "PASS" : "FAIL");
}

int main() {
    char studentNames[MAX_STUDENTS][20] = {"Alice", "Bob", "Charlie"};
    int studentMarks[MAX_STUDENTS][MAX_SUBJECTS] = {
        {95, 92, 88, 91},   // Should get A
        {70, 68, 72, 75},   // Should get C
        {40, 50, 45, 38}    // Should Fail
    };

    // Currently only running one to demonstrate low coverage
    printGrade(studentNames[0], studentMarks[0]);

    // Uncomment these to improve coverage:
    // printGrade(studentNames[1], studentMarks[1]);
    // printGrade(studentNames[2], studentMarks[2]);

    return 0;
}
