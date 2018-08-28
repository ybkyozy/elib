# Microsoft Developer Studio Project File - Name="esquirrel3_static" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=esquirrel3_static - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "esquirrel3_static.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "esquirrel3_static.mak" CFG="esquirrel3_static - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "esquirrel3_static - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "esquirrel3_static - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "esquirrel3_static - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "esquirrel3_static___Win32_Release"
# PROP BASE Intermediate_Dir "esquirrel3_static___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "esquirrel3_static___Win32_Release"
# PROP Intermediate_Dir "esquirrel3_static___Win32_Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "./squirrel3/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "__E_STATIC_LIB" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Special Build Tool
TargetPath=.\esquirrel3_static___Win32_Release\esquirrel3_static.lib
SOURCE="$(InputPath)"
PostBuild_Cmds="E:\编程\编程工具\e\sdk\tools\resym.exe" all infile="$(TargetPath)" outfile="$(TargetPath)"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "esquirrel3_static - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "esquirrel3_static - Win32 Release"
# Name "esquirrel3_static - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\esquirrel3.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\esquirrel3.h
# End Source File
# End Group
# Begin Group "squirrel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\squirrel3\include\sqconfig.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\sqstdaux.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\sqstdblob.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\sqstdio.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\sqstdmath.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\sqstdstring.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\sqstdsystem.h
# End Source File
# Begin Source File

SOURCE=.\squirrel3\include\squirrel.h
# End Source File
# End Group
# End Target
# End Project
