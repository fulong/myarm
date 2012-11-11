#!/bin/bash
#configure.sh
temp_file=/tmp/cross_configure #暂存文件

####################项目的源码目录汇总###################################
#目录中只包含了没有系统，跟CPU无关的代码目录
OS_dir="/OS/"
ARCH_Sum="/cortex-m3 /arm920t" #这个变量表示函数NoARCH_AND_NoOS_Source_Path中消除的文件夹
extend_src="/tools_src/"
NoARCH_AND_NoOS_Source_Path()
{
	sum_dir=$(find $root_dir -type d | grep -v '^\./\.')

	Csources=$(find $root_dir |grep -v '^\./\.' | grep '\.c$') # | sed 's/^\..*\///g')
	Ssources=$(find $root_dir |grep -v '^\./\.' | grep '\.S$') # | sed 's/^\..*\///g')
if [ "$root_dir" = "." ];then
	for TEMP in $ARCH_Sum $OS_dir $extend_src
	do
		sum_dir=$(echo "$sum_dir" | grep -v "$TEMP")
		Csources=$(echo "$Csources" | grep -v "$TEMP")
		Ssources=$(echo "$Ssources" | grep -v "$TEMP")
	done		
fi
	echo "#############增加NoARCH相关源文件与目录####################" >>$mk_name
	Csources=$(echo -n $Csources)
	echo "Csources=$Csources" >>$mk_name
	Ssources=$(echo -n $Ssources)
	echo "Ssources=$Ssources" >>$mk_name

	sum_dir=$(echo -n $sum_dir) #将所有行连接在一起，并使他们在同一行
	echo "VPATH=$sum_dir" >> $mk_name
	echo "#############增加NoARCH相关源文件与目录####################" >>$mk_name
#	echo "GPATH=$sum_dir" >> $mk_name
}
####################项目的源码目录汇总###################################

####################项目的自定义源码目录###################################
#
#brief:根据需要来增添相应的源码目录跟相应源码
#
#parm:目前有
#		1.cortex-m3,增添cortex-m3源码目录跟cortex-m3源码
#		2.OS,增添OS源码目录跟OS源码
#		3.自定义添加文件,目录
#note:只支持一个参数
Source_Path()
{
	local sum_dir_temp=$(find . -type d | grep -v '^\./\.' | grep "$1")
	Csources=$(find . | grep -v '^\./\.' | grep '\.c$' | grep "$1" ) # | sed 's/^\..*\///g')
	Ssources=$(find . | grep -v '^\./\.' | grep '\.S$' | grep "$1" ) # | sed 's/^\..*\///g')
	Csources=$(echo -n $Csources)
	Ssources=$(echo -n $Ssources)
		
if [ "$1" != "NO_USE" ];then
	echo "#############增加$1相关源文件与目录####################" >>$mk_name
	echo "Csources+=$Csources" >>$mk_name
	echo "Ssources+=$Ssources" >>$mk_name

	sum_dir_temp=$(echo -n $sum_dir_temp) #将所有行连接在一起，并使他们在同一行
	echo "VPATH+=$sum_dir_temp" >> $mk_name
#	echo "GPATH+=$sum_dir_temp" >> $mk_name
	sum_dir="$sum_dir $sum_dir_temp"
	echo "#############增加$1相关源文件与目录####################" >>$mk_name
fi
}
#configure.sh
######################定义项目名称######################################
ProjectName()
{
	local flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
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
	echo "proj_name=$proj_name" > $mk_name
	fi
	else 
	echo "proj_name=$proj_name" > $mk_name
	fi
	done
}
######################定义项目名称######################################
####################项目是否选用OS###################################
OS_Select()
{
	local OS_VAR='ucos-ii\nRT-Thread\n' #可供选择的指令集
	local flag=1 #初始化这个自动变量，使下面的能正确使用这个变量
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
	echo "OS=$OS">> $mk_name
		Source_Path "$OS"
}
####################项目是否选用OS###################################
