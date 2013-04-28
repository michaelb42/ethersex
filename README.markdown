# What's this?

This is my personal variant of the Ethersex firmware for the Atmel megaAVR processors.

### Branches:
* __master__  
	the common master branch of this repository. New features will be added
	here when they are ready for prime time.
* __e6_upstream__  
	this branch should always closely track upstream/master by pull'ing from
	ethersex/ethersex and push'ing here.
* __experimental__  
	this branch is used for experimental stuff. It will be `reset --hard`
	as needed from time to time and might not even compile...
* __project_neptun__  
	Ethersex based firmware for the main controller of a project codenamed
	"Project Neptun", an aquarium / aquarium computer using "as many
	&micro;controllers as possible" &trade;.
* __avrdude_config__  
	add `program` and `fuses` target to the toplevel Makefile and integrate
	avdude configuration options into menuconfig.
* __...__  
	several other transient experimental- and bugfix-branches.

***************************************************************************
(Text of original Ethersex README.markdown follows)
***************************************************************************
About Ethersex
==============
Ethersex, originally developed to provide an alternative firmware for the [etherrape hardware](http://www.lochraster.org/etherrape),
evolved into a full-featured still light-weight firmware for the Atmel megaAVR processors.  
For more information and a comprehensive documentation  consult [http://www.ethersex.de](http://www.ethersex.de)!

How to configure the firmware
=============================
Make sure that you meet the requirements.  
Use `make menuconfig` to configure and `make` to compile the firmware.
The final hex file is named `ethersex.hex`.

[See the Quick Start Guide in the wiki for more information](http://ethersex.de/index.php/Quick_Start_Guide)

How to add a new hardware pinning
=================================
Use the script at `scripts/add-hardware` to add a new pinning.


Used 3rd party software 
=======================
This program contains software by other authors:

* [the uIP tcp/ip stack](http://www.sics.se/~adam/uip) in the directory `/protocols/uip/`, written by Adam Dunkels
* [usb-software stack from obdev](http://www.obdev.at/products/vusb/index.html) in `/protocols/usb/usbdrv/`
* [sd card reader](http://www.roland-riegel.de/sd-reader/index.html) in `/hardware/storage/sd_reader`

License
=======
All ethersex related code is licensed under GPLv3, unless otherwise noted. See COPYING in the main
directory, but in doubt check the file header. Usually every file contains a
header, stating all contributing authors and the specific license used.

Various make targets
====================

* `make show-config` -- Shows the activated modules
