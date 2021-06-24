#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _person {
	char* firstName;
	char* lastName;
	char* title;
	unsigned int age;
} Person;

typedef struct _alternatePerson {
	char* firstName;
	char* lastName;
	char* title;
	unsigned int age;
} AlternatePerson;

void initializePerson(Person* person, const char* fn,
			const char* ln, const char* title, uint age) {
	person->firstName = (char*)malloc(strlen(fn)+1);
	strcpy(person->firstName, fn);
	person->lastName = (char*)malloc(strlen(ln)+1);
	strcpy(person->lastName, ln);
	person->title = (char*)malloc(strlen(title)+1);
	strcpy(person->title, title);
	person->age = age;
}

void deallocatePerson(Person *person) {
	free(person->firstName);
	free(person->lastName);
	free(person->title);
}

void processPerson() {
	Person* ptrPerson;
	ptrPerson = (Person*)malloc(sizeof(Person));

	initializePerson(ptrPerson, "Peter", "Underwood", "Manager", 38);
	
	deallocatePerson(ptrPerson);
	free(ptrPerson);
}	


int main() {
	Person person;
	AlternatePerson otherPerson;

	printf("%d\n", sizeof(Person));
	printf("%d\n", sizeof(otherPerson));

	processPerson();
	//printf("%s\n", per->firstName);

	return 0;
}


	
	
