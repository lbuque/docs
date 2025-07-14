Home Assistant
==============

ESPHome 是一个用于 Home Assistant 的固件生成器，支持多种设备和传感器。它允许用户通过简单的 YAML 配置文件来定义设备的功能和行为。

本文档将介绍如何使用 ESPHome 来配置和安装 SparkC3 继电器控制固件，并集成到 Home Assistant 中。

Prerequisites
-------------

- Home Assistant 2023.10 or later, installed with the Home Assistant Operating System. If you do not have Home Assistant installed yet, refer to the installation page for instructions.
- The password to your 2.4 GHz Wi-Fi network
- Chrome (or a Chromium-based browser like Edge) on desktop (not Android/iOS)
- SparkC3
- USB Power 模块
- USB Serial cable


Installing the software onto the SparkC3
------------------------------------------

Before you can use this device with Home Assistant, you need to install a bit of software on it.

1. 要将 SparkC3 连接到计算机，请按照以下的示意图进行连接， 并连接到计算机：

    连线图


2. 请确保此页面在桌面上基于 Chromium 的浏览器中打开。它不适用于平板电脑或手机。

    - 选择下方的“连接”按钮。如果您的浏览器不支持 Web 串口，您将看到警告信息，而不是按钮。

        .. raw:: html

            <script
                type="module"
                src="https://unpkg.com/esp-web-tools@10/dist/web/install-button.js?module"
            ></script>

            <style>
            esp-web-install-button button[slot="activate"] {
                background-color: #03a9f4 !important;
                color: #ffffff !important;
                border: none !important;
                padding: 10px 20px !important;
                border-radius: 4px !important;
                font-size: 14px !important;
                cursor: pointer !important;
            }
            esp-web-install-button button[slot="activate"]:hover {
                background-color: #0288d1 !important;
            }
            </style>

            <esp-web-install-button
            manifest="https://raw.githubusercontent.com/lbuque/docs/refs/heads/master/source/_static/controller/spark-c3/firmware/manifest.json"
            >
            <button slot="activate">Connect</button>
            <span slot="unsupported">您的浏览器不支持此功能，请使用 Chrome、Edge 或其他基于 Chromium 的浏览器。</span>
            <span slot="not-allowed">请通过 HTTPS 访问此页面以使用固件安装功能。</span>
            </esp-web-install-button>

    - 对于高级用户：配置文件可在 GitHub 上获取。


3. 选择安装SparkC3 ，然后安装。

    选择图片

    - 安装完成后，选择“下一步”。
    - 将 SparkC3 添加到您的 Wi-Fi：
        - 出现提示时，从列表中选择您的网络并输入 2.4 GHz Wi-Fi 网络的凭据。
        - 选择“连接”。
        - SparkC3 现已加入您的网络。选择“添加到 Home Assistant”。

4. 这将打开“我的家庭助理链接”。


- 如果您之前未使用过 My Home Assistant，则需要对其进行配置。如果您的 Home Assistant 网址无法在 上访问http://homeassistant.local:8123，请将其替换为您的 Home Assistant 实例的网址。

- 打开链接。



5. 选择“确定”。


通过 Home Assistant 来控制 SparkC3
----------------------------------




故障排除
--------

暂无
