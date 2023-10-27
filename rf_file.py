import serial
import time

ser = serial.Serial('/dev/ttyS0', 2000000, timeout=0.1)
number = 0

while True:
    try:
        start_time = time.time()  

        received_number = ser.readline().strip()
        if received_number:
            received_number = int(received_number)
            if received_number > number:
                number = received_number

        end_time = time.time()
        elapsed_time = end_time - start_time  #get elapsed time

        current_time = time.strftime("%H:%M:%S")

        print(f"Received number: {number}, Time Stamp : {current_time} Elapsed time: {elapsed_time} seconds")

        number += 1
        ser.write(f"{number}\n".encode())

        with open('Communication_log.txt', 'a') as file:
            file.write(f'Information: {number}, Time Stamp : {current_time}, Elapsed time: {elapsed_time} sec\n')
            file.flush()

    except KeyboardInterrupt:
        break

# ser.close()
