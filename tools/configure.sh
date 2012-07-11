#!/bin/bash
##################################################################
# @file : configure.sh
# @brief: 项目代码最初使用的时候必须先运行这个脚本，配置好编译器，体系结构等等
######################全局变量######################################
temp_file=/tmp/cross_configure #暂存文件
cross_select= #编译器类型存储
arch_select= #指令集选型
cpu_select= #CPU内核选型
exe_dir= #可执行文件，与反汇编文件所在
LDS_BAK=lds_bak #链接脚本备份文件所在的文件夹
log_dir= #源文件所依赖的汇总文件所保存的文件夹
proj_name= #项目的名字
OS= #选择的RT系统
######################全局变量######################################
dialog --title "configure" --msgbox "项目代码最初使用的时候运行的一个脚本，配置好编译环境，体系结构等等" 10 30 
######################定义项目名称######################################
ProjectName()
{
	flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
	while [ "$flag" != "0" ];do
	dialog --clear
	dialog --title "项目名称" --inputbox "请输入你当前使用项目名称。为空时，会默认为Myarm.\n" 20 50  2> $temp_file
	
	proj_name=$(cat $temp_file)
	flag=0
	if [ -z "$proj_name" ];then
	dialog --title "再次确认" --yesno "你将会使用默认的项目名称，你确定要这样做吗？" 10 30
	flag=$?
	if [ "$flag" = "0" ];then
	proj_name=Myarm
	echo "proj_name=$proj_name" > configure.mk
	fi
	else 
	echo "proj_name=$proj_name" > configure.mk
	fi
	done
}
######################定义项目名称######################################
#################总共的源文件#####################################
#################总共的源文件#####################################
#################交叉编译器版本选择#####################################
CrossCompiler_Select()
{
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
	echo "CROSS_COMPILER=arm-none-eabi-" >> configure.mk
	cross_select=arm-none-eabi
	elif [ "$cross_select" = "2" ];then
	echo "CROSS_COMPILER=arm-uclinuxeabi-" >> configure.mk
	cross_select=arm-uclinuxeabi
	fi
}
#################交叉编译器版本选择#####################################
####################指令集版本选择####################################
#Permissible names are: `armv2', `armv2a', `armv3', `armv3m', 
#`armv4', `armv4t', `armv5', `armv5t', `armv5e', `armv5te', `armv6', `armv6j', `armv6t2', `armv6z', `armv6zk', `armv6-m',
#`armv7', `armv7-a', `armv7-r', `armv7-m', `iwmmxt', `iwmmxt2', `ep9312'.
#输入指令集版本选择。
ARCH_Select()
{
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
}
####################指令集版本选择####################################
####################CPU内核版本选择####################################
#Permissible names are: `arm2', `arm250', `arm3', `arm6', `arm60', `arm600', `arm610', `arm620', `arm7', `arm7m', `arm7d', `arm7dm', `arm7di', `arm7dmi', `arm70', `arm700', `arm700i', `arm710', `arm710c', `arm7100', `arm720', `arm7500', `arm7500fe', `arm7tdmi', `arm7tdmi-s', `arm710t', `arm720t', `arm740t', `strongarm', `strongarm110', `strongarm1100', `strongarm1110', `arm8', `arm810', `arm9', `arm9e', `arm920', 
#`arm920t', `arm922t', `arm946e-s', `arm966e-s', `arm968e-s', `arm926ej-s', `arm940t', `arm9tdmi', `arm10tdmi', `arm1020t', `arm1026ej-s', `arm10e', `arm1020e', `arm1022e', `arm1136j-s', `arm1136jf-s', `mpcore', `mpcorenovfp', `arm1156t2-s', `arm1156t2f-s', `arm1176jz-s', `arm1176jzf-s', `cortex-a5', `cortex-a7', 
#`cortex-a8', `cortex-a9', `cortex-a15', `cortex-r4', `cortex-r4f', `cortex-r5', `cortex-m4', `
#cortex-m3', `cortex-m1', `cortex-m0', `xscale', `iwmmxt', `iwmmxt2', `ep9312', `fa526', `fa626', `fa606te', `fa626te', `fmp626', `fa726te'.
#输入CPU内核版本选择。
CPU_Select()
{
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
	if [ "$arch_select" = "" ] && [ "$flag" = "0" ];then
	    dialog  --msgbox "cpu选型有误，与指令集版本不能不同时为空，请重新配置一次。" 20 50
	    rm configure.mk
	    clear
	    exit 0
	fi
	fi
	done
	
	echo "CPU=$cpu_select" >> configure.mk
	if [ "$arch_select" != "" ] && [ "$cpu_select" = "" ];then
	    dialog  --msgbox "cpu选型有误，与指令集版本不能不同时为空，请重新配置一次。" 20 50
	    rm configure.mk
	    clear
	    exit 0
	fi
}
####################CPU内核版本选择####################################
####################生成的bin文件跟反汇编文件所在的路径####################################
#这里所需要的O文件都是中间文件，所以到最后，这些都将在编译成功后删除掉。
dir4exe()
{
	flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
	while [ "$flag" != "0" ];do
	dialog --title "设置O文件输出的路径" --inputbox "请输入O文件的链接路径，这路径也是链接脚本所在的位置。最终链接生成的bin文件跟反汇编文件将会移动到这个路径中。格式为:exe_dir" 20 50  2> $temp_file
	exe_dir=$(cat $temp_file)
	if [ -z "$exe_dir" ];then
	dialog --title "再次确认" --yesno "bin文件跟反汇编文件将在根目录上，你确定要这样做吗？" 10 30 
	flag=$?
	exe_dir=.
	else
	mkdir -p $exe_dir
	flag=0
	fi
	if [ "$flag" = "0" ];then
	echo "exe_dir=$exe_dir" >> configure.mk
	fi
	done
}
###################生成的bin文件跟反汇编文件所在的路径####################################
####################自动生成的依赖文件文件所在的路径####################################
dir4log()
{
	flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
	while [ "$flag" != "0" ];do
	dialog --title "设置自动生成的日志文件文件所在的路径" --inputbox "自动生成的依赖文件文件所在的路径,格式为:log" 20 50  2> $temp_file
	log_dir=$(cat $temp_file)
	if [ -z "$log_dir" ];then
	dialog --title "再次确认" --yesno "自动生成的依赖文件文件将在根目录上，你确定要这样做吗？" 10 30 
	flag=$?
	log_dir=.
	else
	mkdir -p $log_dir
	flag=0
	fi
	if [ "$flag" = "0" ];then
	echo "log_dir=$log_dir" >> configure.mk
	fi
	done
}
####################自动生成的依赖文件文件所在的路径####################################
####################项目的源码目录汇总###################################
#目录中只包含了没有系统，跟CPU无关的代码目录
NoARCH_AND_NoOS_Source_Path()
{
	sum_dir=$(find . -type d | grep -v '^\./\.' | grep -v "OS" | grep -v 'cortex-m3')

	Csources=$(find . |grep -v '^\./\.' | grep '\.c$' | grep -v OS | grep -v 'cortex-m3') # | sed 's/^\..*\///g')
	Ssources=$(find . |grep -v '^\./\.' | grep '\.s$' | grep -v OS | grep -v 'cortex-m3') # | sed 's/^\..*\///g')

	Csources=$(echo -n $Csources)
	echo "Csources=$Csources" >>configure.mk
	Ssources=$(echo -n $Ssources)
	echo "Ssources=$Ssources" >>configure.mk

	sum_dir=$(echo -n $sum_dir) #将所有行连接在一起，并使他们在同一行
	echo "VPATH=$sum_dir" >> configure.mk
#	echo "GPATH=$sum_dir" >> configure.mk
}
####################项目的源码目录汇总###################################
####################项目的自定义源码目录###################################
#
#brief:根据需要来增添相应的源码目录跟相应源码
#
#parm:目前有
#		1.cortex-m3,增添cortex-m3源码目录跟cortex-m3源码
#		2.OS,增添OS源码目录跟OS源码
#note:只支持一个参数
Source_Path()
{
	sum_dir_temp=$(find . -type d | grep -v '^\./\.' | grep "$1")
	Csources=$(find . | grep -v '^\./\.' | grep '\.c$' | grep "$1" ) # | sed 's/^\..*\///g')
	Ssources=$(find . | grep -v '^\./\.' | grep '\.s$' | grep "$1" ) # | sed 's/^\..*\///g')
	Csources=$(echo -n $Csources)
	Ssources=$(echo -n $Ssources)
		
	echo "OS=$OS">> configure.mk
if [ "$1" != "NO_USE" ];then
	echo "#############增加$1相关源文件与目录####################" >>configure.mk
	echo "Csources+=$Csources" >>configure.mk
	echo "Ssources+=$Ssources" >>configure.mk

	sum_dir_temp=$(echo -n $sum_dir_temp) #将所有行连接在一起，并使他们在同一行
	echo "VPATH+=$sum_dir_temp" >> configure.mk
#	echo "GPATH+=$sum_dir_temp" >> configure.mk
	sum_dir="$sum_dir $sum_dir_temp"
	echo "#############增加$1相关源文件与目录####################" >>configure.mk
fi
}
####################项目的自定义源码目录###################################
####################项目是否选用OS###################################
OS_Select()
{
	OS_VAR='ucos-ii\nRT-Thread\n' #可供选择的指令集
	flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
	while [ "$flag" != "0" ];do
	dialog --clear
	dialog --title "OS版本选择" --inputbox "请输入你当前使用的OS名称。你可以选择的OS(目前支持).\n$OS_VAR" 20 50  2> $temp_file
	
	OS=$(cat $temp_file)
	flag=0
	if [ -z "$OS" ];then
		dialog --title "再次确认" --yesno "你将不使用OS，你确定要这样做吗？" 10 30
		flag=$?
		if [ "$flag" = "0" ];then
			OS="NO_USE"
		fi
	elif [ "$OS" != "ucos-ii" ] && [ "$OS" != "RT-Thread" ] ;then
		dialog --title "你可以选择的OS(目前支持),请输入正确的OS名称"  --msgbox "$OS_VAR" 20 50
		flag=1
	fi
	done
	if [ "$OS" = "NO_USE" ];then
		OS=OS_NO_USE
	fi
	Source_Path $OS
}
####################项目是否选用OS###################################
####################编译环境配置###################################
ProjectName
CrossCompiler_Select
ARCH_Select
CPU_Select
dir4exe
dir4log
NoARCH_AND_NoOS_Source_Path
OS_Select
Source_Path $cpu_select
clear
echo "编译环境配置开始"
echo "#*******************工具配置*************************************" >> configure.mk
echo "CC=${cross_select}-gcc" >> configure.mk
echo "LD=${cross_select}-ld" >> configure.mk
echo "OBJCOPY=${cross_select}-objcopy" >> configure.mk
echo "OBJDUMP=${cross_select}-objdump" >> configure.mk
echo "AS=${cross_select}-gcc" >> configure.mk
echo "#*******************工具配置*************************************" >> configure.mk
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
#有些时候编译不通过，加上O选项的话
if [ "$cross_select" = "arm-uclinuxeabi" ] || [ "$cpu_select" != "cortex-m3" ];then
echo 'CFLAGS += -O2' >> configure.mk
echo 'ASFLAGS += -O2' >> configure.mk
CFLAGS="$CFLAGS -O2"
ASFLAGS="$ASFLAGS -O2"
fi
#根据CPU型号加上相应的编译选项
if [ "$arch_select" = "armv7-m" ];then
case $cpu_select in
  "cortex-m3" )
      echo 'CFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'ASFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'LD_FLAGS += -T$(exe_dir)/$(CPU).lds' >> configure.mk
      CFLAGS="$CFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      ASFLAGS="$ASFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      LD_FLAGS="$LD_FLAGS -T$exe_dir/$cpu_select.lds"
      cp -rf $LDS_BAK/$cpu_select.lds.bak.txt $exe_dir/$cpu_select.lds
      ;;
  "cortex-a8" )
      echo 'CFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'ASFLAGS += -march=$(ARCH) -mthumb -mcpu=$(CPU) ' >> configure.mk
      echo 'LD_FLAGS += -T$(exe_dir)//$(CPU).lds' >> configure.mk
      CFLAGS="$CFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      ASFLAGS="$ASFLAGS -march=$arch_select -mthumb -mcpu=$cpu_select"
      LD_FLAGS="$LD_FLAGS -T$exe_dir/$cpu_select.lds"
      cp -rf $LDS_BAK/$cpu_select.lds.bak.txt $exe_dir/$cpu_select.lds
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
      echo 'LD_FLAGS = -T$(exe_dir)/$(CPU).lds' >> configure.mk
      CFLAGS="$CFLAGS -march=$arch_select -mcpu=$cpu_select"
      ASFLAGS="$ASFLAGS -march=$arch_select -mcpu=$cpu_select"
      LD_FLAGS="$LD_FLAGS -T$exe_dir/$cpu_select.lds"
      cp -rf $LDS_BAK/$cpu_select.lds.bak.txt $exe_dir/$cpu_select.lds
      ;;
  *) 
    echo "cpu选型有误，与指令集版本不匹配，请重新配置一次。"
    rm configure.mk
    exit 0
    ;;
esac
fi

echo "RM=rm -rf">> configure.mk

echo "配置完成。"
echo "项目名称：$proj_name"
echo "指令集:$arch_select"
echo "CPU内核版本:$cpu_select"
echo "CC工具为${cross_select}-gcc "
echo "LD工具为${cross_select}-ld "
echo "OBJCOPY工具为${cross_select}-objcopy "
echo "OBJDUMP工具为${cross_select}-objdump "
echo "AS工具为${cross_select}-gcc "
echo "CC的选项为$CFLAGS"
echo "AS的选项为$ASFLAGS"
echo "LD的选项为$LD_FLAGS"
echo "OBJCOPY的选项为$OBJCOPY_FLAGS"
echo "OBJDUMP的选项为$OBJDUMP_FLAGS"
echo "bin文件跟反汇编文件将在$exe_dir/目录中"
echo "自动生成的依赖文件文件在$log_dir/目录上"
echo "项目的所有目录(VPATH的值) ： $sum_dir"
#*******************工具选项配置******************************************
####################编译环境配置###################################

exit 0
