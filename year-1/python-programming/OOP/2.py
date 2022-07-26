from os import system
import msvcrt

def isNegative(amt):
    if amt <= 0:
        return True
    else:
        return False

class Person:
    def __init__(self, wallet):
        self.wallet = wallet

    def deduct(self, amt):
        if isNegative(amt):
            print("Enter non-negative amount!")
            return 
        
        if amt > self.wallet:
            print("Insufficient funds!")
            return

        self.wallet -= amt

    def add(self, amt):
        if isNegative(amt):
            print("Enter non-negative amount!")
            return
        
        self.wallet += amt

    def printDet(self):
        print(f"Wallet balance: {self.wallet}")

class Account:
    def __init__(self, balance):
        self.balance = balance

    def withdraw(self, amt):
        if isNegative(amt):
            print("Enter non-negative amount!")
            return 
        
        if amt > self.balance:
            print("Insufficient funds!")

        self.balance -= amt

    def deposit(self, amt):
        if isNegative(amt):
            print("Enter non-negative amount!")
            return
        
        self.balance += amt

    def printDet(self):
        print(f"Account balance: {self.balance}")

if __name__ == "__main__":
    # Object declaration
    wallet = float(input("Enter the starting amount in wallet: "))
    balance = float(input("Enter the starting account balance: "))
    P = Person(wallet)
    A = Account(balance)


    # Display MENU
    while True:
        system("cls")
        
        print("MENU")
        print("1. Check Wallet")
        print("2. Check Account")
        print("3. Deposit")
        print("4. Withdraw")
        print("5. Exit")

        op = int(input("Enter your option: "))

        # Conditional statement nesting
        if op == 1:
            P.printDet()

        elif op == 2:
            A.printDet()

        elif op == 3:
            amt = float(input("Enter amount to deposit: "))
            A.deposit(amt)
            P.deduct(amt)
            print(f"{amt} has been deposited into your Account!")

        elif op == 4:
            amt = float("Enter the amount to withdraw: ")
            A.withdraw(amt)
            P.add(amt)
            print(f"{amt} has been withdrawn and added to your Wallet!")

        elif op == 5:
            break

        else:
            print("Invalid choice! Please try again.")

        msvcrt.getch()