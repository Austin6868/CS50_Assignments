#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 1;
    int height = 0;
    bool isNotWithin = true;

    do //a do-while loop that reprompts the message that limits the input within 1 to 8 inclusive
    {
        height = get_int("Height: ");
        if (height <= 8 && height >= 1)
        {
            isNotWithin = false;
        }

    }
    while (isNotWithin);


    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0 ; j < height - count ; j++) //this is for the spaces that happens first
        {
            printf(" ");
        }
        for (int p = 0 ; p < count ; p++) //this is for the hashes that are printed second
        {
            printf("#");
        }
        printf("  "); //spaces between the hashes
        for (int k = 0 ; k < count ; k++) //this is for the hashes printed last
        {
            printf("#");
        }
        printf("\n");
        count++;
    }
}