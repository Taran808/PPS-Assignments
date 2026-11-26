#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    char *monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

    /* Check for leap year */
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        daysInMonth[1] = 29;
    }

    for(month = 0; month < 12; month++)
    {
        struct tm date = {0};

        date.tm_year = year - 1900;
        date.tm_mon = month;
        date.tm_mday = 1;

        mktime(&date);

        printf("\n\n      %s %d\n", monthNames[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        /* Print spaces before the first day */
        for(day = 0; day < date.tm_wday; day++)
        {
            printf("    ");
        }

        /* Print dates */
        for(day = 1; day <= daysInMonth[month]; day++)
        {
            printf("%3d ", day);

            if((day + date.tm_wday) % 7 == 0)
                printf("\n");
        }

        printf("\n");
    }

    return 0;
}
