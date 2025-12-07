#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int sub1, sub2, sub3;
    float percentage;
    char grade[5];
};

int main() {
    struct Student students[5];
    int n, choice;
    float total = 0, avg;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll);
        
        do {
            printf("Marks in Subject 1 (0-100): ");
            scanf("%d", &students[i].sub1);
        } while(students[i].sub1 < 0 || students[i].sub1 > 100);
        
        do {
            printf("Marks in Subject 2 (0-100): ");
            scanf("%d", &students[i].sub2);
        } while(students[i].sub2 < 0 || students[i].sub2 > 100);
        
        do {
            printf("Marks in Subject 3 (0-100): ");
            scanf("%d", &students[i].sub3);
        } while(students[i].sub3 < 0 || students[i].sub3 > 100);
        
        students[i].percentage = (students[i].sub1 + students[i].sub2 + students[i].sub3) / 3.0;
        total += students[i].percentage;
        
        if(students[i].percentage >= 90) strcpy(students[i].grade, "A+");
        else if(students[i].percentage >= 80) strcpy(students[i].grade, "A");
        else if(students[i].percentage >= 70) strcpy(students[i].grade, "B+");
        else if(students[i].percentage >= 60) strcpy(students[i].grade, "B");
        else if(students[i].percentage >= 50) strcpy(students[i].grade, "C");
        else strcpy(students[i].grade, "F");
    }
    
    avg = total / n;
    
    printf("\nStudent Records:\n");
    for(int i = 0; i < n; i++) {
        printf("\nName: %s\n", students[i].name);
        printf("Roll: %d\n", students[i].roll);
        printf("Percentage: %.2f%%\n", students[i].percentage);
        printf("Grade: %s\n", students[i].grade);
    }
    
    printf("\nClass Average: %.2f%%\n", avg);
    
    printf("\nStudents Above Average:\n");
    for(int i = 0; i < n; i++) {
        if(students[i].percentage > avg) {
            printf("%s (%.2f%%)\n", students[i].name, students[i].percentage);
        }
    }
    
    printf("\nStudents Below Average:\n");
    for(int i = 0; i < n; i++) {
        if(students[i].percentage < avg) {
            printf("%s (%.2f%%)\n", students[i].name, students[i].percentage);
        }
    }
    
    return 0;
}