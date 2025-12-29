from PyQt5.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout,
                             QHBoxLayout, QPushButton, QLineEdit, QListWidget,
                             QListWidgetItem, QMessageBox)

class TodoApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("할 일 목록")
        self.setGeometry(100, 100, 500, 600)
        
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        
        layout = QVBoxLayout()
        central_widget.setLayout(layout)
        
        input_layout = QHBoxLayout()
        self.input_field = QLineEdit()
        self.input_field.setPlaceholderText("할 일을 입력하세요...")
        self.input_field.returnPressed.connect(self.add_todo)
        input_layout.addWidget(self.input_field)
        
        add_button = QPushButton("추가")
        add_button.clicked.connect(self.add_todo)
        input_layout.addWidget(add_button)
        
        layout.addLayout(input_layout)
        
        self.todo_list = QListWidget()
        layout.addWidget(self.todo_list)
        
        button_layout = QHBoxLayout()
        remove_button = QPushButton("삭제")
        remove_button.clicked.connect(self.remove_todo)
        button_layout.addWidget(remove_button)
        
        clear_button = QPushButton("전체 삭제")
        clear_button.clicked.connect(self.clear_all)
        button_layout.addWidget(clear_button)
        
        layout.addLayout(button_layout)
    
    def add_todo(self):
        text = self.input_field.text().strip()
        if text:
            self.todo_list.addItem(text)
            self.input_field.clear()
        else:
            QMessageBox.warning(self, "경고", "할 일을 입력하세요!")
    
    def remove_todo(self):
        current_item = self.todo_list.currentItem()
        if current_item:
            self.todo_list.takeItem(self.todo_list.row(current_item))
        else:
            QMessageBox.warning(self, "경고", "삭제할 항목을 선택하세요!")
    
    def clear_all(self):
        reply = QMessageBox.question(self, "확인", "모든 항목을 삭제하시겠습니까?",
                                    QMessageBox.Yes | QMessageBox.No)
        if reply == QMessageBox.Yes:
            self.todo_list.clear()

if __name__ == "__main__":
    app = QApplication([])
    window = TodoApp()
    window.show()
    app.exec_()

