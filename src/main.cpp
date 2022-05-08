#include "main.h"

int main(){
    dbg::setEnabled(false);
    
	dbg::p("Program execution started");
    dbg::p("Program execution time is " + dbg::getExecTime_S());
    dbg::logIgnore("This can also be printed this way");
    dbg::p("Program debugging state is set to " + std::to_string(dbg::getEnabled()));
    dbg::setEnabled(true);
    dbg::p("Program debugging state is set to " + std::to_string(dbg::getEnabled()));
    dbg::l("This means that logging works, but only when logging is set to true");
    dbg::setEnabled(false);
    dbg::p("Program debugging state is set to " + std::to_string(dbg::getEnabled()));
    dbg::log("This shouldn't be printed");
    dbg::p("If you saw a statement that said \"This shouldn't be printed\" then the debugger broke");
    dbg::logWrn("This is a warning");
    dbg::logErr("This is an error");
    dbg::logClr("This message is in green");
    dbg::logClr("This message is in magenta", dbg::MAGENTA);
    dbg::logRnbw("This message should be logged in rainbow-esque colours");
    dbg::pRnbw("This message should be printed in rainbow-esque colours");
    dbg::p("That should be all!");

    return 0;
}
