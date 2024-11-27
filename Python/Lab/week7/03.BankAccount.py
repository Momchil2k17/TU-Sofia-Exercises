class BankAccount:
    
    def __init__(self,iban,owner,balance):
        self.iban=iban
        self.owner=owner
        self.balance=self.validateBalance(balance)
    def validateBalance(self,balance):
        if balance<0:
            while balance<0:
                balance=int(input("Invalid balance,please enter a valid number: "))
            return balance
        else:
            return balance
    def deposit(self,amount):
        if amount<=0:
            print("You can't deposit less than zero money")
        else:
            self.balance+=amount
    def withdraw(self,amount):
        if self.balance<amount:
            print("Insufficient balance")
        else:
            self.balance-=amount
    def display_balance(self):
        print(f"Owner: {self.owner} Balance: {self.balance}")

b1=BankAccount("4123hfajhsfjkas","Momo Kenta",-10)
b2=BankAccount("fjasldkfjl;sad","Kiro Lopatkata",1000)

b1.deposit(-1)
b1.deposit(100)
b1.withdraw(200)
b1.withdraw(20)
b1.display_balance()

b2.deposit(1500)
b2.withdraw(1000)
b2.display_balance()
        