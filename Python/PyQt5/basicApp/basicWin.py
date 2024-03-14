import sys
from PyQt5.QtWidgets import *

class MyApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setGeometry(100, 100, 200, 200)
        self.show()

if __name__ == "__main__":
    app = QApplication(sys.argv) #App 생성
    ex = MyApp()    #위젯생성
    sys.exit(app.exec_())
