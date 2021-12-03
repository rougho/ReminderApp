# ReminderApp

An anniversary reminder application using C 

![Screenshot 2021-12-03 182821](https://user-images.githubusercontent.com/49981164/144646421-3960dc6a-51f2-4bd2-92f5-828539e5d1fc.png)

This Calendar is a simple program that allows the users to add or delete different events during the year.
The users can then review all the events added by them. When the users want to add an event, they will be
first asked to add the date (dd/mm/yyyy) and then further add more details about the event itself (topic and description).
In order to delete an event, the users will have to select the “delete” option in the menu and then enter any keyword
about the event. If the keyword is found, then the user is given the choice to delete it.

this project is made by different header files which carry the functions for each part such as delete,search,calender,menu and so on and
it written using Code::Block IDE and cygwin64 compiler.


![addevent](https://user-images.githubusercontent.com/49981164/144650812-5351e37d-91ce-428f-adc6-d3b5d62982c1.png)

as you can see in the menu there is 6 option to pick, depends to which number user going to enter the program will run a function related to the option.

<1.add event>

When user enter 1 the codes in the main.h will run to ask the user for the information of event and then going to store them in a struct in an array.
After the program is done with getting inputs from the user (character by character) it going to open a file (a+ mode : opens a file for reading and appending) with a name which I have given(jubilee.txt) and print the inputs from user with the format given by me into the file the program opened.
Then ask user that want to continue adding events or not.
