import tkinter as tk
from tkinter import messagebox

def button_click():
    messagebox.showinfo("알림", "버튼이 클릭되었습니다!")

root = tk.Tk()
root.title("Tkinter 예제")
root.geometry("300x200")

label = tk.Label(root, text="안녕하세요, Tkinter!")
label.pack(pady=10)

button = tk.Button(root, text="클릭하세요", command=button_click)
button.pack(pady=10)

entry = tk.Entry(root, width=30)
entry.pack(pady=10)

def show_text():
    text = entry.get()
    messagebox.showinfo("입력값", f"입력한 텍스트: {text}")

button2 = tk.Button(root, text="텍스트 표시", command=show_text)
button2.pack(pady=10)

root.mainloop()

