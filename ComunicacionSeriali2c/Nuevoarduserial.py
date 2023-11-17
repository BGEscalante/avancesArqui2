# cargar modulo de control de puerto de serial
import tkinter import *
import serial

# Crear variables de tipo objeto serial
arduino = serial.Serial(port = 'COM3', baudrate = 9600, timeout = 0.1)

# crear funcion de la lectura escritura de puerto serial
def ledStatuts():
    if estado.get() == 'Enceder': x = 1
    else: x= 0
    arduino.write(bytes(x,'utf-8')) 
    if x == 1:
        estado.set('Apagar')
    else:
        estado.set('Encender')

frmRoot = Tk()
frmRoot.geometry('400x300')
estado = StringVar()
estado.set('Encender')
