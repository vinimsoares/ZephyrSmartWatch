# ZephyrSmartWatch

## Hardware Set-Up
**SDK:** NRF Connect SDK v3.4.0  
**MCU:** Xiao nrf52840 Sense   
-ARM Cortex-M4 32-bit 64MHz  
-Bluetooth Low Energy 5.4/Bluetooth Mesh/NFC  
-Built-in 6-axis IMU  
**Display:** 1.28" Touch Round LCD  
-GC9A01 display driver, 240x240, RGB565 over SPI  
-CST816D capacitive touch driver over I2C  


## Build
This project was designed around the xiao nrf52840 sense board and building reflects that. It can be built using:  

```
west build -p always -b xiao_ble/nrf52840/sense -s .
```

## Flashing
The xiao nrf52840 sense boards supports the UF2 bootloader.  
Double click the reset button to put board in storage mode.  
The board can be flashed by copying the zephyr.uf2 inside `\app_name\build\app_name\zephyr` to the storage or running:  

```
west flash -r uf2
```



## Author & Contact
Vinicius Malaman Soares  
Computer Engineer Student @ Iowa State University  
vinicius.malaman12@gmail.com
