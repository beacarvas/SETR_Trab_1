
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_MBOX_H
#define Z_INCLUDE_SYSCALLS_MBOX_H


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

extern int z_impl_mbox_send(const struct mbox_channel * channel, const struct mbox_msg * msg);

__pinned_func
static inline int mbox_send(const struct mbox_channel * channel, const struct mbox_msg * msg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&channel, *(uintptr_t *)&msg,
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_MBOX_H
#define Z_INCLUDE_SYSCALLS_MBOX_H


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

extern int z_impl_mbox_send(const struct mbox_channel * channel, const struct mbox_msg * msg);

__pinned_func
static inline int mbox_send(const struct mbox_channel * channel, const struct mbox_msg * msg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&channel, *(uintptr_t *)&msg, K_SYSCALL_MBOX_SEND);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_send(channel, msg);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_send(channel, msg) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_SEND, mbox_send, channel, msg); 	retval = mbox_send(channel, msg); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_SEND, mbox_send, channel, msg, retval); 	retval; })
#endif
#endif


extern int z_impl_mbox_mtu_get(const struct device * dev);

__pinned_func
static inline int mbox_mtu_get(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_MBOX_MTU_GET);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_mtu_get(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_mtu_get(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_MTU_GET, mbox_mtu_get, dev); 	retval = mbox_mtu_get(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_MTU_GET, mbox_mtu_get, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_mbox_set_enabled(const struct mbox_channel * channel, bool enable);

__pinned_func
static inline int mbox_set_enabled(const struct mbox_channel * channel, bool enable)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&channel, *(uintptr_t *)&enable, K_SYSCALL_MBOX_SET_ENABLED);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_set_enabled(channel, enable);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_set_enabled(channel, enable) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_SET_ENABLED, mbox_set_enabled, channel, enable); 	retval = mbox_set_enabled(channel, enable); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_SET_ENABLED, mbox_set_enabled, channel, enable, retval); 	retval; })
#endif
#endif


extern uint32_t z_impl_mbox_max_channels_get(const struct device * dev);

__pinned_func
static inline uint32_t mbox_max_channels_get(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (uint32_t) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_MBOX_MAX_CHANNELS_GET);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_max_channels_get(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_max_channels_get(dev) ({ 	uint32_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_MAX_CHANNELS_GET, mbox_max_channels_get, dev); 	retval = mbox_max_channels_get(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_MAX_CHANNELS_GET, mbox_max_channels_get, dev, retval); 	retval; })
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
