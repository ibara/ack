/*
  (c) copyright 1988 by the Vrije Universiteit, Amsterdam, The Netherlands.
  See the copyright notice in the ACK home directory, in the file "Copyright".
*/

/* $Header$ */

/*
	MULTIPLY AND DISMEMBER PARTS (FIF 4)
*/

#include "FP_types.h"
#include "FP_shift.h"

_float mlf4();
_float sbf4();

fif4(x,y)
_float	x,y;
{
	EXTEND e;

	y = mlf4(x,y);
	extend((_double *)&y,&e,sizeof(SINGLE));
	e.exp--;			/* additional bias correction */
	if (e.exp < 1) {
		x = 0;
		return;
	}
	if (e.exp > 31 - SGL_M1LEFT) {
		x = y;
		y = 0;
		return;
	}
	b64_sft(&e.m1, 64 - e.exp);
	b64_sft(&e.m1, e.exp - 64);	/* "loose" low order bits */
	e.exp++;
	compact(&e,(_double *) &x, sizeof(SINGLE));
	y = sbf4(x, y);
}
