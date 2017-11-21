#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct info {
	char *name;
	char *value;
	struct info *next;
} Info;

////////////////////////////////////////////////////////////////////////////////////////

typedef struct contact {
	char *name;
	Info *information;
	struct contact *next;
} Contact;

////////////////////////////////////////////////////////////////////////////////////////

Contact* addContact(Contact *, char *);
void addInformation(Contact *, char *, char *, char *);
void printContact(Contact *, char *);
int count(Contact *);
void print(Contact *);
Contact* addContactOrdered(Contact *, char *);
void addInformationOrdered(Contact *, char *, char *, char *);
Contact *removeContact(Contact *, char *);
void removeInformation(Contact *, char *, char *); 

////////////////////////////////////////////////////////////////////////////////////////
