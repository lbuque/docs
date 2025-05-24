==============
Ubiqua 抓包
==============

.. include:: ../../refs/zigbee-series/om15020-jn5169/resource.ref
.. include:: ../../refs/zigbee-series/om15020-jn5169/sniffer-ubiqua.ref


烧录 sniffer 固件
=================

参考 :doc:`flash` 中的说明，烧录 |JennicSniffer_JN5169_1000000.bin|_ 固件到 **OM15020-JN5169** 中。


安装 Ubiqua
============

|Ubiqua|_ 是一个网络抓包工具。在 |Ubiqua|_ 下载并安装最新版本的 **Ubiqua**。


开始使用 Ubiqua
===============

1. 添加 OM15020-JN5169 设备

|add-device.png|

2. 选中设备，右键选择协议栈

|protocol-stack.png|

3. 选中设备，右键选择信道

.. note::

    信道根据网关的信道设置，才能捕获到网关所在的 ZigBee 网络数据包。

|channel.png|

4. 打开开关

|on.png|

5. 开始抓ZigBee数据包

打开`Tool` -> `Options...` -> `Security`，配置 `Application or Trust Center Link Key`
Key: 5A6967426565416C6C69616E63653039

|options.png|

6. 捕获到协调器节点

|sniffer-1.png|

7. 添加一个 ZigBee 子设备

|sniffer-1.png|

.. note::

    数据包显示有彩色，说明 key 是正确，才能成功解密数据包，如果数据包全为灰色黑色，说明 key 设置不对
