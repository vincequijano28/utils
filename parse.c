/*
 *	File: 			parse.c
 *	Description:	utilities for any parse routines in linux
 *	Author:			Vincent Quijano
 *	Date:			Dec 20, 2015
 *	Revision:		0.1		- Dec 20, 2015
 *							- Initial commit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parstr(char * src, char * p, char * eos, int len)
{
	char * loc;		/* Pointer to our intended string. */
	char tmp[len];
	int rc = 0;
	
	/* print inputs */
	printf("Input string: \"%s\"\n", src);
	printf("To parse: \"%s\"\n", p);

	/* parse the string*/
	loc = strstr(src, p);

	/* validate */
	if(loc) {
		/* compare the string*/
		rc = memcmp(p, loc, len-1);
		memcpy(tmp, loc, len-1);

		if(rc == 0) {
			printf("String found!: \"%s\"\n", tmp);
			
			/* write back the eos (end of string) of string */
			eos = loc;
			printf("address is: %d\n", loc);
		}
		else {
			printf("ERROR: String do not match!\n");
			printf("Parsed string: \"%s\"\n", tmp);
		}
	}
	else {
		printf("ERROR: String not found!\n");
		rc = 1;
	}

	return rc;
}
