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
After the program is done with getting inputs from the user (character by character) it going to open a file (a+ mode : opens a file for reading and appending) with a name which I have given(jubilee.txt) and print the inputs from user with the format given by me into the file that program opened.
Then ask user that want to continue adding events or not.

![addevent_yes](https://user-images.githubusercontent.com/49981164/144654593-ce2fbf59-88fe-4e3d-b08a-1c6064d3a3c0.png)


if the user enter "y",the code runs again from the begining where it was getting inputs (using 'goto') and goes all over steps before.

![addevent_no](https://user-images.githubusercontent.com/49981164/144654947-63cd11db-5d8b-44a8-8582-a1a50aa04f88.png)

if the user enter "n" the function will terminate and show the the user menu again for user to choose other option.

<3. Look Events>

Opens jubilee.txt file and prints character by character if reach end of the line goes next line and keep printing until reaches EOF (end of file).

![1](https://user-images.githubusercontent.com/49981164/145841591-7c1dca1d-7aff-4aa5-b7d2-0f6574b3302b.png)
