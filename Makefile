###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
sinclude configure.mk
.PHONY: configure all clean distclean install

all:$(Csources:.c=.o) $(Ssources:.s=.o)
install:
	-@mv -f *.o ${obj_dir}/ 
	@echo "将O文件移动到${obj_dir}/目录中，进行链接"
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
	-@${RM} ${obj_dir}/*.o *.o
	@echo "清除所有O文件"
distclean:
	-@${RM} ${obj_dir}/ ${depend_dir}/ configure.mk *.o
	@echo "清除所有能自动生成的文件"
	