The version used is ESP-IDF v5.4. The usage of the four sample files lvgl_demo_v8, lvgl_demo_v9, esp_draw_bit, and esp_brookesia_phone is as follows:
```
idf.py set-target esp32p4

idf.py flash monitor
```
After selecting the esp32p4 chip, you can directly flash it.

lvgl_demo_v8 is a sample for LVGL v8.

lvgl_demo_v9 is a sample for LVGL v9.

esp_draw_bit is a sample for drawing points on touch areas.

esp_brookesia_phone is a sample that mimics a mobile phone UI. The usage of the usb_extend_screen sample is as follows:
```
idf.py set-target esp32p4

idf.py menuconfig
```
After entering the configuration page, configure it according to the following path.

![image 1](pictures\img1.png)

After configuration, use `idf.py flash monitor` to flash the program. Once flashed, it can be used as a secondary screen via the high-speed USB port.

Note: Currently, the driver does not support portrait mode; full-screen display is not supported on this product. See the secondary screen documentation for driver installation instructions.

The source code for the xiaozhi-esp32 program is on GitHub. Visit https://github.com/78/xiaozhi-esp32 to obtain the latest source code.

The provided xiaozhi-esp32 sample version is v1.5.6. The specific usage is as follows:

```
idf.py set-target esp32p4

idf.py menuconfig
```

![image 2](pictures\img2.png)

```
idf.py build

idf.py flash monitor
```
If the following is printed:

![image 3](pictures\img3.png)

Please first check if the board has been selected correctly, and then check if the corresponding code in the image below matches.

![image 4](pictures\img4.png)

![image 5](pictures\img5.png)

To update to the latest version, copy the jc1060pa1 folder from this example to the corresponding location. The display and touch libraries are located in the common_components folder in the same directory as xiaozhi-esp32. Please add EXTRA_COMPONENT_DIRS and copy the display and touch library folders to the specified directory. Add the following code to your CMakeLists.txt file:
```
set(EXTRA_COMPONENT_DIRS
../common_components //replace with your path
)
```
system_info.cc

![image 6](pictures\img6.png)

Kconfig.projbuild
