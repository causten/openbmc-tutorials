sbin_PROGRAMS = buswatcher

buswatcher_SOURCES = main.cpp


buswatcher_LDFLAGS = $(SYSTEMD_LIBS) $(SDBUSPLUS_LIBS) \
                     $(PHOSPHOR_DBUS_INTERFACES_LIBS)
buswatcher_CFLAGS =  $(SYSTEMD_CFLAGS) $(SDBUSPLUS_CFLAGS) \
                     $(PHOSPHOR_DBUS_INTERFACES_CFLAGS)