#include "contact.h" 


  void printstheinformation ( Info *head );

/////////////////////////////////////////////////////////////////////////////////////////////
// add a new contact to your list of contacts
//	   1. Make sure a contact by that name does not exist (print an error message and exit if it exists)
//	   2. Add a new contact with that name (add-at-front)

Contact* addContact(Contact *myContacts, char *contactName) {
     Contact *checker = myContacts;
     while(checker){
     if(  strcmp(contactName,checker->name) == 0 ){
             printf("Oops,Seems like this contact already exists !! \n");
             return NULL;
             }
     checker = checker->next;
     }
   Contact *newnode = malloc(sizeof(Contact));
   newnode->name = malloc(strlen(contactName)+1);
   strcpy(newnode->name,contactName);
   newnode->information = NULL;
   newnode->next = myContacts;
   myContacts = newnode;
      return myContacts;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a new piece of inforamtion to the specified contact
//   1. Make sure a contact by that name exists (so you can add information to it)
//   2. If the informational item already exists, update the information's value to the new value
//   3. Otherwise, add the piece of information to the end of the contact's information list (add-at-end)
// ******************************************************************************************

Info *  addsattheend ( Info *infoshead , char *infoName, char *infoValue){

         if(infoshead != NULL){
         printf("The value when the head enters is %s \n \n ", infoshead->value);
    }


      Info *newnode = malloc(sizeof(Info));
      newnode->name = malloc(strlen(infoName) + 1);
      strcpy(newnode->name,infoName);
      newnode->value = malloc(strlen(infoValue)+1);
      strcpy(newnode->value,infoValue);
      newnode->next = NULL;

      if(infoshead == NULL)
          return  newnode;

        Info *temp = infoshead;
        while(temp->next != NULL){
          temp = temp->next;
          }
        temp->next = newnode;
  
  
         printf("The value when the head enters is %s \n \n ", infoshead->value);


        return infoshead ;
        }

//*********************************************************************************************************************************************

void addInformation(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {


   int count = 0;
  Contact *checker = myContacts;
  while(checker){
    if(strcmp(contactName,checker->name) == 0)
     count ++;      
    checker = checker->next;
  }
  if (count == 0) {
     printf("Wait, you are trying to add an information to a contact that does not even exists!! \n");
     return ;
     }
    
   Contact *contactpointer = myContacts;

     while (contactpointer) {

           if(strcmp(contactName,contactpointer->name) == 0) {
            
             Info *infoshead = contactpointer->information;
            
                Info *checks = infoshead;

                while (checks != NULL){
                   if(strcmp(checks->name,infoName)==0){
                       checks->value = infoValue;
                       return;
                    }
                checks = checks->next;
            }

            infoshead  =  addsattheend(infoshead,infoName,infoValue);
            printf("%s\n", infoshead->value);
       contactpointer->information = infoshead;
       }
        contactpointer = contactpointer->next;
        }
 
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// prints all the information for a given contact
//	1. Make sure a contact with that name exists
//	2. Print the name of the contact
//	3. print all the informational items <name|value> associated with that contact

void printContact(Contact *myContacts, char *contactName) {
  int count = 0;
  Contact *checker = myContacts;
  while(checker){
  if(strcmp(contactName,checker->name) == 0)
  count++;
  checker  = checker->next;
  }
 
 if (count == 0) {
    printf("  Ooopps!! The contact names does not matches \n");
    return ;
    }
   
  while(myContacts) {
     if(strcmp(myContacts->name,contactName) == 0 ) {
        printf(" %s \n", myContacts->name);
        printstheinformation(myContacts->information);
          }
    myContacts = myContacts->next;
    }

         
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// returns the size of a given contact list
//	Iterate through the contact list to count the number of contacts, return that count
int count(Contact *myContacts) {
  
  int count = 0;
  
    while(myContacts){
      count++;
      myContacts = myContacts->next;
    }
   
	return count;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//***********************************************************

  void printstheinformation ( Info *head ){
     
     while(head){

     printf(" < %s | %s > \n", head->name, head->value);

     head = head->next;
     }
  return ;
  }

//********************************************************************************

// prints all your contacts
//	For each contact
//	   a.  Print the name of the contact
//	   b.  Print all the <information name|information value> pairs in that contact
//	Note: this code can call other functions as needed
void print(Contact *myContacts) {
      
      while (myContacts) {
        
        printf("%s\n", myContacts->name);
        printstheinformation(myContacts->information);
        myContacts = myContacts->next;
    }
     return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a new contact (in alphabetical order)
//	1. Make sure a contact by that name does not exist 
//	2. Add a new contact with that name (add-in-order)

Contact *addContactOrdered(Contact *myContacts, char *contactName) {
	        Contact*checker = myContacts;
        while (checker) {
            if(strcmp(checker->name,contactName) == 0) {
            printf(" LOL!! You have already added this contact \n");
            return NULL;
        }
           checker = checker->next;
           }
    
    Contact *newnode = malloc(sizeof(Contact));
    newnode->name = malloc(strlen(contactName) + 1);
    strcpy(newnode->name,contactName);
    newnode->information = NULL;
    newnode->next = NULL;

    if (myContacts == NULL) 
      return newnode;

    if (strcmp(myContacts->name,contactName) > 0 ){
       newnode->next = myContacts;
       return newnode;
       }
    
    Contact *previous = myContacts;
    Contact *current = previous -> next ;
    
    while (current !=  NULL && (strcmp(contactName,current->name) > 0) ) {
          previous = current;
          current = current->next;
        }
    previous->next = newnode;
    newnode->next = current;
    return myContacts;
}



/////////////////////////////////////////////////////////////////////////////////////////////
// adds a new info to the specified contact (in alphabetical order)
//	1. Make sure a contact by that name exists (so you can add an info to it)
//	2. If the informational item already exists, update the item (replace its value with the new value)
//	3. Otherwise, add the new info to the contact (add-in-order)

//.................................................................................................................
Info * addsinorder ( Info * head, char *infoName, char *infoValue){

  Info *newnode = malloc(sizeof(Info));
  newnode->name = malloc(strlen(infoName)+1);
  strcpy(newnode->name, infoName);
  newnode->value = malloc(strlen(infoValue)+1);
  strcpy(newnode->value, infoValue);
  newnode->next = NULL;

  if(head == NULL) 
    return newnode;
  
  if(strcmp(head->name,infoName) > 0 ) {
     newnode->next = head;
      return newnode;
    }
  
  Info *previous = head;
  Info *current = previous->next;
   
   while (current &&  strcmp(infoName,current->name) > 0 ) {
      previous = current;
      current = current->next;
      }
   previous->next = newnode;
   newnode->next = current;
 Info *headcheck = head;
while(headcheck) {
  printf("%s %s \n", headcheck->name, headcheck->value);
  headcheck = headcheck->next;
  }
  
return head ;
}
//......................................................................................................................
void addInformationOrdered(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {

    int count = 0;
    Contact *checker = myContacts;
    while(checker){
     if(strcmp(checker->name,contactName) == 0) {
        count++; }
    checker = checker->next;
    }
    if (count == 0) {
      printf(" Oh NO!! You are trying to add the information to a contact that does not exist\n");
      return;
      }
   
   Info *infoshead = NULL;
   Contact *findscontact = myContacts;
    Info *infochecker = NULL;
    while (findscontact) {
       if(strcmp(findscontact->name,contactName) == 0 ) {
           infoshead = findscontact->information;
        infochecker = infoshead;
        while(infochecker) {
          printf(" %s %s \n", infochecker->name, infochecker->value);
          infochecker= infochecker ->next;
          }
          //check if the info name matches??
             infochecker = infoshead;
              while(infochecker) {
                if(strcmp(infochecker->name,infoName) == 0){ 
                  infochecker->value = infoValue;
                  return;}

                  infochecker = infochecker->next; 
                  }

        //If it does not matches then add information.
          printf("***************\n");
              infoshead = addsinorder(infoshead,infoName,infoValue);
   printf("Wait, it called the function\n\n");

              Info *tempcheck = infoshead;
              while(tempcheck){
                 printf("%s %s \n", tempcheck->name,tempcheck->value);
                 tempcheck = tempcheck->next;
                 }
              findscontact->information = infoshead;
                                   }
        findscontact = findscontact->next;
        }
  
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// remove information from a contact
//	1. Make sure a contact with that name exists
//	2. Make sure the informational item exists in that contact
//	3. Remove that piece of information from the contact
//..................................................................

 Info* removestheinfo ( Info * head, char *infoName) {

     if (strcmp(head->name,infoName) == 0) {
        Info *newhead = head->next;
           free(head);
           return newhead;
           }
        
        Info *previous = head;
        Info *current = head->next;
        while (current && strcmp(current->name,infoName) != 0 ) {
        previous = current;
        current = current->next;
        }
    
    previous->next = current->next;
    free(current);
    return head;
    }









//..........................................................................

void removeInformation(Contact *myContacts, char *contactName, char *infoName) {
   int count = 0;
  
  Contact *checker = myContacts;
    while(checker) {
      if(strcmp(checker->name, contactName) == 0)
      count++;
    checker = checker->next;
}
   if (count == 0){
     printf(" Oops! There is no such contact \n ");
     return ;
     }
   
   Contact *contactchecker = myContacts;
    Info *infoshead = NULL;
    Info *infochecker = NULL;
    while(contactchecker) {
        if(strcmp(contactchecker->name,contactName) == 0) {
                infoshead = contactchecker->information;
                  infochecker = infoshead;
                  int count = 0;
                  while(infochecker) {
                   if(strcmp(infochecker->name, infoName) == 0) count++;
                  infochecker = infochecker->next;
                  }
                    if(count == 0 ) {
                       printf("There is no such information found in the given contact \n");
                       return; }

                infoshead = removestheinfo(infoshead,infoName);
                contactchecker->information = infoshead;
                      }
   
   contactchecker = contactchecker->next;
   }
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a contact (and all the informational items for that contact)
//	1. Make sure a contact with that name exists
//	2. Remove that contact 

Contact *removeContact(Contact *myContacts, char *contactName) {
   int count = 0;
  
  Contact *checker = myContacts;
    while(checker) {
      if(strcmp(checker->name, contactName) == 0)
      count++;
    checker = checker->next;
}
      if(count == 0) {
      printf(" HAHAHAH!! you are trying to remove the contact that does not even exist\n");
      return NULL;
      }
    
    if(myContacts == NULL) return myContacts;
     
     if(strcmp (myContacts->name,contactName) == 0) {
        Contact *newhead = myContacts->next;
        free(myContacts);
        return newhead;
    }

        Contact *previous = myContacts;
        Contact *current = previous->next;

        while (current && strcmp(current->name, contactName) != 0) {
            previous = current;
            current = current->next;
        }
          previous->next = current->next;
          free(current);
          return myContacts;
          }


