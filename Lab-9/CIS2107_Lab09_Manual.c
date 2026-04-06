/*
 * Name:	Eunseo Hwang
 * Date: April 5 2026
 * Section:	002
 * Lab:  	CIS2107_Lab09_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);

    //test for endsWithed
    endsWithed(series, size);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char *s) {
    char arr[100];
    strcpy(arr, s);  

    printf("Uppercase String: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%c", toupper(arr[i]));
    }
    printf("\n");

    printf("Lowercase String: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%c", tolower(arr[i]));
    }
    printf("\n");

    return NULL;
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int i1, i2, i3, i4;

    i1 = atoi(s1);
    i2 = atoi(s2);
    i3 = atoi(s3);
    i4 = atoi(s4);

    int sum = i1 + i2 + i3 + i4;

    return sum;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
   float f1, f2, f3, f4;

   f1 = atof(s1);
   f2 = atof(s2);
   f3 = atof(s3);
   f4 = atof(s4);

   float sum = f1+ f2 + f3 + f4;

   return sum;

}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int result = strcmp(s1, s2);

    printf("\n");
    if (result < 0) {
        printf("Test 1 < Test 2\n");
    } else if (result == 0) {
        printf("Test1 == Test 2\n");
    } else {
        printf("Test 1 > Test 2\n");
    }

    printf("\n");
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
   int result = strncmp(s1, s2, n);

   if (result < 0) {
        printf("Test 1 < Test 2\n");
   } else if (result == 0) {
        printf("Test1 == Test 2\n");
   } else {
        printf("Test 1 > Test 2\n");
   }
}

//6.(Random Sentences) 
void randomize(void) {
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};

    char sentence[100] = "";

    for (int i = 0; i < 20; i++) {
        sentence[0] = '\0';

        strcat(sentence, article[rand() % 5]);
        strcat(sentence, " ");

        strcat(sentence, noun[rand() % 5]);
        strcat(sentence, " ");

        strcat(sentence, verb[rand() % 5]);
        strcat(sentence, " ");

        strcat(sentence, preposition[rand() % 5]);
        strcat(sentence, " ");

        strcat(sentence, article[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, noun[rand() % 5]);

        sentence[0] = toupper(sentence[0]);
        strcat(sentence, ". ");

        printf("%s", sentence); 
    }
    printf("\n");
   
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
  char *areaNum = strtok(num, "() -");
  char *first = strtok(NULL, "() -");
  char *second = strtok(NULL, "() -");

  char number[8] = "";
  strcat(number, first);
  strcat(number, second);

  printf("\nPhone Number: %d %ld\n", atoi(areaNum), atol(number));
  printf("\n");

  return 0;
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char *words[100];
    int count = 0;
    char *token = strtok(text, " ");

    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    printf("Reversed string: ");
    for (int i = count-1; i >= 0; i--) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *result = strstr(line, sub);

    while(result != NULL) {
        count++;
        result = strstr(result + 1, sub);
    }
    
    return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    char *result = strchr(line, c);

    while(result != NULL) {
        count++;
        result = strchr(result + 1, c);
    }

    return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    for (char letter = 'a'; letter <= 'z'; letter++) {
        int count = 0;
        char *result = strchr(string, letter);
        
        while (result != NULL) {
            count++;
            result = strchr(result + 1, letter);
        }
        
        result = strchr(string, toupper(letter));
        while (result != NULL) {
            count++;
            result = strchr(result + 1, toupper(letter));
        }
        
        if (count > 0) {
            printf("%c | %c : %d\n", toupper(letter), letter, count);
        }
    }
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int count = 0;
    char *result = strtok(string, " \n");
 
    while (result != NULL) {
        count++;
        result = strtok(NULL, " \n");
    }

   return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    printf("\nWords Beginning with B: \n");

    for (int i = 0; i < size; i++) {
        if (tolower(string[i][0]) == 'b') {
            printf("     %s\n", string[i]);
        }
    }

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    printf("\nWords Ending with ed: \n");

    for (int i = 0; i < size; i++) {
        int len = strlen(string[i]);
        if (string[i][len-2] == 'e' && string[i][len-1] == 'd') {
            printf("     %s\n", string[i]);
        }
    }

}
