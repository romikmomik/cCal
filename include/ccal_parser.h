#ifndef __CCAL_PARSER_H__
#define __CCAL_PARSER_H__

#include <errno.h>

#if defined(__cplusplus)
extern "C" {
#endif
// input string = mm.yyyy
// return 
// month = mm
// year = yyyy
//  Success - GOOD SRING
/*
 *
 *	Input too short or to long
 *	Input contains not valid symbols
 *  Month is not valid (1-12)
 *  Year  is not valid (0000 - 9999)
 *	
 */
int ccal_parse(const char* input,int * month,int* year)
{
	return EXIT_SUCCESS;
}
#if defined(__cplusplus)
}
#endif

#endif /*__CCAL_PARSER_H__*/
