###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
sinclude configure.mk
OBJ = $(Csources:.c=.o) $(Ssources:.s=.o)
.PHONY: configure all clean distclean install

all:$(OBJ)
	@echo "编译完成"
	-@mv  *.o ${obj_dir}/ 
	@echo "将O文件移动到${obj_dir}/目录中，进行链接"

install:${OBJ}
	${LD} ${LD_FLAGS} -o ${obj_dir}/temp.elf $^
	@echo "链接完成"
	${OBJCOPY} ${OBJCOPY_FLAGS} ${obj_dir}/temp.elf ${obj_dir}/$(proj_name).bin
	${OBJDUMP} ${OBJDUMP_FLAGS} ${obj_dir}/temp.elf > ${obj_dir}/$(proj_name).dis
	@echo "bin与反汇编文件生成完毕"
	@${RM} ${obj_dir}/temp.elf
	@echo "elf中间文件删除完毕"
%.d::%.c 
	@$(CC) -MM $(CFLAGS) $< > ${depend_dir}/$@.temp
	@cat ${depend_dir}/$@.temp | sed 's/$*\.o:/$*\.o $*\.d :/g' > ${depend_dir}/$@
	@${RM} ${depend_dir}/$@.temp
%.d::%.s
	@$(CC) -MM $(CFLAGS) $< > ${depend_dir}/$@.temp
	@cat ${depend_dir}/$@.temp | sed 's/$*\.o:/$*\.o $*\.d :/g' > ${depend_dir}/$@
	@${RM} ${depend_dir}/$@.temp
sinclude $(Csources:.c=.d) 
sinclude $(Ssources:.s=.d)

configure:./configure.sh
	@./configure.sh
clean :
	-@${RM} ${obj_dir}/*.o *.o ${obj_dir}/$(proj_name).bin ${obj_dir}/$(proj_name).dis
	@echo "清除所有O文件,bin与反汇编文件"
distclean:
	-@${RM} configure.mk  *.d $(CPU).lds *.o ${obj_dir}/$(proj_name).bin ${obj_dir}/$(proj_name).dis;
	-@if [ "${depend_dir}" != "." ];then \
	${RM} ${depend_dir}/;\
	fi
	-@if [ "${obj_dir}" != "." ];then \
	${RM} ${obj_dir}/;\
	fi
	@echo "清除所有能自动生成的文件"
	