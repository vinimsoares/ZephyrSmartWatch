# ZephyrSmartWatch

## Build
This project was designed around the xiao nrf52840 sense board and building reflects that. It can be built using:  
```
west build -p always -b xiao_ble/nrf52840/sense
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
Computer Engineer @ Iowa State University  
vinicius.malaman12@gmail.com