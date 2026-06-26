#include <stdio.h>
#include <ctype.h>
int askQuestion(char *question, char *opt1, char *opt2, char *opt3, char *opt4, char correctAns) {
    printf("\n%s\n", question);
    printf("A. %s\n", opt1);
    printf("B. %s\n", opt2);
    printf("C. %s\n", opt3);
    printf("D. %s\n", opt4);

    char answer;
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer); 
    if (toupper(answer) == correctAns) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect! The correct answer was %c.\n", correctAns);
        return 0;
    }
}

int main() {
    int score = 0;
    int totalQuestions = 5;

    printf("=== WELCOME TO THE C QUIZ ===\n");

    // Question 1
    score += askQuestion("What is the size of an 'int' data type in C (typically)?", 
                         "2 bytes", "4 bytes", "8 bytes", "1 byte", 'B');

    // Question 2
    score += askQuestion("Which of the following is a valid loop in C?", 
                         "loop", "repeat-until", "for", "while-do", 'C');

    // Question 3
    score += askQuestion("Which symbol is used to terminate a statement in C?", 
                         ".", ";", ":", ",", 'B');

    // Question 4
    score += askQuestion("What does the 'printf()' function do?", 
                         "Takes user input", "Prints text to the screen", "Performs a mathematical calculation", "Stores a variable", 'B');

    // Question 5
    score += askQuestion("Which operator is used to compare two values in C?", 
                         "=", "==", "!=", "<>", 'B');
    printf("\n=== QUIZ OVER ===");
    printf("\nYour final score is: %d out of %d\n", score, totalQuestions);

    return 0;
}
