.define	CERASE,CKILL,CSTOP,CSTART
.define .lino,.filn

.define F_DUM,EXIT

.define	begtext,begdata,begbss
.define	EARRAY,ERANGE,ESET,EIDIVZ,EHEAP,EILLINS,ECASE
.define	hol0,.reghp,.limhp,.trpim,.trppc
.define	LINO_AD,FILN_AD


CERASE	= 010
CKILL	= 030
CSTART	= 021
CSTOP	= 023
F_DUM	= 0


LINO_AD	= 0
FILN_AD	= 4

EARRAY	= 0
ERANGE	= 1
ESET	= 2
EIDIVZ	= 6
EHEAP	= 17
EILLINS	= 18
ECASE	= 20

	.text
begtext:
	add.l	#2,sp !convert argc from 4-byte to 2-byte
	pea	endbss
	jsr	_brk
	add.l	#4,sp
	jsr	_m_a_i_n
	add	#010,sp
EXIT:

	.data
begdata:
hol0:
.lino:
	.short	0,0	! lino
.filn:
	.long	0	! filn
.reghp:
	.long	endbss
.limhp:
	.long	endbss
.trppc:
	.long	0
.trpim:
	.short	0


	.bss
begbss:
