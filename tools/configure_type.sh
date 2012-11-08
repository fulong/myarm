#!/bin/bash
#用来生成configure_type.mk
#configure_type_mk,表示这个文件存在
#configure_type，表示项目目前所在的项目属性。
#1.prj_configure，这里代表的是arm项目。
#2.setting_tools_configure，这里代表项目是关于setting的，因为项目有编写setting这个程序的源代码，所以要分开来管理。
#HOST，代表编译出来的目标文件是什么指令系统的。
#1.arm
#2.x86
#extern_src_dir，代表辅助项目的源代码目录，如tools的setting。
export $2
if ! [ "$1" == "YES" ];then
		echo 'configure_type_mk=YES' > configure_type.mk
		echo "configure_type=$configure_type" >> configure_type.mk
		echo 'HOST=arm' >> configure_type.mk
		echo 'extern_src_dir:=tools_src/setting' >> configure_type.mk
else
case "$configure_type" in
	"prj_configure")
		sed -i 's/^configure_type=.*$/configure_type=prj_configure/g' configure_type.mk
		sed -i 's/^HOST=.*$/HOST=arm/g' configure_type.mk
		echo "转到arm项目"
	;;
	"setting_tools_configure")
		sed -i 's/^configure_type=.*$/configure_type=setting_tools_configure/g' configure_type.mk
		sed -i 's/^HOST=.*$/HOST=x86/g' configure_type.mk	
		echo "转到x86项目"
		;;
	*)
		echo "项目类型有误。"
		exit 1
	;;
esac
fi
exit 0