#include <cs50.h>
#include <stdio.h>

void right(int p, int height);
void left(int l);

int main(void)
{
    // prompt for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int place = height;
    int line = 1;
    for (int i = 0; i < height; i++)
    {
        // prints right-aligned pyramid
        right(place, height);
        place--;
        printf("  ");
        // prints left-aligned pyramid
        left(line);
        line++;
        printf("\n");
    }
}

void right(int p, int height)
{
    for (int i = 0; i < height; i++)
    {
        if (i < p - 1)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
    }
}

void left(int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("#");
    }
}
