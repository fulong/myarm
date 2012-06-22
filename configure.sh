#!/bin/bash
##################################################################
# @file : configure.sh
# @brief: 项目代码最初使用的时候必须先运行这个脚本，配置好编译器，体系结构等等
######################全局变量######################################
temp_file=/tmp/cross_configure #暂存文件
cross_select= #编译器类型存储
arch_select= #指令集选型
cpu_select= #CPU内核选型
obj_dir= #可执行文件，与反汇编文件所在
######################全局变量######################################

dialog --title "configure" --msgbox "项目代码最初使用的时候运行的一个脚本，配置好编译环境，体系结构等等" 10 30 
#################交叉编译器版本选择#####################################
cross_item_num=2
cross_item='1 arm-none-eabi 2 arm-uclinuxeabi'

flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
#判断选择的是哪个编译器版本。
while [ "$flag" != "0" ];do
dialog --clear
dialog --title "交叉编译器版本" --menu "你将会选择哪个版本？" 10 30 ${cross_item_num} ${cross_item} --title "再次确认" --yesno "你确定要这样做吗？" 10 30 2> $temp_file
flag=$?
done

cross_select=$(cat $temp_file)
if [ "$cross_select" = "1" ];then
echo "CROSS_COMPILER=arm-none-eabi-" > configure.mk
cross_select=arm-none-eabi
elif [ "$cross_select" = "2" ];then
echo "CROSS_COMPILER=arm-uclinuxeabi-" > configure.mk
cross_select=arm-uclinuxeabi
fi
#################交叉编译器版本选择#####################################
####################指令集版本选择####################################
#Permissible names are: `armv2', `armv2a', `armv3', `armv3m', 
#`armv4', `armv4t', `armv5', `armv5t', `armv5e', `armv5te', `armv6', `armv6j', `armv6t2', `armv6z', `armv6zk', `armv6-m',
#`armv7', `armv7-a', `armv7-r', `armv7-m', `iwmmxt', `iwmmxt2', `ep9312'.
#输入指令集版本选择。
ARCH_VAR='armv7-m\narmv4t\n' #可供选择的指令集
flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
while [ "$flag" != "0" ];do
dialog --clear
dialog --title "指令集版本选择" --inputbox "请输入你当前使用的指令集名称。你可以选择的指令集(目前支持).\n$ARCH_VAR" 20 50  2> $temp_file

arch_select=$(cat $temp_file)
flag=0
if [ -z "$arch_select" ];then
dialog --title "再次确认" --yesno "你将会使用GCC默认的指令集，你确定要这样做吗？" 10 30
flag=$?
elif [ "$arch_select" != "armv7-m" ] && [ "$arch_select" != "armv4t" ] ;then
dialog --title "你可以选择的指令集(目前支持),请输入正确的指令集名称"  --msgbox "$ARCH_VAR" 20 50
flag=1
fi
done

echo "ARCH=$arch_select" >> configure.mk
####################指令集版本选择####################################
####################CPU内核版本选择####################################
#Permissible names are: `arm2', `arm250', `arm3', `arm6', `arm60', `arm600', `arm610', `arm620', `arm7', `arm7m', `arm7d', `arm7dm', `arm7di', `arm7dmi', `arm70', `arm700', `arm700i', `arm710', `arm710c', `arm7100', `arm720', `arm7500', `arm7500fe', `arm7tdmi', `arm7tdmi-s', `arm710t', `arm720t', `arm740t', `strongarm', `strongarm110', `strongarm1100', `strongarm1110', `arm8', `arm810', `arm9', `arm9e', `arm920', 
#`arm920t', `arm922t', `arm946e-s', `arm966e-s', `arm968e-s', `arm926ej-s', `arm940t', `arm9tdmi', `arm10tdmi', `arm1020t', `arm1026ej-s', `arm10e', `arm1020e', `arm1022e', `arm1136j-s', `arm1136jf-s', `mpcore', `mpcorenovfp', `arm1156t2-s', `arm1156t2f-s', `arm1176jz-s', `arm1176jzf-s', `cortex-a5', `cortex-a7', 
#`cortex-a8', `cortex-a9', `cortex-a15', `cortex-r4', `cortex-r4f', `cortex-r5', `cortex-m4', `
#cortex-m3', `cortex-m1', `cortex-m0', `xscale', `iwmmxt', `iwmmxt2', `ep9312', `fa526', `fa626', `fa606te', `fa626te', `fmp626', `fa726te'.
#输入CPU内核版本选择。
CPU_VAR='arm920t\ncortex-a8\ncortex-m3\n' #可供选择的CPU内核
flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
while [ "$flag" != "0" ];do
dialog --clear
dialog --title "CPU内核版本" --inputbox "请输入你当前使用的CPU内核版本名称。你可以选择的CPU内核版本(目前支持).\n$CPU_VAR" 20 50  2> $temp_file

cpu_select=$(cat $temp_file)
flag=0
if [ -z "$cpu_select" ];then
dialog --title "再次确认" --yesno "你将会使用GCC默认的CPU内核版本，你确定要这样做吗？" 10 30
flag=$?
elif [ "$cpu_select" != "arm920t" ] && [ "$cpu_select" != "cortex-a8" ] && [ "$cpu_select" != "cortex-m3" ] ;then
dialog --title "你可以选择的CPU内核版本(目前支持),请输入正确的CPU内核版本名称"  --msgbox "$CPU_VAR" 20 50
flag=1
fi
if [ "$arch_select" = "" ];then
    dialog  --msgbox "cpu选型有误，与指令集版本不能不同时为空，请重新配置一次。" 20 50
    rm configure.mk
    clear
    exit 0
fi
done

echo "CPU=$cpu_select" >> configure.mk
####################CPU内核版本选择####################################
if [ "$arch_select" != "" ] && [ "$cpu_select" = "" ];then
    dialog  --msgbox "cpu选型有误，与指令集版本不能不同时为空，请重新配置一次。" 20 50
    rm configure.mk
    clear
    exit 0
fi

####################o文件输出的路径####################################
#这里所需要的O文件都是中间文件，所以到最后，这些都将在编译成功后删除掉。
flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
while [ "$flag" != "0" ];do
dialog --title "设置O文件输出的路径" --inputbox "请输入O文件的链接路径，这路径也是链接脚本所在的位置。最终链接生成的bin文件跟反汇编文件将会移动到这个路径中。格式为:./home/" 20 50  2> $temp_file
obj_dir=$(cat $temp_file)
if [ -z "$obj_dir" ];then
dialog --title "再次确认" --yesno "bin文件跟反汇编文件将在根目录上，你确定要这样做吗？" 10 30 
flag=$?
else
mkdir -p $obj_dir
flag=0
fi
if [ "$flag" = "0" ];then
echo "obj_dir=$obj_dir" >> configure.mk
fi
done
####################o文件输出的路径####################################
clear
####################项目的源码目录汇总###################################
sum_dir=$(find . -type d | grep -v git )
echo "配置VPATH搜索路径，VPATH值为"
echo "$sum_dir"
sum_dir=$(echo -n $sum_dir) #将所有行连接在一起，并使他们在同一行
echo "VPATH=$sum_dir" >> configure.mk
####################项目的源码目录汇总###################################
####################编译环境配置###################################
#*******************工具配置********************************************
echo "CC工具为${cross_select}-gcc "
echo "CC=${cross_select}-gcc" >> configure.mk
echo "LD工具为${cross_select}-ld "
echo "LD=${cross_select}-ld" >> configure.mk
echo "OBJCOPY工具为${cross_select}-objcopy "
echo "OBJCOPY=${cross_select}-objcopy" >> configure.mk
echo "OBJDUMP工具为${cross_select}-objdump "
echo "OBJDUMP=${cross_select}-objdump" >> configure.mk
echo "AS工具为${cross_select}-gcc "
echo "AS=${cross_select}-gcc" >> configure.mk
#*******************工具配置********************************************
#*******************工具选项配置******************************************
echo "配置工具的选项"
CFLAGS='-c -Wall -ffunction-sections '
ASFLAGS='-c -Wall -ffunction-sections'
OBJCOPY_FLAGS='-O binary -S'
LD_FLAGS='--gc-sections '
OBJDUMP_FLAGS='-D -m arm'
echo 'CFLAGS = -c -Wall -ffunction-sections' >> configure.mk
echo 'ASFLAGS = -c -Wall -ffunction-sections' >> configure.mk
echo 'LD_FLAGS = --gc-sections ' >> configure.mk
echo 'OBJCOPY_FLAGS = -O binary -S' >> configure.mk
echo 'OBJDUMP_FLAGS = -D -m arm' >> configure.mk
if [ "$cross_select" = "arm-uclinuxeabi" ] || [ "$cpu_select" != "cortex-m3" ];then
echo 'CFLAGS += -02' >> configure.mk
echo 'ASFLAGS += -02' >> configure.mk
CFLAGS="$CFLAGS -02"
ASFLAGS="$ASFLAGS -02"
fi

if [ "$arch_select" = "armv7-m" ];then
case $cpu_select in
  "cortex-m3" )
      echo 'CFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'ASFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'LD_FLAGS += -Tcortex-m3.lds' >> configure.mk
      CFLAGS="$CFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      ASFLAGS="$ASFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      LD_FLAGS="$LD_FLAGS -Tcortex-m3.lds"
      ;;
  "cortex-a8" )
      echo 'CFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'ASFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'LD_FLAGS += -Tcortex-a8.lds' >> configure.mk
      CFLAGS="$CFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      ASFLAGS="$ASFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      LD_FLAGS="$LD_FLAGS -Tcortex-a8.lds"
      ;;
  *) 
    echo "cpu选型有误，与指令集版本不匹配，请重新配置一次。"
    rm configure.mk
    exit 0
    ;;
esac
fi
if [ "$arch_select" = "armv4t" ];then
case $cpu_select in
  "arm920t" )
      echo 'CFLAGS += -march=$(ARCH) -mcpu=$(CPU)' >> configure.mk
      echo 'ASFLAGS += -march=$(ARCH) -mcpu=$(CPU)' >> configure.mk
      echo 'LD_FLAGS = -Tarmv4t.lds' >> configure.mk
      CFLAGS="$CFLAGS -march=$arch_select -mcpu=$cpu_select"
      ASFLAGS="$ASFLAGS -march=$arch_select -mcpu=$cpu_select"
      LD_FLAGS="$LD_FLAGS -Tarm920t.lds"
      ;;
  *) 
    echo "cpu选型有误，与指令集版本不匹配，请重新配置一次。"
    rm configure.mk
    exit 0
    ;;
esac
fi
echo "配置完成。"
echo "CC的选项为$CFLAGS"
echo "AS的选项为$ASFLAGS"
echo "LD的选项为$LD_FLAGS"
echo "OBJCOPY的选项为$OBJCOPY_FLAGS"
echo "OBJDUMP的选项为$OBJDUMP_FLAGS"
#*******************工具选项配置******************************************
####################编译环境配置###################################

exit 0