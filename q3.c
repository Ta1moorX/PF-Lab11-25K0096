#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[30];
    char designation[30];
    float salary;
    char joiningDate[20];
    char phone[15];
    char email[50];
    int experience;
};

int main() {
    struct Employee emp[10];
    int n, choice, year, joiningYear;
    char searchDept[30];
    float deptTotal[5] = {0}, deptCount[5] = {0};
    char depts[5][20] = {"IT", "HR", "Finance", "Marketing", "Operations"};
    
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("\n=== Employee %d ===\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        
        printf("Department (IT/HR/Finance/Marketing/Operations): ");
        scanf("%s", emp[i].department);
        
        printf("Designation (Intern/Junior/Senior/Manager/Director): ");
        scanf("%s", emp[i].designation);
        
        printf("Salary: $");
        scanf("%f", &emp[i].salary);
        
        printf("Joining Date (YYYY): ");
        scanf("%d", &joiningYear);
        emp[i].experience = 2025 - joiningYear;
        sprintf(emp[i].joiningDate, "%d", joiningYear);
        
        printf("Phone: ");
        scanf("%s", emp[i].phone);
        printf("Email: ");
        scanf("%s", emp[i].email);
        
        for(int j = 0; j < 5; j++) {
            if(strcmp(emp[i].department, depts[j]) == 0) {
                deptTotal[j] += emp[i].salary;
                deptCount[j]++;
            }
        }
    }
    
    printf("\nDepartment Wise Statistics of Salary\n");
    for(int i = 0; i < 5; i++) {
        if(deptCount[i] > 0) {
            printf("%s: Average Salary = $%.2f\n", depts[i], deptTotal[i] / deptCount[i]);
        }
    }
    
    printf("\nEligible employees for promotion (more than 3 years)\n");
    for(int i = 0; i < n; i++) {
        if(emp[i].experience > 3) {
            printf("%s (%s) - %d years\n", emp[i].name, emp[i].designation, emp[i].experience);
        }
    }
    
    printf("\nSearch by department: ");
    scanf("%s", searchDept);
    printf("\nEmployees in %s:\n", searchDept);
    for(int i = 0; i < n; i++) {
        if(strcmp(emp[i].department, searchDept) == 0) {
            printf("- %s (%s) $%.2f\n", emp[i].name, emp[i].designation, emp[i].salary);
        }
    }
    
    return 0;
}