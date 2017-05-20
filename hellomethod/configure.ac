AC_PREREQ([2.69])
AC_INIT([hellomethod], [1.0])
AC_LANG([C++])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects -Wall -Werror foreign dist-xz])
AM_SILENT_RULES([yes])

# Checks for programs
AC_PROG_CXX
AC_PROG_INSTALL #Checks/sets the install variable to be used
AC_PROG_MAKE_SET

# Check for libraries
PKG_CHECK_MODULES([SYSTEMD], [libsystemd >= 221])
PKG_CHECK_MODULES([PHOSPHOR_DBUS_INTERFACES], [phosphor-dbus-interfaces],, \
    AC_MSG_ERROR(["Requires phosphor-dbus-interfaces package."]))
PKG_CHECK_MODULES([SDBUSPLUS], [sdbusplus],, \
    AC_MSG_ERROR(["Requires sdbusplus package."]))

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_14([noext])
AX_APPEND_COMPILE_FLAGS([-Wall -Werror], [CXXFLAGS])

# Checks for library functions
LT_INIT # Removes WARNING: unrecognized options: --with-libtool-sysroot

# Check for sdbus++
AC_PATH_PROG([SDBUSPLUSPLUS], [sdbus++])
AS_IF([test "x$SDBUSPLUSPLUS" == "x"],
    AC_MSG_ERROR(["Requires sdbus++"]))

AC_ARG_VAR(BMC_BUSNAME, [The BMC Dbus busname to own])
AS_IF([test "x$BMC_BUSNAME" == "x"], [BMC_BUSNAME="xyz.openbmc_project.Tutorials"])
AC_DEFINE_UNQUOTED([BMC_BUSNAME], ["$BMC_BUSNAME"], [The BMC DBus busname to own])

AC_ARG_VAR(BMC_OBJPATH, [The BMC state manager Dbus root])
AS_IF([test "x$BMC_OBJPATH" == "x"], [BMC_OBJPATH="/xyz/openbmc_project/tutorial/hellomethod"])
AC_DEFINE_UNQUOTED([BMC_OBJPATH], ["$BMC_OBJPATH"], [The BMC state manager Dbus root])


# Check for header files.
AC_CHECK_HEADER(systemd/sd-bus.h, ,[AC_MSG_ERROR([Could not find systemd/sd-bus.h...systemd developement package required])])
AC_CHECK_HEADER(sdbusplus/bus/match.hpp, ,[AC_MSG_ERROR([Could not find sdbusplus/server/match.hpp...openbmc/sdbusplus package required])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT