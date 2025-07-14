USB Power模块(适用于继电器控制)
============================

本章节介绍如何使用 SparkC3 控制 USB Power 模块。

本教程同样适用于市场上销售的继电器控制模块。

硬件连接
--------

将 SparkC3 和 USB Power 模块连接起来，确保连接正确。

放一个图片

基础代码示例
------------

Arduino IDE 示例
~~~~~~~~~~~~~~~~

.. code-block:: cpp

    #include <Arduino.h>

    #define POWER_PIN 9  // USB Power 控制引脚

    void setup() {
      Serial.begin(115200);
      pinMode(POWER_PIN, OUTPUT);
      digitalWrite(POWER_PIN, HIGH);  // 使用高电平来关闭 USB 的电源
      Serial.println("USB Power 控制系统启动");
    }

    void loop() {
      // 打开 USB Power
      digitalWrite(POWER_PIN, LOW);
      Serial.println("USB Power 开启");
      delay(2000);

      // 关闭 USB Power
      digitalWrite(POWER_PIN, HIGH);
      Serial.println("USB Power 关闭");
      delay(2000);
    }

MicroPython 示例
~~~~~~~~~~~~~~~~

即将推出...


Wi-Fi 远程控制
--------------

通过 Wi-Fi 连接实现远程 USB Power 控制：

.. code-block:: cpp

    #include <WiFi.h>
    #include <WebServer.h>

    // !!! 请替换为您的 Wi-Fi SSID 和密码 !!!
    const char* ssid = "your_wifi_ssid";
    const char* password = "your_wifi_password";

    WebServer server(80);
    const int relayPin = 9;
    bool relayState = false;

    void setup() {
      Serial.begin(115200);
      pinMode(relayPin, OUTPUT);
      digitalWrite(relayPin, HIGH);  // 初始状态关闭

      // 连接 Wi-Fi
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("正在连接WiFi...");
      }

      Serial.println("WiFi连接成功");
      Serial.print("IP地址: ");
      Serial.println(WiFi.localIP());

      // 设置Web服务器路由
      server.on("/", handleRoot);
      server.on("/relay/on", handleRelayOn);
      server.on("/relay/off", handleRelayOff);
      server.on("/status", handleStatus);

      server.begin();
      Serial.println("Web服务器启动");
    }

    void loop() {
      server.handleClient();
    }

    void handleRoot() {
      String html = "<!DOCTYPE html>";
      html += "<html><head>";
      html += "<meta charset='UTF-8'>";
      html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
      html += "<title>SparkC3 USB Power 控制</title>";
      html += "<style>";
      html += "body { font-family: Arial, sans-serif; text-align: center; margin: 50px; }";
      html += "button { padding: 10px 20px; margin: 10px; font-size: 16px; cursor: pointer; }";
      html += ".status { font-size: 18px; margin: 20px 0; }";
      html += "</style>";
      html += "</head><body>";
      html += "<h1>SparkC3 USB Power 控制</h1>";
      html += "<div class='status'>USB Power 状态: <span id='status'>" + String(relayState ? "开启" : "关闭") + "</span></div>";
      html += "<button onclick='toggleRelay(true)'>开启</button>";
      html += "<button onclick='toggleRelay(false)'>关闭</button>";
      html += "<script>";
      html += "function toggleRelay(state) {";
      html += "  var xhr = new XMLHttpRequest();";
      html += "  xhr.onreadystatechange = function() {";
      html += "    if (xhr.readyState == 4 && xhr.status == 200) {";
      html += "      document.getElementById('status').innerText = state ? '开启' : '关闭';";
      html += "    }";
      html += "  };";
      html += "  xhr.open('GET', state ? '/relay/on' : '/relay/off', true);";
      html += "  xhr.send();";
      html += "}";
      html += "</script>";
      html += "</body></html>";
      server.send(200, "text/html; charset=utf-8", html);
    }

    void handleRelayOn() {
      digitalWrite(relayPin, LOW);
      relayState = true;
      server.send(200, "text/plain; charset=utf-8", "USB Power 已开启");
    }

    void handleRelayOff() {
      digitalWrite(relayPin, HIGH);
      relayState = false;
      server.send(200, "text/plain; charset=utf-8", "USB Power 已关闭");
    }

    void handleStatus() {
      String json = "{\"relay\":" + String(relayState ? "true" : "false") + "}";
      server.send(200, "application/json", json);
    }

**使用步骤：**

1. 将 SparkC3 通过 USB Serial 连接到计算机。
2. 在 Arduino IDE 中打开上述代码。
3. 替换 Wi-Fi SSID 和密码。
4. 在弹出的对话框中选择正确的串口设备
4. 上传代码到 SparkC3。
6. 等待固件烧录完成
7. 将 SparkC3 连接到 USB Power 模块。

**固件功能：**

- 预配置的 USB Power 控制代码
- Wi-Fi 连接和 Web 服务器
- 远程控制接口
- 状态监控功能


注意事项
--------

暂无


故障排除
--------

暂无
