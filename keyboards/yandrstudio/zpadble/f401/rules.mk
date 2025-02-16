# MCU name
MCU = STM32F401

# Bootloader selection
BOOTLOADER = stm32-dfu

# Bootloader selection
# MCU_LDSCRIPT = STM32F401xC_tinyuf2
# BOOTLOADER = tinyuf2
# FIRMWARE_FORMAT = uf2

# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812
WS2812_DRIVER = pwm

OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes

CUSTOM_MATRIX = lite    # for using the A9 pin as matrix io
QUANTUM_SRC += matrix_io.c 74hc595_io.c


EEPROM_DRIVER = custom
SRC += eep/eeprom_stm32.c
SRC += eep/flash_stm32.c
OPT_DEFS += -DEEPROM_EMU_STM32F401xC
