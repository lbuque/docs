==============
Wireshark 抓包
==============

.. include:: ../../refs/zigbee-series/om15020-jn5169/resource.ref
.. include:: ../../refs/zigbee-series/om15020-jn5169/sniffer-wireshark.ref

烧录 sniffer 固件
=================

参考 :doc:`flash` 中的说明，烧录 |JennicSniffer_JN5169_1000000.bin|_ 固件到 **OM15020-JN5169** 中。

安装 Wireshark
===============

|WireShark|_ 是一个网络抓包工具。在 |WireShark|_ 下载并安装最新版本的 **Wireshark**。


运行 ZBSniffer.exe 抓包工具
===========================

在启动抓包前，先设置 **Wireshark** 的安装目录， **OM15020-JN5169** 的串口端口号和 ZigBee 的运行信道。

点击 **ZBSniffer.exe** 的 **Start** 按钮后启动 **Wireshark**。 二者通过命名管道的方式交换抓包数据。 **Wireshark** 将会接收命名管道的数据，并解析 **IEEE802.15.4** 数据包。

|ZBSniffer.png|


设置Trust Center Link Key
=========================

在 **Wireshark** 中配置 ZigBee 默认的 Link Key ，否则无法解析加密网络内容。

通过 `Edit` --> `Preferences` --> `Protocols` --> `ZigBee` 菜单配置16 字节的 `Trust Center Link Key={5A:69:67:42:65:65:41:6C:6C:69:61:6E:63:65:30:39}`

    |Preferences.png|

    |TrustCenterLinkKey.png|


下面是通过 **Wireshark** 解析 ZigBee 数据包的截图，可以将 ZigBee 的各个字段进行详细解析。

    |ZigBeePackage.png|


抓取分析 IEEE802.15.4/Thread 协议
=================================

由于 Thread 与 ZigBee 都是基于 IEEE802.15.4 MAC ，所以这个工具也可以通过 **Wireshark** 解析 Thread 协议。

    |ThreadPackage.png|
