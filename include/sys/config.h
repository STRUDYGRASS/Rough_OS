#ifndef _ORANGES_CONFIG_H_
#define _ORANGES_CONFIG_H_


/**
 * Some sector are reserved for us (the gods of the os) to copy a tar file
 * there, which will be extracted and used by the OS.
 *
 * @attention INSTALL_NR_SECTS should be a multiple of NR_DEFAULT_FILE_SECTS:
 *                INSTALL_NR_SECTS = n * NR_DEFAULT_FILE_SECTS (n=1,2,3,...)
 */
#define	INSTALL_START_SECT		0x8000
#define	INSTALL_NR_SECTS		0x800

/**
 * boot parameters are stored by the loader, they should be
 * there when kernel is running and should not be overwritten
 * since kernel might use them at any time.
 */
#define	BOOT_PARAM_ADDR			0x900  /* physical address */
#define	BOOT_PARAM_MAGIC		0xB007 /* magic number */
#define	BI_MAG				0
#define	BI_MEM_SIZE			1
#define	BI_KERNEL_FILE			2

/**
 * corresponding with boot/include/load.inc::ROOT_BASE, which should
 * be changed if this macro is changed.
 */
#define	MINOR_BOOT			MINOR_hd2a

#endif