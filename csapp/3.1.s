	.file	"3.1.c"
	.text
	.globl	gt
	.type	gt, @function
gt:
.LFB22:
	.cfi_startproc
	cmpq	%rsi, %rdi
	setg	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE22:
	.size	gt, .-gt
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB23:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jle	.L3
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
.L3:
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	absdiff, .-absdiff
	.globl	absdiff_j
	.type	absdiff_j, @function
absdiff_j:
.LFB24:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jg	.L6
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L6:
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE24:
	.size	absdiff_j, .-absdiff_j
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB25:
	.cfi_startproc
	cmpq	$1, %rdi
	je	.L10
	cmpq	$2, %rdi
	jne	.L11
	movl	$10, %eax
	ret
.L10:
	movl	$5, %eax
	ret
.L11:
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE25:
	.size	switch_eg, .-switch_eg
	.globl	absdiff_c
	.type	absdiff_c, @function
absdiff_c:
.LFB26:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jle	.L13
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
.L13:
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
	.cfi_endproc
.LFE26:
	.size	absdiff_c, .-absdiff_c
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 11.2.1 20210816 [revision 056e324ce46a7924b5cf10f61010cf9dd2ca10e9]"
	.section	.note.GNU-stack,"",@progbits
