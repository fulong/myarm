proj_name=fulong
CROSS_COMPILER=arm-uclinuxeabi-
ARCH=armv7-m
CPU=cortex-m3
exe_dir=exe
log_dir=log
Csources=./libc/libmath.c ./libc/string.c ./libc/font.c ./package/usart_package.c ./package/tft.c ./protocol/spi.c ./sysdev/general/usart.c ./sysdev/general/led.c ./sysdev/general/gpio.c ./sysdev/general/touch.c ./sysdev/general/init_main.c ./sysdev/general/interrupt.c ./user/main.c ./chip/tsc2046.c ./chip/ssd1963.c
Ssources=
Depend_OBJ=libmath.d string.d font.d usart_package.d tft.d spi.d usart.d led.d gpio.d touch.d init_main.d interrupt.d main.d tsc2046.d ssd1963.d
VPATH=. ./lds_bak ./libc ./start_code ./package ./protocol ./sysdev ./sysdev/general ./cpu ./exe ./log ./user ./user/user_configure ./chip
#############增加ucos-ii相关源文件与目录####################
Csources+=./OS/ucos-ii/main.c
Ssources+=
Depend_OBJ+=main.d
VPATH+=./OS/ucos-ii
#############增加ucos-ii相关源文件与目录####################
#############增加cortex-m3相关源文件与目录####################
Csources+=./sysdev/cortex-m3/src/fsmc.c ./sysdev/cortex-m3/src/rcc.c ./sysdev/cortex-m3/src/systick.c ./cpu/cortex-m3/stm32f103/CoreSupport/core_cm3.c ./cpu/cortex-m3/stm32f103/STM32F10x/system_stm32f10x.c
Ssources+=./start_code/cortex-m3/startup_stm32f10x_hd.s
Depend_OBJ+=fsmc.d rcc.d systick.d core_cm3.d startup_stm32f10x_hd.d
VPATH+=./start_code/cortex-m3 ./protocol/cortex-m3 ./protocol/cortex-m3/inc ./sysdev/cortex-m3 ./sysdev/cortex-m3/inc ./sysdev/cortex-m3/src ./cpu/cortex-m3 ./cpu/cortex-m3/stm32f103 ./cpu/cortex-m3/stm32f103/CoreSupport ./cpu/cortex-m3/stm32f103/STM32F10x
#############增加cortex-m3相关源文件与目录####################
#*******************工具配置*************************************
CC=arm-uclinuxeabi-gcc
LD=arm-uclinuxeabi-ld
OBJCOPY=arm-uclinuxeabi-objcopy
OBJDUMP=arm-uclinuxeabi-objdump
AS=arm-uclinuxeabi-gcc
#*******************工具配置*************************************
CFLAGS = -c -Wall -ffunction-sections
ASFLAGS = -c -Wall -ffunction-sections
LD_FLAGS = --gc-sections 
OBJCOPY_FLAGS = -O binary -S
OBJDUMP_FLAGS = -D -m arm
CFLAGS += -O2
ASFLAGS += -O2
CFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) 
ASFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) 
LD_FLAGS += -T$(exe_dir)/$(CPU).lds
RM=rm -rf
