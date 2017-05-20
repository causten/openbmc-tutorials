#pragma once

#include <sdbusplus/server.hpp>
#include "xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp"

namespace phosphor
{
namespace tutorial
{

using ManagerIface = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::tutorial::hellomethod::server::Manager>;

/** @class Manager
 *  @brief OpenBMC logging manager implementation.
 *  @details A concrete implementation for the
 *  xyz.openbmc_project.Logging.Internal.Manager DBus API.
 */
class Manager : public ManagerIface
{
    public:
        
        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Manager(sdbusplus::bus::bus& bus, const char* objPath) :
                ManagerIface(bus, objPath) {};

        /*
         * @fn commit()
         * @brief sd_bus Commit method implementation callback.
         * @details Create an error/event log based on transaction id and
         *          error message.
         * @param[in] transactionId - Unique identifier of the journal entries
         *                            to be committed.
         * @param[in] msg - The error exception message associated with the
         *                     error log to be committed.
         */
        void commit(int32_t transactionId, std::string msg) override;

};

} // namespace logging
} // namespace phosphor