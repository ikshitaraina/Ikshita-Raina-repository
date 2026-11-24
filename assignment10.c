
#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int days[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int first_day;

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    struct tm date = {0};
    time_t t;

    printf("Enter year: ");
    scanf("%d", &year);

    if (year < 1900 || year > 9999)
    {
        printf("Invalid year");
        return 0;
    }

    // Check leap year
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        days[1] = 29;
    }

    // Find first day of the year
    date.tm_year = year - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_isdst = -1;

    t = mktime(&date);

    if (t == (time_t)-1)
    {
        printf("Unable to calculate calendar");
        return 0;
    }

    first_day = date.tm_wday;

    // Print calendar for all 12 months
    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);

        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Print blank spaces
        for (int i = 0; i < first_day; i++)
        {
            printf("    ");
        }

        // Print dates
        for (day = 1; day <= days[month]; day++)
        {
            printf("%4d", day);

            if ((first_day + day) % 7 == 0)
            {
                printf("\n");
            }
        }

        // Calculate first day of next month
        first_day = (first_day + days[month]) % 7;
    }

    printf("\n");

    return 0;
}
