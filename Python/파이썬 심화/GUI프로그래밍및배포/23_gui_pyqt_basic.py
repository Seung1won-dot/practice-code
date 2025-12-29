from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel, QVBoxLayout, QWidget

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("PyQt5 예제")
        self.setGeometry(100, 100, 400, 300)
        
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        
        layout = QVBoxLayout()
        central_widget.setLayout(layout)
        
        self.label = QLabel("안녕하세요, PyQt5!")
        layout.addWidget(self.label)
        
        self.button = QPushButton("클릭하세요")
        self.button.clicked.connect(self.on_button_click)
        layout.addWidget(self.button)
        
        self.count = 0
    
    def on_button_click(self):
        self.count += 1
        self.label.setText(f"버튼이 {self.count}번 클릭되었습니다!")

if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    app.exec_()

