//Eunseo Hwang Mar 01
//CIS2107 Lab7 Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1
    int *hPtr = &hPos;
    int *tPr = &tPos;

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos < 70 && tPos < 70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");
    }

    if (tPos >= 70 && hPos >= 70) {
        puts("It's a tie.");
    } else if (tPos >= 70) {
        puts("Tortoise WINS!!! YAY!!!");
    } else if (hPos >= 70){
        puts("Hare wins. Yuch.");
    }

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin){
    return (hMin < tMin) ? hMin : tMin;
}

//Prints the position of the H and T
void printRace(int hPos,int tPos){
    if (tPos == hPos) {
        for (int i = 1; i < hPos; i++) {
            putchar(' ');
        }
        printf("OUCH!!");
    } else {
        int first, second;
        char c1, c2;

        if (hPos < tPos) {
            first = hPos;
            second = tPos;
            c1 = 'H';
            c2 = 'T';
        } else if (tPos < hPos) {
            first = tPos;
            second = hPos;
            c1 = 'T';
            c2 = 'H';
        }

        for (int i = 1; i < first; i++) {
            putchar(' ');
        }
        putchar(c1);

        for (int i = first + 1; i < second; i++) {
            putchar(' ');
        }
        putchar(c2);
    }
}

//Controls the tortoise movement
void tortMove(int *tPtr){
    int random = randomNumberGenerator();

    //Fast plod
    if (random <= 5) {
        *tPtr += 3;
    }
    //Slip
    else if (random <= 7) {
        *tPtr -= 6;
    }
    //Slow plod
    else if (random <= 8) {
        *tPtr += 1;
    }

    if (*tPtr < 1) {
        *tPtr = 1;
    }
}

//Controls the hare movement
void hareMove(int *hPtr){
    int random = randomNumberGenerator();

    if (random <= 2) {

    } else if (random <= 4) {
        *hPtr += 9;
    } else if (random == 5) {
        *hPtr -= 12;
    } else if (random <= 8) {
        *hPtr += 1;
    } else {
        *hPtr -= 2;
    }

    if (*hPtr < 1) {
        *hPtr = 1;
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
    return rand() % 10 + 1;
}
