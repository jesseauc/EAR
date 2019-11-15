<<<<<<< HEAD
#Programmer: Alexander Leones
#Project: Elderly Assistance Robot
#  uiCubby.py 
# first semester lab prototype ui
# Nov 3, 2019
import time
from tkinter import *
from tkinter.ttk import *
import RPi.GPIO as GPIO

#cubby gpio IDs
cubby1=21
cubby2=20
cubby3=16
cubby4=12
cubby1Input= 26

space1=False #space 1 is initially empty

GPIO.setmode(GPIO.BCM)
GPIO.setup(cubby1, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby2, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby3, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby4, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby1Input, GPIO.IN)
master = Tk()
master.title("Assistant Robot GUI V2")
master.geometry("600x100")

ONlabel1 = Label(master, text="Cubby Empty (system start)")
ONlabel1.grid(row=0, column=0)
print(space1)

def cubby1Button():
	global space1
	if(space1==False):
		GPIO.output(cubby1, GPIO.HIGH) #signal storage op.
		while not GPIO.input(cubby1Input):
			time.sleep(0.1)
		space1=True           #space1 is occupied? True
		print(space1)
		ONlabel1.config(text = "Cubby ocupied") #Display it's full
	else:
		GPIO.output(cubby1,GPIO.LOW)
		space1=False
		print(space1)
		ONlabel1.config(text="Cubby Empty")
		
def ExitButton():
	Exitbutton = Button(master, text="Exit", command= EandD)
	Exitbutton.grid(row=1, column=8)
def EandD():
	master.destroy()
	GPIO.cleanup()

Cubby1StoreButton = Button(master, text="GPIO 21 Cubby 1", command= cubby1Button)
Cubby1StoreButton.grid(row=1, column=0)
ExitButton()
master.mainloop()
=======
#Programmer: Alexander Leones
#Project: Elderly Assistance Robot
#  uiCubby.py 
# first semester lab prototype ui
# Nov 3, 2019
import time
from tkinter import *
from tkinter.ttk import *
import RPi.GPIO as GPIO

#cubby gpio IDs
cubby1=21
cubby2=20
cubby3=16
cubby4=12

space1=False #space 1 is initially empty
space2=False
space3=False

GPIO.setmode(GPIO.BCM)
GPIO.setup(cubby1, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby2, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby3, GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(cubby4, GPIO.OUT,initial=GPIO.LOW)

master = Tk()
master.title("Assistant Robot GUI V2")
master.geometry("600x100")

ONlabel1 = Label(master, text="Cubby Empty (system start)")
ONlabel1.grid(row=0, column=0)
ONlabel2 = Label(master, text="Cubby Empty (system start)")
ONlabel2.grid(row=0, column=1)
ONlabel3 = Label(master, text="Cubby Empty (system start)")
ONlabel3.grid(row=0, column=2)

def cubby1Button():
	global space1
	if(space1==False):
		GPIO.output(cubby1, GPIO.HIGH) #signal storage op.
		space1=True           #space1 is occupied? True
		ONlabel1.config(text = "Cubby ocupied") #Display it's full
	else:
		GPIO.output(cubby1,GPIO.LOW)
		space1=False
		ONlabel1.config(text="Cubby Empty")	
def cubby2Button():
	global space2
	if(space2==False):
		GPIO.output(cubby2, GPIO.HIGH) #signal storage op.
		space2=True           #space1 is occupied? True
		ONlabel2.config(text = "Cubby ocupied") #Display it's full
	else:
		GPIO.output(cubby2,GPIO.LOW)
		space2=False
		ONlabel2.config(text="Cubby Empty")
def cubby3Button():
	global space3
	if(space3==False):
		GPIO.output(cubby3, GPIO.HIGH)
		space3=True
		ONlabel3.config(text = "Cubby ocupied") #Display it's full
	else:
		GPIO.output(cubby3, GPIO.LOW)
		space3=False
		ONlabel3.config(text="Cubby Empty")

def ExitButton():
	Exitbutton = Button(master, text="Exit", command= EandD)
	Exitbutton.grid(row=1, column=8)
def EandD():
	master.destroy()
	GPIO.cleanup()

Cubby1StoreButton = Button(master, text="GPIO 21 Cubby 1", command= cubby1Button)
Cubby1StoreButton.grid(row=1, column=0)
Cubby2StoreButton = Button(master, text="GPIO 20 Cubby 2", command= cubby2Button)
Cubby2StoreButton.grid(row=1, column=1)
Cubby3StoreButton = Button(master, text="GPIO 16 Cubby 3", command= cubby3Button)
Cubby3StoreButton.grid(row=1, column=2)
ExitButton()

master.mainloop()
>>>>>>> b3e3508cb8da7a819e0db2fd81617f7c4896a6ac
