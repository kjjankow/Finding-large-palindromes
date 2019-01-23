/***********
 Project Euler #4
 A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
 **********/

#include <iostream>

using namespace std;

int palinCheck(int numFront)  // Function to check if a number is a palindrome. If YES, return that palindrome.
{
    int check = numFront;
    int numBack = 0;
    
    while(numFront > 0)
    {
        int lastDigit = numFront % 10;          // Finds last digit of the number
        numBack = numBack * 10 + lastDigit;     // Puts last digit into first digit of the reverse
        numFront = numFront / 10;               // Removes a digit from the original number
    }
    
    if (check == numBack)      // Returns only if value is a palindrome, otherwise 0
    {
        return numBack;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int possiblePalin = 0;
    int largestPalin = 0;
    for(int i=100; i<1001; i++)           // Nested loops to calculate the product of 2, 3 digit numbers
    {
        for(int j=100; j< 1001; j++)
        {
            int number = i*j;
            possiblePalin = palinCheck(number);     // Sends value to palindrome check function
            if (possiblePalin > largestPalin)       // Checks if returned value is larger than current
            {
                largestPalin = possiblePalin;
            }
        }
    }
    cout << "The largest palindrome of 2, 2 digit numbers is: " << largestPalin << endl;
    
    return 0;
}

