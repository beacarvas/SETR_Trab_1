
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_LOG_MSG2_H
#define Z_INCLUDE_SYSCALLS_LOG_MSG2_H


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

extern void z_impl_z_log_msg2_static_create(const void * source, const struct log_msg2_desc desc, uint8_t * package, const void * data);

__pinned_func
static inline void z_log_msg2_static_create(const void * source, const struct log_msg2_desc desc, uint8_t * package, const void * data)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke4(*(uintptr_t *)&source, *(uintptr_t *)&desc, *(uintptr_t *)&package, *(uintptr_t *)&data, K_SYSCALL_Z_LOG_MSG2_STATIC_CREATE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_z_log_msg2_static_create(source, desc, package, data);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define z_log_msg2_static_create(source, desc, package, data) do { 	sys_port_trace_syscall_enter(K_SYSCALL_Z_LOG_MSG2_STATIC_CREATE, z_log_msg2_static_create, source, desc, package, data); 	z_log_msg2_static_create(source, desc, package, data); 	sys_port_trace_syscall_exit(K_SYSCALL_Z_LOG_MSG2_STATIC_CREATE, z_log_msg2_static_create, source, desc, package, data); } while(false)
#endif
#endif


extern void z_impl_z_log_msg2_runtime_vcreate(uint8_t domain_id, const void * source, uint8_t level, const void * data, size_t dlen, const char * fmt, va_list ap);

__pinned_func
static inline void z_log_msg2_runtime_vcreate(uint8_t domain_id, const void * source, uint8_t level, const void * data, size_t dlen, const char * fmt, va_list ap)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		uintptr_t more[] = {
			*(uintptr_t *)&fmt,
			*(uintptr_t *)&ap
		};
		/* coverity[OVERRUN] */
		arch_syscall_invoke6(*(uintptr_t *)&domain_id, *(uintptr_t *)&source, *(uintptr_t *)&level, *(uintptr_t *)&data, *(uintptr_t *)&dlen, (uintptr_t) &more, K_SYSCALL_Z_LOG_MSG2_RUNTIME_VCREATE);
		return;
	}
#endif
	compiler_barrier();
	z_impl_z_log_msg2_runtime_vcreate(domain_id, source, level, data, dlen, fmt, ap);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define z_log_msg2_runtime_vcreate(domain_id, source, level, data, dlen, fmt, ap) do { 	sys_port_trace_syscall_enter(K_SYSCALL_Z_LOG_MSG2_RUNTIME_VCREATE, z_log_msg2_runtime_vcreate, domain_id, source, level, data, dlen, fmt, ap); 	z_log_msg2_runtime_vcreate(domain_id, source, level, data, dlen, fmt, ap); 	sys_port_trace_syscall_exit(K_SYSCALL_Z_LOG_MSG2_RUNTIME_VCREATE, z_log_msg2_runtime_vcreate, domain_id, source, level, data, dlen, fmt, ap); } while(false)
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
