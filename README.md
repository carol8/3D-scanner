# 3D Scanner - PMP Documentation
## Overview

This project presents a **low-cost 3D scanner** designed to measure and visualize distances with high accuracy. The scanner rotates a distance sensor on both horizontal and vertical axes and transmits measurement data to a computer for real-time visualization.

For full details, refer to the **complete documentation** in [3D Scanner.pdf](3D%20Scanner.pdf).

## Hardware Assembly Instructions

### Required Components:
- **2x** Servo Motors with PWM as a control signal and 6V nominal voltage (I used 2 goBilda servos)
- **1x** VL53L0X ToF sensor or equivalent (I used a Rev Robotics 2m Distance Sensor)
- **1x** Arduino UNO R3
- **1x** Battery holder (4x 1.5V)
- **Cables & jumpers**
- **Aluminum brackets** (see the photo at the end of mechanical assembly for reference)
- **M3 & M4 screws and nuts**

### Mechanical Assembly:
1. Attach the **first servo motor** to the base structure.  
2. Fix the **second servo motor** on top of the first one using aluminum brackets.  
3. Mount the **distance sensor** onto the second servo motor.  
4. Secure all components using **M3 & M4 screws and nuts**.
5. Ensure smooth rotation by manually testing the servos.  

The full assembly should look like this once completed:

![image](https://github.com/user-attachments/assets/020e2f72-a9fc-4dbd-b794-885da58c3086)


### Electronic Connections:
1. **Connect the servos** to the Arduino:
   - Yaw servo → **Pin 9**
   - Pitch servo → **Pin 10**
2. **Connect the distance sensor**:
   - **VCC** → 5V on Arduino
   - **GND** → GND on Arduino
   - **SDA** → A4 on Arduino
   - **SCL** → A5 on Arduino
3. **Power the servos separately** using the battery pack.
4. **Connect GND of the battery pack** to Arduino GND (common ground for PWM signals).  

The electrical diagram of the connections:

![image](https://github.com/user-attachments/assets/58b6a973-4726-404f-9971-9604aaca9561)

## Usage Instructions

### 1. Uploading Arduino Code
1. Open **Arduino IDE**.
2. Connect the Arduino UNO via **USB**.
3. Upload the provided **Arduino sketch** to control the servos and read sensor data.
4. Open the **Serial Monitor** to check if the sensor is outputting data correctly.

### 2. Running the Visualization Software (Processing)
1. Install **Processing** from [https://processing.org](https://processing.org).
2. Open the **Processing script**.
3. Ensure that the correct serial port is set.
4. Run the script to visualize **real-time distance measurements** in a 3D representation.  

When both scripts are run concurrently, this should be the output of the visualisation script:

![image](https://github.com/user-attachments/assets/25369ac6-01dd-40a9-a633-cdb6ce301e15)


---

## Full Documentation

For more details, including full source code and design considerations, check the complete documentation in **[Scanner 3D (Documentatie PMP).pdf](Scanner%203D%20(Documentatie%20PMP).pdf)**.

---

**This project is open-source and can be improved with better sensors, stepper motors, or refined calibration! Contributions are welcome!**
