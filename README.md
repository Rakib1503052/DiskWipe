# DiskWipe

Additional License
______________________________________________________________________
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
                    Version 2, December 2004
 	  Everyone is permitted to copy and distribute verbatim or modified 
	  copies of this license document.
    
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
       TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 
   
       0. You just DO WHAT THE FUCK YOU WANT TO.
 ______________________________________________________________________

# Description
A small tool to completely wipe the free space on any disk storage by overwritting the free space multiple times.
And by "wipe", it means making any data deleted from that space to be unrecoverable.

It fills the available space of the given directory with, first '0's and then '1's, essentially overwritting any 
previous data. One pass consists of filling the space with 0s and 1s, once each. The more times the memory is 
overwritten the more difficult it will be to recover previous data.

Note that the tool does not delete any file. You have to delete the files you don't want to see before wiping.
_________________________________________________________________________________________________________________

# Build Instruction
Due to a bug in MinGW's "fs_path.h" header, MinGW 8.1.0 cannot build it. Either use Visual Studio or MinGW 9 or 
above (available on msys2).

The built binary should work independently.
_________________________________________________________________________________________________________________

# Usage instruction
Run the executable ("DiskWipe.exe"), preferably from a usb drive. Enter the root directory to wipe. Note that you
CAN enter a folder path but it would still wipe the entire free space of the root directory. After inputting root
directory, you'll see the total, free and write-available space on the directory. Enter 'y' or 'Y' to continue. 
Enter the number of passes you want to make. For solid state memory, 1 pass is enough. For HDD, at least 2 passes
is recommended. Of course, the more the merrier. Now, wait till the wiping is done.
_________________________________________________________________________________________________________________

# Regarding setup files
The "DiskWipeSetup" folder includes the setup files for Windows. Download and run "setup.exe" to install. Then run.

Note: Requires Micorsoft Visual C++ Redistributable.
Download from here https://docs.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170

(Yeah, sue me. I used VS2022 because CodeBlocks MinGW has a buggy header and I didn't want to setup msys2 for this. If MinGW 
releases a new version for CodeBlocks, I'll rebuild it.)
