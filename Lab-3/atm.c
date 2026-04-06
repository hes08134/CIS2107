// Eunseo Hwang Jan 30 CIS 2107
//Lab 3 ATM Machine
//checking balance, withdraw and deposit cash, and printing the receipt

#include <stdio.h>
#include <stdlib.h>

double balance = 5000;
int transactionCount = 0;
double withdrawTotal = 0;
double depositTotal = 0;

void checkBalance();
void withdrawCash();
void depositCash();
void receipt();

int main()
{
    printf("***************************************\n");
    printf("Welcome to the ATM Machine\n");
    printf("***************************************\n");

    int pin;
    int pinError = 3;
    int menuNum;


    //Enter PIN
    while (pinError > 0) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &pin);
        
        if(pin == 3014) {
            printf("PIN validation sucessful.\n");
            printf("\n");
            break;
        }

        else {
            pinError--;
            if (pinError > 0) {
                printf("Invalid PIN Number. You have %d attempt(s) left\n", pinError);
            }
            else {
                printf("Too many failed attempts. Transaction cancelled.\n");
                exit(0);
            }
        }
    }

    //ATM Main Menu
    while(1) {
        printf("ATM Main Menu: \n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Quit\n");
        printf("Select one option: ");
        scanf("%d", &menuNum);
        printf("\n");

        if (menuNum == 1) {
            checkBalance();
            transactionCount++;
        }

        else if (menuNum == 2) {
            withdrawCash();
            transactionCount++;
        }

        else if(menuNum == 3) {
            depositCash();
            transactionCount++;
        }

        else if(menuNum == 4) {
            printf("Thank you for using our ATM\n");
            printf("You performed %d transaction(s).\n", transactionCount);
            printf("GOOD BYE!!");

            exit(0);
        }

        else {
            printf("Invalid Number. Please enter 1-4.\n");
        }
    }

    return 0;
}

//#1 Check Balance
void checkBalance() {
    printf("Your current balance is: $%.2f\n", balance);
    receipt();
}

//#2 Cash Withdrawal
void withdrawCash() {
    double withdraw;
    int count = 0;

    while (count < 3){
        printf("Enter your amount to withdraw (in multiples of $20, up to $1000): ");
        scanf("%lf", &withdraw);

        //check negative,0 and multiples of 20 and >1000 and > balance
        if (withdraw <= 0 || (int)withdraw != withdraw || (int)withdraw % 20 != 0 || withdraw > balance || withdrawTotal + withdraw > 1000) {

            count++;
            if (count < 3) {
                printf("Invalid amount. You have %d attempt(s) left. \n", 3 - count);
            }
            else {
                printf("Invalid amount. You have %d attempt(s) left. \n", 3 - count);
                printf("Too many invalid attempts. Transaction cancelled.\n");
                transactionCount--;
                exit(0);
            }   
            continue;
        }

        withdrawTotal = withdrawTotal + withdraw;
        balance = balance - withdraw;
        printf("Please take your cash. Your balance is: $%.2f\n", balance);

        receipt();
        return;
    }
}

//#3 Cash Deposition
void depositCash() {
    double deposit;
    int count = 0;
    
    while (count < 3) {
        printf("Enter amount to deposit (daily limit $10000): ");
        scanf("%lf", &deposit);
        count++;

        if (deposit <= 0 || (int)deposit != deposit || depositTotal + deposit > 10000) {
            if (count < 3) {
                printf("Invalid amount. You have %d attempt(s).\n", 3 - count);
            }
            else {
                printf("Invalid amount. You have %d attempt(s) left. \n", 3 - count);
                printf("Too many invalid attempts. Transactions cancelled.\n");
                transactionCount--;
                exit(0);
            }
            continue;
        }


        depositTotal = depositTotal + deposit;
        balance = balance + deposit;
        printf("Deposit Successful. Your new balance is $%.2f\n", balance);

        receipt();
        return;
    }
}

//receipt
void receipt() {
    int receiptNum;

    printf("Do you want a receipt?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &receiptNum);
    
    if (receiptNum == 1) {
        printf("Virtual receipt printed.\n");
    }
    else {
        printf("No receipt chosen.\n");
    }

    printf("\n");
}