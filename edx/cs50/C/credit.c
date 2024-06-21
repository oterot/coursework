#include <stdio.h>
#include <cs50.h>

//function to sum the digits of given number
long sum_of_digits(long x)
{
    long sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    return (sum);
}

int main(void)
{
    // get number from the user
    long n = get_long("Number: ");
    long sum = 0;
    int product = 0;
    bool odd = true;
    int current_digit = 0;
    int previous_digit = 0;
    int digit_count = 0;

    while (n != 0)
    {
        digit_count++;
        previous_digit = current_digit;
        // mod 10 gets us the rightmost current digit
        current_digit = n % 10;

        // if current digit index is odd then we add it to our sum
        if (odd == true)
        {
            sum += current_digit;
            odd = false;
        }

        // if current digit is even we'll multiply by 2 then add the product of the digits to our sum
        else
        {
            product = current_digit * 2;
            sum += sum_of_digits(product);
            odd = true;
        }
        n = n / 10;
    }

    int index = current_digit * 10 + previous_digit;

    // VISA format
    if (sum % 10 == 0 && current_digit == 4 && (digit_count == 13 || digit_count == 16))
    {
        printf("VISA\n");
    }
    // AMEX format
    else if (sum % 10 == 0 && (index == 34 || index == 37) && digit_count == 15)
    {
        printf("AMEX\n");
    }
    // Mastercard format
    else if (sum % 10 == 0 && (index >= 51 && index <= 55) && digit_count == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}