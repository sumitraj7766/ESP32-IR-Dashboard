#include <WiFi.h>
#include <WebServer.h>

#define IR_PIN 34

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

// 🔥 Modern Attractive Webpage
String webpage = R"====(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 Smart Dashboard</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  
  <style>
    body {
      margin: 0;
      font-family: 'Segoe UI', sans-serif;
      background: linear-gradient(135deg, #1d2b64, #f8cdda);
      color: white;
      text-align: center;
    }

    h1 {
      margin-top: 30px;
      font-size: 2.5rem;
    }

    .card {
      background: rgba(255,255,255,0.1);
      backdrop-filter: blur(10px);
      border-radius: 20px;
      padding: 30px;
      margin: 40px auto;
      width: 300px;
      box-shadow: 0 8px 30px rgba(0,0,0,0.3);
    }

    #status {
      font-size: 28px;
      margin: 20px 0;
      font-weight: bold;
    }

    .detected {
      color: #ff4b5c;
    }

    .safe {
      color: #00ffcc;
    }

    button {
      padding: 10px 20px;
      border: none;
      border-radius: 10px;
      font-size: 16px;
      background: #ffffff;
      color: #333;
      cursor: pointer;
    }

    button:hover {
      background: #ddd;
    }
  </style>
</head>

<body>

<h1>🚀 ESP32 IR Dashboard</h1>

<div class="card">
  <div id="status">Loading...</div>
  <button onclick="getData()">Refresh</button>
</div>

<script>
function getData() {
  fetch("/data")
    .then(res => res.text())
    .then(data => {
      let statusDiv = document.getElementById("status");

      statusDiv.innerHTML = data;

      if (data.includes("Detected")) {
        statusDiv.className = "detected";
      } else {
        statusDiv.className = "safe";
      }
    });
}

setInterval(getData, 1000);
</script>

</body>
</html>
)====";

// Serve webpage
void handleRoot() {
  server.send(200, "text/html", webpage);
}

// Send IR data
void handleData() {
  int value = digitalRead(IR_PIN);

  if (value == 0) {
    server.send(200, "text/plain", "🔥 Object Detected");
  } else {
    server.send(200, "text/plain", "✅ No Object");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/data", handleData);

  server.begin();
}

void loop() {
  server.handleClient();
}