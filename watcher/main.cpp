#include <iostream>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/bus/match.hpp>


static int caughtSignal(sd_bus_message* msg,
                        void* userData,
                        sd_bus_error* retError)
{
    auto sdPlusMsg = sdbusplus::message::message(msg);

    fprintf(stderr, "Message Signature: %s\n", sdPlusMsg.get_signature());


    std::vector<std::string> result;
    sdPlusMsg.read(result);

    for  (const auto& i : result) {
        fprintf(stderr, "%s\n", i.c_str());
    }


    return 0;
}

bool cmdDone = false;

int main(int argc, char *argv[])
{

    auto bus = sdbusplus::bus::new_default();

    // Monitor for a specific signal 
    auto s = "type='signal',interface='org.openbmc',member='Sensor'";

    // Setup Signal Handler
    sdbusplus::bus::match::match caughtSignals(bus,
                               s,
                               caughtSignal,
                               nullptr);

    // Wait for signal
    while(!cmdDone)
    {
        bus.process_discard();
        if (cmdDone) break;
        bus.wait();
    }


    return 0;
}