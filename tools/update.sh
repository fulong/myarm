#!/bin/bash
echo "更新目录变化"
update_dir_row=$(cat configure.mk -n | grep VPATH | sed 's/^[ ]*//g' | cut -s -f 1)
