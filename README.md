# seabreeze_files_for_arm

Modified following files.

NativeRS232Windows.c
NativeUSBWinUSB.c
NativeRS232.h
NativeRS232.cpp
RS232.cpp


Modification is for the case of _MSC_VER (microsoft compiler)
existance and UNICODE instead of char* routines w_char* routines are used

In order to find the modified part of the code search in these 5 files "// DK" comment.
I think modification are clear, so no comment are provided





In order to install *.inf file pnputil can be used
   
   >pnputil -i -a inf_file_name.inf
 
 If command succed As a result of this command one should see 
 following output
    Processing inf :            OOI_HR2000Plus.inf
    Successfully installed the driver on a device on the system.
    Driver package added successfully.
    Published name :            out_inf_file_name.inf
 
 
In order to uninstall driver installed with above described step again pnputil can be used
   
   >pnputil -d out_inf_file_name.inf
   >pnputil -f -d out_inf_file_name.inf    :: force delete



Following are the types and the files in each group

 1. inf files
    a) OOI_HR2000Plus2.inf  -> This file is for OceanOptics HR2000+ device
