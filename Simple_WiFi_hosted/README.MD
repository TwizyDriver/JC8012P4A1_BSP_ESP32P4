## Terminal output

```
Hard resetting via RTS pin...
--- Terminal on COM5 | 115200 8-N-1
--- Available filters and text transformations: colorize, debug, default, direct, esp32_exception_decoder, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at https://bit.ly/pio-monitor-filters
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
I (1951) sdio_wrapper: SDIO master: Slot 1, Data-Lines: 4-bit Freq(KHz)[40000 KHz]
I (1951) sdio_wrapper: GPIOs: CLK[18] CMD[19] D0[14] D1[15] D2[16] D3[17] Slave_Reset[54]
I (1951) sdio_wrapper: Queues: Tx[20] Rx[20] SDIO-Rx-Mode[1]
I (1991) sdio_wrapper: Function 0 Blocksize: 512
I (1991) sdio_wrapper: Function 1 Blocksize: 512
I (2091) H_SDIO_DRV: Card init success, TRANSPORT_RX_ACTIVE
I (2091) transport: set_transport_state: 1
I (2091) transport: Waiting for esp_hosted slave to be ready
I (2111) H_SDIO_DRV: SDIO Host operating in STREAMING MODE
I (2111) H_SDIO_DRV: Open data path at slave
I (2111) H_SDIO_DRV: Starting SDIO process rx task
I (2111) H_SDIO_DRV: Received ESP_PRIV_IF type message
I (2111) transport: Received INIT event from ESP32 peripheral
I (2121) transport: EVENT: 12
I (2121) transport: Identified slave [esp32c6]
I (2121) transport: EVENT: 11
I (2131) transport: capabilities: 0xd
I (2131) transport: Features supported are:
I (2131) transport:      * WLAN
I (2141) transport:        - HCI over SDIO
I (2141) transport:        - BLE only
I (2141) transport: EVENT: 13
W (2151) transport: Version mismatch: Host [2.12.0] > Co-proc [0.0.0] ==> Upgrade co-proc to avoid RPC timeouts
I (2161) transport: ESP board type is : 13

I (2161) transport: Base transport is set-up, TRANSPORT_TX_ACTIVE
I (2171) H_API: Transport active
I (2171) transport: Slave chip Id[12]
I (2171) transport: raw_tp_dir[-], flow_ctrl: low[60] high[80]
I (2181) transport: transport_delayed_init
I (2181) esp_cli: Registering command: crash
I (2191) esp_cli: Registering command: reboot
I (2191) esp_cli: Registering command: mem-dump
I (2191) esp_cli: Registering command: task-dump
I (2201) esp_cli: Registering command: cpu-dump
I (2201) esp_cli: Registering command: heap-trace
I (2211) esp_cli: Registering command: sock-dump
I (2211) esp_cli: Registering command: host-power-save
I (2221) hci_stub_drv: Host BT Support: Disabled
I (2221) H_SDIO_DRV: Received INIT event
I (2221) H_SDIO_DRV: Event type: 0x22
I (2231) H_SDIO_DRV: Write thread started
I (2291) transport: Attempt connection with slave: retry[0]
I (2291) transport: Transport is already up
I (2411) RPC_WRAP: Coprocessor Boot-up
I (2641) app_main: Wi-Fi starts on ESP32-P4 using external ESP32-C6
I (2641) RPC_WRAP: ESP Event: wifi station started
I (2661) H_API: esp_wifi_remote_connect
I (2671) app_main: Started connection
I (3641) app_main: Application running...
I (4641) app_main: Application running...
I (5641) app_main: Application running...
I (5691) RPC_WRAP: ESP Event: Station mode: Connected
I (5691) esp_wifi_remote: esp_wifi_internal_reg_rxcb: sta: 0x40022b36
I (5691) app_main: Successfully connected to the AP ssid : ZyXEL2
I (6641) app_main: Application running...
I (7071) esp_netif_handlers: sta ip: 192.168.1.69, mask: 255.255.255.0, gw: 192.168.1.1
I (7071) app_main: got ip:192.168.1.69
I (7641) app_main: Application running...
I (8641) app_main: Application running...
I (9641) app_main: Application running...
```
