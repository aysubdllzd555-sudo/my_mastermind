#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int is_valid_guess(char* guess);
int my_strcmp(char* s1, char* s2);
int my_atoi(char* str);
void generate_random_code(char* code);

#endif