BUILT_SOURCES = \
	xyz/openbmc_project/tutorial/hellomethod/Manager/server.cpp \
	xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp 


sbin_PROGRAMS = hellomethod
hellomethod_SOURCES = \
				method_tutorial.cpp \
				xyz/openbmc_project/tutorial/hellomethod/Manager/server.cpp \
				main.cpp


hellomethod_LDFLAGS = $(SYSTEMD_LIBS) $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS)
hellomethod_CFLAGS =  $(SYSTEMD_CFLAGS) $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS)

xyz/openbmc_project/tutorial/hellomethod/Manager/server.cpp: xyz/openbmc_project/tutorial/hellomethod/Manager.interface.yaml xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) interface server-cpp xyz.openbmc_project.tutorial.hellomethod.Manager > $@

xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp: xyz/openbmc_project/tutorial/hellomethod/Manager.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) interface server-header xyz.openbmc_project.tutorial.hellomethod.Manager > $@