/* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/dma.h>

extern int z_vrfy_dma_request_channel(const struct device * dev, void * filter_param);
uintptr_t z_mrsh_dma_request_channel(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg2;	/* unused */
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	int ret = z_vrfy_dma_request_channel(*(const struct device **)&arg0, *(void **)&arg1)
;
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
