==============
Wireshark 抓包
==============

.. include:: ../refs/om15080-jn5189/resource.ref
.. include:: ../refs/om15080-jn5189/sniffer-wireshark.ref

烧录 sniffer 固件
=================

参考 :doc:`flash` 中的说明，烧录 |Sniffer_jn5189_1000000baud_8N1_NoFlowControl.bin|_ 固件到 **om15080-jn5189** 中。

安装 Wireshark
===============

|WireShark|_ 是一个网络抓包工具。在 |WireShark|_ 下载并安装最新版本的 **Wireshark**。


安装辅助工具
============

安装 |Kinetis_Protocol_Analyzer_Adapter.exe|_ 到电脑上，如果电脑安装了 npcap ，需要卸载掉。


打开 WireShark
===============

1. 打开 Kinetis_Protocol_Analyzer_Adapter ，进入如下界面：

    |protocol-analyzer-adapter.png|

2. 选择需要捕获的信道

    |select-channel.png|

3. 点击按钮，打开 **WireShark**

    |open-wireshark.png|


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
