#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int byTwo = 0;

    int byOne = 0;

    int sum = 0;

    //getting the card number as long integer and converting into string for easier manipulation
    long number = get_long("Card number: ");
    char cardNumber[256];
    sprintf(cardNumber, "%ld", number);

    //loops for luch's algorithm to determine the validity of the card numerically
    for (int i = strlen(cardNumber) - 2 ; i >= 0 ; i -= 2)
    {
        int fixed = (cardNumber[i] - '0') * 2;

        if (fixed / 10 >= 1)
        {
            fixed = 1 + fixed % 10;
        }

        byTwo += fixed;
    }

    for (int i = strlen(cardNumber) - 1 ; i >= 0 ; i -= 2)
    {

        byOne += (cardNumber[i] - '0');

    }

    sum = byTwo + byOne;

    //guarding statement determining the validity of the card and the providers
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (sum % 10 == 0 && strlen(cardNumber) == 15 && cardNumber[0] == '3' && (cardNumber[1] == '4' || cardNumber[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if (sum % 10 == 0 && strlen(cardNumber) == 16 && cardNumber[0] == '5' && (cardNumber[1] == '1' || cardNumber[1] == '2'
             || cardNumber[1] == '3' || cardNumber[1] == '4' || cardNumber[1] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else if (sum % 10 == 0 && (strlen(cardNumber) == 13 || strlen(cardNumber) == 16) && cardNumber[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}