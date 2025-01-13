# Simple Banking System

## Overview

This project implements a simple banking system where users can create bank accounts, deposit money, withdraw money, and check their account balance. The program is built using C++ and provides a console interface for the user to interact with.

## Features

- **Create Account:** Users can create a new account by providing their name, account number, and initial balance.
- **Deposit:** Users can deposit money into their account.
- **Withdraw:** Users can withdraw money from their account, provided they have sufficient funds.
- **Check Balance:** Users can view the current balance of their account.

## Code Description

### Classes

1. **BankAccount Class:**
   - Stores information related to an individual bank account such as account holder name, account number, and balance.
   - Provides methods for depositing, withdrawing, and checking the account balance.

2. **Bank Class:**
   - Manages multiple bank accounts.
   - Provides methods to create an account, deposit money, withdraw money, and get the account balance by account number.

### Main Program Flow

- The user is presented with a menu to choose the action they want to perform.
- Based on the user’s input, the program either creates a new account, deposits or withdraws money, or shows the balance of a specified account.
- The system continues to run until the user chooses to exit.

## Example of Usage


## How to Compile and Run

1. Save the code in a file named `banking_system.cpp`.
2. Open a terminal or command prompt and navigate to the directory containing the file.
3. Compile the code using a C++ compiler:
   ```bash
   g++ banking_system.cpp -o banking_system
