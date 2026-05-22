#include "my_mastermind.h"

int main(int argc, char** argv)
{
    char secret_code[5] = {0};
    int max_attempts = 10;
    int code_provided = 0;
    int i;
    for (i = 1; i < argc; i++)
    {
        if (my_strcmp(argv[i], "-c") == 1 && i + 1 < argc)
        {
            int j = 0;
            while(argv[i+1][j] != '\0' && j < 4)
            {
                secret_code[j] = argv[i+1][j];
                j++;
            }
            secret_code[4] = '\0';
            code_provided = 1;
            i++;
        }
        else if (my_strcmp(argv[i], "-t") == 1 && i + 1 < argc)
        {
            max_attempts = my_atoi(argv[i+1]);
            i++;
        }
    }
    if (code_provided == 0)
    {
        srand(time(NULL));
        generate_random_code(secret_code);
    }

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
    
    int raund = 0;
    char guess[50];
    
    while(raund < max_attempts)
    {
        printf("---\n");
        printf("Round %d\n", raund);
        printf(">");
        fflush(stdout);
        
        char c;
        int i = 0;
        int bytes_read;
        while((bytes_read = read(0, &c, 1)) > 0)
        {
            if(c == '\n') {
                break;
            }
            guess[i] = c;
            i++;
        }
        guess[i] = '\0';
        if (bytes_read == 0 && i == 0)
        {
            printf("\n");
            return 0;
        }

        if (is_valid_guess(guess) == 0) {
            printf("Wrong input!\n");
            continue;
        }

        if(my_strcmp(guess, secret_code) == 1)
        {
            printf("Congratz! You did it!\n");
            return 0;
        }

        int well_placed = 0;
        int misplaced = 0;
        int j;

        for(i = 0; i < 4; i++) {
            if(guess[i] == secret_code[i]) {
                well_placed++;
            } 
            else {
                for(j = 0; j < 4; j++) {
                    if(guess[i] == secret_code[j]) {
                        misplaced++;
                        break;
                    }
                }
            }
        }
        printf("Well placed pieces: %d\n", well_placed);
        printf("Misplaced pieces: %d\n", misplaced);

        raund++;
    }

    return 0;
}