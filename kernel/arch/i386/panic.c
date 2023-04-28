#include <stdio.h>
#include <stdint.h>

#include <kernel/panic.h>
#include <kernel/tty.h>

__attribute__((__noreturn__))
void panic(const char* panic_str) {
    //clear the screen
    terminal_initialize();

    //print some uh oh text
    terminal_setcolor(15, 1);
    terminal_writestring("kernel: panic: a fatal system error has occured\n");
    terminal_writestring(panic_str);
    terminal_writestring('\n');

    regdump();

    //put the computer in an infinite loop
    asm volatile ("hlt");
    for(;;){}
}

void regdump() {
    uint32_t eax, ebx, ecx, edx, esi, edi, esp, ebp;
    asm volatile (
        "movl %%eax, %[a1] ;"
        "movl %%ebx, %[a2] ;"
        "movl %%ecx, %[a3] ;"
        "movl %%edx, %[a4] ;"
        "movl %%esi, %[a5] ;"
        "movl %%edi, %[a6] ;"
        "movl %%esp, %[a7] ;"
        "movl %%ebp, %[a8] ;" 
        :
        [a1] "=m" (eax), [a2] "=m" (ebx), [a3] "=m" (ecx), [a4] "=m" (edx),
        [a5] "=m" (esi), [a6] "=m" (edi), [a7] "=m" (esp), [a8] "=m" (ebp)
    );

    printf("%x", ebx);
    
}