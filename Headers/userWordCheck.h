/*

	This header file contains the function that allows the user to search for a particular event by using a keyword.
	Once the keyword found, all the details about that specific event will be displayed on the screen.
	If there is more than one event with that specific keyword, then all the events containing that keyword
	will be displayed on the screen.

	Written by: Rouhollah - Rayan - Rron.

    Last modified: 16 Nov. 2021.

*/



// This function asks the user to type a keyword and then opens a text file.
// It looks for that keyword through the whole file, line by line, word by word.
// Once the keyword found, it will print all the events containing that keyword and adds an Event Tag to them
// The Event Tag is the number of the line where the event is found
int userWordCheck()
{
	// declaring some variables
    char keyWord[64], storedLines[512];
	int n, m, i, j, line;  // i and j are the indexes for the character arrays storedLines and keyWord respectively

	// declaring a file pointer and opening the file in read mode
	FILE* fp;
	fp = fopen("jubilee", "r");

	// getting the keyword from the user
	printf("\tWhat events are you looking for?  ");
	getchar();
	gets(keyWord);

	// storing the length of the keyword inside the variable m
	m = strlen(keyWord);

	line = 0;

	// This while-loop goes through the whole file "fp" line by line and each line is stored inside the variable storedLines
	// It will only stop when it reaches the end of the file
	// The fgets() function reads up to 512 characters from one line inside the file and then copies them inside storedLines
	// At the end of the file, fgets() will return NULL which will end the while-loop
	while (fgets(storedLines, 512, fp) != NULL)
	{
		i = 0;  // counter that allows us to go through the whole line later
		n = strlen(storedLines);  // assigning the value of the length of the stored line to "n"

		printf("The events you were looking for : \n");

		// This while-loop makes sure to go through the whole line
		while (i < n)
		{
			j = 0;

			// This while-loop compares the keyword given by the user with the words present in the stored line
			// It keeps incrementing the indexes i and j until the i becomes greater than n (which means that
			// we reached the end of the line) or until j becomes greater than m (which means that we reached
			// the end of the keyword entered by the user).
			// The other condition for this while-loop to stop is if the characters compared dont match.
			while (i < n && j < m && storedLines[i] == keyWord[j]) {
				++i, ++j;
			}

			// This if statement checks if the words actually match
			// It only prints the line of text containing the keyword
			// It recognises the end of the word by checking if it reached the end of the file or a blank space or a new line
			if ((i == n || storedLines[i] == ' ' || storedLines[i] == '\n') && j == m)
			{
				// the event tag represents the line number of the sentence
				printf("\t Event Tag: %d ->\t %s ", line+1, storedLines);  // prints the corresponding line
			}

			// moving to the next word
			while (i < n && storedLines[i] != ' ')
			{
				++i;
			}
			++i;
		}

		++line;

	}  // end of the main while-loop

	fclose(fp);  // closing the file
	return 0;
}
