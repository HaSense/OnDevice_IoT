class Calculator:
    def plus(self, a, b):
        return a + b

    def minus(self, a, b):
        return a - b

    def multiple(self, a, b):
        return a * b

    def divide(self, a, b):
        if b == 0:
            return "0으로 나눌 수 없습니다."
        return a / b

# 메인 코드
if __name__ == "__main__":
    calc = Calculator()
    
    a = 10
    b = 5

    print(f"{a} + {b} = {calc.plus(a, b)}")
    print(f"{a} - {b} = {calc.minus(a, b)}")
    print(f"{a} * {b} = {calc.multiple(a, b)}")
    print(f"{a} / {b} = {calc.divide(a, b)}")

    # 0으로 나누기 시도
    print(f"{a} / 0 = {calc.divide(a, 0)}")
