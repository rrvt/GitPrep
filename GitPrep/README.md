# GitPrep

An application to delete unneccessary files from a local Git directory.

## Getting Started

This version was created with Visual Studion 2017.  It was compiled with the following properties:

  - Windows SDK Version: 10.0.18362.0
  - Platform Toolset: visual Studio 2017 (v141)
  - MFC: Use MFC in a Shared DLL
  - Character Set:  Use Unicode Character Set
  - Precompiled Header:  Not Using Precompiled Headers
  - Linker/Additional Dependencies:  Htmlhelp.lib, OpenSSL.3.1\libssl.lib, OpenSSL.3.1\libcrypto.lib

The HTML Help Workshop (HHW), Version 4.74.8702.0 was used to prepare the help file (WixApp.chm).  It is
copied into the Release directory.  I used Dreamweaver (DW) to do most of the content production of the
help files that the HTML Help Workshop produces (i.e. HHW is used to produce the pages/files needed
and DW is used to fill in the content).

Additionally the WIX Installer, The very old Help Workshop and SlickEdit were used to process the code.
The Product (Wix installation file) was produced by my WixApp but it can be manipulated by
hand for changes.

## Prerequisites

  - Windows 7 or above.  visual Studio 2017 or above.
  - HTML Help Workshop (HHW), Version 4.74.8702.0
  - an HTML editor (I use an old copy of Dreamweaver)
  - The Wix Toolset (https://wixtoolset.org/) installed in Visual Studio
  - WixApp was used to prepare the product.wxs file

## Installing

Run the "msi" installer file.

## Running the tests

Setup a test Git upload directory.  Copy one or more projects into it.  Run GitPrep giving the Git
directory as the directory to process.  Use the appropriate commands to delete extraneous files and
directories.  Compile the resulting projects just as one would do in their home directories.  This
will demonstrate that the upload will work.  Start over to upload to Git.

## Authors

Robert R. Van Tuyl

Contact:  romeo romeo victor tango alpha tango sam whisky delta echo dot charlie oscar mike

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


