# CommonCrypto

## Install
To install CommonCrypto library to be used as a swift module in Linux Ubuntu, do the following:

1. Install required packages:

        $ sudo aptitude install gnustep
        $ sudo aptitude install gnustep-devel
        $ sudo aptitude install clang

2. Edit .bashrc file

        ~$ vim .bashrc 
Then Add:

        export GNUSTEP_MAKEFILES=/usr/share/GNUstep/Makefiles
Then:

        ~$ source .bashrc
        
3. Build CommonCrypto

        CommonCrypto$ make

4. If you get the following error:

        fatal error: 'TargetConditionals.h' file not found
Then do the following:

        /$ sudo find . -name "TargetConditionals.h"
If not found then download swift toolchain from https://swift.org/download/ to Linux find the file from the toolchain

        $ sudo cp /path/to/TargetConditionals.h /usr/include

5. Repeat step #3

6. Copy the library to /usr/lib

        CommonCrypto$ sudo cp obj/libCommonCrypto* /usr/lib

## A note from Niels Grewe

CommonCrypto is Apple's basic cryptography library. It's not per-se relevant
for Objective-C code, but it is extensively used in Mac OS X and iOS
applications. I speculate that having it around will make porting from Mac OS X
to GNUstep easier for some people.

This version of CommonCrypto is derived from the Apple version 36064.
It contains several modifications to make it compile and run under GNUstep.
This mostly involved setting up a GNUmakefile and moving the Mach-O specific
portions of the assembly code over to ELF directives. Presently, it requires
clang and GNUstep-Make and has the following limitations:

* For now, I have hardcoded some platform specific include paths, such as
limits.h. You might need to modify them by hand.
* Always uses the assembly versions of the crypto primitives for AES and SHA1.
This means that it will only work on IA-32 and x86-64 platforms.

These problems will probably go away once I add a proper configure script.

CommonCrypto has been released by Apple under a APSL/BSD license. The port is
maintained by Niels Grewe <niels.grewe@halbordnung.de>. Please direct all
criticisms, suggestions or bug reports to him.

## A note from Amr Aboelela
1. In this version I did the following in file AESAssembly.h:

        #if 0
        #define	UseAESedp_IntelAssembly
        #else
        #define	UseAESedp_GeneralC
        #endif
That will make the code run in C only and not in Assembly as the assembly code didn't run corretly with me in my Linux Ubuntu environment

2. I have tried IBM BlueCryptor which uses OpenSSL in Linux and CommonCrypto in Mac OS, what I found when I ran my unit testing is that it took 5 seconds in Mac OS, while it would take about 26 seconds in a Linux VM. However, when I tried this version of CommonCrypto in Linux, it used to take roughly the same like in Mac OS.
