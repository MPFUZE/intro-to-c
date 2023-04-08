//==============================================
// Name:           Manav Patel
// Student Number: 134182203
// Email:          mdpatel30@myseneca.ca
// Section:        NFF
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name* name)
{

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    // scanf("%c%*c", &yesNo);

    if (yes()) //<-- yes() is for input and check codition if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else
    {
        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
    // char yesNo;
    printf("Please enter the contact's street number: ");
    do
    {
        // scanf("%d", &address->streetNumber);
        address->streetNumber = getInt();
        if (address->streetNumber < 1)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }

        // clearKeyboard();
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    // scanf("%c%*c", &yesNo);

    if (yes()) // <-- if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            // scanf("%d", &address->apartmentNumber);
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 1)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
            // clearKeyboard();
        } while (address->apartmentNumber < 1);
    }
    else
    {
        address->apartmentNumber = 0;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{

    // Do not ask cellPhone Number Mandadory
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell); //<-- scanf("%10[^\n]", numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");

    if (yes()) // <-- if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home); //<-- scanf("%10[^\n]", numbers->home);
    }
    else
    {
        numbers->home[0] = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    if (yes()) // <-- if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business); //<-- scanf("%10[^\n]", numbers->business);
    }
    else
    {
        numbers->business[0] = '\0';
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

