# Arduino Learning Lab 🚀

Welcome to my embedded systems repository! This space tracks my progress as I learn to wire circuits and program the Arduino Uno.

## 📂 Project Directory

### 📑 [01: RGB Ultrasonic Distance Indicator & Smart Barrier System](./01_RGB_Distance_Sensor)
* **Description:** A smart parking assist and automated garage barrier system that evolved from a basic RGB proximity indicator. The system dynamically measures an approaching vehicle's distance using an ultrasonic sensor and provides real-time visual (RGB LED), audible (Piezo), textual (I2C LCD), and physical (Servo) driver feedback.
* **Key Concepts learned:** `pinMode` IO configuration, microsecond pulse timing (`pulseIn()`), I2C communication protocol, multi-peripheral code integration, PWM servo control, array buffers, and handling sensor telemetry.
* 
#### 🛠️ Project 01 Evolution: Development Steps

This project was developed sequentially, transforming a basic proximity circuit into an advanced, multi-peripheral integrated design:

#### Step 1: Initial Proximity Feedback (RGB LED Circuit)
* **Goal:** Establish basic multi-color output indicators to represent distance thresholds.
* **Implementation:** Wired an RGB LED to digital pins using current-limiting resistors (200 Ω) to manage specific color outputs based on hardcoded test values.

#### Step 2: Integrating the Distance Sensor (HC-SR04)
* **Goal:** Replace static conditions with live physical distance measurements.
* **Implementation:** Integrated an HC-SR04 ultrasonic sensor. Configured a high-frequency trigger pulse (10 µs) to emit sonic bursts, using `pulseIn()` to calculate distance via the speed of sound formula:
 {Distance} = {Duration}/{0.034}*{2}

#### Step 3: Adding Audible Alerts (Piezo Speaker)
* **Goal:** Introduce non-visual driver warnings mimicking real vehicle backup sensors.
* **Implementation:** Connected a piezo buzzer to a digital output pin. Used the built-in `tone()` function to program distinct sound profiles: a continuous high-frequency alert for the critical zone and pulsing, intermittent "beeps" for the warning zone.

#### Step 4: Upgrading to a Smart Dashboard (I2C 16x2 LCD)
* **Goal:** Display precise telemetry tracking and readable status messages.
* **Implementation:** Wired an LCD with an integrated I2C backpack module to reduce pin usage down to just 2 communication lines (SDA/SCL on pins A4/A5). Handled screen buffer clearing (`lcd.clear()`) to display live distance on row 1 and shifting text statuses (`CLEAR`, `SLOW DOWN`, `STOP`) on row 2.

#### Step 5: Automated Barrier Control (Micro Servo Motor)
* **Goal:** Create an interactive, physical reaction to the parking state.
* **Implementation:** Connected a micro servo motor to a PWM pin (Pin 11) using the `Servo.h` library. The barrier automatically lifts to 90° while approaching, then seals shut at 0° once a vehicle has safely reached its designated stop point.

---
*More projects coming soon!*
