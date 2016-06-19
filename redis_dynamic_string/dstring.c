#include "dstring"
#include <sys/types.h>
#include <stdarg.h>

size_t DynStrLen(const DynStr s)
{
	DynStrHead *dynStrHead = (void *)(s - (sizeof(DynStrHead)));
	return dynStrHead->len;
}

size_t DynStrAvail(const DynStr s)
{
	DynStrHead * dynStrHead = (void *)(s - (sizeof(DynStrHead)));
	return dynStrHead->free;
}

DynStr NewLenDynStr(const void *init, size_t initLen)
{
	DynStrHead * dsh = (DsyStrHead *)malloc(sizeof(DsyStrHead) + initLen + 1);

	if (dsh == NULL)
		return NULL;

	dsh->len = initLen;
	dsh->free = 0;
	if(initLen && init)
	{
		memcpy(dsh->buf, init, initLen);
	}

	dsh->buf[initlen] = '\0';
	return (DynStr)sh->buf;

}

DynStr NewEmptyDynStr(void)
{
	return NewLenDynStr("",0);
}

DsyStr NewDynStr(const char *init)
{
	size_t initLen = (init == NULL) ? 0 : strlen(init);
	return NewLenDynStr(init, initLen);
}

void FreeDynStr(DynStr ds)
{
	if(ds == NULL)
		return;
	free(ds - sizeof(DsyStrHead));
}

/*copy a DynStr string*/
DsyStr DupDynStr(DsyStr ds)
{
	return NewLenDynStr(ds,DynStrLen(ds));
}

/*update DynStr len*/
void UpdateDynStrLen(const DynStr ds)
{
	DynStrHead *dsh = (DynStrHead *)(ds - sizeof(DynStrHead));
	int len = strlen(ds);
	dsh->free = dsh->len - len;
	dsh->len = len;
}

void EmptyDynStr(const DynStr ds)
{
	DynStrHead *dsh = (DynStrHead *)(ds - sizeof(DynStrHead));
	dsh->free = dsh->len;
	dsh->len = 0;
	dsh->buf[0] = '\0';
}

DynStr EnlargeDynStr(DynStr ds, size_t addLen)
{
	DynStrHead *dsh = (DynStrHead *)(ds - sizeof(DynStrHead));
	size_t availLenDs, lenDs, newLen;
	availLenDs = DynStrAvail(ds);
	if (availLenDs > addLen)
		return ds;
	
	lenDs = DynStrLen(ds);
	newLen = lenDs + addLen;
	if (newLen > DYNSTR_MAX_MALLOC)
		newLen += DYNSTR_MAX_MALLOC;
	else
		newLen *= 2;

	dsh = realloc(dsh, newLen + sizeof(DynStrHead) + 1);
	dsh->free = newLen - lenDs;
	dsh->len = lenDs;

	return dsh->buf;
}
DynStr RmFreeSpaceDynStr(DynStr ds)
{
	DynStrHead *dsh = (DynStrHead *)(ds - sizeof(DynStrHead));
	len = DynStrLen(dsh);
	dsh = (DynStrHead *)realloc(dsh, sizeof(DynStrHead) + len + 1);
	dsh->len = len;
	dsh->free = 0;
	dsh->buf[len] = '\0';
	
	return dsh->buf;
}

size_t DynStrAllocSize(DynStr ds)
{
	DynStrHead *dsh = (DynStrHead *)(ds - (sizeof(DynStrHead)));
	return sizeof(DynStrHead) + dsh->len + dsh->free + 1;
}
