# CommonCrypto

## Install
1. Install gnustep:

    $ sudo aptitude install gnustep-devel

2. Edit .bashrc file

   ~$ vim .bashrc 

- Then Add:

    export GNUSTEP_MAKEFILES=/usr/share/GNUstep/Makefiles/

3. 

    CommonCrypto$ make
    CommonCrypto$ make install

4. If you get the following error:

    fatal error: 'TargetConditionals.h' file not found

- Then:

    /$ sudo find . -name "TargetConditionals.h"
    /$ cp path/to/TargetConditionals.h usr/include

- Then run make again

5. Copy the library to /usr/lib

    CommonCrypto$ sudo cp obj/libCommonCrypto* /usr/lib

