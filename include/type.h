
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            type.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef	_YUNFEI_TYPE_H
#define	_YUNFEI_TYPE_H


typedef	unsigned int		u32;
typedef	unsigned short		u16;
typedef	unsigned char		u8;

typedef	char *			va_list; //for printf

typedef	void	(*int_handler)	();
typedef	void	(*task_f)	();
typedef	void	(*irq_handler)	(int irq);

typedef void*	system_call;


#endif /* _YUNFEI_TYPE_H */
