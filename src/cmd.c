/* A recursive-descent parser generated by peg 0.1.18 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 7
#line 1 "src/cmd.leg"

#define YYSTYPE unsigned long
#include <stdlib.h>
#include <stdbool.h>

#include "shared.h"
#include "menu.h"

////////// STATE MACHINE //////////
typedef char jf_cmd_parser_state;

// make sure to start from 0 so memset init works
#define JF_CMD_VALIDATE_START	0
#define JF_CMD_VALIDATE_ATOMS	1
#define JF_CMD_VALIDATE_FOLDER	2
#define JF_CMD_VALIDATE_OK		3
#define JF_CMD_SPECIAL			4
#define JF_CMD_SUCCESS			5

#define JF_CMD_FAIL_FOLDER		-1
#define JF_CMD_FAIL_SYNTAX		-2
#define JF_CMD_FAIL_DISPATCH	-3

#define JF_CMD_IS_FAIL(state)	((state) < 0)
///////////////////////////////////


////////// YY_CTX //////////
// forward declaration wrt PEG generated code
typedef struct _yycontext yycontext;

#define YY_CTX_LOCAL
#define YY_CTX_MEMBERS			\
	jf_cmd_parser_state state;	\
	char *input;				\
	size_t read_input;
////////////////////////////


////////// INPUT PROCESSING //////////
#define YY_INPUT(ctx, buf, result, max_size)						\
	{																\
		size_t to_read = 0;											\
		while (to_read < max_size) {								\
			if (ctx->input[ctx->read_input + to_read] == '\0') {	\
				break;												\
			}														\
			to_read++;												\
		}															\
		memcpy(buf, ctx->input + ctx->read_input, to_read);			\
		ctx->read_input += to_read;									\
		result = to_read;											\
	}
//////////////////////////////////////


////////// FUNCTION PROTOTYPES //////////
jf_cmd_parser_state yy_cmd_get_parser_state(const yycontext *ctx);

static void yy_cmd_digest(yycontext *ctx, const size_t n);
static void yy_cmd_digest_range(yycontext *ctx, const size_t l, const size_t r);
static void yy_cmd_finalize(yycontext *ctx, const bool parse_ok);
/////////////////////////////////////////

#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy_string(yycontext *yy); /* 7 */
YY_RULE(int) yy_num(yycontext *yy); /* 6 */
YY_RULE(int) yy_Atom(yycontext *yy); /* 5 */
YY_RULE(int) yy_Items(yycontext *yy); /* 4 */
YY_RULE(int) yy_Selector(yycontext *yy); /* 3 */
YY_RULE(int) yy_ws(yycontext *yy); /* 2 */
YY_RULE(int) yy_Start(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_num(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_num\n"));
  {
#line 83
   __ = strtoul(yytext, NULL, 10); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_Atom(yycontext *yy, char *yytext, int yyleng)
{
#define n yy->__val[-1]
#define r yy->__val[-2]
#define l yy->__val[-3]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Atom\n"));
  {
#line 82
   yy_cmd_digest(yy, n); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef n
#undef r
#undef l
}
YY_ACTION(void) yy_1_Atom(yycontext *yy, char *yytext, int yyleng)
{
#define n yy->__val[-1]
#define r yy->__val[-2]
#define l yy->__val[-3]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Atom\n"));
  {
#line 81
   yy_cmd_digest_range(yy, l, r); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef n
#undef r
#undef l
}
YY_ACTION(void) yy_1_Selector(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Selector\n"));
  {
#line 77
   yy_cmd_digest_range(yy, 1, jf_menu_child_count()); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_4_Start(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_4_Start\n"));
  {
#line 76
   yy_cmd_finalize(yy, true); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_Start(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Start\n"));
  {
#line 74
   yy->state = JF_CMD_SPECIAL; jf_menu_quit(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_Start(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Start\n"));
  {
#line 71
   yy->state = JF_CMD_SPECIAL; jf_menu_clear(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Start(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Start\n"));
  {
#line 70
   yy->state = JF_CMD_SPECIAL; jf_menu_dotdot(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy_string(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "string"));  if (!yymatchClass(yy, (unsigned char *)"\377\333\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377")) goto l1;
  l2:;	
  {  int yypos3= yy->__pos, yythunkpos3= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\377\333\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377")) goto l3;  goto l2;
  l3:;	  yy->__pos= yypos3; yy->__thunkpos= yythunkpos3;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "string", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "string", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_num(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "num"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l4;
#undef yytext
#undef yyleng
  }  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l4;
  l5:;	
  {  int yypos6= yy->__pos, yythunkpos6= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l6;  goto l5;
  l6:;	  yy->__pos= yypos6; yy->__thunkpos= yythunkpos6;
  }  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l4;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_num, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "num", yy->__buf+yy->__pos));
  return 1;
  l4:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "num", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Atom(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 3, 0);
  yyprintf((stderr, "%s\n", "Atom"));
  {  int yypos8= yy->__pos, yythunkpos8= yy->__thunkpos;  if (!yy_num(yy)) goto l9;  yyDo(yy, yySet, -3, 0);
  l10:;	
  {  int yypos11= yy->__pos, yythunkpos11= yy->__thunkpos;  if (!yy_ws(yy)) goto l11;  goto l10;
  l11:;	  yy->__pos= yypos11; yy->__thunkpos= yythunkpos11;
  }  if (!yymatchChar(yy, '-')) goto l9;
  l12:;	
  {  int yypos13= yy->__pos, yythunkpos13= yy->__thunkpos;  if (!yy_ws(yy)) goto l13;  goto l12;
  l13:;	  yy->__pos= yypos13; yy->__thunkpos= yythunkpos13;
  }  if (!yy_num(yy)) goto l9;  yyDo(yy, yySet, -2, 0);  yyDo(yy, yy_1_Atom, yy->__begin, yy->__end);  goto l8;
  l9:;	  yy->__pos= yypos8; yy->__thunkpos= yythunkpos8;  if (!yy_num(yy)) goto l7;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_2_Atom, yy->__begin, yy->__end);
  }
  l8:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Atom", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 3, 0);
  return 1;
  l7:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Atom", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Items(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Items"));
  {  int yypos15= yy->__pos, yythunkpos15= yy->__thunkpos;  if (!yy_Atom(yy)) goto l16;
  l17:;	
  {  int yypos18= yy->__pos, yythunkpos18= yy->__thunkpos;  if (!yy_ws(yy)) goto l18;  goto l17;
  l18:;	  yy->__pos= yypos18; yy->__thunkpos= yythunkpos18;
  }  if (!yymatchChar(yy, ',')) goto l16;
  l19:;	
  {  int yypos20= yy->__pos, yythunkpos20= yy->__thunkpos;  if (!yy_ws(yy)) goto l20;  goto l19;
  l20:;	  yy->__pos= yypos20; yy->__thunkpos= yythunkpos20;
  }  if (!yy_Items(yy)) goto l16;  goto l15;
  l16:;	  yy->__pos= yypos15; yy->__thunkpos= yythunkpos15;  if (!yy_Atom(yy)) goto l14;
  }
  l15:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Items", yy->__buf+yy->__pos));
  return 1;
  l14:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Items", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Selector(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Selector"));
  {  int yypos22= yy->__pos, yythunkpos22= yy->__thunkpos;  if (!yymatchChar(yy, '*')) goto l23;  yyDo(yy, yy_1_Selector, yy->__begin, yy->__end);  goto l22;
  l23:;	  yy->__pos= yypos22; yy->__thunkpos= yythunkpos22;  if (!yy_Items(yy)) goto l21;
  }
  l22:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Selector", yy->__buf+yy->__pos));
  return 1;
  l21:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Selector", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ws(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ws"));  if (!yymatchClass(yy, (unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l24;
  yyprintf((stderr, "  ok   %s @ %s\n", "ws", yy->__buf+yy->__pos));
  return 1;
  l24:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ws", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Start(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Start"));
  l26:;	
  {  int yypos27= yy->__pos, yythunkpos27= yy->__thunkpos;  if (!yy_ws(yy)) goto l27;  goto l26;
  l27:;	  yy->__pos= yypos27; yy->__thunkpos= yythunkpos27;
  }
  {  int yypos30= yy->__pos, yythunkpos30= yy->__thunkpos;  if (!yymatchString(yy, "..")) goto l31;
  l32:;	
  {  int yypos33= yy->__pos, yythunkpos33= yy->__thunkpos;  if (!yy_ws(yy)) goto l33;  goto l32;
  l33:;	  yy->__pos= yypos33; yy->__thunkpos= yythunkpos33;
  }  yyDo(yy, yy_1_Start, yy->__begin, yy->__end);  goto l30;
  l31:;	  yy->__pos= yypos30; yy->__thunkpos= yythunkpos30;  if (!yymatchChar(yy, 'h')) goto l34;  yyDo(yy, yy_2_Start, yy->__begin, yy->__end);  goto l30;
  l34:;	  yy->__pos= yypos30; yy->__thunkpos= yythunkpos30;  if (!yymatchChar(yy, 'q')) goto l35;
  l36:;	
  {  int yypos37= yy->__pos, yythunkpos37= yy->__thunkpos;  if (!yy_ws(yy)) goto l37;  goto l36;
  l37:;	  yy->__pos= yypos37; yy->__thunkpos= yythunkpos37;
  }  yyDo(yy, yy_3_Start, yy->__begin, yy->__end);  goto l30;
  l35:;	  yy->__pos= yypos30; yy->__thunkpos= yythunkpos30;  if (!yy_Selector(yy)) goto l29;
  l38:;	
  {  int yypos39= yy->__pos, yythunkpos39= yy->__thunkpos;  if (!yy_ws(yy)) goto l39;  goto l38;
  l39:;	  yy->__pos= yypos39; yy->__thunkpos= yythunkpos39;
  }
  }
  l30:;	  goto l28;
  l29:;	  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
   yy_cmd_finalize(yy, false); ;
#undef yytext
#undef yyleng
  }  goto l25;
  l28:;	  yyDo(yy, yy_4_Start, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Start", yy->__buf+yy->__pos));
  return 1;
  l25:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Start", yy->__buf+yy->__pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_Start);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif
#line 90 "src/cmd.leg"

jf_cmd_parser_state yy_cmd_get_parser_state(const yycontext *ctx)
{
	return ctx->state;
}


static void yy_cmd_digest(yycontext *ctx, size_t n)
{
	jf_item_type item_type;

	// no-op on fail state
	if (JF_CMD_IS_FAIL(ctx->state)) {
		return;
	}

	// no-op if item does not exist (out of bounds)
	if ((item_type = jf_menu_child_get_type(n)) == JF_ITEM_TYPE_NONE) {
		return;
	}

	switch (ctx->state) {
		case JF_CMD_VALIDATE_START:
			if (JF_ITEM_TYPE_IS_FOLDER(item_type)) {
				ctx->state = JF_CMD_VALIDATE_FOLDER;
			} else {
				ctx->state = JF_CMD_VALIDATE_ATOMS;
			}
			break;
		case JF_CMD_VALIDATE_ATOMS:
			if (JF_ITEM_TYPE_IS_FOLDER(item_type)) {
				ctx->state = JF_CMD_FAIL_FOLDER;
			}
			break;
		case JF_CMD_VALIDATE_FOLDER:
			if (! JF_ITEM_TYPE_IS_FOLDER(item_type)) {
				ctx->state = JF_CMD_FAIL_FOLDER;
			}
			break;
		case JF_CMD_VALIDATE_OK:
			if (! jf_menu_child_dispatch(n)) {
				ctx->state = JF_CMD_FAIL_DISPATCH;
			}
			break;
		default:
			fprintf(stderr, "Error: yy_cmd_digest encountered unexpected state transition. This is a bug.\n");	
			break;
	}
}


static void yy_cmd_digest_range(yycontext *ctx, size_t l, const size_t r)
{
	int step = l <= r ? 1 : -1;
	while (true) {
		yy_cmd_digest(ctx, l);
		if (l == r || l == -1) break;
		l += step;
	}
}


static void yy_cmd_finalize(yycontext *ctx, const bool parse_ok)
{
	if (parse_ok == false) {
		ctx->state = JF_CMD_FAIL_SYNTAX;
	} else {
		switch (ctx->state) {
			case JF_CMD_VALIDATE_ATOMS:
			case JF_CMD_VALIDATE_FOLDER:
				ctx->read_input = 0;
				ctx->state = JF_CMD_VALIDATE_OK;
				break;
			case JF_CMD_VALIDATE_OK:
			case JF_CMD_SPECIAL:
			case JF_CMD_VALIDATE_START: // all items out of bounds
				ctx->state = JF_CMD_SUCCESS;
				break;
			case JF_CMD_FAIL_FOLDER:
				break;
			default:
				fprintf(stderr, "Error: yy_cmd_finalize encountered unexpected state transition. This is a bug.\n");	
		}
	}
}

