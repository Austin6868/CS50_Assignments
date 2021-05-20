#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //variables
    int years = 0;
    int startPop = 0;
    int endPop = 0;
    //prompting for the population
    //guarding the variable, condition: starting size has to be >=9, the ending size has to be larger than that of the starting size.
    do
    {
        startPop = get_int("Start size: ");
    }
    while (startPop < 9);

    do
    {
        endPop = get_int("End size: ");
    }
    while (endPop < startPop);

    //calculaiton
    if (startPop == endPop)
    {
        years = 0;
    }
    else
    {
        do
        {
            years++;
            startPop = startPop + startPop / 3 - startPop / 4;
        }
        while (startPop < endPop);
    }
    //printing years
    printf("Years: %d\n", years);
}