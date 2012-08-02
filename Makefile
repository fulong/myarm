###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
SHELL=/bin/bash
setting_src_dir:=tools_src/setting
sinclude configure_type.mk

ifeq "$(configure_on)" "YES"
ifeq "$(configure_type)" "prj_configure"
sinclude configure.mk
endif
ifeq "$(configure_type)" "tools_configure"
sinclude setting.mk
endif

endif

OBJ = $(Csources:.c=.o) $(Ssources:.s=.o)
ifeq "$(configure_on)" "YES"
include_open=$(shell cat ${log_dir}/$(proj_name).log | tail -n1)
endif

Depend_OBJ=$(OBJ:.o=.d)
.PHONY:status allclean update configure all clean distclean install setting dclean
ifeq "$(configure_on)" "YES"
all:
	@echo "include_open" >> ${log_dir}/$(proj_name).log
	@make $(OBJ)
	@make install
	@echo "工程编译安装完成" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log

install:$(proj_name).bin
	@echo "安装完成" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
$(proj_name).bin:$(OBJ)
ifeq "$(HOST)" "arm"
	${LD} ${LD_FLAGS} -o ${exe_dir}/$(proj_name).elf $^
	@echo "链接完成" | tee -a ${log_dir}/$(proj_name).log
	${OBJCOPY} ${OBJCOPY_FLAGS} ${exe_dir}/$(proj_name).elf ${exe_dir}/$(proj_name).bin
	${OBJDUMP} ${OBJDUMP_FLAGS} ${exe_dir}/$(proj_name).elf > ${exe_dir}/$(proj_name).dis
	@echo "$(proj_name).bin与反汇编文件生成完毕" | tee -a ${log_dir}/$(proj_name).log
	@${RM} ${exe_dir}/$(proj_name).elf
	@echo "elf中间文件删除完毕" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
else
	gcc -o ${exe_dir}/$(proj_name).bin $^
endif
%.d::%.s
	@echo "自动更新$*.s的依赖"
	@echo "$*.o:$*.s" > $@
	@sed -i 's/\.o:/\.d :/g' $@
	@echo "$*.o:$*.s" >> $@
	@sed -i '$$a\\t$$(AS) $$(ASFLAGS) $$< -o $$@ ' $@
	@sed -i '$$a\\t@echo "完成$*.o的生成" >> ${log_dir}/obj.log' $@
	@sed -i '$$a\\t@date >> ${log_dir}/obj.log' $@
	@echo "完成$*.s的依赖的生成" >> ${log_dir}/depend.log;
	@date >> ${log_dir}/depend.log
%.d::%.c
	@echo "自动更新$*.c的依赖"
	@echo "$*.d:\\"> $@
	@$(CC) -MM  $< >> $@
	@echo "$*.temp__:\\">> $@
	@$(CC) -MM  $< >> $@
	@sed -i 's/^.*\.o://g' $@
	@sed -i 's/\.temp__/\.o/g' $@
	@sed -i '$$a\\t$$(CC) $$(CFLAGS) $$< -o $$@ ' $@
	@sed -i '$$a\\t@echo "完成$*.o的生成" >> ${log_dir}/obj.log' $@
	@sed -i '$$a\\t@date >> ${log_dir}/obj.log' $@
	@echo "$*.c的依赖生成完成" >> ${log_dir}/depend.log;
	@date >> ${log_dir}/depend.log
endif #ifeq "$(configure_on)" "YES"
configure:
	-@${RM} $(Depend_OBJ) *.mk  ${exe_dir}/$(CPU).lds ${OBJ} ${exe_dir}/$(proj_name).bin ${exe_dir}/$(proj_name).dis ${log_dir}/*.log;
	-@if [ "${exe_dir}" != "." ] && [ "${exe_dir}" != "" ];then \
	${RM} ${exe_dir}/;\
	fi
	@echo 'configure_on=YES' > configure_type.mk
	@echo 'configure_type=prj_configure' >> configure_type.mk
	@echo 'HOST=arm' >> configure_type.mk
	@./tools/configure.sh
	@log_dir=$$(cat configure.mk | grep "log_dir"| sed 's/.*=//g');\
	proj_name=$$(cat configure.mk | grep "proj_name"| sed 's/.*=//g');\
	touch $$log_dir/obj.log $$log_dir/depend.log;\
	if ! [ -f "$$log_dir/$$proj_name.log" ];then \
	touch $$log_dir/$$proj_name.log;\
	fi
ifeq "$(configure_on)" "YES"
update:
	@echo "更新目录,文件变化" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log 
	@./tools/update.sh
	
setting:
	@./tools/setting.bin
compiling4setting:
	@echo 'configure_on=YES' > configure_type.mk
	@echo 'configure_type=tools_configure' >> configure_type.mk
	@echo 'HOST=pc-linux' >> configure_type.mk
	@echo 'proj_name=setting' > setting.mk
	@echo 'log_dir=$(setting_src_dir)/log' >> setting.mk
	@echo 'exe_dir=tools' >> setting.mk
	@echo 'CC=gcc' >> setting.mk
#	@echo 'OBJCOPY=objcopy' >> setting.mk
#	@echo 'OBJDUMP=objdump' >> setting.mk
#	@echo 'AS=gcc' >> setting.mk
	@echo 'CFLAGS = -c -O2 -Wall -ffunction-sections' >> setting.mk
#	@echo 'ASFLAGS = -c -O2 -Wall -ffunction-sections' >> setting.mk
#	@echo 'LD_FLAGS = --gc-sections ' >> setting.mk
#	@echo 'OBJCOPY_FLAGS = -O binary -S' >> setting.mk
#	@echo 'OBJDUMP_FLAGS = -D ' >> setting.mk
	@sum_dir_temp=$$(find . -type d | grep -v '^\./\.' | grep "$(setting_src_dir)");\
	sum_dir_temp=$$(echo -n $$sum_dir_temp);\
	echo "VPATH=$$sum_dir_temp" >> setting.mk
	@echo "VPATH+=$(exe_dir)" >> setting.mk
	@Csources=$$(find . | grep -v '^\./\.' | grep '\.c$$' | grep "$(setting_src_dir)");\
	Csources=$$(echo -n $$Csources);\
	echo "Csources=$$Csources" >> setting.mk
	@Ssources=$$(find . | grep -v '^\./\.' | grep '\.s$$' | grep "$(setting_src_dir)" );\
	Ssources=$$(echo -n $$Ssources);\
	echo "Ssources=$$Ssources" >> setting.mk

allclean:clean dclean
clean :
	${RM}  ${log_dir}/obj.log ${OBJ} ${exe_dir}/$(proj_name).dis
ifneq "$(configure_type)" "tools_configure"
	${RM}  ${exe_dir}/$(proj_name).bin
endif
	@echo "清除所有o文件,bin与反汇编文件,日志文件" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
dclean :
	${RM} $(Depend_OBJ) ${log_dir}/depend.log
	@echo "清除依赖文件" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
distclean:
	@echo "清除所有自动生成的文件" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
	@make allclean
ifeq "$(configure_type)" "prj_configure"
	${RM} *.mk
	-@if [ "${exe_dir}" != "." ] && [ "${exe_dir}" != "" ];then \
	${RM} ${exe_dir}/;\
	fi
endif
#如果使用了下面语句，makefile将自动重建依赖文件

change2ARMprj:
	@echo "变回ARM项目状态" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
	@sed -i '2d' configure_type.mk
	@sed -i '$$aconfigure_type=prj_configure' configure_type.mk
	@sed -i 's/HOST=pc-linux/HOST=arm/g' configure_type.mk
	
endif #ifeq "$(configure_on)" "YES"

status:
ifneq "$(configure_on)" "YES"
	@echo "configure文件不存在"
endif
ifeq "$(configure_type)" "prj_configure"
	@echo "Makefile目前在ARM项目状态中"
	@echo "使用的处理器为$(ARCH)"
endif
ifeq "$(configure_type)" "tools_configure"
	@echo "Makefile目前在编译工具项目状态中"
endif

ifeq "$(include_open)" "include_open"
sinclude $(Depend_OBJ)
endif
