/*

    This header file contains the functions that will allow the user to access the text file jubilee.txt
    and print out all the events contained there on the terminal window.

    Written by: Rouhollah - Rayan - Rron.



*/


// This function reads all the content inside the text file jubilee.txt that contains all the events added
// by the user previously and then prints it on the terminal window to allow the user to see all their entries
void lookEvents()
{
    // declaring a file pointer and some other variables
    FILE *fp;
    int j, k, c;

    // opening the text file in read mode
    fp = fopen("jubilee.txt", "r");

    // initializing the counter that allows to print max. 100 different entries (events)
    k = 0;

    // starting the loop to print the events one by one (max. 100 events)
    while (k < 100)
    {
        // This for-loop reads the file character by character until it reaches 255 characters
        // or it reaches the end of the line or the end of the file
        for (j = 0; (j < 255) && ((c = getc(fp)) != EOF) && (c !='\n'); ++j)
        {
            printf("%c", c);  // prints all the characters one by one thanks to the for-loop
        }

        // checks if it is not the end of the file
        if (c != EOF)
        {
            printf("\n");  // if it is not then it is the end of the line, so it jumps to a new line
        }
        else
        {
            break;  // if it is the end of the file then it breaks from the while-loop
        }

        k++;  // incrementing the counter to print the next line present on the text file

    }  // end of the while-loop

fclose(fp);
}

