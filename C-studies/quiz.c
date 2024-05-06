   #include <stdio.h>
   #include <ctype.h>
   #include <stdbool.h>

   enum Difficulty{
      easy = 1,
      medium = 2
   };

   int main() {
      printf("QUIZ GAME\n"); 

      char questions[][100] = {"1. What year did the C language debut?: ",
                              "2. Who is credited with creating C?: ",
                              "3. What is the predecessor of C?: ",
                              "4. How many bits has 8 bytes?: ",
                              "5. What is the symbol for the element gold?: ",
                              "6. What is the name of the world's longest river?: ",
                              "7. What is the capital of Liechtenstein: ?"
      };
                              
      char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                           "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                           "A. Objective C", "B. B", "C. C++", "D. C#",
                           "A. 16", "B. 64", "C. 4", "D. 32",
                           "A. Fe", "B. Cu", "C. Au", "D. Pt",
                           "A. Nile", "B. Amazon", "C. Yangtze", "D. Mississippi",
                           "A. Vaduz", "B. Berna", "C. Liubliana", "D. Bratislava",
      };
                           
      char answers[] = {'B', 'A', 'B', 'D', 'C', 'A'};
      int quest_size = sizeof(questions)/sizeof(questions[0]);

      enum Difficulty diff;

      printf("Choose your difficulty Easy (1) or Medium (2)? ");
      scanf("%d", &diff);

      diff == easy ? printf("Easy mode chosen!\n") : printf("Medium mode chosen!\n(this mode is kinda hard ngl");

      bool wrong_medium = false;
      int quest_miss;

      char guess;
      int score = 0;   

      for(int i = 0; i < quest_size; i++) {
         printf("\n*********************\n");
         printf("%s\n", questions[i]);
         printf("*********************\n");

         for(int j = (i * 4); j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
         }

         printf("guess: ");
         scanf("%c ", &guess);

         guess = toupper(guess);

         if(guess == answers[i]) {
            printf("CORRECT!\n");
            score++;
         }

         else {
            printf("WRONG!\n");
            if (diff == medium) {
               wrong_medium = true;   
            }
         }

         if (wrong_medium) {
            quest_miss = i + 1;
            break;
         }
         
      }

      if (diff == easy) {
         printf("\n*********************\n");
         printf("FINAL SCORE: %d/%d\n", score, quest_size);
         printf("*********************\n");
   
         float rate = (float) score * 100 / quest_size;
         printf("You had a rate of %.2f!", rate);
      }
      
      else if (diff == medium) {
         printf("\n*********************\n");
         printf("Unfortunately you got the question number %d\n wrong!", quest_miss);
         printf("I told you that this mode is kinda hard!");
         printf("*********************\n");
      }

      return 0;
   }