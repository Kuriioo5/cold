  .file "main.cold"
  .text
  .section .rodata.str1.1,"aMS",@progbits,1
.LC0:
  .string "Hello, world!"
  .section .text.startup,"ax",@progbits
  .p2align 4
  .globl main
  .type main, @function
main:
.LFB0:
  .cfi_startproc
  subq $8, %rsp
  leaq .LC0(%rip), %rdi
  call puts@PLT
  xorl %eax, %eax
  addq $8, %rsp
  ret
  .cfi_endproc
.LFE0:
  .size main, .-main
  .section .note.GNU-stack,"",@progbits
