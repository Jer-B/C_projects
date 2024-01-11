/*
    CS-50 pset-4: Filter Less.
    description: Photo filters: Grayscale, blur, reflect and sepia
    @file credit.c
    @author Jeremy B.
    @version 1.0 3 Nov 2020
*/

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //2D arrays calculating color for each pixel and do an average of it to replace on the original
    //divide sum of colors value by 3.0 for average being rounded

    // row
    for (int i = 0; i < height; i++)
    {
        // column
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int avg = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //2D arrays calculating color for each pixel using cs50 - pset4 given formula for sepia pixel
    //pixel value must not go over 255 and should be capped at 255 if over, value must be rounded

    //row
    for (int i = 0; i < height; i++)
    {
        //column
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            //if value over 255, capped at 255 and original value replacement
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
                image[i][j].rgbtRed = sepiaRed;

            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
                image[i][j].rgbtBlue = sepiaBlue;
            }

            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //setting swap
    RGBTRIPLE swap[height][width];

    //2D array with an invert reading row and target pixel to swap
    for (int i = 0; i < height; i++)
    {
        //target pixel to swap at first position in a row
        int target = 0;

        //reverse reading, target current pixel
        for (int j = width - 1; j >= 0; j--, target++)
        {
            swap[i][target] = image[i][j];
        }
    }

    //swap loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = swap[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //set swap color
    RGBTRIPLE swap[height][width];

    //image row
    for (int i = 0; i < height; i++)
    {
        //image column
        for (int j = 0; j < width; j++)
        {

            //set sum RGB
            float sum_red = 0;
            float sum_blue = 0;
            float sum_green = 0;

            //set counter
            int counter = 0;

            //set 2 area array, row and column for looking around current pixel
            int row_area[] = {i - 1, i, i + 1};
            int col_area[] = {j - 1, j, j + 1};

            //loop row area, up - current - down, around targeted pixel
            for (int row = 0; row < 3; row++)
            {
                //loop column area, left side - current - right side, around targeted pixel
                for (int col = 0; col < 3; col++)
                {
                    //set current
                    int row_current = row_area[row];
                    int col_current = col_area[col];

                    if (row_current >= 0 && row_current < height && col_current >= 0 && col_current < width)
                    {
                        RGBTRIPLE pixel = image[row_current][col_current];

                        //sum total of current pixel iterations (and around area) for each colors
                        sum_red += pixel.rgbtRed;
                        sum_green += pixel.rgbtGreen;
                        sum_blue += pixel.rgbtBlue;

                        //counter++
                        counter++;
                    }
                }
            }

            //determine value of total / count into swap
            swap[i][j].rgbtRed = round(sum_red / counter);
            swap[i][j].rgbtGreen = round(sum_green / counter);
            swap[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }

    //swap loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = swap[i][j];
        }
    }
    return;
}
