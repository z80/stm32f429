#~/bin/sh
ARCH=arm
CROSS_COMPILE=/home/z80/programs/sw4stm32/plugins/fr.ac6.mcu.externaltools.arm-none.linux32_1.7.0.201602151102/tools/compiler/bin/arm-none-eabi-

PATH=$PATH:/home/z80/programs/sw4stm32/plugins/fr.ac6.mcu.externaltools.arm-none.linux32_1.7.0.201602151102/tools/compiler/bin
arm-none-eabi-gdb ../out/linux-4.4.5/vmlinux -tui
