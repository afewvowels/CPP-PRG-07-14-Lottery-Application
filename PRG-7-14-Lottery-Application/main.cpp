//
//  main.cpp
//  PRG-7-14-Lottery-Application
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that simulates a lottery. The program should have an array of five
//  integers named lottery and should generate a random number in the range of 0
//  through 9 for each element in the array. The user should enter five digits, which should
//  be stored in an integer array named user. The program is the compare the corresponding
//  elements in the two arrays and keep a count of the digits that match. For example,
//  the following shows the lottery array and the user array with sample numbers stored
//  in each. There are two matching digits (2 and 4).
//
//  Lottery Array:
//  7   4   9   1   3
//
//  User Array:
//  4   2   9   7   3
//
//  The program should display the random numbers stored in the lottery array and the
//  number of matching digits. If all of the digits match, display a message proclaiming the
//  user as a grand prize winner.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int INT_LOTTERY_NUMBERS = 5;

int generateRandomNumber();
void getPlayerInput(const int[], int[]);
void outputNumbers(const int[], const int[]);
void checkArraySimilarity(const int[], const int[]);

int main()
{
    int intLotteryArray[INT_LOTTERY_NUMBERS];
    int intPlayerArray[INT_LOTTERY_NUMBERS];
    
    for(int number = 0 ; number < INT_LOTTERY_NUMBERS ; number++)
    {
        do
        {
            intLotteryArray[number] = generateRandomNumber();
        } while(intLotteryArray[number] > 10);
    }
    
    getPlayerInput(intLotteryArray, intPlayerArray);
    
    outputNumbers(intLotteryArray, intPlayerArray);
    
    checkArraySimilarity(intLotteryArray, intPlayerArray);
    
    return 0;
}


int generateRandomNumber()
{
    int intResult,
    intTempTime;
    
    float fltClock;
    
    intTempTime = time(0);
    
    //Test when intTempTime is the same as time(0)
    //It is sometimes false and falls through
    //With no returned value
    while(intTempTime == time(0))
    {
        while(intTempTime != time(0))
        {
            fltClock = time(0);
            
            unsigned seed = time(0);
            
            srand(seed);
            
            intResult = rand() % 9;
            
            //intResult += 1;
            
            //Used for debug to see random outputs with heads/tails result
            //            cout << intResult << endl << time(0) << endl;
            
            return intResult;
        }
    }
    return 0;
}

void getPlayerInput(const int intAnswers[], int intGuesses[])
{
    int intTemp;
    
    for(int number = 0 ; number < INT_LOTTERY_NUMBERS ; number++)
    {
        cout << "Please enter your guess for number " << number + 1 << ": ";
        cin >> intTemp;
        while(!cin || intTemp < 0 || intTemp > 9)
        {
            cout << "Please enter a number between 0 and 9: ";
            cin >> intTemp;
        }
        intGuesses[number] = intTemp;
    }
}

void outputNumbers(const int intAnswers[], const int intGuesses[])
{
    for(int answer = 0 ; answer < INT_LOTTERY_NUMBERS ; answer++)
    {
        cout << intAnswers[answer] << " ";
    }
    cout << "Lottery" << endl;
    
    for(int guess = 0 ; guess < INT_LOTTERY_NUMBERS ; guess++)
    {
        cout << intGuesses[guess] << " ";
    }
    cout << "Player" << endl;
}

void checkArraySimilarity(const int intAnswers[], const int intGuesses[])
{
    int intMatches;
    
    intMatches = 0;
    
    for(int i = 0 ; i < INT_LOTTERY_NUMBERS ; i++)
    {
        if(intGuesses[i] == intAnswers[i])
        {
            intMatches++;
        }
    }
    if(intMatches != 5)
    {
        cout << "You matched " << intMatches << " numbers!" << endl;
    }
    else if(intMatches == 5)
    {
        cout << "Congratulations! You won the lottery and are a grand prize winner!" << endl;
    }
}

