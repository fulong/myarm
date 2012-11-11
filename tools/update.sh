#!/bin/bash
export $1
export $2
# @parm $1,传递的是工程所在的状态。
source tools/lib.sh
#update_item_order="VPATH Csources Ssources"
if [ -z "$configure_type" ] || [ -z "$CPU" ];then
	echo "MK配置不对，请重建。"
	exit 1
fi
case "$configure_type" in
	"prj_configure" )
	mk_name=configure.mk
	root_dir=.
	extend_dir=tools_src
	;;
	"setting_tools_configure" )
	mk_name=setting.mk
	root_dir=tools_src/setting
	;;
	"*")
	echo "工程状态有误"
	exit 1
	;;
esac

clear_file()
{
echo "删除更新前的生成的.d,.o文件"
find $root_dir | grep -v "$extend_dir" | grep '\.d$' | xargs rm -f
find $root_dir | grep -v "$extend_dir" | grep '\.o$' | xargs rm -f
}
item_update() 
{
#	local update_item=(Csources Ssources VPATH)
	local row=0
	touch sed.sh
	local NoARCH_Csources_row=$(echo `cat $mk_name -n  | sed 's/^[ ]*//g' | grep "Csources" | cut -s -f 1 | head -n1`)
	local CPU_Csources_row=$(echo `cat $mk_name -n  | sed 's/^[ ]*//g' | grep "Csources" | cut -s -f 1 | tail -n1`)
	NoARCH_Csources_row=$(expr "$NoARCH_Csources_row" - "1") 
	CPU_Csources_row=$(expr "$CPU_Csources_row" - "1") 
case "$configure_type" in
	"prj_configure" )
	local OS_Csources_row=$(echo `cat $mk_name -n  | sed 's/^[ ]*//g' | grep "Csources" | cut -s -f 1 | head -n2| tail -n1`)
	OS_Csources_row=$(expr "$OS_Csources_row" - "2") 
	echo "${OS_Csources_row}d" >> sed.sh
	OS_Csources_row=$(expr "$OS_Csources_row" + "1")
	;;
	"setting_tools_configure" )
	local OS_Csources_row=
	;;
	*)
	echo "工程状态有误"
	exit 1
	;;
esac
#	echo "${update_item[2]}"
for num in $CPU_Csources_row $NoARCH_Csources_row $OS_Csources_row
do
	while [ "$row" -lt "5" ]
	do
		row=$(expr "$row" + "1")
		echo "${num}d" >> sed.sh
		num=$(expr "$num" + "1")
	done
	row=0
done
	#echo "`expr ${row} + 1`i${update_item}${operate}${content}" >> sed.sh
sed -i -f sed.sh $mk_name
rm -f sed.sh

NoARCH_AND_NoOS_Source_Path
if ! [ -z "$OS_Csources_row" ];then
	OS_Select
fi
Source_Path $CPU
echo "更新的行数为：包括$NoARCH_Csources_row，$CPU_Csources_row，$OS_Csources_row"
echo "完成！！"
}
clear_file
item_update #"NoARCH"
#item_update "`cat configure.mk | grep "OS=" | sed 's/OS=//g'`"
#item_update "`cat configure.mk | grep "CPU=" | sed 's/CPU=//g'`"
exit 0