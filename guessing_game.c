#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int random, guess;
    int no_of_guess = 0;
    srand(time(NULL));

    printf("welcome to the world to Guessing Numbers\n");
    random = rand() % 100 + 1;  // generating between 0 to 100
    //printf("\nNumber genarated is %d : ", random);

    do {
        printf("\n Please enter your guess between (1 to 100): ");
        scanf("%d", &guess);
        no_of_guess ++;

        if (guess < random){
            printf("Guess a larger number. \n");
        } else if (guess > random){
            printf("Guess a smaller number. \n");
        } else {
            printf(" congratulations !! You have successfully guessed the number is %d attempts ", no_of_guess);
        }
    } while (guess != random);

    printf("\n Bye bye Thanks for playing.");
    printf("\n Developed by : ChauhanCoding");
}