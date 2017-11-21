#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"

typedef enum {	ADD_CONTACT,
		ADD_INFORMATION,
		PRINT_CONTACT,
		COUNT,
		PRINT,
		ADD_CONTACT_ORDERED,
		ADD_INFORMATION_ORDERED,
		REMOVE_CONTACT,
		REMOVE_INFORMATION,
		HELP,
		QUIT,
		INVALID } Option;

// auxiliary functions
Option getAction(void);
void printOptions(void);
void optionDetails(void);
char *getString(char *);

// main routine
int main( int argc, char* argv[ ] ) {
	Contact *myContacts = NULL;
	char *contactName, *infoName, *infoValue;
	Option opt;

	printf("\n\nProject 6 - contact management system\n\n");
	opt = getAction();
	while (opt != QUIT) {
		switch (opt) {
			case ADD_CONTACT:
				printf("Adding a new contact\n");
				contactName = getString("Enter the name of the new contact");
				printf("\n\tAdding the contact '%s' (add-at-front) \n", contactName);
				myContacts = addContact(myContacts, contactName);
				break;
			case ADD_INFORMATION:
				printf("Add information to an existing contact\n");
				contactName = getString("Enter the name of the contact");
				infoName = getString("Enter the name of the information to add");
				infoValue = getString("Enter the information value");
				printf("\n\tAdding the  information <'%s'|'%s'> to the contact '%s' (add-at-end)\n",
						infoName, infoValue, contactName);
				addInformation(myContacts, contactName, infoName, infoValue);
				break;
			case PRINT_CONTACT:
				printf("Print a contact\n");
				contactName = getString("Enter the name of the contact");
				printf("\n\tPrinting the contact '%s'\n", contactName);
				printContact(myContacts, contactName);
				break;
			case COUNT:
				printf("Print the number of contacts\n");
				printf("\n\tYou have %d contacts\n", count(myContacts) );
				break;
			case PRINT:
				printf("Print all the contacts\n");
				print(myContacts);
				break;
			case ADD_CONTACT_ORDERED:
				printf("Adding a new contact (in alphabetical order)\n");
				contactName = getString("Enter the name of the new contact");
				printf("\n\tAdding contact '%s' (in alphabetical order)\n", contactName);
				myContacts = addContactOrdered(myContacts, contactName);
				break;
			case ADD_INFORMATION_ORDERED:
				printf("Adding information to a contact (in alphabetical order)\n");
				contactName = getString("Enter the name of the contact");
				infoName = getString("Enter the name of the information");
				infoValue = getString("Enter the information value");
				printf("\n\tAdding the information <'%s'|'%s'> to the contact '%s' (in alphabetical order)\n",
						infoName, infoValue, contactName);
				addInformationOrdered(myContacts, contactName, infoName, infoValue);
				break;
			case REMOVE_INFORMATION:
				printf("Removing information from a contact\n");
				contactName = getString("Enter the name of the contact");
				infoName = getString("Enter the name of the information to remove");
				printf("\n\tRemoving the information '%s' from the contact %s\n", 
						infoName, contactName);
				removeInformation(myContacts, contactName, infoName);
				break;
			case REMOVE_CONTACT:
				printf("Removing a contact\n");
				contactName = getString("Enter the name of the contact to remove");
				printf("\n\tRemoving the contact %s\n", contactName);
				myContacts = removeContact(myContacts, contactName);
				break;
			case HELP:
				optionDetails();
				break;
			default: break;
		}
		opt = getAction();
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////

Option getAction(void) {
	// print the list of options
	printOptions();
	Option answer = INVALID;

	while (answer == INVALID) {
		// read the user command
		char input[32];
		fgets(input, 31, stdin);
		input[strlen(input)-1] = '\0';

		// update answer
		if (strcmp(input, "quit") == 0)			answer = QUIT;
		else if (strcmp(input, "addContact") == 0)	answer = ADD_CONTACT;
		else if (strcmp(input, "addInformation") == 0)	answer = ADD_INFORMATION;
		else if (strcmp(input, "printContact") == 0)	answer = PRINT_CONTACT;
		else if (strcmp(input, "count") == 0)		answer = COUNT;
		else if (strcmp(input, "print") == 0)		answer = PRINT;
		else if (strcmp(input, "addContactOrdered") == 0) answer = ADD_CONTACT_ORDERED;
		else if (strcmp(input, "addInformationOrdered") == 0) answer = ADD_INFORMATION_ORDERED;
		else if (strcmp(input, "removeContact") == 0)	answer = REMOVE_CONTACT;
		else if (strcmp(input, "removeInformation") == 0) answer = REMOVE_INFORMATION;
		else if (strcmp(input, "help") == 0)		answer = HELP;
		else {
			if (strlen(input)>0) {
				printf("\nINVALID OPTION\n");
				printOptions();
			}
		}
	}
	return answer;
}

void printOptions(void) {
	printf("\nOptions: addContact addInformation printContact count print addContactOrdered addInformationOrdered removeContact removeInformation help quit\n");
	printf("Select an option: ");
}

void optionDetails(void) {
	printf("\nThe Options are:\n");
	printf("\taddContact             Create a new contact (add-at-front)\n");
	printf("\taddInformation         Add information to an existing contact (add-at-end)\n");
	printf("\tprintContact           Print a contact\n");
	printf("\tcount                  Return the number of contacts\n");
	printf("\tprint                  Print all contacts\n");
	printf("\taddContactOrdered      Create a new contact (in alphabetical order)\n");
	printf("\taddInformationOrdered  Add information to an existing contact (in alphabetical order)\n");
	printf("\tremoveContact          Remove a contact\n");
	printf("\tremoveInformation      Remove information from a contact\n");
	printf("\thelp                   Display this detailed menu\n");
	printf("\tquit                   Exit the program\n");
}

char *getString(char *str) {
	char input[1024];
	printf("%s : ", str);
	fgets(input, 1023, stdin);
	input[strlen(input)-1] = '\0';	// get rid of \n character
	char *answer = (char *) malloc (strlen(input) + 1);
	strcpy(answer, input);
	return answer;
}
