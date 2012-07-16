#!/bin/bash
#configure.sh
####################项目的源码目录汇总###################################
#目录中只包含了没有系统，跟CPU无关的代码目录
NoARCH_AND_NoOS_Source_Path()
{
	sum_dir=$(find . -type d | grep -v '^\./\.')

	Csources=$(find . |grep -v '^\./\.' | grep '\.c$') # | sed 's/^\..*\///g')
	Ssources=$(find . |grep -v '^\./\.' | grep '\.s$') # | sed 's/^\..*\///g')

	for TEMP in $ARCH_Sum $OS_dir
	do
		sum_dir=$(echo "$sum_dir" | grep -v "$TEMP")
		Csources=$(echo "$Csources" | grep -v "$TEMP")
		Ssources=$(echo "$Ssources" | grep -v "$TEMP")
	done
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
#configure.sh
#update.sh
dir_update()
{
	update_dir_row=$(echo `cat configure.mk -n | grep "VPATH" | sed 's/^[ ]*//g' | cut -s -f 1`)
	update_vpath_dir=
}
#update.sh
