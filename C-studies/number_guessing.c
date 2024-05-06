#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum Difficulty{
    easy = 1,
    normal = 2
};

const int MIN = 1;
const int MAX = 100;

int main() {
    enum Difficulty diff;
    bool already_close = false;

    printf("************************************\n");
    printf("Welcome to the number guessing game!\n");
    printf("************************************\n");

    printf("Choose your difficulty Easy (1) or Medium (2)? \n");
    scanf("%d", &diff);

    diff == easy ? printf("Easy mode chosen!") : printf("Medium mode chosen!");

    srand(time(0));
    int answer = (rand() % MAX) + MIN;

    int min_numb = MIN;
    int max_numb = MAX;
    int close_count = 0;

    int guesses = 0;
    int guess;

    do {
        printf("\nGuess a number between %d and %d: ", min_numb, max_numb);
        scanf("%d", &guess);
        guesses++;

        if (guess > answer) {
            printf("Your number is too high!\n");
            if (diff == easy && max_numb > guess) {
                max_numb = guess;
            }
        }

        else if (guess < answer) {
            printf("Your number is too low!\n");
            if (diff == easy && guess > min_numb) {
                min_numb = guess;
            }
        }
        
        if (0 < abs(guess - answer) && abs(guess - answer) <= 5) {
            close_count++;
            close_count > 6 ? printf("BRO COME ON!\n"), already_close = true : printf("Hint: you're almost there :D\n");
        }

        else if (already_close) {
            printf("Are you serious? You had it JUST RIGHT THERE AND YOU LOST IT\nBRO, I DON'T... HOW!?\n");
        }
        

    } while (guess != answer);
    already_close ? printf("FINALLY GODDAMNNIT.\nYOU SHOULD BE ASHAMED OF YOURSELF.\nJust kidding, I hope that you didn't take it to heart; I hope your dreams come true :)\n") : printf("YOU'RE CORRECT!! CONGRATULATIONS!!\n");
     
    printf("\n**********************\n");
    printf("answer: %d\n", answer);
    printf("guesses: %d\n", guesses);
    printf("**********************");
    
   return 0;
}