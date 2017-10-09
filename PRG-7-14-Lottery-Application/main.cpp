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
#include <random>

using namespace std;

const int INT_LOTTERY_NUMBERS = 5;

int generateRandomNumber();
void getPlayerInput(const int[], int[]);
void outputNumbers(const int[], const int[]);
void checkArraySimilarity(const int[], const int[]);

int main()
{
    // Declare array for lottery numbers (will be auto populated)
    int intLotteryArray[INT_LOTTERY_NUMBERS];
    
    // Declare array for player numbers (user generated)
    int intPlayerArray[INT_LOTTERY_NUMBERS];
    
    // Loop used to populate winning numbers lottery array
    // easily extensible if the total number of numbers
    // needs to change
    for(int number = 0 ; number < INT_LOTTERY_NUMBERS ; number++)
    {
        intLotteryArray[number] = generateRandomNumber();
    }
    
    // Get player input to fill second player array
    getPlayerInput(intLotteryArray, intPlayerArray);
    
    // Output numbers...
    outputNumbers(intLotteryArray, intPlayerArray);
    
    // ...then check to see if there's a match
    // (this happens fast)
    checkArraySimilarity(intLotteryArray, intPlayerArray);
    
    return 0;
}

// This function uses the Mersenne twister PRNG
// to generate numbers one at a time.
int generateRandomNumber()
{
    int intResult;
    
    // Use random_device to generate seed value
    random_device rd;
    
    // Seed Mersenne twister engine with random_device result
    mt19937 engine(rd());
    
    // Define what output from engine will be
    uniform_int_distribution<> distribution(0,9);
    
    // Use distribution with engine to generate numbers
    intResult = distribution(engine);
    
    return intResult;
}

void getPlayerInput(const int intAnswers[], int intGuesses[])
{
    int intTemp;
    
    for(int number = 0 ; number < INT_LOTTERY_NUMBERS ; number++)
    {
        cout << "Please enter your guess for number " << (number + 1) << ": ";
        cin >> intTemp;
        while(!cin || intTemp < 0 || intTemp > 9)
        {
            cout << "Please enter a number between 0 and 9: ";
            cin.clear();
            cin.ignore();
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
    // Declare accumulator to hold total matches
    int intMatches;
    
    // Initialize accumulator
    intMatches = 0;
    
    // Loop through both arrays and compare both arrays at index i
    for(int i = 0 ; i < INT_LOTTERY_NUMBERS ; i++)
    {
        // If there's a match, increment the accumulator
        if(intGuesses[i] == intAnswers[i])
        {
            intMatches++;
        }
    }
    
    // Test first case, likeliest outcome, partial match
    if(intMatches != 5)
    {
        cout << "You matched " << intMatches << " numbers!" << endl;
    }
    // Test second case, unlikely to match all five
    else if(intMatches == 5)
    {
        cout << "Congratulations! You won the lottery and are a grand prize winner!" << endl;
    }
    // Output error message if the first two cases fail to pass
    else
    {
        cout << "ERROR COMPARING ARRAYS" << endl;
    }
}

