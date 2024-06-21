#include <stdio.h>
#include <cs50.h>

/*
 *  Prints out a pyramid made out of # symbols of height specified the user.
 */

int main(void)
{

    //have the user determine the pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    //print one row at a time starting from top
    for (int row = 1; row <= height; row++)
    {
        int spaces = height - row;
        int hashes = row;

        //print spaces
        while(spaces > 0)
        {
            printf(" ");
            spaces--;
        }

        //print hashes
        while (hashes > 0)
        {
            printf("#");
            hashes--;
        }

        printf("\n");
    }

    return 0;
}
