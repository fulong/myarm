#!/bin/bash
dialog --title "setting" --msgbox "说明：用户配置./user/user_configure/configure.h，这文件中是保存着一些宏开关，来控制编译选项。" 10 30
if ! [ -f "configure.mk" ];then
	dialog --title "setting" --msgbox "请先配置configure.mk文件,在根目录使用\nmake configure。" 10 30
	exit 1
fi
exit 0