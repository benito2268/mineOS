#include <stdio.h>  
#include <string.h>
#include <stdint.h>
#include <errno.h>

#include <kernel/panic.h>
#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	printf("line 1\n");
	terminal_setcolor(5, 3);
	printf("%s%d", "errno: ", errno);

	panic(_TRIG_PANIC);
}
