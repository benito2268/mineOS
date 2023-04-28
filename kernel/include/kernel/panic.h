#ifndef _PANIC_H
#define _PANIC_H

#define _TRIG_PANIC "SYS_TRIGGERED_PANIC\n"
#define _STACK_SMASHING_DETECTED "STACK_SMASHING_DETECTED\n"

__attribute__((__noreturn__))
void panic(const char* panic_str);
void regdump();

#endif