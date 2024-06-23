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

## Update

### Update 6/22/24

Added the MIT License to the installation.

### Update 6/13/24

Fix WinPos.

### Update 4/12/24 & $/18/24

Improved the way Toolbars and Window Position and size are handled.

### Update 2/16/24

Reorganized the Library so that it compiles once into Debug and Release directories under the Library
directory.

### Update 1/8/24

Added "Target" to directories to delete.  Libary and other changes.

### Update 12/25/23

Reworked ExpandableP and ripple due to changes.

### Update 6/29/23

Library update.

### Update 3/31/23

Add Report Orientation Dialog.  Add three additional directories to delete from Git:  Data, Data01,
Data02.

### Update 3/15/23

Complete move of orientation to reports.  Also removed redundant classes.

### Update 3/8/23

Added numbers to notepad archive output.   Fixed (hopefully) Print and Print Preview.  See MakeApp for
details.

### Update 10/27/22

Start app in the same position and size as when it last exited.  Update toolbar background.

### Update 8/26/22

Added logic to remove backup files (i.e. has a letter extension followed by a 12 digit date/time
extension).  Also will remove bin directory.

### Update 8/3/22

Minor Library Updates.

### Update 4/15/22

Big adventure in February when I started moving to a new Win11 and Visual Studio 2022.  I now
feel that this version is working in the new environment.  There were several changes made to the app
in order to compile properly on VS22.

### Update 01/31/22

Updates to the library, mostly about the toolbar, but also NewAllocator, and a minor addition to
Expandable.

Also scrubbed the project files to remove all references to precompiled header files which I turned off
in VS17.  Unfortnately VS does not remove all references and pch files kept cropping up.  Not only does
that slow down the compiler but the files are large...

### Update 12/18/21

While creating a template for a dialog box only application with a toolbar the Library was added to and
changed to hopefully simplify toolbar creation.  This version of the toolbar includes buttons, edit boxes,
combo boxes and drop down menus as well as the traditional 16x15 icons.

GitPrep is a tradional App, has a traditional 16x15 pixel icon toolbar.

## Authors

Robert R. Van Tuyl

Contact:  romeo romeo victor tango alpha tango sam whisky delta echo dot charlie oscar mike

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


