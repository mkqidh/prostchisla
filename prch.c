#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int isPrime(long long num)
{
    if (num <= 2) return 0;

    if (num % 2 != 0)
    {
        for (long long del = 3; del * del <= num; del += 2)
        {
            if (num % del == 0)
                return 0;
        }
    }
    else return 0;
    return 1;
}

void createNumber(long long num, long long max, long long prostue[], int* count)
{
    if (0 < num && num <= max)
    {
        prostue[*count] = num;
        *count += 1;
    }
    for (int i = 1; i <= 9; i += 2)
    {
        if (num * 10 + i <= max && isPrime(num * 10 + i))
        {
            createNumber(num * 10 + i, max, prostue, count);
        }
    }
}

int main(int argX, char* limArg[])
{
    setlocale(LC_ALL, "Rus");

    long long ch = 4294967296;
    long long prostue[500];
    int count = 0;
    char chislo[100];
    int last = -1;

    if (argX > 1)
        ch = atoll(limArg[1]);

    if (ch > 4294967296)
        ch = 4294967296;

    long long range = 1;

    printf("Введите диапазон поиска гиперпростых чиcел (до 2^32): ");
    createNumber(1, ch, prostue, &count);
    createNumber(2, ch, prostue, &count);
    createNumber(3, ch, prostue, &count);
    createNumber(5, ch, prostue, &count);
    createNumber(7, ch, prostue, &count);

    printf("Гиперпростые числа до %llu:\n", ch);

    while (range != 10000000000) 
    {

        for (int i = 0; i < count; i++) {

            if (range <= prostue[i] && prostue[i] < range * 10)
                printf("%lld\n", prostue[i]);
        }
        range *= 10;
    }
    range = 1;

    printf("Всего гиперпростых чисел: %d\n", count);

    
}



