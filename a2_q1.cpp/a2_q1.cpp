//  main.cpp
//  a2_q1.cpp
//
//  Created by Laura Persichini on 2020-10-10.
//  Copyright © 2020 Laura Persichini. All rights reserved.
// *

// Project: Determining palindromic primes (question #1)
// Purpose: Output prime numbers and determine if they are palindromic and their
// digits have odd sums.
// Due date: October 11, 2020

/*
 I used simple numbers to test the limitations of my program. I found that input small values
 made it easy to quickly identify errors in the program. I also tested the program using
 negative values to verify that the program did not allow that type of input. Furthermore, I
 tested both decimal values and 0. The program will work for both of these values, however it is
 recommended to input whole numbers to guarantee accuracy. This program will work for all
 positive integer values (i.e.2147483647).
 */

#include <iostream>

using namespace std;

//getting positive integer value input from user
int getting_input() {
    int positive_number;
    
    cout << " please enter a number greater than 0: ";
    cin >> positive_number;
    
    // continue prompting until input is greater than zero
    while (positive_number < 0) {
        cout << " please enter a positive number: ";
        cin >> positive_number;
    }
    
    return positive_number;
}

// determine if input is prime (testing if a number is divisible by anything other
// one or itself)
bool determine_prime(int n)  {
    bool is_prime = true;
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    
    return is_prime;
}

// determine if the number is a palindrome (check if reverse of the input is equal to
// the input itself)
bool determine_palindrome(int n) {
    string n_string = to_string(n);
    reverse(n_string.begin(),n_string.end()); // reversing the string
    int reverse_n = stoi(n_string); //converting string back to integer
    
    if (n == reverse_n) {
        return true;
    } else {
        return false;
    }
}

// determine if the sum of the digits is odd
bool determine_digits_odd(int n) {
    int sum = 0;
    
    // summing all of the digits
    while (n != 0) {
       sum = sum + n % 10;
       n = n / 10;
    }
    
    if (sum % 2 == 1) {
        return true;
    } else {
        return false;
    }
}

// output of prime numbers, statements regarding if the imput is palindromic and
// if the sum or the digits is odd
void output_prime_numbers(int b) {
    for (int i = 1; i <= b; i++) {
        if (determine_prime(i)) {
            cout << i << endl;
            
            if (determine_palindrome(i)) {
                cout << "this is a palindromic prime" << endl;
            }
            
            if (determine_digits_odd(i)) {
                cout << "the sum of the digits is odd" << endl;
            }
        }
    }
}

//main function
int main(int argc, const char * argv[]) {
    int number = getting_input();
    output_prime_numbers(number);
    
    return 0;
}
