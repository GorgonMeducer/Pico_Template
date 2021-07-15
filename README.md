# Pico_Template (0.1.2)
An MDK template for Raspberry Pi Pico

- Compiler: Arm Compiler 6.16 (Using non-intrusive wrapper to support pico-sdk which is written in GCC)


# Known issue
- Debugger support is not available for now.
- elf2uf2 cannot convert axf file to uf2 [issue506](https://github.com/raspberrypi/pico-sdk/issues/506) (**Fixed in this template**, waiting for upstream approval)
- stage2 boot succeed but the blink LED demo doesn't work. (I am working on this)

