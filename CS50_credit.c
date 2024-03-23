#include <cs50.h>
#include <stdio.h>

int every_other_digit(long visa);
int double_and_add(int number);
int count_digit(long credit);
void check_type(long credit);

int main(void)
{

    long credit = get_long("Number: ");

    int sum_every_other_digit = every_other_digit(credit);

    if (sum_every_other_digit % 10 == 0)
    {
        check_type(credit);
    }
    else
    {
        printf("INVALID\n");
    }
}

int every_other_digit(long visa)
{
    int sum = 0;
    int div = 1;
    while (visa > 0)
    {
        if (div % 2 == 0)
        {
            sum = sum + double_and_add(visa % 10);
        }
        else
        {
            sum = sum + visa % 10;
        }
        visa = visa / 10;
        div = div + 1;
    }
    return sum;
}

int double_and_add(int number)
{
    number = number * 2;
    int sum = 0;
    while (number > 0)
    {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

int count_digit(long credit)
{
    int digits = 0;
    while (credit > 0)
    {
        digits = digits + 1;
        credit = credit / 10;
    }
    return digits;
}

void check_type(long credit)
{
    int digit = count_digit(credit);
    while (credit > 99)
    {
        credit = credit / 10;
    }
    if (digit == 15 && (credit == 34 || credit == 37))
    {
        printf("AMEX\n");
    }
    else if (digit == 13 && ((credit / 10) == 4))
    {
        printf("VISA\n");
    }
    else if (digit == 16)
    {
        if ((credit / 10) == 4)
        {
            printf("VISA\n");
        }
        else if (credit > 50 && credit < 56)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
