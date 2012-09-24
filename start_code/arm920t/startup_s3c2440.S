//设置向量表
#include "memory.h"
#include "2440addr.h"
#include "clock_option.h"

//Pre-defined constants

#define USERMODE             0x10
#define FIQMODE              0x11
#define IRQMODE              0x12
#define SVCMODE              0x13
#define ABORTMODE            0x17
#define UNDEFMODE            0x1b
#define SYSMODE				 0x1f
#define MODEMASK             0x1f
#define NOINT                0xc0

//The location of stacks

#define UserStack            (_STACK_BASEADDRESS-0x3800)     //0x33ff4800 ~
#define SVCStack             (_STACK_BASEADDRESS-0x2800)     //0x33ff5800 ~
#define UndefStack           (_STACK_BASEADDRESS-0x2400)     //0x33ff5c00 ~
#define AbortStack           (_STACK_BASEADDRESS-0x2000)     //0x33ff6000 ~
#define IRQStack             (_STACK_BASEADDRESS-0x1000)     //0x33ff7000 ~
#define FIQStack             (_STACK_BASEADDRESS-0x0)        //0x33ff8000 ~

.arm
.globl _start
_start: b       start_code
        ldr     pc, _undefined_instruction
        ldr     pc, _software_interrupt
        ldr     pc, _prefetch_abort
        ldr     pc, _data_abort
        ldr     pc, _not_used
        ldr     pc, _irq
        ldr     pc, _fiq

_undefined_instruction: .word undefined_instruction
_software_interrupt:    .word software_interrupt
_prefetch_abort:        .word prefetch_abort
_data_abort:            .word data_abort
_not_used:              .word not_used
_irq:                   .word irq
_fiq:                   .word fiq

        .balignl 16,0xdeadbeef


start_code:

	ldr     r0,=WTCON       //watch dog disable
	ldr     r1,=0x0
	str     r1,[r0]

   	ldr     r0,=INTMSK
	ldr     r1,=0xffffffff  //all interrupt disable
	str     r1,[r0]

	ldr     r0,=INTSUBMSK
	ldr     r1,=0x7fff      //all sub interrupt disable
	str     r1,[r0]

	//To reduce PLL lock time, adjust the LOCKTIME register.
	ldr     r0,=LOCKTIME
	ldr     r1,=0xffffff
	str     r1,[r0]

	ldr     r0,=CLKDIVN
	ldr     r1,=CLKDIV_VAL          // 0=1:1:1, 1=1:1:2, 2=1:2:2, 3=1:2:4, 4=1:4:4, 5=1:4:8, 6=1:3:3, 7=1:3:6.
	str     r1,[r0]

.if	CLKDIV_VAL > 1 // means Fclk:Hclk is not 1:1.
	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xc0000000//R1_nF:OR:R1_iA
	mcr p15,0,r0,c1,c0,0
.else
	mrc p15,0,r0,c1,c0,0
	bic r0,r0,#0xc0000000//R1_iA:OR:R1_nF
	mcr p15,0,r0,c1,c0,0
.endif

	//Configure UPLL
	ldr     r0,=UPLLCON
	ldr     r1,=((U_MDIV<<12)+(U_PDIV<<4)+U_SDIV)   //Fin = 12.0MHz, UCLK = 48MHz
	str     r1,[r0]
	nop     // at least 7-clocks delay must be inserted for setting hardware be completed.
	nop
	nop
	nop
	nop
	nop
	nop
	 //Configure MPLL
	ldr     r0,=MPLLCON
	ldr     r1,=((M_MDIV<<12)+(M_PDIV<<4)+M_SDIV)       //Fin = 12.0MHz, FCLK = 200MHz
	str     r1,[r0]

	bl sdram_init

	bl InitStacks

//===========================================================

	ldr     r0, =BWSCON
	ldr     r0, [r0]
	ands    r0, r0, #6     //OM[1:0] != 0, NOR FLash boot
	ldrne   pc,=_main           //do not read nand flash
	adr     r0, start_code //OM[1:0] == 0, NAND FLash boot
	cmp     r0, #0x40                          //if use Multi-ice,
	ldrne   pc,=_main           //do not read nand flash
        //
//===========================================================
nand_boot_beg:
	bl		RdNF2SDRAM

  	mrs     r0,cpsr
	bic     r0,r0,#MODEMASK
	orr     r1,r0,#SYSMODE
	bic		r1,r1,#NOINT
	msr     cpsr_cxsf,r1            //UserMode
	ldr     sp, =UserStack          // UserStack=0x33FF_5C00

	ldr		lr, =start_os
	ldr		pc, =_main
start_os:
	bl		main
	ldr     pc, =halt
//===========================================================
//		bl copy_steppingstone_to_sdram
//		ldr pc,=on_sdram
halt:
		bl halt

/*copy_steppingstone_to_sdram:
		mov r1,#0
		ldr r2,=SDRAM_BASE
		mov r3,#4096 @steppingstone的大小
1:
		ldr r4,[r1],#4
		str r4,[r2],#4
		cmp r1,r3
		bne 1b
		mov pc,lr
*/
sdram_init:
		mov r1,#MEM_CTL_BASE
		adrl r2,mem_cfg_val
		add r3,r1,#52
1:
		ldr r4,[r2],#4
		str r4,[r1],#4
		cmp r1,r3
		bne 1b
		mov pc,lr
		.align 5
mem_cfg_val:
		.long BWSCON_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONn_SET
		.long BANKCONn_SET
		.long REFRESH_SET
		.long BANKSIZE_SET
		.long MRSRBx_SET
		.long MRSRBx_SET



InitStacks:
        mrs     r0,cpsr
        bic     r0,r0,#MODEMASK
        orr     r1,r0,#UNDEFMODE
        orr		r1,r1,#NOINT
        msr     cpsr_cxsf,r1            //UndefMode
        ldr     sp,=UndefStack          // UndefStack=0x33FF_5C00

        orr     r1,r0,#ABORTMODE
        orr		r1,r1,#NOINT
        msr     cpsr_cxsf,r1            //AbortMode
        ldr     sp,=AbortStack          // AbortStack=0x33FF_6000

        orr     r1,r0,#IRQMODE
        orr		r1,r1,#NOINT
        msr     cpsr_cxsf,r1            //IRQMode
        ldr     sp,=IRQStack           // IRQStack=0x33FF_7000

        orr     r1,r0,#FIQMODE
        orr		r1,r1,#NOINT
        msr     cpsr_cxsf,r1            //FIQMode
        ldr     sp,=FIQStack           // FIQStack=0x33FF_8000

        orr     r1,r0,#SVCMODE
        orr		r1,r1,#NOINT
        msr     cpsr_cxsf,r1            //SVCMode
        ldr     sp,=SVCStack            // SVCStack=0x33FF_5800

        //USER mode has not be initialized.

	   mov     pc,lr
       //The LR register will not be valid if the current mode is not SVC mode.
/*
 * exception handlers
 */
        .align  5
undefined_instruction:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_undefined_instruction
		bl undefined_instruction
        .align  5
software_interrupt:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_software_interrupt
//		stmfd sp!,{r0-r12,lr}
//		sub r1,lr,#4
//		ldr r0,[r1]
//		eor r0,r0,#0xef000000
//      bl      software_handle
//		ldmia sp!,{r0-r12,pc}^
		b software_interrupt
        .align  5
prefetch_abort:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_prefetch_abort
		bl prefetch_abort

        .align  5
data_abort:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_data_abort
		bl data_abort
        .align  5
not_used:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_not_used
		bl not_used

#ifdef CONFIG_USE_IRQ

        .align  5
irq:
//        get_irq_stack
//        irq_save_user_regs
//        bl      do_irq
//        irq_restore_user_regs
		bl irq
        .align  5
fiq:
//        get_fiq_stack
        /* someone ought to write a more effiction fiq_save_user_regs */
//        irq_save_user_regs
//        bl      do_fiq
//        irq_restore_user_regs
		bl fiq
#else

        .align  5
irq:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_irq
//		bl irq_handle
		bl irq
        .align  5
fiq:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_fiq
		sub lr,lr,#4
		stmfd sp!,{r0-r7,lr}
		stmfd sp!,{r8-r13}^

		bl fiq_handle
		add sp,sp,#24
		ldmia sp!,{r0-r7,pc}^
/*		bl fiq*/
#endif
