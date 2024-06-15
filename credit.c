#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int luhn(int num[], int len)
{
    int start = len - 2;
    int start2 = len - 1;
    int sum1 = 0;
    int temp = 0;
    int temp1 = 0;
    int temp2 = 0;
    int sum2 = 0;
    int total = 0;
    int i;
    for (i = start; i >= 0; i = i - 2)
    {
        temp = (2 * (num[i] - 48));
        if (temp >= 10)
        {
            temp1 = temp % 10;
            sum1 = sum1 + temp1;
            temp2 = floor(temp / 10);
            sum1 = sum1 + temp2;
        }
        else
        {
            sum1 = sum1 + temp;
        }
    }
    for (i = start2; i >= 0; i = i - 2)
    {
        sum2 = sum2 + ((num[i] - 48));
    }
    total = sum1 + sum2;
    if (total % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string card_type(int num[], int len)
{
    int number = num[0];
    int number2 = num[1];
    string type;
    switch (len)
    {
        case 15:
            if (number == 51)
            {
                if ((number2 == 52) || (number2 == 55))
                {
                    type = "AMEX\n";
                    return type;
                }
                else
                {
                    type = "INVALID\n";
                    return type;
                }
            }
            else
            {
                type = "INVALID\n";
                return type;
            }
            break;
        case 13:
            type = "VISA\n";
            return type;
            break;
        case 16:
            if (number == 53)
            {
                if (number2 <= 53)
                {
                    type = "MASTERCARD\n";
                    return type;
                }
                else
                {
                    type = "INVALID\n";
                    return type;
                }
            }
            else if (number == 52)
            {
                type = "VISA\n";
                return type;
            }
            else
            {
                type = "INVALID\n";
                return type;
            }

            break;
        default:
            type = "INVALID\n";
            return type;
    }
}

int main(void)
{
    int i;
    string creditNum = get_string("Number: ");
    int lengthCredit = strlen(creditNum);
    int creditNumbers[lengthCredit];
    for (i = 0; i < lengthCredit; i++)
    {
        creditNumbers[i] = creditNum[i];
    }

    int sums = luhn(creditNumbers, lengthCredit);
    if (sums == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        string card = card_type(creditNumbers, lengthCredit);
        printf("%s", card);
    }
}
