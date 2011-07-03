/*                        Copyright (c) 1988 Bellcore
**                            All Rights Reserved
**       Permission is granted to copy or use this program, EXCEPT that it
**       may not be sold for profit, the copyright notice must be reproduced
**       on copies, and credit should be given to Bellcore where it is due.
**       BELLCORE MAKES NO WARRANTY AND ACCEPTS NO LIABILITY FOR THIS PROGRAM.
*/


#ifndef lint
static char rcsid[] =
    "$Header: /usr/sharelan/cvs/SEACAS/prepost/spiff/misc.c,v 1.2 2004/10/29 14:00:41 gdsjaar Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>

#include "misc.h"
#include "visual.h"
#include "output.h"

/*
**	various routines used throughout the program
*/

static int _Z_qflag = 0;

void Z_setquiet(void)
{
    _Z_qflag = 1;
}

char Z_err_buf[Z_LINELEN];

#ifndef NOCHATTER
/*
**	I/O coverup to reassure users with HUGE files
**	that spiff is doing something
*/
void Z_chatter(char *str)
{
    if (!_Z_qflag) {
	(void) fputs("spiff -- ", stderr);
	(void) fputs(str, stderr);
    }
}
#endif

/*
**	complain unless you've been told to be quiet
*/
void Z_complain(char *str)
{
    if (!_Z_qflag)
	(void) fputs(str, stderr);
}

/*
**	quit with an error code
*/
static void _Z_errexit(void)
{
    (void) exit(2);
}

/*
**	complain and die
*/
void _Z_qfatal(char *str)
{
    V_cleanup();		/* try reset the device to normal */
    O_cleanup();		/*  "    "    "     "   "    "    */
    Z_complain(str);
    _Z_errexit();
}

/*
**	scream and die
*/
void Z_fatal(char *str)
{
    V_cleanup();		/* try reset the device to normal */
    O_cleanup();		/*  "    "    "     "   "    "    */
    (void) fputs(str, stderr);
    _Z_errexit();
}

/*
**	allocate memory with error checking
*/
int *_Z_myalloc(int k)
{
    int *tmp;
    if ((tmp = (int *) calloc((unsigned) k, (unsigned) 1))) {
	return (tmp);
    }
    Z_fatal("Out of Memory\n");
    return (tmp);		/* boilerplate to shut up lint */
}

void Z_exceed(int d)
{
    (void) sprintf(Z_err_buf,
		   "The files differ in more than %d places\n", d);
    _Z_qfatal(Z_err_buf);
}
