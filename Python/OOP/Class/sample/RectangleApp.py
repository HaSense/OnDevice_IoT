class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)

    def __str__(self):
        return f"사각형의 너비: {self.width}, 높이: {self.height}"

# 메인 코드
if __name__ == "__main__":
    # 사각형 객체 생성
    rect = Rectangle(10, 20)
    print(rect)  # 사각형의 속성 출력

    # 면적 계산 및 출력
    print(f"사각형의 면적: {rect.area()}")

    # 둘레 계산 및 출력
    print(f"사각형의 둘레: {rect.perimeter()}")
