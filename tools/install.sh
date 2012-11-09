#!/bin/bash
# @file install.sh
# @brief 安装bin文件到工程中，或者将bin文件烧入到设备中。
# @parm $1,传递的是工程所在的状态。
# @parm $2,传递的是工程所在的处理器架构，从而可以选择不一样的处理bin文件的方式
echo "安装中........"
if [ -z "$1" ] || [ -z "$2" ];then
	echo "$1"
	echo "$2"
echo "Error!!Please config this project."
exit 1
else
	configure_type=$1;
	ARCH=$2;
fi
case "$configure_type" in
	"prj_configure" )
	mk_name=configure.mk
		;;
	"setting_tools_configure" )
	mk_name=setting.mk
	ln_install_dir=tools
		;;
	"*")
	echo "工程状态有误"
	exit 1
	;;
esac
install_dir=$(grep 'exe_dir=' $mk_name)
bin=$(grep 'proj_name=' $mk_name)
export $install_dir
export $bin
if [ -f "${exe_dir}/${proj_name}.bin" ];then
case "$ARCH" in
	"x86")
	echo "删除${proj_name}.bin在tools的链接"
	rm -rf ${ln_install_dir}/${proj_name}.bin
	echo "在tools中产生${proj_name}.bin链接"
	ln -s ../${exe_dir}/${proj_name}.bin ${ln_install_dir}/${proj_name}.bin
	;;
	"armv4t")
	sudo usb2ram ${exe_dir}/${proj_name}\.bin || echo "烧写程序错误。" && exit 1
	exit 0
	;;
	*)
	echo "ARCH有误。"
	exit 1
esac
else
	echo "${proj_name}.bin is not exsit."
	exit 1
fi
