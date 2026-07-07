## Methodology
This project implements a low-cost ECG Acquisition and Noise Filtering system using an Arduino Uno, AD8232 ECG sensor, OLED display, and SD card module. ECG electrodes are placed on the user's body to capture the heart's electrical signals, which are sensed by the AD8232 module. The sensor amplifies and conditions the weak ECG signal before sending it to the Arduino Uno. The Arduino reads the ECG data, applies basic noise filtering techniques to reduce power-line interference, baseline wander, and motion artifacts, and processes the signal for improved clarity. The filtered ECG signal is displayed in real time on the OLED display, allowing continuous monitoring of heart activity. Simultaneously, the processed ECG data is stored on the SD card for future analysis and record keeping. This methodology provides an affordable, portable, and efficient solution for real-time ECG monitoring.

## Future Scope
- Develop a wireless ECG monitoring system using Bluetooth or Wi-Fi.
- Integrate IoT technology for remote patient monitoring through cloud platforms.
- Implement AI and Machine Learning algorithms to automatically detect heart abnormalities.
- Develop a mobile application for real-time ECG visualization and health tracking.
- Improve noise filtering using advanced digital signal processing (DSP) techniques.
- Add heart rate calculation and automatic arrhythmia detection.
- Miniaturize the hardware to create a wearable ECG monitoring device.
- Enable real-time alerts to doctors or caregivers during abnormal ECG conditions.
- Support multi-lead ECG acquisition for more accurate cardiac analysis.
- Enhance data storage and visualization with cloud-based healthcare systems.
