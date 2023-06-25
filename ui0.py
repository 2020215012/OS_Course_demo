# -*- coding:utf-8 -*-
# author:skipper 
# date:5/15/23 
# time:6:52 PM 
# software: PyCharm
import os
import subprocess
import sys
import time

from PyQt5.QtCore import QThread
from PyQt5.QtGui import QPalette, QLinearGradient, QColor
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QPushButton, QLineEdit, QTextEdit


class Thread_0(QThread):  # 线程0
    def __init__(self):
        super().__init__()

    def run(self):
        values = [1, 2, 3, 4, 5]
        for i in values:
            print(i)
            time.sleep(0.5)  # 休眠


class Thread_1(QThread):  # 线程1
    def __init__(self):
        super().__init__()

    def run(self, input_str: str) -> str:
        cmd0 = "gcc Message_queue/Talker.c -o Message_queue/Talker"
        cmd1 = "Message_queue/Talker"
        os.system(cmd0)
        a = subprocess.run(cmd1, shell=True, input=input_str.encode(), stdout=subprocess.PIPE)

        cmd2 = "gcc Message_queue/Listener.c -o Message_queue/Listener"
        cmd3 = "Message_queue/Listener"
        os.system(cmd2)
        b = subprocess.getoutput(cmd3)
        return b


class Thread_2(QThread):  # 线程2
    def __init__(self):
        super().__init__()

    def run(self, input_str: str) -> str:
        cmd0 = "gcc Socket/Server.c -o Socket/Server"
        cmd1 = "Socket/Server"
        os.system(cmd0)
        a = subprocess.Popen(cmd1, shell=True, stdout=subprocess.PIPE)
        cmd2 = "gcc Socket/Client.c -o Socket/Client"
        cmd3 = "Socket/Client 127.0.0.1"
        os.system(cmd2)
        b = subprocess.run(cmd3, shell=True, input=input_str.encode(), stderr=subprocess.PIPE)
        return a.stdout.read().decode()


class Thread_3(QThread):  # 线程3
    def __init__(self):
        super().__init__()

    def run(self, input_str: str) -> str:
        cmd0 = "gcc Shared_storage/Talker.c -o Shared_storage/Talker"
        cmd1 = "Shared_storage/Talker"
        os.system(cmd0)
        a = subprocess.run(cmd1, shell=True, input=input_str.encode(), stdout=subprocess.PIPE)

        cmd2 = "gcc Shared_storage/Listener.c -o Shared_storage/Listener"
        cmd3 = "Shared_storage/Listener"
        os.system(cmd2)
        b = subprocess.getoutput(cmd3)
        return b


class Thread_4(QThread):  # 线程4
    def __init__(self):
        super().__init__()

    def run(self, input_str: str) -> str:
        cmd0 = "gcc Pipe/pipe.c -o Pipe/pipe"
        os.system(cmd0)
        cmd1 = "Pipe/pipe"
        a = subprocess.run(cmd1, shell=True, input=input_str.encode(), stdout=subprocess.PIPE)
        return a.stdout.decode()


class Thread_5(QThread):  # 线程5
    def __init__(self):
        super().__init__()

    def run(self, input_str: str) -> str:
        cmd0 = "gcc Fifo/Fifo.c -o Fifo/Fifo"
        os.system(cmd0)
        cmd1 = "Fifo/Fifo"
        a = subprocess.run(cmd1, shell=True, input=input_str.encode(), stdout=subprocess.PIPE)
        return a.stdout.decode()


class Thread_6(QThread):  # 线程6
    def __init__(self):
        super().__init__()

    def run(self, input_str: str) -> str:
        cmd0 = "gcc Semaphore/Semaphore_new.c -o Semaphore/Semaphore_new"
        os.system(cmd0)
        cmd1 = "Semaphore/Semaphore_new"
        a = subprocess.run(cmd1, shell=True, input=input_str.encode(), stdout=subprocess.PIPE)
        return a.stdout.decode()


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):

        self.btn1 = QPushButton('Message_queue', self)
        self.btn1.move(200, 100)
        self.btn1.setFixedSize(200, 100)
        self.btn1.clicked.connect(self.on_click_1)

        self.btn2 = QPushButton('Socket', self)
        self.btn2.move(200, 250)
        self.btn2.setFixedSize(200, 100)
        self.btn2.clicked.connect(self.on_click_2)

        self.btn3 = QPushButton('Shared_storage', self)
        self.btn3.move(200, 400)
        self.btn3.setFixedSize(200, 100)
        self.btn3.clicked.connect(self.on_click_3)

        self.btn4 = QPushButton('Pipe', self)
        self.btn4.move(200, 550)
        self.btn4.setFixedSize(200, 100)
        self.btn4.clicked.connect(self.on_click_4)

        self.btn5 = QPushButton('Fifo', self)
        self.btn5.move(200, 700)
        self.btn5.setFixedSize(200, 100)
        self.btn5.clicked.connect(self.on_click_5)

        self.btn6 = QPushButton('Semaphore', self)
        self.btn6.move(200, 850)
        self.btn6.setFixedSize(200, 100)
        self.btn6.clicked.connect(self.on_click_6)

        self.text1 = QTextEdit('input text', self)
        self.text1.setStyleSheet("QLineEdit { border: 2px solid black; }")
        self.text1.move(600, 100)
        self.text1.setFixedSize(500, 350)

        self.text2 = QTextEdit('output text', self)
        self.text2.setStyleSheet("QLineEdit { border: 2px solid black; }")
        self.text2.move(600, 600)
        self.text2.setFixedSize(500, 350)

        self.setGeometry(500, 250, 1200, 1100)
        self.setWindowTitle('Linux IPC')
        palette = QPalette()  # 创建一个QPalette对象
        gradient = QLinearGradient(0, 0, 0, self.width())  # 创建一个线性渐变对象
        gradient.setColorAt(0, QColor('#4f4f4f'))  # 设置渐变起点颜色为白色
        gradient.setColorAt(1, QColor('#ffffff'))  # 设置渐变终点颜色为浅灰色
        palette.setBrush(QPalette.Background, gradient)  # 将渐变对象应用于QPalette的Background属性
        self.setPalette(palette)  # 将QPalette应用于QWidget
        self.show()

    def on_click_1(self):
        s = self.text1.toPlainText()
        if s == '' or s == "Please input something":
            self.text1.setText("Please input something")
            self.text2.setText("Please input something")
        else:
            thread1 = Thread_1()
            s2 = thread1.run(s)
            self.text2.setText(s2)

    def on_click_2(self):
        s = self.text1.toPlainText()
        if s == '' or s == "Please input something":
            self.text1.setText("Please input something")
            self.text2.setText("Please input something")
        else:
            thread2 = Thread_2()
            self.text2.setText(thread2.run(s))

    def on_click_3(self):
        s = self.text1.toPlainText()
        if s == '' or s == "Please input something":
            self.text1.setText("Please input something")
            self.text2.setText("Please input something")
        else:
            thread3 = Thread_3()
            s2 = thread3.run(s)
            self.text2.setText(s2)

    def on_click_4(self):
        s = self.text1.toPlainText()
        if s == '' or s == "Please input something":
            self.text1.setText("Please input something")
            self.text2.setText("Please input something")
        else:
            thread4 = Thread_4()
            s2 = thread4.run(s)
            self.text2.setText(s2)

    def on_click_5(self):
        s = self.text1.toPlainText()
        if s == '' or s == "Please input something":
            self.text1.setText("Please input something")
            self.text2.setText("Please input something")
        else:
            thread5 = Thread_5()
            s2 = thread5.run(s)
            self.text2.setText(s2)

    def on_click_6(self):
        s = self.text1.toPlainText()
        if s == '' or s == "Please input something":
            self.text1.setText("Please input something")
            self.text2.setText("Please input something")
        else:
            thread6 = Thread_6()
            s2 = thread6.run(s)
            self.text2.setText(s2)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
