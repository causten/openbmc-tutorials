# Build the Simulator

The Cheatsheet already shows how to build the simulator so follow the [guide](https://github.com/openbmc/docs/blob/master/cheatsheet.md#building-qemu).  

Once the code has been built follow the [Using QEMU](https://github.com/openbmc/docs/blob/master/cheatsheet.md#using-qemu)
portion of the guide.  There is a point in the instructions where you need to
satisfy the `<path>/flash-palmetto` path.  Head over to the
[build server](https://openpower.xyz/job/openbmc-build/distro=ubuntu,target=palmetto/lastSuccessfulBuild/artifact/images/palmetto/flash-palmetto) 
and just use that one for now.

If you followed the instructions correctly you should reach the login prompt.

Login `root/0penBmc`


You are Done!


## Extra credit

The cheatsheet shows how to port forward the https and ssl ports.  There is 
another port that some developers like to use to see what is exposed on the
REST / Dbus.  On real hardware it would be port 3000.  Try to forward it and
point your web browser there.
