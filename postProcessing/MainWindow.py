import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QMainWindow, QApplication
from MainWindowUI import Ui_MainWindow
from BarUI import Ui_Bar

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Set up the user interface from Designer.
        self.ui = Ui_MainWindow ()
        self.ui.setupUi (self)

        self.barWindow = BarWindow(self)
        self.plotWindow = PlotWindow(self)

        self.ui.barButton.clicked.connect(self.openBar)
        self.ui.plotButton.clicked.connect(self.openPlot)


    def openBar(self):
        self.barWindow.show()
        self.barWindow.setEnabled(True)
    
    def openPlot(self):
        self.plotWindow.show()
        self.plotWindow.setEnabled(True)

class BarWindow(QMainWindow, Ui_Bar):
    def __init__(self, home):
        super(BarWindow, self).__init__(home)
        self.home = home
        self.setupUi(self, "Bar")

class PlotWindow(QMainWindow, Ui_Bar):
    def __init__(self, home):
        super(PlotWindow, self).__init__(home)
        self.home = home
        self.setupUi(self, "2D Plot")
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MainWindow()
    ex.show()
    sys.exit(app.exec_())
