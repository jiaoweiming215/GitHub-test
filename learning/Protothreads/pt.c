
/*******************************************************************************************

****************************************************************************/
typedef unsigned short lc_t;
#define LC_INIT(s) s = 0;
#define LC_RESUME(s) switch(s) { case 0:
#define LC_SET(s) s = __LINE__; case __LINE__:
#define LC_END(s) }
