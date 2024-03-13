import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLineEdit, QLabel


class SimpleTextDisplayApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('PyQt5 텍스트 디스플레이')
        self.setGeometry(100, 100, 300, 100)

        # 레이아웃 설정
        layout = QVBoxLayout()
        self.setLayout(layout)

        # QLineEdit 위젯 생성
        self.inputEdit = QLineEdit()

        # QLabel 위젯 생성
        self.displayLabel = QLabel('여기에 입력한 내용이 표시됩니다.')

        # QPushButton 위젯 생성
        self.displayButton = QPushButton('텍스트 출력')
        self.displayButton.clicked.connect(self.showContent)

        # 위젯을 레이아웃에 추가
        layout.addWidget(self.inputEdit)
        layout.addWidget(self.displayLabel)
        layout.addWidget(self.displayButton)

    def showContent(self):
        # QLineEdit에서 텍스트를 가져와 QLabel에 설정합니다.
        text = self.inputEdit.text()
        self.displayLabel.setText(text)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWindow = SimpleTextDisplayApp()
    mainWindow.show()
    sys.exit(app.exec_())
