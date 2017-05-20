# Add your code to the flash image

This tutorial will show you how to get the code you have working from [Hop on the bus](lessonbusmethod.md) 
in to a flash iamge.  This allows you to not have to scp the files over
every time and also introduces you to yocto recipies.

Simple follow the steps laid out in the [OpenBMC Yocto documentation](https://github.com/openbmc/docs/blob/master/yocto-development.md) 
and replace `welcome` with `hellomethod`

## Extra Credit
The shows tutorial shows how to add the code to your flash image but doesn't show
how to launch it as part of the boot process.  Fix up the build to have it running
at boot.