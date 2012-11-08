#!/bin/bash
if [ -f "configure.mk" ];then
install_dir="$(grep 'exe_dir=' configure.mk)"
bin="$(grep 'proj_name=' configure.mk)"
export $install_dir
export $bin
if [ -f "${exe_dir}/${proj_name}.bin" ];then
sudo usb2ram ${exe_dir}/${proj_name}\.bin
exit 0
else
echo "${proj_name}.bin is not exsit."
exit 1
fi
else
echo "please config this project."
exit 1
fi
