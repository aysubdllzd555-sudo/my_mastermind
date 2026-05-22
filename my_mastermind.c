#include "my_mastermind.h"

// Stringləri müqayisə edən funksiya
int my_strcmp(char* s1, char* s2)
{
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i]) return 0;
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0')
    {
        return 1;
    }
    return 0;
}

// Cəhd sayını oxumaq üçün stringi ədədə çevirən funksiya
int my_atoi(char* str)
{
    int res = 0;
    int i = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

// 0-8 arası təkrarlanmayan təsadüfi kod yaradan funksiya
void generate_random_code(char* code)
{
    int used[9] = {0};
    int i = 0;
    while(i < 4)
    {
        int r = rand() % 9;
        if(!used[r])
        {
            code[i] = r + '0';
            used[r] = 1;
            i++;
        }
    }
    code[4] = '\0';
}

// Daxil edilən təxminin düzgünlüyünü yoxlayan funksiya
int is_valid_guess(char* guess)
{
    int length = 0;
    while(guess[length] != '\0')
    {
        length++;
    }
    if(length != 4)
    {
        return 0;
    }
    int i;
    for(i = 0; i < length; i++)
    {
        if(guess[i] < '0' || guess[i] > '8')
        {
            return 0;
        }
    }
    int j;
    for(i = 0; i < length; i++)
    {
        for(j = i + 1; j < length; j++)
        {
            if(guess[j] == guess[i])
            {
                return 0;
            }
        }
    }
    return 1;
}