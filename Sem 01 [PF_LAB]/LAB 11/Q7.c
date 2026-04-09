#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_Courses 10

struct Course{
    char CourseID[10];
    char CourseName[50];
    char InstructorName[50];
    int Credits;
};
struct Department{
    char DepartmentName[50];
    struct Course Courses[MAX_Courses];
    int NumCourses;
};

void AddCourse(struct Department* department) {
    if (department->NumCourses < MAX_Courses) {
        printf("Enter course ID: ");
        scanf("%s", department->Courses[department->NumCourses].CourseID);
        
        printf("Enter course name: ");
        getchar();
        fgets(department->Courses[department->NumCourses].CourseName, 50, stdin);
        department->Courses[department->NumCourses].CourseName[strcspn(department->Courses[department->NumCourses].CourseName, "\n")] = '\0';
        
        printf("Enter instructor name: ");
        fgets(department->Courses[department->NumCourses].InstructorName, 50, stdin);
        department->Courses[department->NumCourses].InstructorName[strcspn(department->Courses[department->NumCourses].InstructorName, "\n")] = '\0';
       
        printf("Enter course Credits: ");
        scanf("%d", &department->Courses[department->NumCourses].Credits);
        department->NumCourses++;
        printf("Course added successfully!\n");
    } else {
        printf("Cannot add more Courses. Department is full!\n");
    }
}
void DisplayCourses(struct Department department) {
    printf("\nCourses in %s Department:\n", department.DepartmentName);
    for (int i = 0; i < department.NumCourses; i++) {
        printf("Course ID: %s\n", department.Courses[i].CourseID);
        printf("Course Name: %s\n", department.Courses[i].CourseName);
        printf("Instructor: %s\n", department.Courses[i].InstructorName);
        printf("Credits: %d\n\n", department.Courses[i].Credits);
    }
}
int CalculateTotalCredits(struct Department department) {
    int TotalCredits = 0;
    for (int i = 0; i < department.NumCourses; i++) {
        TotalCredits += department.Courses[i].Credits;
    }
    return TotalCredits;
}

void AddDepartment(struct Department* department) {
    printf("Enter department name: ");
    getchar();
    fgets(department->DepartmentName, 50, stdin);
    department->DepartmentName[strcspn(department->DepartmentName, "\n")] = '\0';
    department->NumCourses = 0;
    printf("Department added successfully!\n");
}

int main() {
    struct Department university[MAX_DEPARTMENTS];
    int NumDepartments = 0;
    int DepartmentIndex;
    int choice;

    while (1) {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add a Department\n");
        printf("2. Add a Course to a Department\n");
        printf("3. Display All Departments and Courses\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (NumDepartments < MAX_DEPARTMENTS) {
                    AddDepartment(&university[NumDepartments]);
                    NumDepartments++;
                } else {
                    printf("Maximum number of departments reached.\n");
                }
                break;
            case 2:
                printf("Enter department index (0 to %d): ", NumDepartments - 1);
                scanf("%d", &DepartmentIndex);
                if (DepartmentIndex >= 0 && DepartmentIndex < NumDepartments) {
                    AddCourse(&university[DepartmentIndex]);
                } else {
                    printf("Invalid department index.\n");
                }

            break;
            case 3:
                for (int i = 0; i < NumDepartments; i++) {
                    DisplayCourses(university[i]);
                }
                break;
            case 4:
                printf("\nEnter department index (0 to %d): ", NumDepartments - 1);
                scanf("%d", &DepartmentIndex);
                if (DepartmentIndex >= 0 && DepartmentIndex < NumDepartments) {
                    int TotalCredits = CalculateTotalCredits(university[DepartmentIndex]);
                    printf("Total Credits in %s Department: %d\n", university[DepartmentIndex].DepartmentName, TotalCredits);
                } else {
                    printf("Invalid department index.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
