#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define Buffer_size 512

int main(int argc, char *argv[])
{
    //if more or less than 1 argument line, remind user
    if (argc != 2)
    {
        printf("Argument line should be 1. Usage ./recover filename.jpg\n");
        return 1;
    }

    //open input argument file for reading
    FILE *input_file = fopen(argv[1], "r");

    //check NULL
    if (input_file == NULL)
    {
        printf("File can't be openned. NULL ERROR");
        return 1;
    }

    //buffer structure
    typedef uint8_t BYTE;
    BYTE buffer[Buffer_size];

    size_t Bytes_block;


    //number of byte to read
    int Block_size = 512;
    //set first and already found jpeg to false
    bool first_jpeg = false;
    bool already_jpeg = false;

    //current file where it write
    FILE *current;
    //FILE *new_file;
    //image name number
    int file_number = 0;

    //new_current file when previous current close
    char new_current[500];

    //open SD_Card while True
    while (true)
    {
        // read 512 bytes block to buffer until end of file
        Bytes_block = fread(buffer, sizeof(BYTE), Block_size, input_file);

        if (Bytes_block == 0)
        {
            break;
        }

        //if beginning new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            already_jpeg = true;

            if (!first_jpeg)
            {
                first_jpeg = true;
            }

            else
            {
                //close file where it wrotes to if not first_jpeg
                fclose(current);
            }

            //open new current file with name number incremented for writing
            sprintf(new_current, "%03i.jpg", file_number);
            current = fopen(new_current, "w");
            fwrite(buffer, sizeof(BYTE), Block_size, current);

            //increment image file name number for next file
            file_number++;
        }

        else
        {
            //if already found jpeg, keep writing to it
            if (already_jpeg)
            {
                fwrite(buffer, sizeof(BYTE), Bytes_block, current);
            }
        }
    }

    //close input file and current file
    fclose(input_file);
    fclose(current);
    return 0;
}
