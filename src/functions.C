#include <string.h>
#include <malloc.h>
#include <math.h>
#include <UT/UT_DSOVersion.h>
#include <EXPR/EXPR.h>
#include <EXPR/EX_Vector.h>
#include <OP/OP_Director.h>
#include <OP/OP_Operator.h>
#include <OP/OP_Channels.h>
#include <PRM/PRM_RefId.h>
#include <CH/CH_EvalContextFwd.h>
#include <CH/CH_Support.h>
#include <CMD/CMD_Manager.h>

#ifndef EV_START_FN
#define EV_START_FN(name)     \
        static void name(EV_FUNCTION *, EV_SYMBOL *result,\
            EV_SYMBOL **argv, int thread)
#endif // EV_START_FN

EV_START_FN(fn_contextstr)
{
    result->value.sval = strdup("ayyyyy");
}

static int stringArgs[] = { EV_TYPESTRING };

static EV_FUNCTION funcTable[] = {
    EV_FUNCTION(0, "contextstr", 1, EV_TYPESTRING, stringArgs, fn_contextstr),
    EV_FUNCTION()
};

void
CMDextendLibrary(CMD_Manager *)
{
    for (int i = 0; funcTable[i].getName(); i++){
        ev_AddFunction(&funcTable[i]);
    }
}

