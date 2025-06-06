# ESP32-C3 Weather Hub 🌦️📡

This is a central hub project using **ESP32-C3** to receive sensor data from the `weather-station` project via **ESP-NOW**, while simultaneously syncing temperature data to a mobile app through **ESP RainMaker**.

---

## Key Features

- 📡 Receive sensor data from Weather Station devices via **ESP-NOW** (no WiFi required)
- ☁️ Connect to the Internet via WiFi to sync data to the cloud using **ESP RainMaker**
- 📲 Control and monitor temperature and humidity on your smartphone using the ESP RainMaker app
- 🔋 Power-efficient design, suitable for serving as a central hub in a sensor network

---

## Technologies & Hardware

| Component         | Description                           |
|-------------------|-------------------------------------|
| ESP32-C3          | Main microcontroller, ESP-NOW receiver |
| ESP-NOW           | High-speed, low-power wireless protocol |
| WiFi              | Connect ESP RainMaker to the cloud  |
| ESP RainMaker SDK | IoT device management and data sync |

---

## Project Structure
```
esp-weather-hub/
├── main/                  # Main code (ESP-NOW, WiFi, RainMaker)
│   ├── espnow_recv.c      # ESP-NOW data receiving handler
│   ├── rainmaker_app.c    # ESP RainMaker integration
│   └── app_main.c         # Entry point
├── components/            # Custom components (if any)
├── sdkconfig              # ESP-IDF config
├── CMakeLists.txt
└── README.md
```

---

## ⚙️ Build & Flash Instructions

---

## Getting Started

### 1. Clone the repository

```terminal
git clone https://github.com/Hdchipeo/esp-home-hub.git
cd esp-home-hub
```

### 2. Set target and configure:

```
idf.py set-target esp32c3
idf.py menuconfig
```

	•	In menuconfig: configure WiFi, ESP RainMaker credentials (username, password)
	•	Configure ESP-NOW if necessary

### 3. Build and flash:

```
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor (MAC/LINUX)
```


*Change /dev/ttyUSB0 to COM on Windows

Important Notes
	•	ESP-NOW uses MAC addresses, make sure your weather-station devices are configured with compatible MACs
	•	Ensure your ESP32-C3 has a stable WiFi connection to sync with ESP RainMaker
	•	You need to register an account and create a project on ESP RainMaker

Using the ESP RainMaker App
	•	Download the ESP RainMaker app on Android or iOS
	•	Log in with your Espressif account
	•	Connect your ESP32-C3 hub device following the app instructions
	•	Monitor and control weather sensor data in real-time

⸻

📄 License

MIT © Hdchipeo

⸻

Developed by a passionate embedded developer, aiming to bring IoT to the next level! 🚀🤖
⸻
