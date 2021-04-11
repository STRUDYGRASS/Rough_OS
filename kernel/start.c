/*
 * @Description: for c start 
 * @Version: 
 * @Autor: Yunfei
 * @Date: 2021-03-19 15:48:59
 * @LastEditors: Yunfei
 * @LastEditTime: 2021-04-11 20:28:35
 */

#include "head_unit.h"

// #include "string.h"
/*======================================================================*
                            cstart
 *======================================================================*/
PUBLIC void cstart()
{
	disp_str("\n\n\n\n\n-----\"cstart\" begins-----\n");

	// 将 LOADER 中的 GDT 复制到新的 GDT 中
	memcpy(	&gdt,				    // New GDT
		(void*)(*((u32*)(&gdt_ptr[2]))),   // Base  of Old GDT
		*((u16*)(&gdt_ptr[0])) + 1	    // Limit of Old GDT
		);
	// gdt_ptr[6] 共 6 个字节：0~15:Limit  16~47:Base。用作 sgdt 以及 lgdt 的参数。
	u16* p_gdt_limit = (u16*)(&gdt_ptr[0]);
	u32* p_gdt_base  = (u32*)(&gdt_ptr[2]);
	*p_gdt_limit = GDT_SIZE * sizeof(DESCRIPTOR) - 1;
	*p_gdt_base  = (u32)&gdt;

	// idt_ptr[6] 共 6 个字节：0~15:Limit  16~47:Base。用作 sidt 以及 lidt 的参数。
	u16* p_idt_limit = (u16*)(&idt_ptr[0]);
	u32* p_idt_base  = (u32*)(&idt_ptr[2]);
	*p_idt_limit = IDT_SIZE * sizeof(GATE) - 1;
	*p_idt_base  = (u32)&idt;

	init_prot();

	// bochs_magic_break();
	disp_str("-----\"cstart\" finished-----\n");
}