/* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/log_msg2.h>

extern void z_vrfy_z_log_msg2_static_create(const void * source, const struct log_msg2_desc desc, uint8_t * package, const void * data);
uintptr_t z_mrsh_z_log_msg2_static_create(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	z_vrfy_z_log_msg2_static_create(*(const void **)&arg0, *(const struct log_msg2_desc*)&arg1, *(uint8_t **)&arg2, *(const void **)&arg3)
;
	_current->syscall_frame = NULL;
	return 0;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
                                                                                                              /* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/log_msg2.h>

extern void z_vrfy_z_log_msg2_static_create(const void * source, const struct log_msg2_desc desc, uint8_t * package, const void * data);
uintptr_t z_mrsh_z_log_msg2_static_create(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	z_vrfy_z_log_msg2_static_create(*(const void **)&arg0, *(const struct log_msg2_desc*)&arg1, *(uint8_t **)&arg2, *(const void **)&arg3)
;
	_current->syscall_frame = NULL;
	return 0;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
