/* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/espi.h>

extern int z_vrfy_espi_receive_vwire(const struct device * dev, enum espi_vwire_signal signal, uint8_t * level);
uintptr_t z_mrsh_espi_receive_vwire(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	int ret = z_vrfy_espi_receive_vwire(*(const struct device **)&arg0, *(enum espi_vwire_signal*)&arg1, *(uint8_t **)&arg2)
;
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic /* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/espi.h>

extern int z_vrfy_espi_receive_vwire(const struct device * dev, enum espi_vwire_signal signal, uint8_t * level);
uintptr_t z_mrsh_espi_receive_vwire(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	int ret = z_vrfy_espi_receive_vwire(*(const struct device **)&arg0, *(enum espi_vwire_signal*)&arg1, *(uint8_t **)&arg2)
;
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
