/*

    This header file contains the functions that will allow the user to delete any choosen event. It asks the user
    to enter a keyword in order to search for the event that he/she wants to delete.
    If there is more than one event with that specific keyword, then it will ask the user which event they want to delete
    by typing in the ID number of the event (the ID number of each event found is displayed on the screen).

    Written by: Rouhollah - Rayan - Rron.



*/




// This function takes an input (event name) from the user and checks whether that event is present in the
// text file or not, the results of the search are then printed out with an Event Tag specific to each event.
// The user will be then asked which event they want to delete by entering the corresponding Event Tag.
// The first part of this function works similarly as the userWordCheck()
void Delete()
{
    // declaring two file pointers
    FILE *fRead, *fWrite;

    // declaring some other variables
    char *TextFile;
    char c;
    char keyWord[64], storedLines[512];
	int n, m, i, j, line, deleteTag, temp = 1;

    // name of the text file to read from
    TextFile = "jubilee.txt";
    fRead = fopen(TextFile, "r");

    getchar();
    printf("\tWhich event do you want to delete? (please type a keyword) ");
	gets(keyWord);

    m = strlen(keyWord);
	line = 0;

	while (fgets(storedLines, 512, fRead) != NULL)
    {
		i = 0;
		n = strlen(storedLines);
		while (i < n)
        {
			j = 0;

			while (i < n && j < m && storedLines[i] == keyWord[j])
            {
				++i, ++j;
			}
			if ((i == n || storedLines[i] == ' ' || storedLines[i] == '\n') && j == m) {
				printf("Event Tag: %d ->", line+1);
				printf("%s ", storedLines);

			}

			while (i < n && storedLines[i] != ' ') {
				++i;
			}
			++i;
		}

		++line;
	}




    // After the result of the search along with the events tags are printed
    // The user is asked to pick one Event Tag in order to delete the corresponding event
    // The Event Tag will be stored in the variable
    printf("\n\tplease choose a tag number:");
    scanf("%d", &deleteTag);

    c = getc(fRead);

    // reading the file character by character until reaching the end of the file
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fRead);
    }

    // setting the position to the beggining of the file
    rewind(fRead);

    // opening the file "copy.c" in write mode
    // it will write all the events inside this new file except the one that we chose to delete
    fWrite = fopen("copy.c", "w");
    c = getc(fRead);

    // This loop runs as long as it did not reach the end of the file
    while (c != EOF)
    {
        // reading the "jubilee.txt" character by character
        c = getc(fRead);

        // checks if it reached a new line (which also means next event)
        if (c == '\n')
        {
            temp++;  // tracks the number of lines that we are copying in the new file
        }            // (number of line == Event Tag == deleteTag)

        // If the line that we are about to copy in the new file does not correspond to the Event Tag that we want to delete
        // Then we go on and copy the character inside the new file
        if (temp != deleteTag)
        {
            putc(c, fWrite);
        }
    }  // end of while-loop

    // closing the files
    fclose(fRead);
    fclose(fWrite);

    // removing the old file after getting the new copy of it which does not have the deleted event
    remove(TextFile);

    // renaming the new file giving it the same name as the old file
    rename("copy.c", TextFile);
    printf("\nThe event deleted successfully!\n");

}




