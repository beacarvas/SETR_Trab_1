
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_GPIO_H
#define Z_INCLUDE_SYSCALLS_GPIO_H


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

extern int z_impl_gpio_pin_interrupt_configure(const struct device * port, gpio_pin_t pin, gpio_flags_t flags);

__pinned_func
static inline int gpio_pin_interrupt_configure(const struct device * port, gpio_pin_t pin, gpio_flags_t flags)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_GPIO_H
#define Z_INCLUDE_SYSCALLS_GPIO_H


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

extern int z_impl_gpio_pin_interrupt_configure(const struct device * port, gpio_pin_t pin, gpio_flags_t flags);

__pinned_func
static inline int gpio_pin_interrupt_configure(const struct device * port, gpio_pin_t pin, gpio_flags_t flags)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&port, *(uintptr_t *)&pin, *(uintptr_t *)&flags, K_SYSCALL_GPIO_PIN_INTERRUPT_CONFIGURE);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_pin_interrupt_configure(port, pin, flags);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_pin_interrupt_configure(port, pin, flags) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PIN_INTERRUPT_CONFIGURE, gpio_pin_interrupt_configure, port, pin, flags); 	retval = gpio_pin_interrupt_configure(port, pin, flags); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PIN_INTERRUPT_CONFIGURE, gpio_pin_interrupt_configure, port, pin, flags, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_pin_configure(const struct device * port, gpio_pin_t pin, gpio_flags_t flags);

__pinned_func
static inline int gpio_pin_configure(const struct device * port, gpio_pin_t pin, gpio_flags_t flags)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&port, *(uintptr_t *)&pin, *(uintptr_t *)&flags, K_SYSCALL_GPIO_PIN_CONFIGURE);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_pin_configure(port, pin, flags);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_pin_configure(port, pin, flags) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PIN_CONFIGURE, gpio_pin_configure, port, pin, flags); 	retval = gpio_pin_configure(port, pin, flags); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PIN_CONFIGURE, gpio_pin_configure, port, pin, flags, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_port_get_raw(const struct device * port, gpio_port_value_t * value);

__pinned_func
static inline int gpio_port_get_raw(const struct device * port, gpio_port_value_t * value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&port, *(uintptr_t *)&value, K_SYSCALL_GPIO_PORT_GET_RAW);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_port_get_raw(port, value);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_port_get_raw(port, value) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PORT_GET_RAW, gpio_port_get_raw, port, value); 	retval = gpio_port_get_raw(port, value); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PORT_GET_RAW, gpio_port_get_raw, port, value, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_port_set_masked_raw(const struct device * port, gpio_port_pins_t mask, gpio_port_value_t value);

__pinned_func
static inline int gpio_port_set_masked_raw(const struct device * port, gpio_port_pins_t mask, gpio_port_value_t value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&port, *(uintptr_t *)&mask, *(uintptr_t *)&value, K_SYSCALL_GPIO_PORT_SET_MASKED_RAW);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_port_set_masked_raw(port, mask, value);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_port_set_masked_raw(port, mask, value) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PORT_SET_MASKED_RAW, gpio_port_set_masked_raw, port, mask, value); 	retval = gpio_port_set_masked_raw(port, mask, value); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PORT_SET_MASKED_RAW, gpio_port_set_masked_raw, port, mask, value, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_port_set_bits_raw(const struct device * port, gpio_port_pins_t pins);

__pinned_func
static inline int gpio_port_set_bits_raw(const struct device * port, gpio_port_pins_t pins)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&port, *(uintptr_t *)&pins, K_SYSCALL_GPIO_PORT_SET_BITS_RAW);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_port_set_bits_raw(port, pins);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_port_set_bits_raw(port, pins) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PORT_SET_BITS_RAW, gpio_port_set_bits_raw, port, pins); 	retval = gpio_port_set_bits_raw(port, pins); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PORT_SET_BITS_RAW, gpio_port_set_bits_raw, port, pins, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_port_clear_bits_raw(const struct device * port, gpio_port_pins_t pins);

__pinned_func
static inline int gpio_port_clear_bits_raw(const struct device * port, gpio_port_pins_t pins)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&port, *(uintptr_t *)&pins, K_SYSCALL_GPIO_PORT_CLEAR_BITS_RAW);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_port_clear_bits_raw(port, pins);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_port_clear_bits_raw(port, pins) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PORT_CLEAR_BITS_RAW, gpio_port_clear_bits_raw, port, pins); 	retval = gpio_port_clear_bits_raw(port, pins); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PORT_CLEAR_BITS_RAW, gpio_port_clear_bits_raw, port, pins, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_port_toggle_bits(const struct device * port, gpio_port_pins_t pins);

__pinned_func
static inline int gpio_port_toggle_bits(const struct device * port, gpio_port_pins_t pins)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&port, *(uintptr_t *)&pins, K_SYSCALL_GPIO_PORT_TOGGLE_BITS);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_port_toggle_bits(port, pins);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_port_toggle_bits(port, pins) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_PORT_TOGGLE_BITS, gpio_port_toggle_bits, port, pins); 	retval = gpio_port_toggle_bits(port, pins); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_PORT_TOGGLE_BITS, gpio_port_toggle_bits, port, pins, retval); 	retval; })
#endif
#endif


extern int z_impl_gpio_get_pending_int(const struct device * dev);

__pinned_func
static inline int gpio_get_pending_int(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_GPIO_GET_PENDING_INT);
	}
#endif
	compiler_barrier();
	return z_impl_gpio_get_pending_int(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define gpio_get_pending_int(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_GPIO_GET_PENDING_INT, gpio_get_pending_int, dev); 	retval = gpio_get_pending_int(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_GPIO_GET_PENDING_INT, gpio_get_pending_int, dev, retval); 	retval; })
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
