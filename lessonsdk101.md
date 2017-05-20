# Hello World ARM style

In all likelyhood you are running on a PPC64 or x86 system.  OpenBMC typically
runs on an ARM chip so welcome to the world of cross compiling.  To start, 
write yourself a hello world program like this

```
#include <iostream>

int main()
{
  std::cout << "Hello World!";
  return 0;
}

```

And then run `g++ hello.cpp; ./a.out` it will work.  That is because you compiled
it for the system you are running on.  Instead let's compile it for ARM and use
the bindings OpenBMC provides

## Build the SDK
If you haven't built OpenBMC yet follow Follow the [guide](https://github.com/openbmc/openbmc#setting-up-your-openbmc-project)
but replace the `bitbake obmc-phosphor-image` with `bitbake -c populate_sdk obmc-phosphor-image`.
If you where planning to use QEMU you can target the machine `palmetto`.

Now follow the cheatsheet guide for [Building the SDK](https://github.com/openbmc/docs/blob/master/cheatsheet.md#building-the-openbmc-sdk)
The literal text may have changed like `2.1` or `armv5`. Just follow the idea 
and you will get there.


Now run g++ in your cross compiled environment.  Then copy the file on to your
OpenBMC system.  Your program should now print on the BMC.


## Extra Credit
You don't have to cross compile.  You can target the SDK for your native system.
Doing so can be useful if your OS is running dbus because you then get to interact
with it instead.