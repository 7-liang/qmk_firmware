# Keyboard Firmwares of Y&R Studio

## Studio overview

A creative coder.

> Jason Ren (Biu)

## Keyboard Firmwares and Utils

### Keyboards Released by Y&R Studio Itself
| NAME          | VENDOR_ID | PRODUCT_ID | FEATURES                              | COMMERCIALIZATION |
| ------------- | --------- | ---------- | ------------------------------------- | ----------------- |
| rainbow65     | 0xAA96    | 0xAA00     | OLED, RGB, ENCODER                    | &check;           |
| cool87        | 0xAA96    | 0xAA01     | 32u4                                  | &cross;           |
| sb65p         | 0xAA96    | 0xAA02     | 2.4G Single mode Split Keyboard       | &cross;           |
| r65ble        | 0xAA96    | 0xAA03     | BLE 5.0 Dual mod version of rainbow65 | &cross;           |
| whitemouse28t | 0xAA96    | 0xAA04     | External EEPROM (95256), For Test     | &cross;           |
| m60ble        | 0xAA96    | 0xAA05     | BLE 5.0 Dual mode, RGB                | &quest;           |
| yr64ble       | 0xAA96    | 0xAA06     | BLE 5.0 Dual mode                     | &quest;           |


### Keyboards Completed with Y&R Studio Participation 
| NAME         | VENDOR_ID | PRODUCT_ID | FEATURES                         | COMMERCIALIZATION |
| ------------ | --------- | ---------- | ---------------------------------| ----------------- |
| nlhhkb       | 0xAA96    | 0xAAA0     | 32u4                             | &quest;           |
| tdcq68       | 0xAA96    | 0xAAA1     | F401, RGB                        | &cross;           |
| tdcq64_2s    | 0xAA96    | 0xAAA2     | F401, RGB                        | &cross;           |
| yp980ble     | 0xAA96    | 0xAAA3     | BLE 5.0 Dual mode                | &quest;           |
| whitemouse69 | 0xAA96    | 0xAAA4     | F401, RGB                        | &check;           |
| wave87       | 0xAA96    | 0xAAA5     | F401, RGB                        | &check;           |
| m69          | 0xAA96    | 0xAAA6     | F401,80%, RGB, Hotswap           | &check;           |
| m69          | 0xAA96    | 0xAAB6     | F401,80%, RGB, Solder            | &check;           |
| zhou75       | 0xAA96    | 0xAAA7     | F401, ENCODER, Hotswap           | &check;           |
| zhou75       | 0xAA96    | 0xAAB7     | F401, ENCODER, Solder            | &check;           |
| yp87ble      | 0xAA96    | 0xAAA8     | BLE 5.0 Dual mode                | &quest;           |
| hotdox76v2   | 0xAA96    | 0xAAA9     | 32u4, Split KB, OLED, RGB        | &check;           |
| eureka75     | 0xAA96    | 0xAAAA     | F401,ENCODER                     | &check;           |
| boy40ble     | 0xAA96    | 0xAAAB     | BLE 5.0 Dual mode                | &quest;           |
| boyPad       | 0xAA96    | 0xAAAC     | F401                             | &cross;           |
| zhou65       | 0xAA96    | 0xAAAD     | F401                             | &check;           |
| lh68         | 0xAA96    | 0xAAAE     | F401, RGB                        | &quest;           |
| nz64         | 0xAA96    | 0xAAAF     | F401, RGB                        | &check;           |
| ty66ble      | 0xAA96    | 0xAAC0     | BLE 5.0 Dual mode                | &check;           |
| sci980       | 0xAA96    | 0xAAC1     | 32u4, RGB                        | &check;           |
| z_alice_ble  | 0xAA96    | 0xAAC2     | BLE 5.0 Dual mode, RGB           | &check;           |
| coder68ble   | 0xAA96    | 0xAAC3     | BLE 5.0 Dual mode, Hotswap       | &check;           |
| coder68ble   | 0xAA96    | 0xAAC4     | BLE 5.0 Dual mode, Solder        | &check;           |
| s68mble      | 0xAA96    | 0xAAC5     | BLE 5.0 Dual mode, Solder        | &check;           |
| zhou65ble    | 0xAA96    | 0xAAC6     | BLE 5.0 Dual mode, Hotswap       | &check;           |
| m93ble       | 0xAA96    | 0xAAC7     | BLE 5.0 Dual mode, Hotswap, RGB  | &check;           |
| rs40ble      | 0xAA96    | 0xAAC8     | BLE 5.0 Dual mode, Hotswap, RGB  | &check;           |
| s68m         | 0xAA96    | 0xAAC9     | STM32F103 UF2, Solder            | &check;           |
| zpadble      | 0xAA96    | 0xAACA     | BLE, Hotswap, RGB, Encoder, OLED | &check;           |
| ml75r2ble    | 0xAA96    | 0xAACB     | BLE, Encoder, OLED               | &check;           |


### Obsolete keyboard for reference design only

| NAME         | VENDOR_ID | PRODUCT_ID | FEATURES                         | COMMERCIALIZATION |
| --------- | ---- | ---- | ---- | ---- |
| final80v2 | 0xFEED | 0x6060 | STM32F303 | &cross; |



### Keyboard Tools Developed by Y&R Studio

- RGB matrix calculation script
- Sound visualization script
- Real time key remap software

### Make Command
```shell
make yandrstudio/z_alice_ble/f401:ble; make yandrstudio/zhou65ble/f401:ble; make yandrstudio/m93ble/f401:ble; make yandrstudio/rs40ble/f401:ble;
```
