class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        print(f"{amount}원이 입금되었습니다.")

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            print(f"{amount}원이 출금되었습니다.")
        else:
            print("잔액이 부족합니다.")

    def get_balance(self):
        print(f"현재 잔액은 {self.balance}원입니다.")
