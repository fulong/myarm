###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
sinclude configure.mk
SHELL=/bin/bash
OBJ = $(Csources:.c=.o) $(Ssources:.s=.o)
Depend_OBJ = $(Csources:.c=.d) $(Ssources:.s=.d)
.PHONY: configure all clean distclean install setting

all:$(Depend_OBJ)
	@make $(OBJ)
	@echo "完成编译完成"
install:$(proj_name).bin
	@echo "安装完成"
$(proj_name).bin:$(OBJ)
	${LD} ${LD_FLAGS} -o ${obj_dir}/$(proj_name).elf $^
	@echo "链接完成"
	${OBJCOPY} ${OBJCOPY_FLAGS} ${obj_dir}/$(proj_name).elf ${obj_dir}/$(proj_name).bin
	${OBJDUMP} ${OBJDUMP_FLAGS} ${obj_dir}/$(proj_name).elf > ${obj_dir}/$(proj_name).dis
	@echo "$(proj_name).bin与反汇编文件生成完毕"
	@${RM} ${obj_dir}/$(proj_name).elf
	@echo "elf中间文件删除完毕"

%.d::%.s
	@echo "自动更新$*.s的依赖"
	@echo "$*.o:$*.s" > ${depend_dir}/$@
	@sed -i 's/$*\.o:/$*\.d :/g' ${depend_dir}/$@
	@echo "$*.o:$*.s" >> ${depend_dir}/$@
	@sed -i '$$a$$(AS) $$(ASFLAGS) $$< -o $$(obj_dir)/$$@ '  ${depend_dir}/$@
	@sed -i 's/^\$$/\t\$$/g' ${depend_dir}/$@
%.d::%.c
	@echo "自动更新$*.c的依赖"
	@$(CC) -MM  $< > ${depend_dir}/$@
	@sed -i 's/$*\.o:/$*\.d :/g' ${depend_dir}/$@
	@$(CC) -MM  $< >> ${depend_dir}/$@
	@sed -i '$$a$$(CC) $$(CFLAGS) $$< -o $$(obj_dir)/$$@ ' ${depend_dir}/$@
	@sed -i 's/^\$$/\t\$$/g' ${depend_dir}/$@
#如果使用了下面语句，makefile将自动重建依赖文件
sinclude $(wildcard ${depend_dir}/*.d)
configure:
	-@${RM} $(CPU).lds *.o ${obj_dir}/$(proj_name).bin ${obj_dir}/$(proj_name).dis;
	-@if [ "${depend_dir}" != "." ] && [ "${depend_dir}" != "" ];then \
	${RM} ${depend_dir}/;\
	fi
	-@if [ "${obj_dir}" != "." ] && [ "${obj_dir}" != "" ];then \
	${RM} ${obj_dir}/;\
	fi
	@./configure.sh
setting:
	@./setting.sh
clean :
	-@${RM} ${depend_dir}/*.d *.o ${obj_dir}/*.o ${obj_dir}/$(proj_name).bin ${obj_dir}/$(proj_name).dis;
	@echo "清除所有o文件,bin与反汇编文件,各依赖"
distclean:
	@echo "清除所有能自动生成的文件"
	-@${RM} configure.mk   $(CPU).lds *.o ${obj_dir}/*.o ${obj_dir}/$(proj_name).bin ${obj_dir}/$(proj_name).dis *.d;
	-@if [ "${depend_dir}" != "." ] && [ "${depend_dir}" != "" ];then \
	${RM} ${depend_dir}/;\
	fi
	-@if [ "${obj_dir}" != "." ] && [ "${obj_dir}" != "" ];then \
	${RM} ${obj_dir}/;\
	fi
	