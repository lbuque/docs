==============
Home Assistant
==============

.. include:: ../refs/om15020-jn5169/resource.ref
.. include:: ../refs/om15020-jn5169/home-assistant.ref

烧录固件
========

参考 :doc:`flash` 中的说明，烧录 |ZiGate_v3.23-OPDM.bin|_ 固件到 **OM15020-JN5169** 中。


添加 zigbee Home Automation 集成
================================

将 **OM15020-JN5169** 连接到 Home Assistant 的主机上，使用 USB 线连接到主机的 USB 接口。

在 Home Assistant 中添加 ZigBee 子设备，点击 **Configuration** --> **Integrations** --> **Add Integration**，选择 **Zigbee Home Automation** 集成。

|Zigbee-Home-Automation.png|

选择识别出来的端口号，通常是 `/dev/ttyUSB0` 。

|COM.png|


添加 ZigBee 子设备
==================

找一个 ZigBee 子设备，按下重置按钮，通常是按住 5 秒钟。

|add-device.gif|
