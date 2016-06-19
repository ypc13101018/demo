#ifndef __DSTRING_H
#define DYNSTR_MAX_MALLOC
typedef char *DynStr;

typedef struct DynStrHead
{
	unsigned int len;
	unsigned int free;
	char buf[];
}
#endif
