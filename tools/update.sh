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
		;;
	"setting_tools_configure" )
	mk_name=setting.mk
		;;
	"*")
	echo "工程状态有误"
	exit 1
	;;
esac

clear_file()
{
echo "删除更新前的生成的.d,.o文件"
find | grep '\.d$' | xargs rm -f
find | grep '\.o$' | xargs rm -f
}
item_update() 
{
	local update_item=(Csources Ssources VPATH)
	local times=0;
	local content=
	local update_row=$(echo `cat $mk_name -n  | sed 's/^[ ]*//g' | grep "$1" | grep '#' | cut -s -f 1 | head -n1`)
	echo "更新$1相关信息"
#	echo "${update_item[2]}"
	update_row=$(expr "$update_row" + "1") 
	while [ "$times" -lt "3" ] 
	do
		if [ "$times" = "2" ];then
			content=$(find . -type d | grep -v '^\./\.')
		fi
		if [ "$times" = "0" ];then
			content=$(find . |grep -v '^\./\.' | grep '\.c$') # | sed 's/^\..*\///g')
		fi	
		if [ "$times" = "1" ];then
			content=$(find . |grep -v '^\./\.' | grep '\.S$') # | sed 's/^\..*\///g')
		fi		
		#这个顺序跟CONFIGURE.SH生成configure.mk代码一样
		#更新顺序 NoARCH OS ARCHDIR
		_update "`expr "$update_row" + "$times"`" "$content" "${update_item[$times]}" "$1"
		times=$(expr "1" + "$times")
	done
	echo "更新的行数为：包括$update_row在内的后$times行"
	
}
clear_file
#item_update "NoARCH"
#item_update "`cat configure.mk | grep "OS=" | sed 's/OS=//g'`"
#item_update "`cat configure.mk | grep "CPU=" | sed 's/CPU=//g'`"
exit 0