###############################################################
#@file Makefile
#@brief 编译整个项目
#@data 2012-6-22-21:21
###############################################################
sinclude configure.mk
.PHONY: configure all clean distclean

all:
	echo "$(Ssources:.s=.d)"
%.d::%.c 
	@$(CC) -MM $(CFLAGS) $< > ${depend_dir}/$@.temp
	@cat ${depend_dir}/$@.temp | sed 's/$*\.o:/$*\.o $*\.d :/g' > ${depend_dir}/$@
	@${RM} ${depend_dir}/$@.temp
	@echo "$@依赖生成"
%.d::%.s
	@$(CC) -MM $(CFLAGS) $< > ${depend_dir}/$@.temp
	@cat ${depend_dir}/$@.temp | sed 's/$*\.o:/$*\.o $*\.d :/g' > ${depend_dir}/$@
	@${RM} ${depend_dir}/$@.temp
	@echo "$@依赖生成"
sinclude $(Csources:.c=.d) 
sinclude $(Ssources:.s=.d)

configure:./configure.sh
	./configure.sh
clean :
	-${RM} ${obj_dir}/*.o
distclean:
	-${RM} ${obj_dir}/*.o
	-${RM} ${obj_dir}/ ${depend_dir}/ configure.mk 
	