
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_COUNTER_H
#define Z_INCLUDE_SYSCALLS_COUNTER_H


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

extern bool z_impl_counter_is_counting_up(const struct device * dev);

__pinned_func
static inline bool counter_is_counting_up(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (bool) arch_syscall_invoke1(*(uint
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_COUNTER_H
#define Z_INCLUDE_SYSCALLS_COUNTER_H


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

extern bool z_impl_counter_is_counting_up(const struct device * dev);

__pinned_func
static inline bool counter_is_counting_up(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (bool) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_IS_COUNTING_UP);
	}
#endif
	compiler_barrier();
	return z_impl_counter_is_counting_up(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_is_counting_up(dev) ({ 	bool retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_IS_COUNTING_UP, counter_is_counting_up, dev); 	retval = counter_is_counting_up(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_IS_COUNTING_UP, counter_is_counting_up, dev, retval); 	retval; })
#endif
#endif


extern uint8_t z_impl_counter_get_num_of_channels(const struct device * dev);

__pinned_func
static inline uint8_t counter_get_num_of_channels(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (uint8_t) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_GET_NUM_OF_CHANNELS);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_num_of_channels(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_num_of_channels(dev) ({ 	uint8_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_NUM_OF_CHANNELS, counter_get_num_of_channels, dev); 	retval = counter_get_num_of_channels(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_NUM_OF_CHANNELS, counter_get_num_of_channels, dev, retval); 	retval; })
#endif
#endif


extern uint32_t z_impl_counter_get_frequency(const struct device * dev);

__pinned_func
static inline uint32_t counter_get_frequency(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (uint32_t) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_GET_FREQUENCY);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_frequency(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_frequency(dev) ({ 	uint32_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_FREQUENCY, counter_get_frequency, dev); 	retval = counter_get_frequency(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_FREQUENCY, counter_get_frequency, dev, retval); 	retval; })
#endif
#endif


extern uint32_t z_impl_counter_us_to_ticks(const struct device * dev, uint64_t us);

__pinned_func
static inline uint32_t counter_us_to_ticks(const struct device * dev, uint64_t us)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { struct { uintptr_t lo, hi; } split; uint64_t val; } parm0;
		parm0.val = us;
		/* coverity[OVERRUN] */
		return (uint32_t) arch_syscall_invoke3(*(uintptr_t *)&dev, parm0.split.lo, parm0.split.hi, K_SYSCALL_COUNTER_US_TO_TICKS);
	}
#endif
	compiler_barrier();
	return z_impl_counter_us_to_ticks(dev, us);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_us_to_ticks(dev, us) ({ 	uint32_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_US_TO_TICKS, counter_us_to_ticks, dev, us); 	retval = counter_us_to_ticks(dev, us); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_US_TO_TICKS, counter_us_to_ticks, dev, us, retval); 	retval; })
#endif
#endif


extern uint64_t z_impl_counter_ticks_to_us(const struct device * dev, uint32_t ticks);

__pinned_func
static inline uint64_t counter_ticks_to_us(const struct device * dev, uint32_t ticks)
{
#ifdef CONFIG_USERSPACE
	uint64_t ret64;
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		(void)arch_syscall_invoke3(*(uintptr_t *)&dev, *(uintptr_t *)&ticks, (uintptr_t)&ret64, K_SYSCALL_COUNTER_TICKS_TO_US);
		return (uint64_t)ret64;
	}
#endif
	compiler_barrier();
	return z_impl_counter_ticks_to_us(dev, ticks);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_ticks_to_us(dev, ticks) ({ 	uint64_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_TICKS_TO_US, counter_ticks_to_us, dev, ticks); 	retval = counter_ticks_to_us(dev, ticks); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_TICKS_TO_US, counter_ticks_to_us, dev, ticks, retval); 	retval; })
#endif
#endif


extern uint32_t z_impl_counter_get_max_top_value(const struct device * dev);

__pinned_func
static inline uint32_t counter_get_max_top_value(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (uint32_t) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_GET_MAX_TOP_VALUE);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_max_top_value(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_max_top_value(dev) ({ 	uint32_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_MAX_TOP_VALUE, counter_get_max_top_value, dev); 	retval = counter_get_max_top_value(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_MAX_TOP_VALUE, counter_get_max_top_value, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_start(const struct device * dev);

__pinned_func
static inline int counter_start(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_START);
	}
#endif
	compiler_barrier();
	return z_impl_counter_start(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_start(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_START, counter_start, dev); 	retval = counter_start(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_START, counter_start, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_stop(const struct device * dev);

__pinned_func
static inline int counter_stop(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_STOP);
	}
#endif
	compiler_barrier();
	return z_impl_counter_stop(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_stop(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_STOP, counter_stop, dev); 	retval = counter_stop(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_STOP, counter_stop, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_get_value(const struct device * dev, uint32_t * ticks);

__pinned_func
static inline int counter_get_value(const struct device * dev, uint32_t * ticks)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&ticks, K_SYSCALL_COUNTER_GET_VALUE);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_value(dev, ticks);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_value(dev, ticks) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_VALUE, counter_get_value, dev, ticks); 	retval = counter_get_value(dev, ticks); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_VALUE, counter_get_value, dev, ticks, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_set_channel_alarm(const struct device * dev, uint8_t chan_id, const struct counter_alarm_cfg * alarm_cfg);

__pinned_func
static inline int counter_set_channel_alarm(const struct device * dev, uint8_t chan_id, const struct counter_alarm_cfg * alarm_cfg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&dev, *(uintptr_t *)&chan_id, *(uintptr_t *)&alarm_cfg, K_SYSCALL_COUNTER_SET_CHANNEL_ALARM);
	}
#endif
	compiler_barrier();
	return z_impl_counter_set_channel_alarm(dev, chan_id, alarm_cfg);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_set_channel_alarm(dev, chan_id, alarm_cfg) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_SET_CHANNEL_ALARM, counter_set_channel_alarm, dev, chan_id, alarm_cfg); 	retval = counter_set_channel_alarm(dev, chan_id, alarm_cfg); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_SET_CHANNEL_ALARM, counter_set_channel_alarm, dev, chan_id, alarm_cfg, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_cancel_channel_alarm(const struct device * dev, uint8_t chan_id);

__pinned_func
static inline int counter_cancel_channel_alarm(const struct device * dev, uint8_t chan_id)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&chan_id, K_SYSCALL_COUNTER_CANCEL_CHANNEL_ALARM);
	}
#endif
	compiler_barrier();
	return z_impl_counter_cancel_channel_alarm(dev, chan_id);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_cancel_channel_alarm(dev, chan_id) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_CANCEL_CHANNEL_ALARM, counter_cancel_channel_alarm, dev, chan_id); 	retval = counter_cancel_channel_alarm(dev, chan_id); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_CANCEL_CHANNEL_ALARM, counter_cancel_channel_alarm, dev, chan_id, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_set_top_value(const struct device * dev, const struct counter_top_cfg * cfg);

__pinned_func
static inline int counter_set_top_value(const struct device * dev, const struct counter_top_cfg * cfg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&cfg, K_SYSCALL_COUNTER_SET_TOP_VALUE);
	}
#endif
	compiler_barrier();
	return z_impl_counter_set_top_value(dev, cfg);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_set_top_value(dev, cfg) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_SET_TOP_VALUE, counter_set_top_value, dev, cfg); 	retval = counter_set_top_value(dev, cfg); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_SET_TOP_VALUE, counter_set_top_value, dev, cfg, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_get_pending_int(const struct device * dev);

__pinned_func
static inline int counter_get_pending_int(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_GET_PENDING_INT);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_pending_int(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_pending_int(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_PENDING_INT, counter_get_pending_int, dev); 	retval = counter_get_pending_int(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_PENDING_INT, counter_get_pending_int, dev, retval); 	retval; })
#endif
#endif


extern uint32_t z_impl_counter_get_top_value(const struct device * dev);

__pinned_func
static inline uint32_t counter_get_top_value(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (uint32_t) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_COUNTER_GET_TOP_VALUE);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_top_value(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_top_value(dev) ({ 	uint32_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_TOP_VALUE, counter_get_top_value, dev); 	retval = counter_get_top_value(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_TOP_VALUE, counter_get_top_value, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_counter_set_guard_period(const struct device * dev, uint32_t ticks, uint32_t flags);

__pinned_func
static inline int counter_set_guard_period(const struct device * dev, uint32_t ticks, uint32_t flags)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (int) arch_syscall_invoke3(*(uintptr_t *)&dev, *(uintptr_t *)&ticks, *(uintptr_t *)&flags, K_SYSCALL_COUNTER_SET_GUARD_PERIOD);
	}
#endif
	compiler_barrier();
	return z_impl_counter_set_guard_period(dev, ticks, flags);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_set_guard_period(dev, ticks, flags) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_SET_GUARD_PERIOD, counter_set_guard_period, dev, ticks, flags); 	retval = counter_set_guard_period(dev, ticks, flags); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_SET_GUARD_PERIOD, counter_set_guard_period, dev, ticks, flags, retval); 	retval; })
#endif
#endif


extern uint32_t z_impl_counter_get_guard_period(const struct device * dev, uint32_t flags);

__pinned_func
static inline uint32_t counter_get_guard_period(const struct device * dev, uint32_t flags)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		return (uint32_t) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&flags, K_SYSCALL_COUNTER_GET_GUARD_PERIOD);
	}
#endif
	compiler_barrier();
	return z_impl_counter_get_guard_period(dev, flags);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define counter_get_guard_period(dev, flags) ({ 	uint32_t retval; 	sys_port_trace_syscall_enter(K_SYSCALL_COUNTER_GET_GUARD_PERIOD, counter_get_guard_period, dev, flags); 	retval = counter_get_guard_period(dev, flags); 	sys_port_trace_syscall_exit(K_SYSCALL_COUNTER_GET_GUARD_PERIOD, counter_get_guard_period, dev, flags, retval); 	retval; })
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
