
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_PTP_CLOCK_H
#define Z_INCLUDE_SYSCALLS_PTP_CLOCK_H


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

extern int z_impl_ptp_clock_get(const struct device * dev, struct net_ptp_time * tm);

__pinned_func
static inline int ptp_clock_get(const struct device * dev, struct net_ptp_time * tm)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] 
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_PTP_CLOCK_H
#define Z_INCLUDE_SYSCALLS_PTP_CLOCK_H


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

extern int z_impl_ptp_clock_get(const struct device * dev, struct net_ptp_time * tm);

__pinned_func
static inline int ptp_clock_get(const struct device * dev, struct net_ptp_time * tm)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&tm, K_SYSCALL_PTP_CLOCK_GET);
	}
#endif
	compiler_barrier();
	return z_impl_ptp_clock_get(dev, tm);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define ptp_clock_get(dev, tm) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PTP_CLOCK_GET, ptp_clock_get, dev, tm); 	retval = ptp_clock_get(dev, tm); 	sys_port_trace_syscall_exit(K_SYSCALL_PTP_CLOCK_GET, ptp_clock_get, dev, tm, retval); 	retval; })
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
