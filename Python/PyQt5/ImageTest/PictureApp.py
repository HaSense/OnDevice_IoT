import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import QPixmap

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.btn1 = QPushButton("사진출력!!", self)
        self.imageLabel = QLabel(self)

        layout = QVBoxLayout()
        layout.addWidget(self.btn1)
        layout.addWidget(self.imageLabel)
        self.setLayout(layout)

        self.btn1.clicked.connect(lambda: self.showImage('nj1.png'))

        self.setWindowTitle('사진출력 어플')
        self.setGeometry(0, 0, 650, 450)
        self.show()

    def showImage(self, imagePath):
        pixmap = QPixmap(imagePath)
        self.imageLabel.setPixmap(pixmap)
        self.imageLabel.adjustSize()

if __name__ == '__main__':
   app = QApplication(sys.argv)
   ex = MyApp()
   sys.exit(app.exec_())
