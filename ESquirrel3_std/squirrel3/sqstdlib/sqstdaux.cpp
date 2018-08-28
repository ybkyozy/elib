/* see copyright notice in squirrel.h */
#include <squirrel.h>
#include <sqstdaux.h>
#include <assert.h>
#include "zyhelper.h"

void sqstd_printcallstack(HSQUIRRELVM v)
{
    SQPRINTFUNCTION pf = sq_geterrorfunc(v);
    if(pf) {
        SQStackInfos si;
        SQInteger i;
        SQFloat f;
        const SQChar *s;
        SQInteger level=1; //1 is to skip this function that is level 0
        const SQChar *name=0;
        SQInteger seq=0;
        pf(v,_SC("\nCALLSTACK\n"));
        while(SQ_SUCCEEDED(sq_stackinfos(v,level,&si)))
        {
            const SQChar *fn=_SC("unknown");
            const SQChar *src=_SC("unknown");
            if(si.funcname)fn=si.funcname;
            if(si.source)src=si.source;
			zy_printf(v, pf, _SC("*FUNCTION [%s()] %s line [%d]\n"), fn, src, si.line);
            //pf(v,_SC("*FUNCTION [%s()] %s line [%d]\n"),fn,src,si.line);
            level++;
        }
        level=0;
        pf(v,_SC("\nLOCALS\n"));

        for(level=0;level<10;level++){
            seq=0;
            while((name = sq_getlocal(v,level,seq)))
            {
                seq++;
                switch(sq_gettype(v,-1))
                {
                case OT_NULL:
					zy_printf(v, pf, _SC("[%s] NULL\n"), name);
                    //pf(v,_SC("[%s] NULL\n"),name);
                    break;
                case OT_INTEGER:
                    sq_getinteger(v,-1,&i);
					zy_printf(v, pf, _SC("[%s] %d\n"), name, i);
                    //pf(v,_SC("[%s] %d\n"),name,i);
                    break;
                case OT_FLOAT:
                    sq_getfloat(v,-1,&f);
					zy_printf(v, pf, _SC("[%s] %.14g\n"), name, f);
                    //pf(v,_SC("[%s] %.14g\n"),name,f);
                    break;
                case OT_USERPOINTER:
					zy_printf(v, pf, _SC("[%s] USERPOINTER\n"), name);
                    //pf(v,_SC("[%s] USERPOINTER\n"),name);
                    break;
                case OT_STRING:
                    sq_getstring(v,-1,&s);
					zy_printf(v, pf, _SC("[%s] \"%s\"\n"), name, s);
                    //pf(v,_SC("[%s] \"%s\"\n"),name,s);
                    break;
                case OT_TABLE:
					zy_printf(v, pf, _SC("[%s] TABLE\n"), name);
                    //pf(v,_SC("[%s] TABLE\n"),name);
                    break;
                case OT_ARRAY:
					zy_printf(v, pf, _SC("[%s] ARRAY\n"), name);
                    //pf(v,_SC("[%s] ARRAY\n"),name);
                    break;
                case OT_CLOSURE:
					zy_printf(v, pf, _SC("[%s] CLOSURE\n"), name);
                    //pf(v,_SC("[%s] CLOSURE\n"),name);
                    break;
                case OT_NATIVECLOSURE:
					zy_printf(v, pf, _SC("[%s] NATIVECLOSURE\n"), name);
                    //pf(v,_SC("[%s] NATIVECLOSURE\n"),name);
                    break;
                case OT_GENERATOR:
					zy_printf(v, pf, _SC("[%s] GENERATOR\n"), name);
                    //pf(v,_SC("[%s] GENERATOR\n"),name);
                    break;
                case OT_USERDATA:
					zy_printf(v, pf, _SC("[%s] USERDATA\n"), name);
                    //pf(v,_SC("[%s] USERDATA\n"),name);
                    break;
                case OT_THREAD:
					zy_printf(v, pf, _SC("[%s] THREAD\n"), name);
                    //pf(v,_SC("[%s] THREAD\n"),name);
                    break;
                case OT_CLASS:
					zy_printf(v, pf, _SC("[%s] CLASS\n"), name);
                    //pf(v,_SC("[%s] CLASS\n"),name);
                    break;
                case OT_INSTANCE:
					zy_printf(v, pf, _SC("[%s] INSTANCE\n"), name);
                    //pf(v,_SC("[%s] INSTANCE\n"),name);
                    break;
                case OT_WEAKREF:
					zy_printf(v, pf, _SC("[%s] WEAKREF\n"), name);
                    //pf(v,_SC("[%s] WEAKREF\n"),name);
                    break;
                case OT_BOOL:{
                    SQBool bval;
                    sq_getbool(v,-1,&bval);
					zy_printf(v, pf, _SC("[%s] %s\n"), name, bval == SQTrue ? _SC("true") : _SC("false"));
                    //pf(v,_SC("[%s] %s\n"),name,bval == SQTrue ? _SC("true"):_SC("false"));
                             }
                    break;
                default: assert(0); break;
                }
                sq_pop(v,1);
            }
        }
    }
}

static SQInteger __stdcall _sqstd_aux_printerror(HSQUIRRELVM v)
{
    SQPRINTFUNCTION pf = sq_geterrorfunc(v);
    if(pf) {
        const SQChar *sErr = 0;
        if(sq_gettop(v)>=1) {
            if(SQ_SUCCEEDED(sq_getstring(v,2,&sErr)))   {
				zy_printf(v, pf, _SC("\nAN ERROR HAS OCCURED [%s]\n"), sErr);
                //pf(v,_SC("\nAN ERROR HAS OCCURED [%s]\n"),sErr);
            }
            else{
                pf(v,_SC("\nAN ERROR HAS OCCURED [unknown]\n"));
            }
            sqstd_printcallstack(v);
        }
    }
    return 0;
}

void __stdcall _sqstd_compiler_error(HSQUIRRELVM v,const SQChar *sErr,const SQChar *sSource,SQInteger line,SQInteger column)
{
    SQPRINTFUNCTION pf = sq_geterrorfunc(v);
    if(pf) {
		zy_printf(v, pf, _SC("%s line = (%d) column = (%d) : error %s\n"), sSource, line, column, sErr);
        //pf(v,_SC("%s line = (%d) column = (%d) : error %s\n"),sSource,line,column,sErr);
    }
}

void sqstd_seterrorhandlers(HSQUIRRELVM v)
{
    sq_setcompilererrorhandler(v,_sqstd_compiler_error);
    sq_newclosure(v,_sqstd_aux_printerror,0);
    sq_seterrorhandler(v);
}
