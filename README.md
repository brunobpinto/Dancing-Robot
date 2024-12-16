![Dancing-Robot-Banner](https://github.com/user-attachments/assets/715fb9cd-9444-4aca-a934-df24a70c8797)

# Dancing Robot  
This project was developed as the final activity for the Microcontrollers Project class at PUC-Rio, Brazil. It showcases the integration of Arduino and MediaPipe to create a humanoid dancing robot that mimics human movements. The project was conceived as an idea aligned with this year's class theme, Interactive Art.  

## Video  
Watch the robot in action in the video below:

https://github.com/user-attachments/assets/82b7757a-404e-4159-b0a3-cdb6346fa5df

## Features  
- Humanoid robot capable of imitating human movements.  
- Motion capture powered by MediaPipe for precise tracking.  
- Controlled via Arduino, ensuring smooth and responsive movements.  
- Fully 3D-printed components for a customizable and modular design.  
- Themed around Interactive Art, blending technology and creativity.  
<br><br>
## Getting Started  

### Hardware Requirements  
- Arduino microcontroller (e.g., Arduino Mega or Uno).  
- 12 Servo motors (SG90 and MG90S models).
- 16-Channel 12-bit PWM and Servo Shield for Arduino
- Power supply for the servos and Arduino.  
- Camera for motion capture (any standard webcam, including built-in laptop cameras).
- Structure and pole to securely hold the robot in the air during operation.
- Structural components: 3D-printed parts (see below).
  
> [!WARNING]
> While the Arduino Uno may work, it is recommended to use an Arduino Mega due to its larger SRAM (8 KB vs. 2 KB on the Uno), which provides better performance and stability for memory-intensive tasks.


### Software Requirements  
- Arduino IDE for microcontroller programming.  
- Python 3.8 or later. 


### 3D Printed Files  
All 3D-printed files can be found in the `/3D_Files` directory.  

> [!TIP]
> Since the 3D files of the robot are symmetrical, you can simply open the SLDPRT files and mirror them to create both sides of the robot. Afterward, save the mirrored parts as STL files and you're ready to print! 
<div>‎</div>

## Installation  
### Setup Arduino:
   - Connect the servos to the PWM Servo Shield board.
   - Install the [Adafruit-PWM-Servo-Driver-Library](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library)
   - Upload the provided Arduino code using the Arduino IDE.  

### Install Dependencies:
   - To install the Python dependencies, run the following command:  
     ```bash
     pip install -r requirements.txt
     ```  

### Arduino COM Settings:
Before running the project, make sure to correctly configure the Arduino's serial port. The serial port may vary depending on the operating system and the connection to the Arduino.
1. Open the main Python code file, main.py.
2. Locate the following code snippet:
    ```python
    try:
    arduino = serial.Serial("COM5", baudrate=9600)  # Change port according to your device
    ```
3. Replace **'COM5'** with the serial port of your Arduino.

### 3D Printing and Assembly Components:
   - Ensure that the robot is fully printed and assembled correctly, and that each servo is connected to the correct pwm port.  
   - And make sure the camera is connected and communicating with the code.

### Run the Project:
   - Execute the main.py file to start motion capture and servo control.  
<br><br>

## Usage
<div align="center">
  <img src="https://github.com/user-attachments/assets/80a54fe0-ef96-4b81-948c-8171a126a24c" alt="Interface 1" width="600"/>
  <img src="https://github.com/user-attachments/assets/2fedbf87-2d32-41d0-9361-03a2c7a82e15" alt="Interface 2" width="600"/>
</div>


## How It Works  
### Motion Capture and Pose Detection
- MediaPipe captures keypoints of human movements in real time via a camera.
- By analyzing the angles of the joints, it detects pre-programmed poses and synchronizes them with the music's rhythm.

### Beat Detection and Rhythm Syncing
- The Python code running on the computer detects the beat of the music and establishes the rhythm.
- This timing determines when each pose should be sent to the Arduino for execution.

### Servo Control and Synchronization
- The Arduino receives pose data via serial communication.
- It moves the robot’s servos in sync with the rhythm to perform the correct movements.

### 3D Printing and Assembly
- The robot's frame is constructed using 3D-printed parts.
- This provides a lightweight and modular structure for easy customization and assembly.

## Schematic  
<img src="https://github.com/user-attachments/assets/7e490fb2-ef1e-4cbd-91fc-8d8d68a57102" alt="Mr.Adam's Schematic" width="800"/>

## Contributors  
We would like to extend our heartfelt thanks to everyone who contributed to the development of this project. Your support, ideas, and dedication were essential in bringing this robot to life.

- [@aurorarichaud](https://github.com/aurorarichaud)
- [@brunobpinto](https://github.com/brunobpinto)
- [@gvalente02](https://github.com/gvalente02)
- [@GabiScof](https://github.com/GabiScof)

Thank you all for your hard work and collaboration!
