#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee{
    char Name[50];
    char DOB[15];
    int EmployeeID;
    char Department[50];
    float Salary;
} ;

void AddEmployee(struct Employee employees[], int *employeeCount) {
    if (*employeeCount >= MAX_EMPLOYEES) {
        printf("Error: Maximum employee limit reached.\n");
        return;
    }
    printf("Enter Employee Name: ");
    getchar();
    fgets(employees[*employeeCount].Name, 50, stdin);
    employees[*employeeCount].Name[strcspn(employees[*employeeCount].Name, "\n")] = '\0';

    printf("Enter Date of Birth (dd/mm/yyyy): ");
    fgets(employees[*employeeCount].DOB, 15, stdin);
    employees[*employeeCount].DOB[strcspn(employees[*employeeCount].DOB, "\n")] = '\0';

    printf("Enter Employee ID: ");
    scanf("%d", &employees[*employeeCount].EmployeeID);
    getchar();

    printf("Enter Department: ");
    fgets(employees[*employeeCount].Department, 50, stdin);
    employees[*employeeCount].Department[strcspn(employees[*employeeCount].Department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &employees[*employeeCount].Salary);
    getchar();

    (*employeeCount)++;
    printf("Employee added successfully.\n");
}

void DeleteEmployee(struct Employee employees[], int *employeeCount) {
    int id, i, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *employeeCount; i++) {
        if (employees[i].EmployeeID == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < *employeeCount - 1; j++) {
            employees[j] = employees[j + 1];
        }
        (*employeeCount)--;
        printf("Employee with ID %d deleted successfully.\n", id);
    } else {
        printf("Error: Employee with ID %d not found.\n", id);
    }
}

void DisplayEmployees(struct Employee employees[], int employeeCount) {
    if (employeeCount == 0) {
        printf("No Employees to display.\n");
        return;
    }

    printf("\nEmployee List:\n");
    printf("-----------------------------------------------------------\n");
    printf("%-15s %-15s %-10s %-20s %-10s\n", "Name", "DOB", "Emp ID", "Department", "Salary");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++) {
        printf("%-15s %-15s %-10d %-20s %-10.2f\n",
               employees[i].Name,
               employees[i].DOB,
               employees[i].EmployeeID,
               employees[i].Department,
               employees[i].Salary);
    }
    printf("-----------------------------------------------------------\n");
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddEmployee(employees, &employeeCount);
                break;
            case 2:
                DeleteEmployee(employees, &employeeCount);
                break;
            case 3:
                DisplayEmployees(employees, employeeCount);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
