###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
#configure_type：项目类型，目前有setting，arm，这个向脚本传递的信息。

SHELL=/bin/bash
sinclude configure_type.mk

ifeq "$(configure_type)" "prj_configure"
sinclude configure.mk
endif
ifeq "$(configure_type)" "setting_tools_configure"
sinclude setting.mk
endif

ifeq "$(configure_type_mk)$(configure_mk)" "YESYES" #判断两个配置文件是否存在.
configure_on=YES
else
configure_on=NO
endif

OBJ = $(Csources:.c=.o) $(Ssources:.S=.o)
ifeq "$(configure_on)" "YES"
include_open=$(shell cat ${log_dir}/$(proj_name).log | tail -n1)
endif

Depend_OBJ=$(OBJ:.o=.d)
.PHONY:status allclean update configure all clean distclean install setting dclean
ifeq "$(configure_on)" "YES"
all:
	@echo "include_open" >> ${log_dir}/$(proj_name).log
#	@make $(OBJ)
	@make $(proj_name).bin
	@echo "工程编译安装完成" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log    

$(proj_name).bin:$(OBJ)
ifeq "$(HOST)" "arm"
	${LD} ${LD_FLAGS} -o ${exe_dir}/$(proj_name).elf $^
	@echo "链接完成" | tee -a ${log_dir}/$(proj_name).log
	${OBJCOPY} ${OBJCOPY_FLAGS} ${exe_dir}/$(proj_name).elf ${exe_dir}/$(proj_name).bin
	${OBJDUMP} ${OBJDUMP_FLAGS} ${exe_dir}/$(proj_name).elf > ${exe_dir}/$(proj_name).dis
	@echo "$(proj_name).bin与反汇编文件生成完毕" | tee -a ${log_dir}/$(proj_name).log
	@echo "elf中间文件删除完毕" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
else
	gcc -o ${exe_dir}/$(proj_name).bin $^
endif
%.d::%.S
	@echo "自动更新$*.S的依赖"
	@echo "$*.o:$*.S" > $@
	@sed -i 's/\.o:/\.d :/g' $@
	@echo "$*.o:$*.S" >> $@
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
	@./tools/configure_type.sh "$(configure_type_mk)" configure_type=prj_configure
ifneq "$(configure_type_mk)$(configure_mk)" "YESYES"
	@./tools/configure.sh
endif
install:
	@./tools/install2arm.sh
	@echo "安装完成" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
ifeq "$(configure_on)" "YES"
update4prj: #这个目标晚点会将其变成能服务于每一个项目
	@echo "更新目录,文件变化" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log 
	@./tools/update.sh
setting:
	@./tools/setting.bin
compiling4setting:
	@./tools/configure_type.sh "$(configure_type_mk)" configure_type=setting_tools_configure
	@./tools/configure.sh

allclean:clean dclean
clean :
	${RM}  ${log_dir}/obj.log ${OBJ} ${exe_dir}/$(proj_name).dis
	${RM}  ${exe_dir}/$(proj_name).bin
	@echo "清除所有o文件,bin与反汇编文件,日志文件" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
dclean :
	${RM} $(Depend_OBJ) ${log_dir}/depend.log
	@echo "清除依赖文件" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
distclean:
	@echo "清除所有自动生成的文件" | tee -a ${log_dir}/other.log
	@date >> ${log_dir}/other.log
	@make allclean
	${RM} ${log_dir}/${proj_name}.log
	-@if [ "${exe_dir}" != "." ] && [ "${exe_dir}" != "" ];then \
	${RM} ${exe_dir}/;\
	fi
ifeq "$(configure_type)" "prj_configure"
	${RM}  *.mk *.lds 
endif
ifeq "$(configure_type)" "setting_tools_configure"
	@./tools/configure_type.sh "$(configure_type_mk)" configure_type=prj_configure
endif	
endif #ifeq "$(configure_on)" "YES"

status:
ifneq "$(configure_on)" "YES"
	@echo "configure文件不存在"
endif
ifeq "$(configure_type)" "prj_configure"
	@echo "Makefile目前在ARM项目状态中"
	@echo "使用的处理器为$(ARCH)"
endif
ifeq "$(configure_type)" "setting_tools_configure"
	@echo "Makefile目前在编译linux工具项目状态中(setting.bin)"
endif

#如果使用了下面语句，makefile将自动重建依赖文件
ifeq "$(include_open)" "include_open"
sinclude $(Depend_OBJ)
endif
