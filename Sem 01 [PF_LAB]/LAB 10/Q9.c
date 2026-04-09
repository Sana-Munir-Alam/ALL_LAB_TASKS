#include <stdio.h>
#include <string.h>

# define Max 100
struct Employees{
    int EmployeeID;
    char Name[50];
    char Department[50];
    float Salary;
};

int main(){
    struct Employees Info[Max];
    int N;
    printf("Enter How Many Employees Data You Want To Add: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        printf("\nEnter Details of Employee %d\n", i+1);
        printf("Enter Employee ID: ");
        scanf("%d", &Info[i].EmployeeID);
        getchar();
        printf("Enter Employee Name: ");
        fgets(Info[i].Name, 50, stdin);
        Info[i].Name[strcspn(Info[i].Name, "\n")] = '\0';
        printf("Enter Employee Department: ");
        fgets(Info[i].Department, 50, stdin);
        Info[i].Department[strcspn(Info[i].Department, "\n")] = '\0';
        printf("Enter Employee Salary: ");
        scanf("%f", &Info[i].Salary);   
    }
    printf("\nEmployee Details:\n");
    printf("--------------------------------------------------\n");
    for(int i = 0; i < N; i++){
        printf("Employee ID: %d\n", Info[i].EmployeeID);
        printf("Employee Name: %s\n", Info[i].Name);
        printf("Employee Department: %s\n", Info[i].Department);
        printf("Employee Salary: $%.2f\n", Info[i].Salary);
        printf("--------------------------------------------------\n");
    }
    return 0;
}
