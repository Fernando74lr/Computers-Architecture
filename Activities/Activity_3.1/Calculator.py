import sys
import os
from PyQt5 import QtGui, QtCore
from PyQt5.QtCore import *
from PyQt5.QtGui import *

from calculator_gui import *

class Calculator(QtWidgets.QMainWindow, Calc_UI):
    temp = '0'
    temp_dot = '.'
    res = 0
    operation = ''
    isDot = False

    def __init__(self, *args, **kwargs):
        QtWidgets.QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        # Connections
        self.num_0.clicked.connect(self.n_0)
        self.num_1.clicked.connect(self.n_1)
        self.num_2.clicked.connect(self.n_2)
        self.num_3.clicked.connect(self.n_3)
        self.num_4.clicked.connect(self.n_4)
        self.num_5.clicked.connect(self.n_5)
        self.num_6.clicked.connect(self.n_6)
        self.num_7.clicked.connect(self.n_7)
        self.num_8.clicked.connect(self.n_8)
        self.num_9.clicked.connect(self.n_9)
        self.dot.clicked.connect(self.setDot)
        self.btn_delete.clicked.connect(self.cleanDisplay)
        self.btn_sum.clicked.connect(self.sum)
        self.btn_subs.clicked.connect(self.subs)
        self.btn_mult.clicked.connect(self.mult)
        self.btn_div.clicked.connect(self.div)
        self.btn_result.clicked.connect(self.result)

    def convertInput(self):
        return float(f'{self.temp}{self.temp_dot}')

    def setDot(self):
        self.isDot = True
    
    def cleanDisplay(self):
        self.display.display(0)

    def updateDisplay(self):
        os.system("cls")
        self.display.display(self.convertInput())
        print(self.convertInput())

    def n_0(self):
        if self.isDot:
            self.temp_dot += '0'
        else:
            if not self.temp == '0':
                self.temp += '0'
        # Update display
        self.updateDisplay()
    
    def n_1(self):
        if self.isDot:
            self.temp_dot += '1'
        else:
            self.temp += '1'
        # Update display
        self.updateDisplay()

    def n_2(self):
        if self.isDot:
            self.temp_dot += '2'
        else:
            self.temp += '2'
        # Update display
        self.updateDisplay()

    def n_3(self):
        if self.isDot:
            self.temp_dot += '3'
        else:
            self.temp += '3'
        # Update display
        self.updateDisplay()

    def n_4(self):
        if self.isDot:
            self.temp_dot += '4'
        else:
            self.temp += '4'
        # Update display
        self.updateDisplay()

    def n_5(self):
        if self.isDot:
            self.temp_dot += '5'
        else:
            self.temp += '5'
        # Update display
        self.updateDisplay()

    def n_6(self):
        if self.isDot:
            self.temp_dot += '6'
        else:
            self.temp += '6'
        # Update display
        self.updateDisplay()

    def n_7(self):
        if self.isDot:
            self.temp_dot += '7'
        else:
            self.temp += '7'
        # Update display
        self.updateDisplay()

    def n_8(self):
        if self.isDot:
            self.temp_dot += '8'
        else:
            self.temp += '8'
        # Update display
        self.updateDisplay()

    def n_9(self):
        if self.isDot:
            self.temp_dot += '9'
        else:
            self.temp += '9'
        # Update display
        self.updateDisplay()

    # Addition
    def sum(self):
        # Save 1st num
        self.res = self.convertInput()
        # Reset
        self.temp = '0'
        self.temp_dot = '.'
        self.isDot = False
        # Update display
        self.operation = '+'
    
    # Substraction
    def subs(self):
        # Save 1st num
        self.res = self.convertInput()
        # Reset
        self.temp = '0'
        self.temp_dot = '.'
        self.isDot = False
        # Update display
        self.operation = '-'

    # Multiplication
    def mult(self):
        # Save 1st num
        self.res = self.convertInput()
        # Reset
        self.temp = '0'
        self.temp_dot = '.'
        self.isDot = False
        # Update display
        self.operation = '*'

    # Division
    def div(self):
        # Save 1st num
        self.res = self.convertInput()
        # Reset
        self.temp = '0'
        self.temp_dot = '.'
        self.isDot = False
        # Update display
        self.operation = '/'

    def result(self):
        # Check and perform operation
        if len(self.operation) > 0:
            if self.operation == '+':
                print(f'{self.res} + {self.convertInput()}')
                self.res = round(self.res + self.convertInput(), 2)

            if self.operation == '-':
                self.res = round(self.res - self.convertInput(), 2)

            if self.operation == '*':
                self.res = round(self.res * self.convertInput(), 2)

            if self.operation == '/':
                if self.convertInput() == 0:
                    print('Math Error: can\'nt divide over 0.')
                    self.display.display('-')
                    return
                else:
                    self.res = round(self.res / self.convertInput(), 2)
            
            # Asign result to temp
            self.temp = self.res
            # Resets
            self.temp = '0'
            self.temp_dot = '.'
            self.isDot = False
            self.operation = ''
            # Update display
            self.display.display(self.res)
            print(f'Resultado: {self.res}')
        else:
            pass

if __name__ == "__main__":
    app = QtWidgets.QApplication([])
    window = Calculator()
    window.show()
    app.exec_()
