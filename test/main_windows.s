  .file "main.cold"
  .def ___main; .scl 2; .type 32; .endef
  .section .rdata,"dr"
LC0:
  .ascii "Hello, world!\0"
  .section .text.startup,"x"
  .p2align 4,,15
  .globl _main
  .def _main; .scl 2; .type 32; .endef
_main:
LFB0:
  .cfi_startproc
  pushl %ebp
  movl %esp, %ebp
  andl $-16, %esp
  subl $16, %esp
  call ___main
  movl $LC0, (%esp)
  call _puts
  xorl %eax, %eax
  leave
  ret
  .cfi_endproc
LFE0:
  .def _puts; .scl 2; .type 32; .endef
