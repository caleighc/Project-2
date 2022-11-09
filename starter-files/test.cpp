/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * <#Name#>
 * <#Uniqname#>
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,
    // test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    // Add more calls as you implement more functions.
    // While you're working on a function, it can be useful to comment
    //  out the calls to other functions' tests.
    // Make sure the only function you test in a test function
    //  like test_isGregorianDate is that function (isGregorianDate),
    //  or it may cause issues with the autograder.
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;
    // Write additional tests here
}

void test_isGregorianDate()
{
    // isGregorianDate does not read from cin, so
    // all its tests can be run automatically
    cout << "Now testing function isGregorianDate()\n";
    cout << "9/2/2019:  Expected: 1, Actual: " 
         << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: "
         << isGregorianDate(1, 31, 1001) << endl;
    // Valid Gregorian date
    cout << "Expected: 1, actual: "
         << isGregorianDate(8, 19, 2016) << endl;
    // Well before Gregorian date
    cout << "Expected: 0, actual: "
         << isGregorianDate(3, 12, 1234) << endl;
    // continue with more tests
    // Start of Gregorian date
    cout << "Expected: 1, actual: "
         << isGregorianDate(9, 14, 1752) << endl;
    // Day before start of Gregorian date
    cout << "Expected: 0, actual: "
         << isGregorianDate(9, 13, 1752) << endl;
    // Future date 
    cout << "Expected: 0, actual: "
        << isGregorianDate(11, 7, 2030) << endl;
    // Finished testing
    cout << "Finished testing -- isGregorianDate()" << endl
         << endl;
    // Write your tests here
}

void test_isLeapYear()
{
    // Write your tests here
    cout << "Testing -- isLeapYear()" << endl;
    // because 2015 is a Gregorian year
    cout << "Expected: 0, actual: " << isLeapYear(2015) << endl;
    // If a year is not evenly divisible by 4, it is not a leap year
    cout << "Expected: 0, actual: " << isLeapYear(2011) << endl;
    // If a year is divisible by 4 but not 100, it is a leap year
    cout << "Expected: 1, actual: " << isLeapYear(2004) << endl;
    // If a year is divisible by 100 but not 400, it is not a leap year
    cout << "Expected: 0, actual: " << isLeapYear(1900) << endl;
    // If a year is divisible by 100 and 400, it is a leap year
    cout << "Expected: 1, actual: " << isLeapYear(2000) << endl;
    // Finished testing
    cout << "Finished testing -- isLeapYear()" << endl;
}

void test_isValidDate()
{
    // Write your tests here
    cout << "Testing -- isValidDate()" << endl;
    // Invalid dates given in the spec
    // Not a valid month
    cout << "Expected: 0, actual: " << isValidDate(13, 20, 1980) << endl;
    // Not a valid day
    cout << "Expected: 0, actual: " << isValidDate(1, 32, 1980) << endl;
    // Not a valid day
    cout << "Expected: 0, actual: " << isValidDate(4, 31, 2015) << endl;
    // Any day before 9/14/1752
    cout << "Expected: 0, actual: " << isValidDate(5, 23, 1300) << endl;
    // All invalid 
    cout << "Expected: 0, actual: " << isValidDate(13, 32, 1300) << endl;
    // All valid 
    cout << "Expected: 1, actual: " << isValidDate(9, 2, 2019) << endl;
    // Leap year and 29 days in February
    cout << "Expected: 1, actual: " << isValidDate(2, 29, 2000) << endl;
    // Not a leap year and 29 days in February
    cout << "Expected: 0, actual: " << isValidDate(2, 29, 2001) << endl;
    // Start of Gregorian date
    cout << "Expected: 1, actual: " << isValidDate(9, 14, 1752) << endl;
    // Day before start of Gregorian date
    cout << "Expected: 0, actual: " << isValidDate(9, 13, 1752) << endl;
    cout << "Finished testing -- isValidDate()" << endl;
}

void test_determineDay()
{
    // Write your tests here
    cout << "Testing -- determineDay()" << endl;
    // Example in spec 3, (Tuesday)
    cout << "Expected: 3 (Tuesday), actual: " << determineDay(1, 29, 2064) << endl;
    // Texting 0, Saturday
    cout << "Expected: 0 (Saturday), actual: " << determineDay(11, 5, 2022) << endl;
    // Texting 1, Sunday
    cout << "Expected: 1 (Sunday), actual: " << determineDay(11, 6, 2022) << endl;
    // Testing 2, Monday 
    cout << "Expected: 2 (Monday), actual: " << determineDay(11, 7, 2022) << endl;
    // Testing 4, Wednesday
    cout << "Expected: 4 (Wednesday), actual: " << determineDay(11, 9, 2022) << endl;
    // Testing 5, Thursday
    cout << "Expected: 5 (Thursday), actual: " << determineDay(11, 10, 2022) << endl;
    // Testing 6, Friday
    cout << "Expected: 6 (Friday), actual: " << determineDay(11, 11, 2022) << endl;
    cout << "Finished testing -- determineDay()" << endl;
}

void test_printDayOfBirth()
{
    // printDayOfBirth prints to cout rather than
    // returning a value.
    cout << "Now testing function printDayOfBirth()\n";
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;
    // Testing 0, Saturday
    cout << "Input: 0, Expected: Saturday, Actual: ";
    printDayOfBirth(0);
    cout << endl;
    // Testing 2, Monday
    cout << "Input: 2, Expected: Monday, Actual: ";
    printDayOfBirth(2);
    cout << endl;
    // Testing 3, Tuesday
    cout << "Input: 3, Expected: Tuesday, Actual: ";
    printDayOfBirth(3);
    cout << endl;
    // Testing 4, Wednesday
    cout << "Input: 4, Expected: Wednesday, Actual: ";
    printDayOfBirth(4);
    cout << endl;
    // Testing 5, Thursday
    cout << "Input: 5, Expected: Thursday, Actual: ";
    printDayOfBirth(5);
    cout << endl;
    // Testing 6, Friday
    cout << "Input: 6, Expected: Friday, Actual: ";
    printDayOfBirth(6);
    cout << endl;
    cout << "Finished testing -- printDayOfBirth()" << endl;
}

void test_determineDayOfBirth()
{
    // Write your tests here
    cout << "Testing -- determineDayOfBirth()" << endl;
}

void test_print10LeapYears()
{
    // Write your tests here
}
