/*

                                                  Final Project
                                                Group 7 - Task 7

    This Calendar is a simple program that allows the users to add or delete different events during the year.
    The users can then review all the events added by them. When the users want to add an event, they will be
    first asked to add the date (dd/mm/yyyy) and then further add more details about the event itself (topic and description).
    In order to delete an event, the users will have to select the “delete” option in the menu and then enter any keyword
    about the event. If the keyword is found, then the user is given the choice to delete it.

    Written by: Rouhollah - Rayan - Rron.

    Created: 10 Nov. 2021.

*/


// including the standard library header files
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// including the headers created specifically for this program
#include "Headers/userMenu.h"
#include "Headers/Calender.h"
#include "Headers/Delete.h"
#include "Headers/lookEvents.h"
#include "Headers/userWordCheck.h"

// defining the struct
struct anniversary {
    char event[64];
    char desc[200];
    int dd,mm,yy;
  };

// defining a struct variable named events
struct anniversary events[100];

// declaring the different functions used in the program
void anniversaryUserInput();
void userMenu();
int userWordCheck();
void Delete();
int Calender();
void lookEvents();

// declaring the variable i and assigning it the value of 0.
// It will be used as a counter to make sure that we can only have max. 100 events
int i = 0;

//main function
int main(void)
{
  system("date");  // system call, displays the current date
  userMenu();
  return 0;
}

// This function takes the input from the user and append it to a file called "jubilee.txt"
// This file will serve like our data-base
// We will then be able to access this file to read its content or modify it
void anniversaryUserInput()
{
  // declaring a file pointer. It is necessary for the communication between the file and the program
  FILE * fp;

  // declaring some other variables
  char userContinue = 'y';
  int j, c;

  // This next block of code will keep executing as long as the user wants to add more events
  // It is possibele thanks to the goto statement
  // (See the if statement bellow)
  loopLabel:

  // This while loop takes the user's input and add it to the text file as long as the user wants to add more events
  // It will break only if the user decides not to add more events or if the number of events added reaches 100
    while (i < 100 && (userContinue =='y' || userContinue == 'Y'))
    {
      printf("\t->Please enter the details of the anniversary or the event that you want to add:\n");

      // takes the user's input
      printf("\t->Enter the Day [dd]: ");
      scanf("%d", &events[i].dd);

      printf("\t->Enter the Month [mm]: ");
      scanf("%d", &events[i].mm);

      printf("\t->Enter the Year [yyyy]: ");
      scanf("%d", &events[i].yy);

      printf("\t->Enter the topic of the event (max 63 character): ");
      getchar();

      // For the strings, the program will take the input character by character and assigns them all inside the event variable element
      // It will only stop if the string exceeds 63 characters or if the user hits the "Enter" key
      for (j = 0; (j  < 63) && ((c = getchar()) != EOF) && (c !='\n'); ++j)
      {
        events[i].event[j] = c;
      }
      events[i].event[j] = '\0'; // adding the null character to indicate the end of the string

      // Same as the event string, the only difference is that the program accepts up to
      // 199 characters and assigns them to the variable element called "desc"
      printf("\t->Enter a description for the event (max 199 character): ");
      for (j = 0; (j  < 199) && ((c = getchar()) != EOF) && (c !='\n'); ++j)
      {
        events[i].desc[j] = c;
      }
      events[i].desc[j] = '\0'; // adding the null character to indicate the end of the string

      // We then open the text file after taking all the user input and assigning it to the corresponding variables
      // We open the file with the append and read mode (a+)
      fp = fopen("jubilee.txt", "a+");

      // printing the content of the struct variable inside the text file
      fprintf(fp,"Date -> %d/%d/%d -> Event: %s -> Description: %s \n", events[i].dd , events[i].mm, events[i].yy, events[i].event, events[i].desc);

      // closing the file in order to release the memory allocated by the program
      fclose(fp);

      printf("\t-> Do you want to add another event? [Y/n]: \n");
      scanf("%c",&userContinue);
      if (userContinue == 'Y' || userContinue == 'y')
      {
        getchar();
        i++;  // increments i in case the user wants to add more events
        goto loopLabel;  // go back all the way up to the label named "loopLabel" and execute all the code inside that again
      }
    i++;  // increments i in case the user does not want to add more events

    }  //while loop ends here
}


