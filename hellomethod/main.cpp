#include <iostream>
#include <sdbusplus/server.hpp>
#include "config.h"
#include "xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp"
#include "method_tutorial.hpp"

int main(int argc, char**)
{
    auto bus = sdbusplus::bus::new_default();

    // Add sdbusplus ObjectManager.
    sdbusplus::server::manager::manager objManager(bus, BMC_OBJPATH);

    phosphor::tutorial::Manager manager(bus,
                                        BMC_OBJPATH);

    bus.request_name(BMC_BUSNAME);

    while(true)
    {
        bus.process_discard();
        bus.wait();
    }

    exit(EXIT_SUCCESS);

}