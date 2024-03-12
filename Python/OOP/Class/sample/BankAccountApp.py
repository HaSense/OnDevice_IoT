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

# 메인 코드
if __name__ == "__main__":
    # 계좌 생성
    account = BankAccount("홍길동", 10000)
    print(f"{account.owner}님의 계좌가 생성되었습니다. 초기 잔액은 {account.balance}원입니다.")

    # 입금 테스트
    account.deposit(5000)
    account.get_balance()

    # 출금 테스트
    account.withdraw(3000)
    account.get_balance()

    # 출금 시도 (잔액 부족)
    account.withdraw(15000)
    account.get_balance()
