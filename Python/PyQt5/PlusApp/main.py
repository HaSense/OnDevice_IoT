import sys
from PyQt5.QtWidgets import QApplication, QWidget, QHBoxLayout, QPushButton, QLineEdit, QLabel


class CalculatorApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('PyQt5 계산기 - 한 줄로')
        self.setGeometry(100, 100, 400, 50)

        # 레이아웃 설정
        layout = QHBoxLayout()
        self.setLayout(layout)

        # QLineEdit 위젯 생성
        self.input1 = QLineEdit()
        self.plusLabel = QLabel('+')
        self.input2 = QLineEdit()
        self.equalLabel = QLabel('=')
        self.result = QLineEdit()
        self.result.setReadOnly(True)  # 결과창은 읽기 전용으로 설정

        # QPushButton 위젯 생성
        self.buttonCalculate = QPushButton('계산하기')
        self.buttonCalculate.clicked.connect(self.Plus)

        # 위젯을 레이아웃에 추가
        layout.addWidget(self.input1)
        layout.addWidget(self.plusLabel)
        layout.addWidget(self.input2)
        layout.addWidget(self.equalLabel)
        layout.addWidget(self.result)
        layout.addWidget(self.buttonCalculate)

    def Plus(self):
        # 입력 값을 가져옵니다.
        num1 = int(self.input1.text())
        num2 = int(self.input2.text())

        # 합과 곱을 계산합니다.
        sum = num1 + num2


        # 결과를 QLineEdit에 표시합니다.
        self.result.setText(f'{sum}')


if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWindow = CalculatorApp()
    mainWindow.show()
    sys.exit(app.exec_())
