/* @(#)mach1.c	1.8 */
/*
 * Motorola 68000/68010 dependent C declarations
 */

#define	low3(z)		((short)(z) & 07)
#define	low4(z)		((short)(z) & 017)

#define	fit3(z)		((((z)-1) & ~07) == 0)
#define	fit4(z)		(((z) & ~017) == 0)
#define	fit8(z)		(((z) & ~0xFF) == 0)
#define	fit16(z)	(((z) & ~0xFFFF) == 0)

#define	SIZE_B		0000
#define	SIZE_W		0100
#define	SIZE_L		0200
#define	SIZE_NON	0300
#define	SIZE_DEF	SIZE_W

extern int	mrg_1,mrg_2;
extern expr_t	exp_1,exp_2;
#ifndef ASLD
extern valu_t	rel_1,rel_2;
#endif
extern int 	model;		/* 68000/68010 */

/* addressing mode bits */
#define	DTA		0x01
#define	MEM		0x02
#define	CTR		0x04
#define	ALT		0x08
#define	FITB		0x10
#define	FITW		0x20
#define	PUTW		0x40
#define	PUTL		0x80

#ifndef extern
extern short	eamode[];
#else
short	eamode[] = {
/* 00A */	DTA        |ALT,
/* 01A */	            ALT,
/* 02A */	DTA|MEM|CTR|ALT,
/* 03A */	DTA|MEM    |ALT,
/* 04A */	DTA|MEM    |ALT,
/* 05A */	DTA|MEM|CTR|ALT|FITW|PUTW | (RELO2      )<<8,
/* 06A */	DTA|MEM|CTR|ALT     |PUTW | (RELO1      )<<8,
/* 07x */	0,
/* 070 */	DTA|MEM|CTR|ALT|FITW|PUTW | (RELO2      )<<8,
/* 071 */	DTA|MEM|CTR|ALT     |PUTL | (RELO4      )<<8,
/* 072 */	DTA|MEM|CTR    |FITW|PUTW | (RELO2|RELPC)<<8,
/* 073 */	DTA|MEM|CTR         |PUTW | (RELO1|RELPC)<<8,
/* 074x */	0,
/* 074B */	DTA|MEM        |FITB|PUTW | (RELO1      )<<8,
/* 074W */	DTA|MEM        |FITW|PUTW | (RELO2      )<<8,
/* 074L */	DTA|MEM             |PUTL | (RELO4      )<<8,
};
#endif
