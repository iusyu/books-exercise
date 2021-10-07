movq %rdi,%rax
movq %rdx,%r8
divq %rsi
movq %rax,(%r8)
movq %rdx,(%rcx)
