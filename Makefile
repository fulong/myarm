###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
sinclude configure.mk

SHELL=/bin/bash

OBJ = $(Csources:.c=.o) $(Ssources:.s=.o)

Depend_OBJ=$(OBJ:.o=.d)
.PHONY:update configure all clean distclean install setting dclean

all:$(Depend_OBJ)
	@make $(OBJ)
	@echo "完成编译完成" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log

install:$(proj_name).bin
	@echo "安装完成" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
$(proj_name).bin:$(OBJ)
	${LD} ${LD_FLAGS} -o ${exe_dir}/$(proj_name).elf $^
	@echo "链接完成" | tee -a ${log_dir}/$(proj_name).log
	${OBJCOPY} ${OBJCOPY_FLAGS} ${exe_dir}/$(proj_name).elf ${exe_dir}/$(proj_name).bin
	${OBJDUMP} ${OBJDUMP_FLAGS} ${exe_dir}/$(proj_name).elf > ${exe_dir}/$(proj_name).dis
	@echo "$(proj_name).bin与反汇编文件生成完毕" | tee -a ${log_dir}/$(proj_name).log
	@${RM} ${exe_dir}/$(proj_name).elf
	@echo "elf中间文件删除完毕" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log

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
#如果使用了下面语句，makefile将自动重建依赖文件
configure:
	-@${RM} $(Depend_OBJ) configure.mk  ${exe_dir}/$(CPU).lds ${OBJ} ${exe_dir}/$(proj_name).bin ${exe_dir}/$(proj_name).dis ${log_dir}/*.log;
	-@if [ "${log_dir}" != "." ] && [ "${log_dir}" != "" ];then \
	${RM} ${log_dir}/;\
	fi
	-@if [ "${exe_dir}" != "." ] && [ "${exe_dir}" != "" ];then \
	${RM} ${exe_dir}/;\
	fi
	@./tools/configure.sh
	@echo "配置configure.mk" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
update:
	@echo "更新目录,文件变化" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
	@./tools/update.sh
	
setting:
	@./tools/setting.sh
clean :
	${RM}  ${log_dir}/obj.log ${OBJ} ${exe_dir}/$(proj_name).*
	@echo "清除所有o文件,bin与反汇编文件,日志文件" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
dclean :
	${RM} $(Depend_OBJ) ${log_dir}/depend.log
	@echo "清除依赖文件" | tee -a -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
distclean:
	@echo "清除所有自动生成的文件" | tee -a ${log_dir}/$(proj_name).log
	@date >> ${log_dir}/$(proj_name).log
	${RM} $(Depend_OBJ) configure.mk  ${exe_dir}/$(CPU).lds ${OBJ} ${exe_dir}/$(proj_name).* ${log_dir}/*.log;
	-@if [ "${log_dir}" != "." ] && [ "${log_dir}" != "" ];then \
	${RM} ${log_dir}/;\
	fi
	-@if [ "${exe_dir}" != "." ] && [ "${exe_dir}" != "" ];then \
	${RM} ${exe_dir}/;\
	fi
sinclude $(Depend_OBJ)