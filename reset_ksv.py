import pyfirmata
    
puerto = "/dev/ttyACM0" #Puerto COM de emulación en USB
pin = (13) #PIN donde va conectado el LED
 
#Conexión con placa Arduino
tarjeta = pyfirmata.Arduino(puerto)
while True:
    print("Encendiendo LED...")
    tarjeta.digital[pin].write(1)
    print("Encendido LED...")
    tarjeta.pass_time(20)

    print("Apagando LED...")
    tarjeta.digital[pin].write(0)
    print("Apagado LED...")
    tarjeta.pass_time(3)
    break
tarjeta.exit()
