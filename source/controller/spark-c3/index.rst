Spark-C3 控制器
===============

.. include:: ../../refs/controller/spark-c3/spark-c3.ref

.. toctree::
    :maxdepth: 1

    usb-power.rst
    home-assistant.rst



简介
----

Spark-C3 是一款基于 ESP32-C3 芯片的智能控制器，专为物联网应用设计。

主要特性：

- **处理器**：ESP32-C3 单核 RISC-V 处理器，主频高达 160MHz
- **无线连接**：内置 Wi-Fi 4 (802.11 b/g/n) 和 Bluetooth 5 (LE)
- **低功耗**：支持多种低功耗模式，适合电池供电应用
- **丰富接口**：GPIO、SPI、I2C、UART、ADC、PWM 等多种接口
- **开发友好**：支持 Arduino IDE、ESP-IDF、MicroPython 等开发环境

应用场景：

- **智能家居控制**：灯光控制、继电器控制、传感器数据采集
- **物联网节点**：远程监控、数据传输、设备控制
- **自动化系统**：工业控制、农业监测、环境监控

编程支持：

- **Arduino IDE**：使用熟悉的 Arduino 语法快速开发
- **ESP-IDF**：官方开发框架，功能完整，性能优化
- **MicroPython**：Python 语法，适合快速原型开发
- **PlatformIO**：专业的嵌入式开发平台

技术规格：

- **工作电压**：3.3V
- **工作温度**：-40°C 至 +85°C
- **Flash 存储**：4MB
- **RAM**：400KB SRAM
- **GPIO 数量**：3 个可编程 GPIO
- **无线标准**：

  - Wi-Fi 4 (IEEE 802.11 b/g/n)
  - Bluetooth 5 (LE)

安全特性：

- **加密引擎**：AES、SHA、RSA 硬件加速
- **安全启动**：Secure Boot 支持
- **Flash 加密**：数据保护
- **真随机数生成器**：TRNG 支持

产品参数
--------

引脚说明
--------

|SparkC3-Pinmap.png|

====== ====== =========
标号   名称    功能描述
------ ------ ---------
1      GND    电源负极
------ ------ ---------
2      IO2    GPIO
------ ------ ---------
3      IO9    GPIO
------ ------ ---------
4      RXD    UART0 RX
------ ------ ---------
5      VCC    电源正极
------ ------ ---------
6      RST    复位
------ ------ ---------
7      IO8    GPIO
------ ------ ---------
8      TXD    UART0 TX
====== ====== =========

原理图
-------




使用教程
--------

Arduino
^^^^^^^

1. 按照 `Arduino-ESP32 <https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html>`_ 安装 SparkC3 的SDK包。

2. 在 ``Arduino IDE`` -> ``Tools`` 选择正确的设置，如下所示。

|arduino-config.png|

PlatformIO
^^^^^^^^^^

1. 下载 |SparkC3_PlatformIO.zip|_ 并解压到您的工作目录。
2. 使用 VSCode 打开解压后的目录。
3. 安装 PlatformIO 扩展。
4. 点击下方的上传按钮， 将开始编译并将编译后的固件上传到 SparkC3 。

Home Assistant
^^^^^^^^^^^^^^

详细的 Home Assistant 集成教程请参考：:doc:`home-assistant`


MicroPython
^^^^^^^^^^^

即将推出...

常见问题
--------

还没有客户对此产品有任何问题， 欢迎通过淘宝联系我们！

包装信息
--------

SpaerkC3 控制器包装内包含：

    |SparkC3 控制器主板|

SpaerkC3 继电器套件包装盒内包含：

    ===================== ====================
    |SparkC3 控制器主板|    |USB Power 模块|
    ===================== ====================

更多
-----

- |SparkC3原理图.pdf|_
- |USB Power原理图.pdf|_
- |SparkC3尺寸图.pdf|_
- |USB Power尺寸图.pdf|_

|购买链接|_
