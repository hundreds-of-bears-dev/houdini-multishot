#include <string.h>
#include <UT/UT_DSOVersion.h>
#include <EXPR/EXPR.h>
#include <CH/CH_EvalContextFwd.h>
#include <CMD/CMD_Manager.h>

EV_START_FN(fn_contextstr){
    result->value.sval = strdup("ayyyyy");
}

static int stringArgs[] = { EV_TYPESTRING };

static EV_FUNCTION funcTable[] = {
    EV_FUNCTION(0, "contextstr", 1, EV_TYPESTRING, stringArgs, fn_contextstr),
    EV_FUNCTION()
};

void CMDextendLibrary(CMD_Manager *){
    for (int i = 0; funcTable[i].getName(); i++){
        ev_AddFunction(&funcTable[i]);
    }
}

