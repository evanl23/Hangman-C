#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* TODO: complete the definition of the possible_words[] array. 
*  You may populate it however you'd like.
*  Make sure to update the macro for NUM_WORDS to match the length of your
*  possible words array.
*/
#define NUM_WORDS 1
char* possible_words[] = {"hello"};

int random_number(int min_num, int max_num) {
        srand(time(NULL));
        return (rand() % (max_num - min_num)) + min_num;
}

/* Populates the given display string buffer with '_' characters
 * corresponding to the length of the answer string.
 * For example: if length == 3, after running generate_display_string
 * the display string buffer will contain {'_', '_' , '_','\0'}
*/
void generate_display_string(char* display_string, int length) {
	for (int i = 0; i < length; i++) {
		display_string[i] = '_';
	}
	display_string[length] = '\0';
}

/* Updates the display string to reveal any correctly guessed characters.
 * Also updates value of letters_remaining with the remaining numbers of letters to guess.
 * For example: if answer_string is "hello", and guess is 'l', display string is "_____",
 * update the display string to "__ll_" and value of letters_remaining to 3.
*/
void update_display_string(char* display_string, char* answer_string, char guess, int* letters_remaining) {
	int i = 0;
	while (answer_string[i] != '\0') {
		if (answer_string[i] == guess) {
			display_string[i] = guess;
			*letters_remaining -= 1;
		}
	i++;
	}
}


/* Returns true (1) if guess character is in answer_string 
*/
_Bool guess_in_answer(char* answer_string, char guess){
	int i = 0;
	while (answer_string[i] != '\0') {
		if (guess == answer_string[i]) { return 1;}
		i++;
	}
	return 0;
}

int main(void) {
    char display_string_buffer[100]; // space for our display string

    int lives = 3;

    int random_index = random_number(0, NUM_WORDS);
    char* answer = possible_words[random_index];

    // Variable storing the letters left to guess
    int letters_to_guess = strlen(answer);
    generate_display_string(display_string_buffer, letters_to_guess);

     while(lives > 0 && letters_to_guess > 0) {

        // print number of lives left and space-seperated display_string
        printf("LIVES: %d\n", lives);
        for(int i = 0; i < strlen(answer); i++) {
            printf("%c ", display_string_buffer[i]);
        }
        printf("\n");

        // scan the single-character user guess from STDIN into the variable guess
        printf("Guess: ");
        char guess;
        scanf(" %c", &guess); 

	if (guess_in_answer(answer, guess)) {
		update_display_string(display_string_buffer, answer, guess, &letters_to_guess);
	} else {
		lives--;
	}
    }

	if (lives == 0) { printf("YOU LOSE \n"); }
	else { printf("YOU WIN \n"); }

}
