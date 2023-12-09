import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt

class Window(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Bulls and cows")
        self.setGeometry(750, 250, 1000, 1000)
        self.setNumber()
        self.UI()
    def setNumber(self):
        numbers = list(range(10))
        self.selected_numbers = random.sample(numbers, 4)
        print(self.selected_numbers)
        self.a, self.b, self.c, self.d = self.selected_numbers
        print(self.a, self.b, self.c, self.d)

    def UI(self):

        # Main vertical layout
        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignTop)  # 위로 조정

        # 1 layout: label1 + label2
        self.Label_layout = QVBoxLayout()
        self.text1 = QLabel("Bulls and cows game", self)
        font = QFont()  # 폰트 설정 객체 생성
        font.setBold(True)  # 두껍게
        font.setPointSize(15)  # 폰트 크기
        self.text1.setFont(font)  # text1의 폰트를 설정
        self.text2 = QLabel(":: Rules ::\n\t0~9 four numbers NO duplicate\n\n\tS (Strike) : Correct Position & Number\n\tB (Ball) : Only Correct Number\n\tO (Out) : All Incorrect", self)
        font.setPointSize(10)  # 폰트 크기
        self.text2.setFont(font)  # text2의 폰트를 설정
        self.text2.setMargin(30)
        self.Label_layout.addWidget(self.text1, alignment=Qt.AlignCenter)
        self.Label_layout.addWidget(self.text2, alignment=Qt.AlignCenter)
        self.main_layout.addLayout(self.Label_layout)

        # 2 horizon layout: Start Button, exit Button
        buttons_layout = QHBoxLayout()
        buttons_layout.setAlignment(Qt.AlignHCenter)  # 버튼 레이아웃을 수평 중앙에 정렬
        self.main_layout.addLayout(buttons_layout)

        # 2-1: Start Game Button
        self.startButton = QPushButton("Start Game", self)
        self.startButton.setFixedSize(200, 60)
        font.setPointSize(13)
        self.startButton.setFont(font)
        buttons_layout.addWidget(self.startButton)
        self.startButton.clicked.connect(self.startFunc)

        # 2-2: exit Button
        exitButton = QPushButton("Exit", self)
        exitButton.setFixedSize(200, 60)
        font.setPointSize(13)
        exitButton.setFont(font)
        buttons_layout.addWidget(exitButton)
        exitButton.clicked.connect(self.exitFunc)

        self.show()

    def startFunc(self):

        # 3 horizon layout: spinbox x 4 , Guess Button
        self.Guesslayout = QHBoxLayout()
        self.Guesslayout.setAlignment(Qt.AlignHCenter)  # 버튼 레이아웃을 수평 중앙에 정렬
        self.main_layout.addLayout(self.Guesslayout)
        self.Guesslayout.setContentsMargins(100, 30, 100, 10)
        self.Guesslayout.setAlignment(Qt.AlignHCenter)

        # 3.1 spinbox x 4
        self.n1 = QSpinBox(self)
        self.n2 = QSpinBox(self)
        self.n3 = QSpinBox(self)
        self.n4 = QSpinBox(self)
        self.n1.setStyleSheet("QSpinBox { font-size: 50px; }")
        self.n2.setStyleSheet("QSpinBox { font-size: 50px; }")
        self.n3.setStyleSheet("QSpinBox { font-size: 50px; }")
        self.n4.setStyleSheet("QSpinBox { font-size: 50px; }")
        self.n1.setRange(0, 9)
        self.n2.setRange(0, 9)
        self.n3.setRange(0, 9)
        self.n4.setRange(0, 9)
        self.Guesslayout.addWidget(self.n1)
        self.Guesslayout.addWidget(self.n2)
        self.Guesslayout.addWidget(self.n3)
        self.Guesslayout.addWidget(self.n4)

        # Add spacing between SpinBoxes
        spacing = 10
        self.Guesslayout.addWidget(self.n1)
        self.Guesslayout.addSpacing(spacing)
        self.Guesslayout.addWidget(self.n2)
        self.Guesslayout.addSpacing(spacing)
        self.Guesslayout.addWidget(self.n3)
        self.Guesslayout.addSpacing(spacing)
        spacing = 120
        self.Guesslayout.addWidget(self.n4)
        self.Guesslayout.addSpacing(spacing)

        # 3.2 Guess Box
        self.GuessButton = QPushButton("Guess !", self)
        self.GuessButton.setFixedSize(200, 60)
        font = QFont()
        font.setPointSize(13)
        self.GuessButton.setFont(font)
        self.Guesslayout.addWidget(self.GuessButton)
        self.GuessButton.clicked.connect(self.GuessFunc)

    def GuessFunc(self):
        # 4.1 label
        self.SBO_guideline = QLabel("\t\t\t\t\t S   B   O", self)
        font = QFont()  # 폰트 설정 객체 생성
        font.setBold(True)  # 두껍게
        font.setPointSize(15)  # 폰트 크기
        self.SBO_guideline.setFont(font)
        self.main_layout.addWidget(self.SBO_guideline)

        while True:
            S = 0
            B = 0

            lst = self.selected_numbers.copy()
            glst = [self.n1.value(), self.n2.value(), self.n3.value(), self.n4.value()]

            i = 0
            while i < len(lst):
                if lst[i] == glst[i]:
                    lst.pop(i)
                    glst.pop(i)
                    S += 1
                else:
                    i += 1

            for i in range(len(lst)):
                if glst[i] in lst:
                    B += 1

            O = 4 - S - B

            # 기존에 있는 결과 제거
            for i in reversed(range(self.main_layout.count())):
                widget = self.main_layout.itemAt(i).widget()
                if widget and widget.objectName() == "result_label":
                    widget.setParent(None)

            # 새로운 결과 추가
            result_label = QLabel(
                "\t\t{} {} {} {}\t\t\t {}   {}   {}".format(self.n1.value(), self.n2.value(), self.n3.value(),
                                                            self.n4.value(), S, B, O), self)
            result_label.setObjectName("result_label")  # objectName을 설정하여 나중에 식별 가능하게 함
            font = QFont()
            font.setBold(True)
            font.setPointSize(15)
            result_label.setFont(font)
            self.main_layout.addWidget(result_label)

            if S == 4:
                # 모든 숫자와 자리가 일치하는 경우 게임 종료
                break
            else:
                # 일치하지 않는 경우 다시 값을 입력받기 위해 루프 재실행
                self.n1.setValue(random.randint(0, 9))
                self.n2.setValue(random.randint(0, 9))
                self.n3.setValue(random.randint(0, 9))
                self.n4.setValue(random.randint(0, 9))

    def exitFunc(self):
        mbox = QMessageBox.question(self, "⚠️", "Are you sure to exit?",
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if mbox == QMessageBox.Yes:
            sys.exit()
        elif mbox == QMessageBox.No:
            print("You Clicked No Button")

def main():
    App = QApplication(sys.argv)
    window = Window()
    sys.exit(App.exec_())

if __name__ == '__main__':
    main()
