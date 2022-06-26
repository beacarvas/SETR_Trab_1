
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_PS2_H
#define Z_INCLUDE_SYSCALLS_PS2_H


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

extern int z_impl_ps2_config(const struct device * dev, ps2_callback_t callback_isr);

__pinned_func
static inline int ps2_config(const struct device * dev, ps2_callback_t callback_isr)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&callback_isr, K_SYSCALL_PS2_CONFIG);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_config(dev, callback_isr);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define ps2_config(dev, callback_isr) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PS2_CONFIG, ps2_config, dev, callback_isr); 	retval = ps2_config(dev, callback_isr); 	sys_port_trace_syscall_exit(K_SYSCALL_PS2_CONFIG, ps2_config, dev, callback_isr, retval); 	retval; })
#endif
#endif


extern int z_impl_ps2_write(const struct device * dev, uint8_t value);

__pinned_func
static inline int ps2_write(const struct device * dev, uint8_t value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&value, K_SYSCALL_PS2_WRITE);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_write(dev, value);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define ps2_write(dev, value) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PS2_WRITE, ps2_write, dev, value); 	retval = ps2_write(dev, value); 	sys_port_trace_syscall_exit(K_SYSCALL_PS2_WRITE, ps2_write, dev, value, retval); 	retval; })
#endif
#endif


extern int z_impl_ps2_read(const struct device * dev, uint8_t * value);

__pinned_func
static inline int ps2_read(const struct device * dev, uint8_t * value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&value, K_SYSCALL_PS2_READ);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_read(dev, value);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define ps2_read(dev, value) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PS2_READ, ps2_read, dev, value); 	retval = ps2_read(dev, value); 	sys_port_trace_syscall_exit(K_SYSCALL_PS2_READ, ps2_read, dev, value, retval); 	retval; })
#endif
#endif


extern int z_impl_ps2_enable_callback(const struct device * dev);

__pinned_func
static inline int ps2_enable_callback(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_PS2_ENABLE_CALLBACK);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_enable_callback(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define ps2_enable_callback(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PS2_ENABLE_CALLBACK, ps2_enable_callback, dev); 	retval = ps2_enable_callback(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_PS2_ENABLE_CALLBACK, ps2_enable_callback, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_ps2_disable_callback(const struct device * dev);

__pinned_func
static inline int ps2_disable_callback(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_PS2_DISABLE_CALLBACK);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_disable_callback(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define ps2_disable_callback(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_PS2_DISABLE_CALLBACK, ps2_disable_callback, dev); 	retval = ps2_disable_callback(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_PS2_DISABLE_CALLBACK, ps2_disable_callback, dev, retval); 	retval; })
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
