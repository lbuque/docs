Home Assistant
==============

.. include:: ../../refs/controller/spark-c3/home-assistant.ref

ESPHome 是一个用于 Home Assistant 的固件生成器，支持多种设备和传感器。它允许用户通过简单的 YAML 配置文件来定义设备的功能和行为。

本文档将介绍如何使用 ESPHome 来配置和安装 SparkC3 继电器控制固件，并集成到 Home Assistant 中。

准备
-----

- Home Assistant 2023.10 或更高版本，需与 Home Assistant 操作系统一同安装。
- 2.4 GHz Wi-Fi 网络的密码
- Chrome（或其他基于 Chromium 的浏览器，如 Edge）在桌面上（不支持 Android/iOS）
- SparkC3
- USB Power 模块
- USB串行电缆


将软件安装到 SparkC3 上
------------------------

在将此设备与 Home Assistant 一起使用之前，您需要在其上安装一些软件。

1. 要将 SparkC3 连接到计算机，请按照以下的示意图进行连接， 并连接到计算机：

    **!!!连线图还在施工中...**

2. 请确保此页面在桌面上基于 Chromium 的浏览器中打开。它不适用于平板电脑或手机。

    - 选择下方的“连接”按钮。如果您的浏览器不支持 Web 串口，您将看到警告信息，而不是按钮。

        |install-button|

    - 对于高级用户：配置文件可在 GitHub 上获取。

3. 选择安装SparkC3 ，然后安装。

    |install-firmware.png|

    - 安装完成后，选择“下一步”。
    - 将 SparkC3 添加到您的 Wi-Fi：

        - 出现提示时，从列表中选择您的网络并输入 2.4 GHz Wi-Fi 网络的凭据。
        - 选择“连接”。
        - SparkC3 现已加入您的网络。选择“添加到 Home Assistant”。

            |config-wifi.png| 

4. 这将打开“我的家庭助理链接”。

    |esp32-atom-flash-06.png|

5. 选择“确定”。


通过 Home Assistant 来控制 SparkC3
----------------------------------

|control.png|

故障排除
--------

暂无
