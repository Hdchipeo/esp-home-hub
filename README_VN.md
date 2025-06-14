
cat > README.md << EOF
# ESP32-C3 Weather Hub 🌦️📡

Hub trung tâm sử dụng **ESP32-C3** để nhận dữ liệu cảm biến từ project [weather-station](https://github.com/Hdchipeo/weather-station) thông qua **ESP-NOW**, đồng thời cập nhật dữ liệu lên điện thoại qua app **ESP RainMaker**.

---

## 🚀 Tính năng chính

- 📡 Nhận dữ liệu cảm biến từ các thiết bị Weather Station qua **ESP-NOW** (không cần WiFi)
- ☁️ Kết nối Internet qua WiFi, đồng bộ dữ liệu lên đám mây qua **ESP RainMaker**
- 📲 Điều khiển và xem nhiệt độ, độ ẩm trên điện thoại bằng app ESP RainMaker
- 🔋 Tối ưu tiết kiệm năng lượng, phù hợp làm hub trung tâm trong mạng lưới cảm biến

---

## 🧰 Công nghệ & phần cứng sử dụng

| Thành phần        | Mô tả                                  |
|-------------------|---------------------------------------|
| ESP32-C3          | Vi điều khiển chính, nhận dữ liệu ESP-NOW |
| ESP-NOW           | Giao thức truyền dữ liệu tốc độ cao, low power |
| WiFi              | Kết nối ESP RainMaker lên đám mây     |
| ESP RainMaker SDK | Quản lý và đồng bộ dữ liệu IoT         |

---

## 📁 Cấu trúc project

```
esp-weather-hub/
├── main/                  # Code chính (ESP-NOW, WiFi, RainMaker)
│   ├── espnow_recv.c      # Xử lý nhận dữ liệu ESP-NOW
│   ├── rainmaker_app.c    # ESP RainMaker integration
│   └── app_main.c         # Entry point
├── components/            # Components tuỳ chỉnh (nếu có)
├── sdkconfig              # Config ESP-IDF
├── CMakeLists.txt
└── README.md
```

---

## ⚙️ Hướng dẫn build & flash

### 1. Clone repo:

```terminal
git clone https://github.com/Hdchipeo/esp-home-hub.git
cd esp-home-hub
```

### 2. Chọn target và cấu hình:

```
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor (MAC/LINUX)
```

- Trong menuconfig: cấu hình WiFi, cấu hình ESP RainMaker (nhập tài khoản, mật khẩu)
- Cấu hình ESP-NOW nếu cần

### 3. Build & flash:

\`\`\`bash
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
\`\`\`

> Thay \`/dev/ttyUSB0\` bằng cổng COM phù hợp trên máy bạn.

---

## 🔧 Lưu ý quan trọng

- ESP-NOW sử dụng giao thức MAC Address, đảm bảo các thiết bị weather-station đã được cấu hình MAC tương thích
- Đảm bảo thiết bị ESP32-C3 có WiFi hoạt động ổn định để đồng bộ lên ESP RainMaker
- Bạn cần đăng ký tài khoản và tạo project trên [ESP RainMaker](https://rainmaker.espressif.com/)

---

## 📱 Sử dụng app ESP RainMaker

- Tải app **ESP RainMaker** trên Android hoặc iOS
- Đăng nhập bằng tài khoản Espressif
- Kết nối thiết bị hub ESP32-C3 của bạn theo hướng dẫn app
- Xem và điều khiển dữ liệu cảm biến thời tiết realtime

---

## 📄 License

MIT © [Hdchipeo](https://github.com/Hdchipeo)

---

> Project phát triển bởi một dev hệ nhúng có tâm, sẵn sàng đưa IoT lên tầm cao mới! 🚀🤖
EOF

## Các dự án liên quan

- [weather-station](https://github.com/Hdchipeo/weather-station): The remote ESP-NOW-enabled weather sensor node for this central hub.