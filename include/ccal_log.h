#ifndef __CCAL_LOG_H__
#define __CCAL_LOG_H__

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef DEBUG
	#define ccal_printf(format, ...) do { \
				printf("[CCAL:%s:%d] ",__FILE__,__LINE__); \
				printf(format, ## __VA_ARGS__); \
				printf("\n");} while (0)		
#else
	#define ccal_printf(format, ...) do {} while(0)
#endif

#if defined(__cplusplus)
}
#endif


#endif /* __CCAL_LOG_H__*/ 
