#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char *getRandomWord();

int main() {
    char *word, guessedWord[20], guess;
    int wordLength, i, numGuesses = 0;
    
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the word guessing game!\n");
    
    word = getRandomWord();
    wordLength = strlen(word);
    
    for (i = 0; i < wordLength; i++)
        guessedWord[i] = '_'; // initialize the guessed word to underscores
	guessedWord[i] = '\0'; // add null terminator to the end of the string
    
    printf("The word to be guessed has %d letters.\n", wordLength);
    
    while (1) 
	{ 
		// keep asking for guesses until the user guesses the word
        printf("The word so far is: %s\n", guessedWord);
        printf("Enter your guess (a letter): ");
        scanf(" %c", &guess);
        guess = tolower(guess); // convert the guess to lowercase
        
        if (strchr(word, guess) != NULL)// the guessed letter is in the word
            for (i = 0; i < wordLength; i++)
                if (word[i] == guess)
                    guessedWord[i] = guess; // reveal the guessed letter in the guessed word
        
		else  // the guessed letter is not in the word
            printf("Sorry, '%c' is not in the word.\n", guess);
        
        
        numGuesses++;
        
        if (strcmp(word, guessedWord) == 0) 
		{ 
			// the user guessed the word
            printf("Congratulations!!!\nThe word is: \"%s\"\nYou guessed the word in %d guesses!\n", word, numGuesses);
            break;
        }
    }
    free(word); // free the memory allocated for the word
    
    return 0;
}

char *getRandomWord() 
{
    char *words[] = {"apple", "banana", "orange", "grape", "kiwi", "pear", "peach", "melon"};
    int numWords = sizeof(words) / sizeof(words[0]);
    int index = rand() % numWords;
    return strdup(words[index]); // return a copy of the randomly chosen word
}
