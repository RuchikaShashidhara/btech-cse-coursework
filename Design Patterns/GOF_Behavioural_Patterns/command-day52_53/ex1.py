import tkinter


top = tkinter.Tk()

def helloCallBack():
   print( "Hello Python", "Hello World")

B = tkinter.Button(top, text ="Hello", command = helloCallBack)

B.pack()
top.mainloop()
