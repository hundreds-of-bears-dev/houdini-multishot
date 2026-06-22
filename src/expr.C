#include <iostream>
#include <string>
#include <UT/UT_DSOVersion.h>
#include <EXPR/EXPR.h>
#include <CH/CH_Manager.h>
#include <CMD/CMD_Manager.h>

EV_START_FN(fn_contextstr){
    CH_Manager& mgr = *CHgetManager();
    CH_EvalContext& ctx = mgr.evalContext(0);
    //DEP_ContextOptionsReadHandle ctx_opts = ctx.contextOptions();
    //const DEP_ContextOptionsStack* ctx_stack = ctx.contextOptionsStack();
    //for (int i=0; i<ctx_stack->size(); i++){
    //    std::cout << ctx_stack[i].get() << '\n';
    //}
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

