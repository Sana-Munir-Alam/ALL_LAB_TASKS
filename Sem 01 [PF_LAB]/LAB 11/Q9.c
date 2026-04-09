#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 5
#define MAX_STUDENTS 10

struct Student {
    int studentID;
    char name[100];
    int age;
};

struct Instructor {
    int instructorID;
    char name[100];
    char department[50];
};

struct Course {
    int courseID;
    char courseName[100];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS]; 
    int numStudents;
};


struct Department {
    int departmentID;
    char departmentName[100];
    struct Course courses[MAX_COURSES];
    int numCourses;
};

void addDepartment(struct Department* department) {
    printf("Enter Department ID: ");
    scanf("%d", &department->departmentID);
    getchar();
    
    printf("Enter Department Name: ");
    fgets(department->departmentName, sizeof(department->departmentName), stdin);
    department->departmentName[strcspn(department->departmentName, "\n")] = '\0';
    department->numCourses = 0;
}

void addCourse(struct Department* department) {
    if (department->numCourses >= MAX_COURSES) {
        printf("Max number of courses reached for this department.\n");
        return;
    }
    
    struct Course* course = &department->courses[department->numCourses];
    printf("Enter Course ID: ");
    scanf("%d", &course->courseID);
    getchar();

    printf("Enter Course Name: ");
    fgets(course->courseName, sizeof(course->courseName), stdin);
    course->courseName[strcspn(course->courseName, "\n")] = '\0';

    printf("Enter Instructor ID: ");
    scanf("%d", &course->instructor.instructorID);
    getchar();

    printf("Enter Instructor Name: ");
    fgets(course->instructor.name, sizeof(course->instructor.name), stdin);
    course->instructor.name[strcspn(course->instructor.name, "\n")] = '\0';
    
    printf("Enter Instructor Department: ");
    fgets(course->instructor.department, sizeof(course->instructor.department), stdin);
    course->instructor.department[strcspn(course->instructor.department, "\n")] = '\0';
    
    course->numStudents = 0;
    while (1) {
        printf("\nEnter student details for this course:\n");
        printf("Enter Student ID: ");
        scanf("%d", &course->students[course->numStudents].studentID);
        getchar();

        printf("Enter Student Name: ");
        fgets(course->students[course->numStudents].name, sizeof(course->students[course->numStudents].name), stdin);
        course->students[course->numStudents].name[strcspn(course->students[course->numStudents].name, "\n")] = '\0';
        
        printf("Enter Student Age: ");
        scanf("%d", &course->students[course->numStudents].age);

        course->numStudents++;
        if (course->numStudents >= MAX_STUDENTS) {
            printf("Max number of students enrolled.\n");
            break;
        }
        char choice;
        printf("Do you want to add another student? (y/n): ");
        getchar();
        scanf("%c", &choice);
        if (choice != 'y' && choice != 'Y') break;
    }

    department->numCourses++;
}

void displayStudent(struct Student student) {
    printf("\nStudent ID: %d\n", student.studentID);
    printf("Student Name: %s\n", student.name);
    printf("Student Age: %d\n", student.age);
}

void displayCourse(struct Course course) {
    printf("\nCourse ID: %d\n", course.courseID);
    printf("Course Name: %s\n", course.courseName);
    printf("Instructor ID: %d\n", course.instructor.instructorID);
    printf("Instructor Name: %s\n", course.instructor.name);
    printf("Instructor Department: %s\n", course.instructor.department);
    printf("Enrolled Students: \n");
    for (int i = 0; i < course.numStudents; i++) {
        displayStudent(course.students[i]);
    }
}

void displayDepartment(struct Department department) {
    printf("----------------------------------\n");
    printf("\nDepartment ID: %d\n", department.departmentID);
    printf("Department Name: %s\n", department.departmentName);
    printf("Courses Offered: \n");
    for (int i = 0; i < department.numCourses; i++) {
        displayCourse(department.courses[i]);
    }
}

int main() {
    struct Department departments[MAX_DEPARTMENTS];
    int numDepartments = 0;

    while (1) {
        int choice;
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to Department\n");
        printf("3. Display All Departments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numDepartments >= MAX_DEPARTMENTS) {
                    printf("Maximum number of departments reached.\n");
                    break;
                }
                addDepartment(&departments[numDepartments]);
                numDepartments++;
                break;
            case 2:
                if (numDepartments == 0) {
                    printf("No departments available. Add a department first.\n");
                    break;
                }
                for (int i = 0; i < numDepartments; i++) {
                    printf("%d. %s\n", i + 1, departments[i].departmentName);
                }
                printf("Select a department to add a course to: ");
                int deptChoice;
                scanf("%d", &deptChoice);
                if (deptChoice < 1 || deptChoice > numDepartments) {
                    printf("Invalid department choice.\n");
                    break;
                }
                addCourse(&departments[deptChoice - 1]);
                break;
            case 3:
                for (int i = 0; i < numDepartments; i++) {
                    displayDepartment(departments[i]);
                }
                break;
            case 4:
                printf("Exiting system.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
