//Eunseo Hwang, Jan 25 2025, CIS 2107
//Lab 02 Revenue
//This program calculates total revenue after discounting based on the quantity of items. 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to \"Temple\" store \n");
    printf("\n");

    double itemPrice;
    double quantity;
    double cost;
    double discount;
    double discountAmount;
    double total;

    printf("Enter item price: ");
    scanf("%lf", &itemPrice);
    if (itemPrice <= 0) {
        printf("This is not a valid item price. \n");
        printf("Please run the program again. \n");

        printf("\nThank you for using \"Temple\" store \n");
        exit(1);
    }

    printf("Enter quantity: ");
    scanf("%lf", &quantity);
    if (quantity <= 0 || quantity != (int)quantity) {
        printf("This is not a valid quantity order. \n");
        printf("Please run the program again. \n");

        printf("\nThank you for using \"Temple\" store \n");
        exit(1);
    }

    printf("\n");
    cost = itemPrice * quantity;

    if (quantity >= 1 && quantity <= 49) {
        discount = 0.0;
    }
    else if (quantity >=50 && quantity <= 99) {
        discount = 0.1;
    }
    else if (quantity >= 100 && quantity <= 149) {
        discount = 0.15;
    }
    else {
        discount = 0.25;
    }

    discountAmount = cost * discount;
    total = cost - discountAmount;

    printf("The item price is: %.0f\n", itemPrice);
    printf("The order is: %.0f item(s)\n", quantity);
    printf("The cost is: $%.1f\n", cost);
    printf("The discount is: %.1f%%\n", discount * 100);
    printf("Ths discount amount is: $%.1f\n", discountAmount);
    printf("The total is: $%.1f\n", total);

    printf("\nThank you for using \"Temple\" store \n");

    exit(0);
}