
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_CACHE_H
#define Z_INCLUDE_SYSCALLS_CACHE_H


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

extern int z_impl_sys_cache_data_all(int op);

__pinned_func
static inline int sys_cache_data_all(int op)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&op, K_SYSCALL_SYS_CACHE_DATA_ALL);
	}
#endif
	compiler_barr
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_CACHE_H
#define Z_INCLUDE_SYSCALLS_CACHE_H


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

extern int z_impl_sys_cache_data_all(int op);

__pinned_func
static inline int sys_cache_data_all(int op)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&op, K_SYSCALL_SYS_CACHE_DATA_ALL);
	}
#endif
	compiler_barrier();
	return z_impl_sys_cache_data_all(op);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define sys_cache_data_all(op) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_SYS_CACHE_DATA_ALL, sys_cache_data_all, op); 	retval = sys_cache_data_all(op); 	sys_port_trace_syscall_exit(K_SYSCALL_SYS_CACHE_DATA_ALL, sys_cache_data_all, op, retval); 	retval; })
#endif
#endif


extern int z_impl_sys_cache_data_range(void * addr, size_t size, int op);

__pinned_func
static inline int sys_cache_data_range(void * addr, size_t size, int op)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&addr, *(uintptr_t *)&size, *(uintptr_t *)&op, K_SYSCALL_SYS_CACHE_DATA_RANGE);
	}
#endif
	compiler_barrier();
	return z_impl_sys_cache_data_range(addr, size, op);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define sys_cache_data_range(addr, size, op) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_SYS_CACHE_DATA_RANGE, sys_cache_data_range, addr, size, op); 	retval = sys_cache_data_range(addr, size, op); 	sys_port_trace_syscall_exit(K_SYSCALL_SYS_CACHE_DATA_RANGE, sys_cache_data_range, addr, size, op, retval); 	retval; })
#endif
#endif


extern int z_impl_sys_cache_instr_all(int op);

__pinned_func
static inline int sys_cache_instr_all(int op)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&op, K_SYSCALL_SYS_CACHE_INSTR_ALL);
	}
#endif
	compiler_barrier();
	return z_impl_sys_cache_instr_all(op);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define sys_cache_instr_all(op) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_SYS_CACHE_INSTR_ALL, sys_cache_instr_all, op); 	retval = sys_cache_instr_all(op); 	sys_port_trace_syscall_exit(K_SYSCALL_SYS_CACHE_INSTR_ALL, sys_cache_instr_all, op, retval); 	retval; })
#endif
#endif


extern int z_impl_sys_cache_instr_range(void * addr, size_t size, int op);

__pinned_func
static inline int sys_cache_instr_range(void * addr, size_t size, int op)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&addr, *(uintptr_t *)&size, *(uintptr_t *)&op, K_SYSCALL_SYS_CACHE_INSTR_RANGE);
	}
#endif
	compiler_barrier();
	return z_impl_sys_cache_instr_range(addr, size, op);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define sys_cache_instr_range(addr, size, op) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_SYS_CACHE_INSTR_RANGE, sys_cache_instr_range, addr, size, op); 	retval = sys_cache_instr_range(addr, size, op); 	sys_port_trace_syscall_exit(K_SYSCALL_SYS_CACHE_INSTR_RANGE, sys_cache_instr_range, addr, size, op, retval); 	retval; })
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
