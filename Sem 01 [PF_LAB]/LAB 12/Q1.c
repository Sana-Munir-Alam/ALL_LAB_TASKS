#include <stdio.h>
#include <stdlib.h>

int main() {
    int NumStudents, NumGrades;
    int **Grades;

    printf("Enter the number of students: ");
    scanf("%d", &NumStudents);

    Grades = (int **)malloc(NumStudents * sizeof(int *));
    if (Grades == NULL) {
        printf("Memory allocation failed for students.\n");
        return 1;
    }

    for (int i = 0; i < NumStudents; i++) {
        printf("Enter the number of Grades for student %d: ", i + 1);
        scanf("%d", &NumGrades);
        Grades[i] = (int *)malloc(NumGrades * sizeof(int));
        if (Grades[i] == NULL) {
            printf("Memory allocation failed for Grades of student %d.\n", i + 1);
            return 1;
        }
        printf("Enter the Grades for student %d: \n", i + 1);
        for (int j = 0; j < NumGrades; j++) {
            printf("Grade %d: ", j+1);
            scanf("%d", &Grades[i][j]);
        }
    }

    printf("\n--------------------------------\n");
    printf("\nGrades entered for each student:\n");
    for (int i = 0; i < NumStudents; i++) {
        printf("Student %d Grades: ", i + 1);
        for (int j = 0; j < NumGrades; j++) {
            printf("%d ", Grades[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < NumStudents; i++) {
        free(Grades[i]);
    }
    free(Grades);
    return 0;
}
