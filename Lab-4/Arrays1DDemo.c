//Eunseo Hwang Feb 08 CIS 2107
//Lab 4 Processing 1D Arrays
//process 1D arrays:
//filling with random values, finding the maximum within ranges, reversing the array and the array within ranges, finding sequence

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40
#define rand_min 0
#define rand_max 100

//#1 Fill array
void fillArray(int array[], int size) {
    for (int i = 0; i < size ; i++) {
        array[i] = rand() % (rand_max + 1) + (rand_min);
    }
}

//#2 Find local maximum in selected range
int findWithRange(int array[], int size, int lowSelectedRange, int highSelectedRange) {
    //Check valid num
    if (lowSelectedRange < 0 || highSelectedRange >= size || lowSelectedRange > highSelectedRange) {
        puts("Invalid range");
        exit(0);
    }

    int max = array[lowSelectedRange];
    for (int i = lowSelectedRange; i <= highSelectedRange; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

//#3 Reverse Array
void reverseArray(int array[], int size) {
    int temp;
    for (int i = 0; i < size/2 ; i++) {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

//#4 Reverse Selected Range Array
void reverseSelectedRangeWithinArray(int array[], int size, int startRange, int endRange) {
    //check valid num
    if (startRange < 0 || endRange >= size || startRange > endRange) {
        puts("Invalid range");
        exit(0);
    }
    
    int temp;
    int length = endRange - startRange + 1;

    for (int i = 0; i < length / 2; i++) {
        temp = array[startRange + i];
        array[startRange + i] = array [endRange - i];
        array[endRange - i] = temp;
    }
}

//#5 Find the sequence
int findSequence(int array[], int size, int tom, int jerry) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] == tom && array[i+1] == jerry) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    srand((unsigned)time(NULL));

    int array[SIZE];
    int num;
    int low;
    int high;
    int reverseNum;
    int start;
    int end;
    int first;
    int second;

    printf("Welcome to the 1D array demo!\n\n");

    printf("Let's create the array.\n");
    printf("How many integers would you like it to have? (at most 40)\n");
    printf("Enter here: ");
    scanf("%d", &num);
    printf("Here is your array: \n");
    
    if (num > SIZE || num <= 0 ) {
        printf("Invalid size\n");
        exit(0);
    }

    fillArray(array, num);
    for (int i = 0; i < num; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    puts("Now let's search for a local maximum within the array");
    puts("Enter the LOW index of the part of the array you want to search: ");
    printf("(If you want to search the whole array, enter 0 as your first index, and then %d the second index.)\n", num-1);
    scanf("%d",&low);
    printf("Now enter your HIGH index for the segment: ");
    scanf("%d", &high);
    printf("\n");

    if (low < 0 || high >= num || low > high) {
        puts("Invalid Range");
        exit(0);
    }

    for (int i = 0; i < num; i++) {
        printf("%3d ", array[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    int maxValue = findWithRange(array, num, low, high);
    printf("Maximum = %d\n\n", maxValue);

    printf("Now we can reverse the entire array. Proceed? (1 = yes, 2 = quit)\n");
    scanf("%d", &reverseNum);
    printf("\n");

    if (reverseNum == 1) {
            //Print Original
            puts("Original: ");

            for (int i = 0; i < num; i++) {
                printf("%3d ", array[i]);
                if ((i + 1) % 10 == 0) {
                    printf("\n");
                }
            }
            printf("\n");

            //Print Reversed
            reverseArray(array, num);
            puts("Reversed: ");

            for (int i = 0; i < num; i++) {
                printf("%3d ", array[i]);
                if ((i + 1) % 10 == 0 ) {
                    printf("\n");
                }
            }

    } else {
        exit(0);
    }

    printf("\n");

    printf("Now we will reverse a given segment of the array.\n");
    printf("Enter the start index of the segment: ");
    scanf("%d", &start);
    printf("And now enter the end index: ");
    scanf("%d", &end);
    printf("Revesed selected range array: \n\n");
    
    //Print Original
    puts("Original: ");
    for (int i = 0; i < num; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    //Print Selected Range Reversed Array
    reverseSelectedRangeWithinArray(array, num, start, end);
    printf("Reversing between %d and %d \n", start, end);
    for (int i = 0; i < num; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    //Back to original
    reverseSelectedRangeWithinArray(array, num, start, end);
    printf("\n");

    //Print Sequence
    printf("Now let's find a sequence.\n");

    for (int i = 0; i < num; ++i) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    printf("Enter your first number: ");
    scanf("%d", &first);
    printf("And enter the second number in your sequence: ");
    scanf("%d", &second);

    printf("Your sequence: %d, %d\n", first, second);
    int sequence = findSequence(array, num, first, second);
    if (sequence != -1) {
        printf("sequence found at index %d\n", sequence);
    } else {
        puts("sequence not found");
    }

    return 0;
}