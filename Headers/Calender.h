/*

    This header file contains the functions that will allow the user to print out the calender of any given year.
    The user will be asked which year he wants to view.

    Copyrights: E-mitra Help Desk For_You (YouTube)

    Modified by: Rouhollah - Rayan - Rron .
    Last modified: 15 Nov. 2021

*/




// This function determines the first day of the year using the "Doomsday Algorithm"
// It takes the year entered by the user as an argument and returns the day
int get_first_weekDay(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;

    return day;
}


// Prints out the calender of a given year
int Calender()
{
    // defining and initializing some variables
    int year;
    int day = 0;
    int dayInMonth;
    int weekDay = 0;
    int startingDay;
    int month;

    // takes the desired year as an input
    printf("\t-> Enter your desired year: ");
    scanf("%d", &year);  // the value will be used later by the get_first_weekDay() function

    // defining and initializing the pointer variable months
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // defining and declaring the array monthDays
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // checking if it is a leap year or not
    if((year%4 == 0 && year%100 !=0) || year%400==0)
    {
        monthDays[1] = 29;  // sets February to 29 days if it is a leap year
    }

    // assigning the return value of get_first_weekDay() to the variable startingDay
    startingDay = get_first_weekDay(year);

    // doing this loop for each month
    for(month = 0; month < 12; month++)
    {
        dayInMonth = monthDays[month]+1;
        printf("\n\n\t------------------------%s-----------------------",months[month]);
        printf("\n\t   Sun     Mon     Tue     Wed    Thurs    Fri     Sat\n");

        // doing this loop for each week of the month
        for(weekDay = 0; weekDay < startingDay; weekDay++)
        {
           printf("     ");
        }

        // doing this loop for each day of the week
        for(day = 1; day < dayInMonth; day++)
        {
            printf("\t%5d", day);
            if(++weekDay > 6)
            {
                printf("\n");
                weekDay = 0;
            }
            startingDay = weekDay;
        }
    }  // end of the main for-loop

return 0;

}
