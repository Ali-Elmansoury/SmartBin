# Smart Waste Bin with Proximity-Based Lid Control

An embedded system designed to monitor the waste level in a bin and automatically open the lid when a person approaches. This project integrates sensor-based detection with actuator control to create a more hygienic and user-friendly waste disposal experience.

## Features

- **Continuous Waste Level Monitoring** using ultrasonic sensors.
- **Automatic Lid Opening** via a servo motor when motion is detected nearby.
- **Real-Time Response** for approaching individuals using a proximity sensor.
- **Efficient Resource Use** by minimizing lid movement based on actual presence.
- **Microcontroller-Based** implementation using ATMega32A.

## Technologies and Hardware Used

- **Microchip Studio** for code development.
- **AVRDUDESS** to burn the code.
- **ATMega32A Microcontroller**
- **USB ASP AVR ATMEL USBasp Programmer**
- **Buzzer and LEDs**
- **Ultrasonic Sensor (HC-SR04)** for waste level and proximity detection.
- **Servo Motor** for lid actuation.
- **C Language** for programming logic.

## How It Works

1. The ultrasonic sensor monitors the fill level of the bin continuously.
2. When someone approaches, the lid opens automatically.
3. After a short delay or once the person leaves, the lid closes again.
4. The system ensures hygienic interaction by avoiding physical contact.

## Installation & Setup

1. Connect the ultrasonic sensor to the microcontroller.
2. Attach a servo motor to control the lid mechanism.
3. Upload the code to the microcontroller.
4. Power the system via USB or external battery.

## Use Cases

- Smart waste bins in public spaces, hospitals, or smart homes.
- Hands-free waste disposal systems.
- Eco-friendly monitoring for smart cities.

## Future Improvements

- Integrate Wi-Fi or Bluetooth for remote monitoring.
- Add a display to show fill level percentage.
- Send alerts when the bin is nearly full.

## License

This project is licensed under the MIT License.
