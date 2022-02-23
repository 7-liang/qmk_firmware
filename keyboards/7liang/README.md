# Keyboard Firmware of 7Liang

### Firmware List

| Keyboard          | Vendor ID | Product ID | Device Ver | Features         |
| ----------------- | --------- | ---------- | ---------- | ---------------- |
| tp32              | 0xF340    | 0x0101     | 0x0001     | 32 Keys, Track Point, Kailhua choc, Hot plug, Leather keyboard, Very portable       |
| tpec32            | 0xF340    | 0x0201     | 0x0001     | 32Keys, Track Point + Encoder, MX welded shaft, 3D print hull                     |
| tpec11801         | 0xF340    | 0x0301     | 0x0001     | Remake of Compaq 11801, Add Track Point and Encoder                         |

### Build Command
~~~ shell
qmk compile -kb 7liang/tp32 -km default

make 7liang/tp32:default
~~~
