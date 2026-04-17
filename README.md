# 🚀 ESP32 IR Sensor Dashboard

## 📌 Project Overview

This project is a **real-time object detection system** built using **ESP32 and an IR sensor**, with a **web-based dashboard** for live monitoring.

The ESP32 acts as a web server and updates the dashboard instantly based on sensor input.

---

## 🎯 Key Features

* 🔴 Real-time object detection
* 🌐 Web dashboard hosted on ESP32
* 📡 Wireless monitoring over WiFi
* ⚡ Fast response using embedded system
* 💡 Visual status (Object / No Object)

---

## 🛠️ Tech Stack

* Embedded C (Arduino IDE)
* ESP32 WiFi Web Server
* HTML, CSS (Dashboard UI)
* IoT (Internet of Things)

---

## 🔌 Hardware Components

* ESP32 Development Board
* IR Sensor Module
* Jumper Wires
* USB Cable / Power Supply

---

## 🖥️ Project Output

### 🔴 Object Detected

![Object Detected](images/object_detected.jpg)

### ✅ No Object

![No Object](images/no_object.jpg)

### 🔧 Hardware Setup

![Setup](images/setup.jpg)

---

## ⚙️ Working Principle

1. IR sensor detects object presence
2. ESP32 reads sensor output
3. ESP32 runs a web server
4. Dashboard updates status in real-time

---

## 🚀 How to Run the Project

1. Clone the repository:

```bash
git clone https://github.com/yourusername/ESP32-IR-Dashboard.git
```

2. Open code in Arduino IDE / VS Code

3. Update WiFi credentials:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_PASSWORD";
```

4. Upload code to ESP32

5. Open Serial Monitor → Get IP Address

6. Open browser:

```
http://<ESP32_IP_ADDRESS>
```

---

## 📈 Future Improvements

* 📲 Mobile app integration
* ☁️ Cloud data storage (Firebase / AWS)
* 📩 Notification system (Telegram / Email)
* 📷 Camera integration (ESP32-CAM)

---

## 💼 Use Cases

* Smart security systems
* Object detection automation
* IoT monitoring systems
* Industrial sensing applications

---

## 👨‍💻 Author

**Sumit Kumar**
EEE Student | Embedded Systems & IoT Enthusiast

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub!
