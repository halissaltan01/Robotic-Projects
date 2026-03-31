import serial
import time
from nicegui import ui
import threading

# Initialize the serial port
port = serial.Serial('/dev/ttyUSB2', 9600)

# Shared variable to hold the latest data
latest_data = 0

def move_forward():
    port.write(b'1')
    ui.notify('Motor runs forward')

def move_backward():
    port.write(b'2')
    ui.notify('Motor runs backward')

def stop_motor():
    port.write(b'0')
    ui.notify('Motor has been stopped')

def read_serial():
    global latest_data
    while True:
        try:
            line = port.readline().decode('utf-8').strip()  # Read a line from serial port
            if line:
                latest_data = int(line)  # Convert to integer
        except Exception as e:
            latest_data = f"Error: {e}"
        time.sleep(0.5)  # Delay for stability

# Start the serial reading in a separate thread
thread = threading.Thread(target=read_serial, daemon=True)
thread.start()

# NiceGUI interface
ui.label('Motor Control Panel')

step_label = ui.label('Steps: 0')

def update_display():
    step_label.text = f'Steps: {latest_data}'

ui.timer(1, update_display)  # Update the display every second

ui.button('Forward', on_click=move_forward).style('margin: 10px;')
ui.button('Backward', on_click=move_backward).style('margin: 10px;')
ui.button('Stop', on_click=stop_motor).style('margin: 10px;')

# Run the NiceGUI app
ui.run()
