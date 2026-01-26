//Eunseo Hwang, Jan 25 2025, CIS 2107
//Lab 02 Paycheck
//This program calculates the weekly paycheck based on working hours and hourly salary. 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");
    printf("\n");

    double employeeNum;
    double hourlySalary;
    double weeklyTime;
    double regularPay;
    double overtimePay;
    double netPay;
    double intPart;

    printf("Enter Employee Number: ");
    scanf("%lf", &employeeNum);
    if (employeeNum <= 0 || employeeNum != (int)employeeNum) {
        printf("This is not a valid Employee Number. \n");
        printf("Please run the program again\n");

        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES \"\n");
        exit(1);
    }

    printf("Enter Hourly Salary: ");
    scanf("%lf", &hourlySalary);
    if(hourlySalary <= 0) {
        printf("This is not a valid hourly salary amount. \n");
        printf("Please run the program again\n");

        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES \"\n");
        exit(1);
    }

    printf("Enter Weekly Time: ");
    scanf("%lf", &weeklyTime);
    if (weeklyTime <= 0) {
        printf("This is not a weekly time. \n");
        printf("Please run the program again\n");

        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES \"\n");
        exit(1);
    }

    if (weeklyTime <= 40) {
        regularPay = weeklyTime * hourlySalary;
        overtimePay = 0.0;
    } else {
        regularPay = 40 * hourlySalary;
        overtimePay = (weeklyTime - 40) * (1.5 * hourlySalary);
    }
    
    netPay = regularPay + overtimePay;

    printf("=======================================\n");
    printf("Employee #: %lf\n", employeeNum);
    printf("Hourly Salary: %.1f\n", hourlySalary);
    printf("Weekly Time: %.1f\n", weeklyTime);
    printf("Regular Pay: $%.1f\n", regularPay);
    printf("Overtime Pay: $%.1f\n", overtimePay);
    printf("Net Pay: $%.1f\n", netPay);
    printf("=======================================\n");

    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    exit(0);
}