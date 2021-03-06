
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_MEM_MANAGE_H
#define Z_INCLUDE_SYSCALLS_MEM_MANAGE_H


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

extern void z_impl_k_mem_paging_stats_get(struct k_mem_paging_stats_t * stats);

__pinned_func
static inline void k_mem_paging_stats_get(struct k_mem_paging_stats_t * stats)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_MEM_MANAGE_H
#define Z_INCLUDE_SYSCALLS_MEM_MANAGE_H


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

extern void z_impl_k_mem_paging_stats_get(struct k_mem_paging_stats_t * stats);

__pinned_func
static inline void k_mem_paging_stats_get(struct k_mem_paging_stats_t * stats)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&stats, K_SYSCALL_K_MEM_PAGING_STATS_GET);
		return;
	}
#endif
	compiler_barrier();
	z_impl_k_mem_paging_stats_get(stats);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define k_mem_paging_stats_get(stats) do { 	sys_port_trace_syscall_enter(K_SYSCALL_K_MEM_PAGING_STATS_GET, k_mem_paging_stats_get, stats); 	k_mem_paging_stats_get(stats); 	sys_port_trace_syscall_exit(K_SYSCALL_K_MEM_PAGING_STATS_GET, k_mem_paging_stats_get, stats); } while(false)
#endif
#endif


extern void z_impl_k_mem_paging_thread_stats_get(struct k_thread * thread, struct k_mem_paging_stats_t * stats);

__pinned_func
static inline void k_mem_paging_thread_stats_get(struct k_thread * thread, struct k_mem_paging_stats_t * stats)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke2(*(uintptr_t *)&thread, *(uintptr_t *)&stats, K_SYSCALL_K_MEM_PAGING_THREAD_STATS_GET);
		return;
	}
#endif
	compiler_barrier();
	z_impl_k_mem_paging_thread_stats_get(thread, stats);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define k_mem_paging_thread_stats_get(thread, stats) do { 	sys_port_trace_syscall_enter(K_SYSCALL_K_MEM_PAGING_THREAD_STATS_GET, k_mem_paging_thread_stats_get, thread, stats); 	k_mem_paging_thread_stats_get(thread, stats); 	sys_port_trace_syscall_exit(K_SYSCALL_K_MEM_PAGING_THREAD_STATS_GET, k_mem_paging_thread_stats_get, thread, stats); } while(false)
#endif
#endif


extern void z_impl_k_mem_paging_histogram_eviction_get(struct k_mem_paging_histogram_t * hist);

__pinned_func
static inline void k_mem_paging_histogram_eviction_get(struct k_mem_paging_histogram_t * hist)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&hist, K_SYSCALL_K_MEM_PAGING_HISTOGRAM_EVICTION_GET);
		return;
	}
#endif
	compiler_barrier();
	z_impl_k_mem_paging_histogram_eviction_get(hist);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define k_mem_paging_histogram_eviction_get(hist) do { 	sys_port_trace_syscall_enter(K_SYSCALL_K_MEM_PAGING_HISTOGRAM_EVICTION_GET, k_mem_paging_histogram_eviction_get, hist); 	k_mem_paging_histogram_eviction_get(hist); 	sys_port_trace_syscall_exit(K_SYSCALL_K_MEM_PAGING_HISTOGRAM_EVICTION_GET, k_mem_paging_histogram_eviction_get, hist); } while(false)
#endif
#endif


extern void z_impl_k_mem_paging_histogram_backing_store_page_in_get(struct k_mem_paging_histogram_t * hist);

__pinned_func
static inline void k_mem_paging_histogram_backing_store_page_in_get(struct k_mem_paging_histogram_t * hist)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&hist, K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_IN_GET);
		return;
	}
#endif
	compiler_barrier();
	z_impl_k_mem_paging_histogram_backing_store_page_in_get(hist);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define k_mem_paging_histogram_backing_store_page_in_get(hist) do { 	sys_port_trace_syscall_enter(K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_IN_GET, k_mem_paging_histogram_backing_store_page_in_get, hist); 	k_mem_paging_histogram_backing_store_page_in_get(hist); 	sys_port_trace_syscall_exit(K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_IN_GET, k_mem_paging_histogram_backing_store_page_in_get, hist); } while(false)
#endif
#endif


extern void z_impl_k_mem_paging_histogram_backing_store_page_out_get(struct k_mem_paging_histogram_t * hist);

__pinned_func
static inline void k_mem_paging_histogram_backing_store_page_out_get(struct k_mem_paging_histogram_t * hist)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		/* coverity[OVERRUN] */
		arch_syscall_invoke1(*(uintptr_t *)&hist, K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_OUT_GET);
		return;
	}
#endif
	compiler_barrier();
	z_impl_k_mem_paging_histogram_backing_store_page_out_get(hist);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define k_mem_paging_histogram_backing_store_page_out_get(hist) do { 	sys_port_trace_syscall_enter(K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_OUT_GET, k_mem_paging_histogram_backing_store_page_out_get, hist); 	k_mem_paging_histogram_backing_store_page_out_get(hist); 	sys_port_trace_syscall_exit(K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_OUT_GET, k_mem_paging_histogram_backing_store_page_out_get, hist); } while(false)
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
