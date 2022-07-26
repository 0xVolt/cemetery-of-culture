""" 
Example creating a Class of a Bank Account

* Balance
* Withdraw money
* Deposit money 

All cannot be negative
Withdraw <= Balance """

class Account:
    """This is an example of a bank account"""

    # Constructor
    def __init__(self, balance):
        self.balance = balance

    def deposit(self, amount):
        if amount < 0:
            amount *= -1
        
        self.balance += amount

    def withdraw(self, amount):
        if amount < 0:
            amount *= -1
        
        if (amount > self.balance):
            print("Insufficient funds...")
        else:
            self.balance -= amount

    def showBalance(self):
        try:
            print(f'Balance: {self.balance}')
        except AttributeError:
            print("Attribute 'Balance' does not exist")
            print('After exception is handled')

# Make an an object of type Account
obj = Account(100)
amount = int(input("Enter amount to deposit: "))
obj.deposit(amount)
obj.showBalance()
amount = int(input("Enter withdrawal amount: "))
obj.withdraw(amount)
obj.showBalance()

# Printing classes docstring
print(obj.__doc__)
del obj.balance
try:
    obj.showBalance()
except NameError:
    print('Object does not exist')

del obj
print('Object deleted!')

try:
    obj.showBalance()
except NameError:
    print('Object does not exist')

# Derived class, savings acc is derived from account or is a 'type' of account
class savingsAccount(Account):
    def __init__(self, balance, intt):
        super().__init__(balance) # This calls the parent class's constructor by passing balance as the parameter
        self.interest = intt

    def showInterest(self):
        print(f"Interest is: {self.interest}")
    
    # Overriding the parent function
    def deposit(self, amount):
        try:
            assert(amount > 0)
        except AssertionError:
            print("Amount entered must be greater than 0")

        
        self.balance += amount