CROSS_COMPLIER=arm-none-eabi-
#CROSS_COMPLIER=arm-uclinuxeabi-

ARCH=armv7-m
#Permissible names are: `armv2', `armv2a', `armv3', `armv3m', \
`armv4', `armv4t', `armv5', `armv5t', `armv5e', `armv5te', `armv6', `armv6j', `armv6t2', `armv6z', `armv6zk', `armv6-m', \
`armv7', `armv7-a', `armv7-r', `armv7-m', `iwmmxt', `iwmmxt2', `ep9312'.
CPU=cortex-m3
#Permissible names are: `arm2', `arm250', `arm3', `arm6', `arm60', `arm600', `arm610', `arm620', `arm7', `arm7m', `arm7d', `arm7dm', `arm7di', `arm7dmi', `arm70', `arm700', `arm700i', `arm710', `arm710c', `arm7100', `arm720', `arm7500', `arm7500fe', `arm7tdmi', `arm7tdmi-s', `arm710t', `arm720t', `arm740t', `strongarm', `strongarm110', `strongarm1100', `strongarm1110', `arm8', `arm810', `arm9', `arm9e', `arm920', \
`arm920t', `arm922t', `arm946e-s', `arm966e-s', `arm968e-s', `arm926ej-s', `arm940t', `arm9tdmi', `arm10tdmi', `arm1020t', `arm1026ej-s', `arm10e', `arm1020e', `arm1022e', `arm1136j-s', `arm1136jf-s', `mpcore', `mpcorenovfp', `arm1156t2-s', `arm1156t2f-s', `arm1176jz-s', `arm1176jzf-s', `cortex-a5', `cortex-a7', \
`cortex-a8', `cortex-a9', `cortex-a15', `cortex-r4', `cortex-r4f', `cortex-r5', `cortex-m4', `\
cortex-m3', `cortex-m1', `cortex-m0', `xscale', `iwmmxt', `iwmmxt2', `ep9312', `fa526', `fa626', `fa606te', `fa626te', `fmp626', `fa726te'.
ifeq "$(ARCH)" ""
$(error 请定义CPU指令架构。)
endif
ifeq "$(CPU)" ""
$(error 请定义CPU型号。)
endif
#目录变量
elf_output_dir := obj_output/
output_dir := obj_output/
cpu_dir := stm32f103/
start_dir := start_code/
user_dir := user/

#命令变量
CC = ${CROSS_COMPLIER}gcc
CFLAGS = -c \
		 -Wall \
		 -ffunction-sections 
ifeq "$(ARCH)" "armv7-m"
CFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) 
ifeq "$(CROSS_COMPLIER)" "arm-uclinuxeabi-"
CFLAGS += -O2
endif
endif
ifeq "$(ARCH)" "armv4t"
CFLAGS += -march=$(ARCH) -mcpu=$(CPU) 
endif

AS = ${CROSS_COMPLIER}gcc 
ASFLAGS = -c \
		  -Wall \
		  -ffunction-sections
ifeq "$(ARCH)" "armv7-m"
ASFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) 
ifeq "$(CROSS_COMPLIER)" "arm-uclinuxeabi-"
ASFLAGS += -O2
endif
endif
ifeq "$(ARCH)" "armv4t"
ASFLAGS += -march=$(ARCH) -mcpu=$(CPU) 
endif

LD = ${CROSS_COMPLIER}ld
ifeq "$(ARCH)" "armv7-m"
LD_FLAGS = -Tstm32f103.lds --gc-sections 
endif
ifeq "$(ARCH)" "armv4t"
LD_FLAGS = -Tarm_ucos.lds --gc-sections 
endif

OBJCOPY_FLAGS = -O binary -S

OBJCOPY = ${CROSS_COMPLIER}objcopy
OBJDUMP = ${CROSS_COMPLIER}objdump
OBJDUMP_FLAGS = -D -m arm