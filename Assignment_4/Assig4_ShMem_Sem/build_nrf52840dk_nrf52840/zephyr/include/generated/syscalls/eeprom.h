
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_EEPROM_H
#define Z_INCLUDE_SYSCALLS_EEPROM_H


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

extern int z_impl_eeprom_read(const struct device * dev, off_t offset, void * data, size_t len);

__pinned_func
static inline int eeprom_read(const struct device * dev, off_t offset, void * data, size_t len)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&offset, *(uintptr_t *)&data, *(ui
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_EEPROM_H
#define Z_INCLUDE_SYSCALLS_EEPROM_H


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

extern int z_impl_eeprom_read(const struct device * dev, off_t offset, void * data, size_t len);

__pinned_func
static inline int eeprom_read(const struct device * dev, off_t offset, void * data, size_t len)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&offset, *(uintptr_t *)&data, *(uintptr_t *)&len, K_SYSCALL_EEPROM_READ);
	}
#endif
	compiler_barrier();
	return z_impl_eeprom_read(dev, offset, data, len);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define eeprom_read(dev, offset, data, len) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_EEPROM_READ, eeprom_read, dev, offset, data, len); 	retval = eeprom_read(dev, offset, data, len); 	sys_port_trace_syscall_exit(K_SYSCALL_EEPROM_READ, eeprom_read, dev, offset, data, len, retval); 	retval; })
#endif
#endif


extern int z_impl_eeprom_write(const struct device * dev, off_t offset, const void * data, size_t len);

__pinned_func
static inline int eeprom_write(const struct device * dev, off_t offset, const void * data, size_t len)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke4(*(uintptr_t *)&dev, *(uintptr_t *)&offset, *(uintptr_t *)&data, *(uintptr_t *)&len, K_SYSCALL_EEPROM_WRITE);
	}
#endif
	compiler_barrier();
	return z_impl_eeprom_write(dev, offset, data, len);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define eeprom_write(dev, offset, data, len) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_EEPROM_WRITE, eeprom_write, dev, offset, data, len); 	retval = eeprom_write(dev, offset, data, len); 	sys_port_trace_syscall_exit(K_SYSCALL_EEPROM_WRITE, eeprom_write, dev, offset, data, len, retval); 	retval; })
#endif
#endif


extern size_t z_impl_eeprom_get_size(const struct device * dev);

__pinned_func
static inline size_t eeprom_get_size(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (size_t) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_EEPROM_GET_SIZE);
	}
#endif
	compiler_barrier();
	return z_impl_eeprom_get_size(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define eeprom_get_size(dev) ({ 	size_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_EEPROM_GET_SIZE, eeprom_get_size, dev); 	retval = eeprom_get_size(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_EEPROM_GET_SIZE, eeprom_get_size, dev, retval); 	retval; })
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