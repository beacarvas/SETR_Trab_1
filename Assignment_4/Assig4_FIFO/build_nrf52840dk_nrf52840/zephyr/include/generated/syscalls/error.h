
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_ERROR_H
#define Z_INCLUDE_SYSCALLS_ERROR_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#if !defined(__XCC__)
#pragma GCC diagnostic ignored "-Warray-bounds"
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void z_impl_user_fault(unsigned int reason);

__pinned_func
static inline void user_fault(unsigned int reason)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&reason, K_SYSCALL_USER_FAULT);
		return;
	}
#endif
	compiler_barrier();
	z_impl_user_fault(reason);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define user_fault(re
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_ERROR_H
#define Z_INCLUDE_SYSCALLS_ERROR_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#if !defined(__XCC__)
#pragma GCC diagnostic ignored "-Warray-bounds"
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void z_impl_user_fault(unsigned int reason);

__pinned_func
static inline void user_fault(unsigned int reason)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&reason, K_SYSCALL_USER_FAULT);
		return;
	}
#endif
	compiler_barrier();
	z_impl_user_fault(reason);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define user_fault(reason) do { 	sys_port_trace_syscall_enter(K_SYSCALL_USER_FAULT, user_fault, reason); 	user_fault(reason); 	sys_port_trace_syscall_exit(K_SYSCALL_USER_FAULT, user_fault, reason); } while(false)
#endif
#endif


#ifdef __cplusplus
}
#endif

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif

#endif
#endif /* include guard */
