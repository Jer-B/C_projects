/*
    CS-50 pset-4: Filter More.
    description: Photo filters: Grayscale, blur, reflect and Edge Detection
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //set swap
    RGBTRIPLE swap[height][width];

    //sobel operator algorithm
    //Gx kernel 3x3
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    //Gy Kernel 3x3
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    //image row
    for (int i = 0; i < height; i++)
    {
        //image column
        for (int j = 0; j < width; j++)
        {

            //set Gx RGB
            float Gx_red = 0;
            float Gx_blue = 0;
            float Gx_green = 0;

            //set Gy RGB
            float Gy_red = 0;
            float Gy_blue = 0;
            float Gy_green = 0;

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

                        //sum total of current pixel / position iterations (and around area) for each colors * kernels Gx and Gy positions
                        Gx_red += Gx[row][col] * pixel.rgbtRed;
                        Gx_green += Gx[row][col] * pixel.rgbtGreen;
                        Gx_blue += Gx[row][col] * pixel.rgbtBlue;

                        Gy_red += Gy[row][col] * pixel.rgbtRed;
                        Gy_green += Gy[row][col] * pixel.rgbtGreen;
                        Gy_blue += Gy[row][col] * pixel.rgbtBlue;
                    }
                }
            }

            //Gy and Gx square root caluculation
            int GxGyRed = round(sqrt((Gx_red * Gx_red) + (Gy_red * Gy_red)));
            int GxGyGreen = round(sqrt((Gx_green * Gx_green) + (Gy_green * Gy_green)));
            int GxGyBlue = round(sqrt((Gx_blue * Gx_blue) + (Gy_blue * Gy_blue)));

            //determine value to swap, if value over 255, value is capped at 255
            if (GxGyRed > 255)
            {
                GxGyRed = 255;
                swap[i][j].rgbtRed = GxGyRed;
            }
            else
            {
                swap[i][j].rgbtRed = GxGyRed;
            }

            if (GxGyGreen > 255)
            {
                GxGyGreen = 255;
                swap[i][j].rgbtGreen = GxGyGreen;
            }
            else
            {
                swap[i][j].rgbtGreen = GxGyGreen;
            }

            if (GxGyBlue > 255)
            {
                GxGyBlue = 255;
                swap[i][j].rgbtBlue = GxGyBlue;
            }
            else
            {
                swap[i][j].rgbtBlue = GxGyBlue;
            }
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
