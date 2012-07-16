#!/bin/bash

source tools/lib.sh
echo "更新目录变化"
if ! [ -f "configure.mk" ] ;then
	echo "configure.mk不存在，请创建。"
	exit 1
fi
dir_update
exit 0