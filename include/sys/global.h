/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* EXTERN is defined as extern except in global.c */
#ifdef	GLOBAL_VARIABLES_HERE
#undef	EXTERN
#define	EXTERN
#endif

EXTERN	int		ticks;
EXTERN	int	key_pressed; /**
			      * used for clock_handler
			      * to wake up TASK_TTY when
			      * a key is pressed
			      */

EXTERN	int		disp_pos;
EXTERN	u8		gdt_ptr[6];	// 0~15:Limit  16~47:Base
EXTERN	DESCRIPTOR	gdt[GDT_SIZE];
EXTERN	u8		idt_ptr[6];	// 0~15:Limit  16~47:Base
EXTERN	GATE		idt[IDT_SIZE];

EXTERN	u32		k_reenter;

EXTERN	TSS		tss;
EXTERN	PROCESS*	p_proc_ready;

EXTERN	int		nr_current_console;

extern	PROCESS		proc_table[];
extern	char		task_stack[];
extern  TASK            task_table[];
extern  TASK    user_proc_table[];
extern	irq_handler	irq_table[];

extern	TTY		tty_table[];
extern  CONSOLE         console_table[];

/* FS */
EXTERN	FILE_DESCRIPTION	f_desc_table[NR_FILE_DESC];
EXTERN	INODE		inode_table[NR_INODE];
EXTERN	SUPERBLOCK	super_block[NR_SUPER_BLOCK];
extern	u8 *			fsbuf;
extern	const int		FSBUF_SIZE;
EXTERN	MESSAGE			fs_msg;
EXTERN	PROCESS *		pcaller; //调用者
EXTERN	INODE *		root_inode;
extern	struct dev_drv_map	dd_map[];

/* MM */
EXTERN	MESSAGE			mm_msg;
extern	u8 *			mmbuf;
extern	const int		MMBUF_SIZE;
EXTERN	int			memory_size;

EXTERN	int 		debug_couont;