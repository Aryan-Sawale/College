/*devoloping a power function
First we see the naive approach
x = 2, n = 9
poduct = 1;
int i;
for(i = 0; i < 9; i++)
{
    product = product * x
}

but this is O(n) complexity
for O(logn) complexity (recursion):                     n = 8
                    2^8                                 log 8 = 3 
                2^4 * 2^4
         2^2 * 2^2 * 2^2 * 2^2
2^1 * 2^1 * 2^1 * 2^1 * 2^1 * 2^1 * 2^1 * 2^1

2^15 = 2 * 2^7 * 2^7
*/

int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
