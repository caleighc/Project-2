/**
 * birthdays.cpp
 * Project UID: 59fc568b7f83f8c109ae360f448f7f821ba0a71
 * 
 * <#Name#>
 * <#Uniqname#>
 *
 * EECS 183: Project 2
 *
 * <#description#>
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 *
 *           This function must call isLeapYear().
 */
void print10LeapYears();

/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */
void birthdays() {    
    // TODO: implement
    //only 1, 2, 3 are in range for choice / menu selection
    int menuChoice = 0;
//begin
    printHeading();

    while (menuChoice != 3) {
 
        //getMenuChoice(); //do i need to call this separately??
        menuChoice = getMenuChoice();

        if (menuChoice == 1){
        cout << "Enter your date of birth" << endl;
        cout << "format: month / day / year  --> " << endl;
        //call some function
        }
        if (menuChoice ==2 ){
        cout << "Enter year --> " << endl;
          
        }

        
    } //end of outer while loop

    //getMenuChoice(); //ugh i think get menu choice has to be in a loop in this
    //function instead. this is going to be the inner while loop of a nested while

 //end
    printCloser();
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    // TODO: implement
    //only 1, 2, 3 are in range for choice / menu selection
    int menuChoice = 0;

    
        //print menu to screen
        
        

         while (menuChoice !=1 ||menuChoice != 2 || menuChoice != 3){
        //print menu to screen
        //printMenu();
        printMenu();
        //get info, set variable from function call
        //getMenuChoice(); //do i need to call this separately??
         cin >> menuChoice;

        if (menuChoice !=1 ||menuChoice != 2 || menuChoice != 3){
        //tells user the choice is invalid and the loop iterates again
        cout << "Invalid menu choice" << endl;
        }
    } //end of outer while loop

    // returning 0 to avoid compile error
    //return 0;
    return menuChoice;
}

bool isGregorianDate(int month, int day, int year) {
    // TODO: implement
    // 9, 14, 1752
    // And day on or after September 14th, 1752 is a Gregorian date
    if (year >= 1753) {
        return true;
    }
    else if (year == 1752) {
        if (month > 9) {
            return true;
        }
        if (month == 9) {
            if (day >= 14) {
                return true;
            }
        }
        // Returns false is the month is less than 9 or the day isn't >= 14
        return false;
    }
    // Returns false is year if less than 1752
    else {
        return false;
    }
}

bool isLeapYear(int year) {
    // TODO: implement
    if (year % 400 == 0){
       return true;
    }
    else if ((year % 100 != 0) && (year % 4 == 0)){
        return true;
    }
    else {
        return false;
    }
}


bool isValidDate(int month, int day, int year) {
    // TODO: implement
    // If it isn't a gregorian date the function is going to return false and we are done
    if (isGregorianDate(month, day, year) == false) {
        return false;
    }
    // If month isn't valid the function is going to return false and we are done
    if (month < 1 || month > 12) {
        return false;
    }
    // Check if the year is a leap year
    bool leapYear = isLeapYear(year);
    // April 4, June 6, September 9, November 11
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
            return true;
        }
    }
    // January 1, March 3, May 5, July 7, August 8, October 10, December 12
    if (month == 1 || month == 3 || month == 5 || month == 8 || month == 10 || month ==12) {
        if (day >= 1 && day <= 31) {
            return true;
        }
    }
    // February 2 check
    if (leapYear == true && month == 2) {
        if (day >= 1 && day <= 29) {
            return true;
        }
    }
    if (leapYear == false && month == 2) {
        if (day >= 1 && day <= 28) {
            return true;
        }
    }
    // Returns false after checking all other statements for a valid date 
    return false;
}


int determineDay(int month, int day, int year) {
    // TODO: implement
    
    // returning 0 to avoid compile error
    return 0;
}


void printDayOfBirth(int day) {
    // TODO: implement
    
    return;
}


void determineDayOfBirth() {
    // TODO: implement
    
    return;
}

void print10LeapYears() {
    // TODO: implement
    
    return;
}
