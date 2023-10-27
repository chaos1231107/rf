import serial
import time

ser = serial.Serial('/dev/ttyS0', 2000000, timeout=0.1)

number = 0

while True:
    try:
        received_number = ser.readline().strip()
        if received_number:
            received_number = int(received_number)
            if received_number > number:
                number = received_number
                
        print(f"Received number: {number}")

        number += 1
        ser.write(f"{number}\n".encode())

        #time.sleep(1)  
    except KeyboardInterrupt:
        break

ser.close()



			
	