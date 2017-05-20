# Watch the dbus
DBus is IPC.  So lets do some.  In this tutorial; using C++ and autotools, you
will write a program that will watch for dbus signals.

Make sure you have setup the SDK first.  The build files for this tutorial are
located [here](watcher)

```
. /opt/openbmc-phosphor/2.2/environment-setup-armv5e-openbmc-linux-gnueabi
./bootstrap.sh
./configure ${CONFIGURE_FLAGS}
make
```

Copy the watcher program on to the target OpenBMC system, then run...

```
watcher&
dbus-send --system --type=signal / org.openbmc.Sensor array:string:"parm1","neat"
```

Expect to see

```
Message Signature: as
parm1
neat
```


## Extra information
Notice the `Message Signature: as` that indicated the signal has a buffer of data,
and the data is an array of strings.  In addition to the buffer that we sent, 
events over dbus come with other details too.  The built in tools such as 
busctl, dbus-send and dbus-monitor are very useful

You can run `dbus-monitor --system' to see all the dbus events but quickly you
will realize things get noisy.  Introducing filters...

```
dbus-monitor --system "type='signal', member='Sensor'"
```

Dbus examples and developers guides are not as popular as cat videos so share
when you find one that is [helpful](https://dbus.freedesktop.org/doc/dbus-send.1.html).


## Extra Credit
The `Message Signature` indicates the type of data in the signals buffer.  Can
you make the signature 'asi' ?   Can you change the code to parse the `i`?

