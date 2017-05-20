# A method on the bus
In this tutorial you will create a method and attach to the bus using
yaml and c++. Make sure you have setup the SDK first.  The build files
for this tutorial are located [here](hellomethod)


### Makefile updates to support YAML dbus object
Notice the Makefile added more then just a couple of files.  These lines tell
the build to generate C++ code from the easy to read
[yaml](hellomethod/xyz/openbmc_project/tutorial/hellomethod/Manager.interface.yaml) file

```
BUILT_SOURCES = \
	xyz/openbmc_project/tutorial/lesson3/Manager/server.cpp \
	xyz/openbmc_project/tutorial/lesson3/Manager/server.hpp 
...
xyz/openbmc_project/tutorial/hellomethod/Manager/server.cpp: xyz/openbmc_project/tutorial/hellomethod/Manager.interface.yaml xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) interface server-cpp xyz.openbmc_project.tutorial.hellomethod.Manager > $@

xyz/openbmc_project/tutorial/hellomethod/Manager/server.hpp: xyz/openbmc_project/tutorial/hellomethod/Manager.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) interface server-header xyz.openbmc_project.tutorial.hellomethod.Manager > $@
```


## Steps

1. Build like the [readme](hellomethod/README.md) indicates.  
2. Copy the `hellomethod` to the system and run
3. Examine dbus

```
$ busctl introspect xyz.openbmc_project.Tutorials /xyz/openbmc_project/tutorial/hellomethod

xyz.openbmc_project.tutorial.hellomethod.Manager interface -          -             -
.Commit                                          method    is
```

And there is the Commit Method, along with the introspection showing what type are the input
parameters.

4.  Now it is time to call the method.  Here are a couple of different ways

Locally on the system...

```
busctl call xyz.openbmc_project.Tutorials /xyz/openbmc_project/tutorial/hellomethod \
xyz.openbmc_project.tutorial.hellomethod.Manager Commit is 1 "Hi Chris"
```

Via curl _assuming you have already [logged in](https://github.com/openbmc/docs/blob/master/rest-api.md#logging-in)_

```
curl -b cjar -k -H "Content-Type: application/json" -X POST  -d '{"data": [1, "Hi Chris"]}' \
https://bmc/xyz/openbmc_project/tutorial/hellomethod/action/commit

```


## Extra Credit
Rather then printing the text to the screen save it to a property.  Broadcast a signal annoucing you did it.