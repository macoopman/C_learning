	.text
	.cstring
lC0:
	.ascii "\12\12---- Power Function ----\12\0"
	.align 3
lC1:
	.ascii "Input the base followed by the power. Seperated by space.\0"
lC2:
	.ascii "Enter (base power):  \0"
lC3:
	.ascii "%s\0"
lC4:
	.ascii "%d\0"
lC5:
	.ascii "%d^%d = %d\12\12\12\12\0"
	.text
	.globl _main
_main:
LFB1:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	leaq	lC0(%rip), %rdi
	call	_puts
	leaq	lC1(%rip), %rdi
	call	_puts
	leaq	lC2(%rip), %rsi
	leaq	lC3(%rip), %rdi
	movl	$0, %eax
	call	_printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rsi
	leaq	lC4(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	leaq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	lC4(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_RecursivePower
	movl	%eax, %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	lC5(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	leave
LCFI2:
	ret
LFE1:
	.globl _RecursivePower
_RecursivePower:
LFB2:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -8(%rbp)
	jne	L4
	movl	-4(%rbp), %eax
	jmp	L5
L4:
	movl	-8(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_RecursivePower
	imull	-4(%rbp), %eax
L5:
	leave
LCFI5:
	ret
LFE2:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1-.
	.set L$set$2,LFE1-LFB1
	.quad L$set$2
	.byte	0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB2-.
	.set L$set$7,LFE2-LFB2
	.quad L$set$7
	.byte	0
	.byte	0x4
	.set L$set$8,LCFI3-LFB2
	.long L$set$8
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE3:
	.subsections_via_symbols
