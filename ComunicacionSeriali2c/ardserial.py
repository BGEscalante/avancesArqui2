# cargar modulo de control de puerto de serial
import serial
import time

# Crear variables de tipo objeto serial
arduino = serial.Serial(port = 'COM3', baudrate = 9600, timeout = 0.1)

# crear funcion de la lectura escritura de puerto serial
def wrSerial(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

# Bloque Principal
while True:
    num = input('Ingrese un numero: ')
    valor = wrSerial(num)
    if valor == b'0\r\n':
        print('Apagado')
    else:
        print('Encendido')