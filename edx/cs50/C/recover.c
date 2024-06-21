/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//1 Block = 512 bytes
#define BLOCK 512
#define BYTE 1

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //open forensic image
    FILE *inptr = fopen(argv[1], "r");

    if (inptr == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 1;
    }

    uint8_t data[BLOCK]; //store a block of data
    int found = 0; //counter for jpegs found
    char filename[8]; //store ###.jpg string

    while (fread(data, BYTE, BLOCK, inptr))
    {
        //check for jpeg signature
        if (data[0] == 0xff && data[1] == 0xd8 &&
            data[2] == 0xff && (data[3] == 0xe0 ||
                                data[3] == 0xe1))
        {
            //start a new jpeg file
            found++;
            sprintf(filename, "%.3d.jpg", (found - 1));
        }

        if (found > 0)
        {

            //append to current jpeg file until find new one
            FILE *outptr = fopen(filename, "a");

            //read and write a block at a time
            fwrite(data, BYTE, BLOCK, outptr);

            fclose(outptr);
        }
    }

    return 0;

}
