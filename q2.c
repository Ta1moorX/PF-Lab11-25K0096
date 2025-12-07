#include <stdio.h>
#include <string.h>

struct Transaction {
    char date[20];
    char type[20];
    float amount;
};

struct Account {
    char accNumber[20];
    char name[50];
    char type[20];
    float balance;
    float minBalance;
    float interestRate;
    char creationDate[20];
    char lastTransDate[20];
    struct Transaction transactions[10];
    int transCount;
};

int main() {
    struct Account acc;
    int choice;
    float amount;
    
    printf("\nCreate Bank Account:\n");
    printf("Account Number: ");
    scanf("%s", acc.accNumber);
    printf("Account Holder Name: ");
    scanf("%s", acc.name);
    
    printf("\nAccount Types:\n");
    printf("1. Savings\n2. Current\n3. Fixed Deposit\n");
    printf("Choose type: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        strcpy(acc.type, "Savings");
        acc.minBalance = 1000;
        acc.interestRate = 4.0;
    } else if(choice == 2) {
        strcpy(acc.type, "Current");
        acc.minBalance = 5000;
        acc.interestRate = 0.0;
    } else {
        strcpy(acc.type, "Fixed Deposit");
        acc.minBalance = 10000;
        acc.interestRate = 7.0;
    }
    
    printf("Initial Deposit: $");
    scanf("%f", &acc.balance);
    
    printf("Creation Date (DD/MM/YYYY): ");
    scanf("%s", acc.creationDate);
    
    acc.transCount = 0;
    
    if(acc.balance < acc.minBalance) {
        printf("\nError: Minimum balance for %s is $%.2f\n", acc.type, acc.minBalance);
        return 0;
    }
    
    printf("\nAccount Details:\n");
    printf("Account Number: %s\n", acc.accNumber);
    printf("Name: %s\n", acc.name);
    printf("Type: %s\n", acc.type);
    printf("Balance: $%.2f\n", acc.balance);
    printf("Minimum Balance: $%.2f\n", acc.minBalance);
    printf("Interest Rate: %.2f%%\n", acc.interestRate);
    printf("Creation Date: %s\n", acc.creationDate);
    
    printf("\n1. Deposit\n2. Withdraw\nChoice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Enter amount to deposit: $");
        scanf("%f", &amount);
        acc.balance += amount;
        strcpy(acc.transactions[acc.transCount].type, "Deposit");
        acc.transactions[acc.transCount].amount = amount;
        printf("Enter transaction date: ");
        scanf("%s", acc.transactions[acc.transCount].date);
        strcpy(acc.lastTransDate, acc.transactions[acc.transCount].date);
        acc.transCount++;
        printf("Deposit successful! New balance: $%.2f\n", acc.balance);
    } else {
        printf("Enter amount to withdraw: $");
        scanf("%f", &amount);
        if(acc.balance - amount >= acc.minBalance) {
            acc.balance -= amount;
            strcpy(acc.transactions[acc.transCount].type, "Withdrawal");
            acc.transactions[acc.transCount].amount = amount;
            printf("Enter transaction date: ");
            scanf("%s", acc.transactions[acc.transCount].date);
            strcpy(acc.lastTransDate, acc.transactions[acc.transCount].date);
            acc.transCount++;
            printf("Withdrawal successful! New balance: $%.2f\n", acc.balance);
        } else {
            printf("Error: Cannot maintain minimum balance!\n");
        }
    }
    
    return 0;
}