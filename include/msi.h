/*
 * Copyright (C) 2002,2003 Mike McCormack
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_MSI_H
#define __WINE_MSI_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _MSI_NO_CRYPTO
#include <wincrypt.h>
#endif

typedef unsigned long MSIHANDLE;

typedef enum tagINSTALLSTATE
{
    INSTALLSTATE_NOTUSED = -7,
    INSTALLSTATE_BADCONFIG = -6,
    INSTALLSTATE_INCOMPLETE = -5,
    INSTALLSTATE_SOURCEABSENT = -4,
    INSTALLSTATE_MOREDATA = -3,
    INSTALLSTATE_INVALIDARG = -2,
    INSTALLSTATE_UNKNOWN = -1,
    INSTALLSTATE_BROKEN = 0,
    INSTALLSTATE_ADVERTISED = 1,
    INSTALLSTATE_ABSENT = 2,
    INSTALLSTATE_LOCAL = 3,
    INSTALLSTATE_SOURCE = 4,
    INSTALLSTATE_DEFAULT = 5
} INSTALLSTATE;

typedef enum tagINSTALLUILEVEL
{
    INSTALLUILEVEL_NOCHANGE = 0,
    INSTALLUILEVEL_DEFAULT = 1,
    INSTALLUILEVEL_NONE = 2,
    INSTALLUILEVEL_BASIC = 3,
    INSTALLUILEVEL_REDUCED = 4,
    INSTALLUILEVEL_FULL = 5,
    INSTALLUILEVEL_HIDECANCEL = 0x20,
    INSTALLUILEVEL_PROGRESSONLY = 0x40,
    INSTALLUILEVEL_ENDDIALOG = 0x80,
    INSTALLUILEVEL_SOURCERESONLY = 0x100
} INSTALLUILEVEL;

typedef enum tagUSERINFOSTATE
{
    USERINFOSTATE_MOREDATA = -3,
    USERINFOSTATE_INVALIDARG = -2,
    USERINFOSTATE_UNKNOWN = -1,
    USERINFOSTATE_ABSENT = 0,
    USERINFOSTATE_PRESENT = 1,
} USERINFOSTATE;

typedef enum tagINSTALLLEVEL
{
    INSTALLLEVEL_DEFAULT = 0,
    INSTALLLEVEL_MINIMUM = 1,
    INSTALLLEVEL_MAXIMUM = 0xFFFF
} INSTALLLEVEL;

typedef enum tagINSTALLMESSAGE
{
    INSTALLMESSAGE_FATALEXIT = 0,
    INSTALLMESSAGE_ERROR = 0x01000000,
    INSTALLMESSAGE_WARNING = 0x02000000,
    INSTALLMESSAGE_USER = 0x03000000,
    INSTALLMESSAGE_INFO = 0x04000000,
    INSTALLMESSAGE_FILESINUSE = 0x05000000,
    INSTALLMESSAGE_RESOLVESOURCE = 0x06000000,
    INSTALLMESSAGE_OUTOFDISKSPACE = 0x07000000,
    INSTALLMESSAGE_ACTIONSTART = 0x08000000,
    INSTALLMESSAGE_ACTIONDATA = 0x09000000,
    INSTALLMESSAGE_PROGRESS = 0x0a000000,
    INSTALLMESSAGE_COMMONDATA = 0x0b000000,
    INSTALLMESSAGE_INITIALIZE = 0x0c000000,
    INSTALLMESSAGE_TERMINATE = 0x0d000000,
    INSTALLMESSAGE_SHOWDIALOG = 0x0e000000
} INSTALLMESSAGE;

typedef enum tagREINSTALLMODE
{
    REINSTALLMODE_REPAIR = 0x00000001,
    REINSTALLMODE_FILEMISSING = 0x00000002,
    REINSTALLMODE_FILEOLDERVERSION = 0x00000004,
    REINSTALLMODE_FILEEQUALVERSION = 0x00000008,
    REINSTALLMODE_FILEEXACT = 0x00000010,
    REINSTALLMODE_FILEVERIFY = 0x00000020,
    REINSTALLMODE_FILEREPLACE = 0x00000040,
    REINSTALLMODE_MACHINEDATA = 0x00000080,
    REINSTALLMODE_USERDATA = 0x00000100,
    REINSTALLMODE_SHORTCUT = 0x00000200,
    REINSTALLMODE_PACKAGE = 0x00000400
} REINSTALLMODE;

typedef enum tagINSTALLLOGMODE
{
    INSTALLLOGMODE_FATALEXIT      = (1 << (INSTALLMESSAGE_FATALEXIT >> 24)),
    INSTALLLOGMODE_ERROR          = (1 << (INSTALLMESSAGE_ERROR >> 24)),
    INSTALLLOGMODE_WARNING        = (1 << (INSTALLMESSAGE_WARNING >> 24)),
    INSTALLLOGMODE_USER           = (1 << (INSTALLMESSAGE_USER >> 24)),
    INSTALLLOGMODE_INFO           = (1 << (INSTALLMESSAGE_INFO >> 24)),
    INSTALLLOGMODE_RESOLVESOURCE  = (1 << (INSTALLMESSAGE_RESOLVESOURCE >> 24)),
    INSTALLLOGMODE_OUTOFDISKSPACE = (1 << (INSTALLMESSAGE_OUTOFDISKSPACE >> 24)),
    INSTALLLOGMODE_ACTIONSTART    = (1 << (INSTALLMESSAGE_ACTIONSTART >> 24)),
    INSTALLLOGMODE_ACTIONDATA     = (1 << (INSTALLMESSAGE_ACTIONDATA >> 24)),
    INSTALLLOGMODE_COMMONDATA     = (1 << (INSTALLMESSAGE_COMMONDATA >> 24)),
    INSTALLLOGMODE_PROPERTYDUMP   = (1 << (INSTALLMESSAGE_PROGRESS >> 24)),
    INSTALLLOGMODE_VERBOSE        = (1 << (INSTALLMESSAGE_INITIALIZE >> 24)),
    INSTALLLOGMODE_EXTRADEBUG     = (1 << (INSTALLMESSAGE_TERMINATE >> 24)),
    INSTALLLOGMODE_PROGRESS       = (1 << (INSTALLMESSAGE_PROGRESS >> 24)),
    INSTALLLOGMODE_INITIALIZE     = (1 << (INSTALLMESSAGE_INITIALIZE >> 24)),
    INSTALLLOGMODE_TERMINATE      = (1 << (INSTALLMESSAGE_TERMINATE >> 24)),
    INSTALLLOGMODE_SHOWDIALOG     = (1 << (INSTALLMESSAGE_SHOWDIALOG >> 24))
} INSTALLLOGMODE;

typedef enum tagINSTALLLOGATTRIBUTES
{
    INSTALLLOGATTRIBUTES_APPEND = 0x00000001,
    INSTALLLOGATTRIBUTES_FLUSHEACHLINE = 0x00000002
} INSTALLLOGATTRIBUTES;

typedef enum tagINSTALLMODE
{
    INSTALLMODE_NODETECTION_ANY     = -4,
    INSTALLMODE_NOSOURCERESOLUTION  = -3,
    INSTALLMODE_NODETECTION         = -2,
    INSTALLMODE_EXISTING            = -1,
    INSTALLMODE_DEFAULT             = 0
} INSTALLMODE;

typedef enum tagADVERTISEFLAGS
{
    ADVERTISEFLAGS_MACHINEASSIGN = 0,
    ADVERTISEFLAGS_USERASSIGN = 1
} ADVERTISEFLAGS;

typedef enum tagSCRIPTFLAGS
{
    SCRIPTFLAGS_CACHEINFO = 1,
    SCRIPTFLAGS_SHORTCUTS = 4,
    SCRIPTFLAGS_MACHINEASSIGN = 8,
    SCRIPTFLAGS_REGDATA_APPINFO = 0x10,
    SCRIPTFLAGS_REGDATA_CNFGINFO = 0x20,
    SCRIPTFLAGS_VALIDATE_TRANSFORMS_LIST = 0x40,
    SCRIPTFLAGS_REGDATA_CLASSINFO = 0x80,
    SCRIPTFLAGS_REGDATA_EXTENSIONINFO = 0x100,
} SCRIPTFLAGS;

typedef enum tagINSTALLTYPE
{
    INSTALLTYPE_DEFAULT = 0,
    INSTALLTYPE_NETWORK_IMAGE = 1
} INSTALLTYPE;

typedef enum tagMSIINSTALLCONTEXT
{
    MSIINSTALLCONTEXT_FIRSTVISIBLE  =   0,
    MSIINSTALLCONTEXT_NONE          =   0,
    MSIINSTALLCONTEXT_USERMANAGED   =   1,
    MSIINSTALLCONTEXT_USERUNMANAGED =   2,
    MSIINSTALLCONTEXT_MACHINE       =   4,
    MSIINSTALLCONTEXT_ALL           = (MSIINSTALLCONTEXT_USERMANAGED | MSIINSTALLCONTEXT_USERUNMANAGED | MSIINSTALLCONTEXT_MACHINE),
    MSIINSTALLCONTEXT_ALLUSERMANAGED=   8,
} MSIINSTALLCONTEXT;

typedef enum tagMSISOURCETYPE
{
    MSISOURCETYPE_UNKNOWN = 0x00000000L,
    MSISOURCETYPE_NETWORK = 0x00000001L,
    MSISOURCETYPE_URL     = 0x00000002L,
    MSISOURCETYPE_MEDIA   = 0x00000004
} MSISOURCETYPE;

typedef enum tagMSICODE
{
    MSICODE_PRODUCT = 0x00000000L,
    MSICODE_PATCH = 0x40000000L
} MSICODE;

typedef struct _MSIFILEHASHINFO {
    ULONG dwFileHashInfoSize;
    ULONG dwData[4];
} MSIFILEHASHINFO, *PMSIFILEHASHINFO;

#define MAX_FEATURE_CHARS 38

/* Strings defined in msi.h */
/* Advertised Information */

#define INSTALLPROPERTY_PACKAGENAMEA "PackageName"
static const WCHAR INSTALLPROPERTY_PACKAGENAMEW[] = {'P','a','c','k','a','g','e','N','a','m','e',0};
#define INSTALLPROPERTY_PACKAGENAME WINELIB_NAME_AW(INSTALLPROPERTY_PACKAGENAME)

#define INSTALLPROPERTY_TRANSFORMSA "Transforms"
static const WCHAR INSTALLPROPERTY_TRANSFORMSW[] = {'T','r','a','n','s','f','o','r','m','s',0};
#define INSTALLPROPERTY_TRANSFORMS WINELIB_NAME_AW(INSTALLPROPERTY_TRANSFORMS)

#define INSTALLPROPERTY_LANGUAGEA "Language"
static const WCHAR INSTALLPROPERTY_LANGUAGEW[] = {'L','a','n','g','u','a','g','e',0};
#define INSTALLPROPERTY_LANGUAGE WINELIB_NAME_AW(INSTALLPROPERTY_LANGUAGE)

#define INSTALLPROPERTY_PRODUCTNAMEA "ProductName"
static const WCHAR INSTALLPROPERTY_PRODUCTNAMEW[] = {'P','r','o','d','u','c','t','N','a','m','e',0};
#define INSTALLPROPERTY_PRODUCTNAME WINELIB_NAME_AW(INSTALLPROPERTY_PRODUCTNAME)

#define INSTALLPROPERTY_ASSIGNMENTTYPEA "AssignmentType"
static const WCHAR INSTALLPROPERTY_ASSIGNMENTTYPEW[] = {'A','s','s','i','g','n','m','e','n','t','T','y','p','e',0};
#define INSTALLPROPERTY_ASSIGNMENTTYPE WINELIB_NAME_AW(INSTALLPROPERTY_ASSIGNMENTTYPE)

#define INSTALLPROPERTY_PACKAGECODEA "PackageCode"
static const WCHAR INSTALLPROPERTY_PACKAGECODEW[] = {'P','a','c','k','a','g','e','C','o','d','e',0};
#define INSTALLPROPERTY_PACKAGECODE WINELIB_NAME_AW(INSTALLPROPERTY_PACKAGECODE)

#define INSTALLPROPERTY_VERSIONA "Version"
static const WCHAR INSTALLPROPERTY_VERSIONW[]= {'V','e','r','s','i','o','n',0};
#define INSTALLPROPERTY_VERSION WINELIB_NAME_AW(INSTALLPROPERTY_VERSION)

/* MSI version 1.1 and above */

#define INSTALLPROPERTY_PRODUCTICONA "ProductIcon"
static const WCHAR INSTALLPROPERTY_PRODUCTICONW[]  = {'P','r','o','d','u','c','t','I','c','o','n',0};
#define INSTALLPROPERTY_PRODUCTICON WINELIB_NAME_AW(INSTALLPROPERTY_PRODUCTICON)

/* MSI version 1.5 and above */
#define INSTALLPROPERTY_INSTANCETYPEA "InstanceType"
static const WCHAR INSTALLPROPERTY_INSTANCETYPEW[] = {'I','n','s','t','a','n','c','e','T','y','p','e',0};
#define INSTALLPROPERTY_INSTANCETYPE WINELIB_NAME_AW(INSTALLPROPERTY_INSTANCETYPE)

/* MSI version 3 and above */
#define INSTALLPROPERTY_AUTHORIZED_LUA_APPA "AuthorizedLUAApp"
static const WCHAR INSTALLPROPERTY_AUTHORIZED_LUA_APPW[] = {'A','u','t','h','o','r','i','z','e','d','L','U','A','A','p','p',0};
#define INSTALLPROPERTY_AUTHORIZED_LUA_APP WINELIB_NAME_AW(INSTALLPROPERTY_AUTHORIZED_LUA_APP)


/* Installed Information */
#define INSTALLPROPERTY_INSTALLEDPRODUCTNAMEA "InstalledProductName"
static const WCHAR INSTALLPROPERTY_INSTALLEDPRODUCTNAMEW[] = {'I','n','s','t','a','l','l','e','d','P','r','o','d','u','c','t','N','a','m','e',0};
#define INSTALLPROPERTY_INSTALLEDPRODUCTNAME WINELIB_NAME_AW(INSTALLPROPERTY_INSTALLEDPRODUCTNAME)

#define INSTALLPROPERTY_VERSIONSTRINGA "VersionString"
static const WCHAR INSTALLPROPERTY_VERSIONSTRINGW[] = {'V','e','r','s','i','o','n','S','t','r','i','n','g',0};
#define INSTALLPROPERTY_VERSIONSTRING WINELIB_NAME_AW(INSTALLPROPERTY_VERSIONSTRING)

#define INSTALLPROPERTY_HELPLINKA "HelpLink"
static const WCHAR INSTALLPROPERTY_HELPLINKW[] = {'H','e','l','p','L','i','n','k',0};
#define INSTALLPROPERTY_HELPLINK WINELIB_NAME_AW(INSTALLPROPERTY_HELPLINK)

#define INSTALLPROPERTY_HELPTELEPHONEA "HelpTelephone"
static const WCHAR INSTALLPROPERTY_HELPTELEPHONEW[] = {'H','e','l','p','T','e','l','e','p','h','o','n','e',0};
#define INSTALLPROPERTY_HELPTELEPHONE WINELIB_NAME_AW(INSTALLPROPERTY_HELPTELEPHONE)

#define INSTALLPROPERTY_INSTALLLOCATIONA "InstallLocation"
static const WCHAR INSTALLPROPERTY_INSTALLLOCATIONW[] = {'I','n','s','t','a','l','l','L','o','c','a','t','i','o','n',0};
#define INSTALLPROPERTY_INSTALLLOCATION WINELIB_NAME_AW(INSTALLPROPERTY_INSTALLLOCATION)

#define INSTALLPROPERTY_INSTALLSOURCEA "InstallSource"
static const WCHAR INSTALLPROPERTY_INSTALLSOURCEW[] = {'I','n','s','t','a','l','l','S','o','u','r','c','e',0};
#define INSTALLPROPERTY_INSTALLSOURCE WINELIB_NAME_AW(INSTALLPROPERTY_INSTALLSOURCE)

#define INSTALLPROPERTY_INSTALLDATEA "InstallDate"
static const WCHAR INSTALLPROPERTY_INSTALLDATEW[] = {'I','n','s','t','a','l','l','D','a','t','e',0};
#define INSTALLPROPERTY_INSTALLDATE WINELIB_NAME_AW(INSTALLPROPERTY_INSTALLDATE)

#define INSTALLPROPERTY_PUBLISHERA "Publisher"
static const WCHAR INSTALLPROPERTY_PUBLISHERW[] ={'P','u','b','l','i','s','h','e','r',0};
#define INSTALLPROPERTY_PUBLISHER WINELIB_NAME_AW(INSTALLPROPERTY_PUBLISHER)

#define INSTALLPROPERTY_LOCALPACKAGEA "LocalPackage"
static const WCHAR INSTALLPROPERTY_LOCALPACKAGEW[] = {'L','o','c','a','l','P','a','c','k','a','g','e',0};
#define INSTALLPROPERTY_LOCALPACKAGE WINELIB_NAME_AW(INSTALLPROPERTY_LOCALPACKAGE)

#define INSTALLPROPERTY_URLINFOABOUTA "URLInfoAbout"
static const WCHAR INSTALLPROPERTY_URLINFOABOUTW[] = {'U','R','L','I','n','f','o','A','b','o','u','t',0};
#define INSTALLPROPERTY_URLINFOABOUT WINELIB_NAME_AW(INSTALLPROPERTY_URLINFOABOUT)

#define INSTALLPROPERTY_URLUPDATEINFOA "URLUpdateInfo"
static const WCHAR INSTALLPROPERTY_URLUPDATEINFOW[] = {'U','R','L','U','p','d','a','t','e','I','n','f','o',0};
#define INSTALLPROPERTY_URLUPDATEINFO WINELIB_NAME_AW(INSTALLPROPERTY_URLUPDATEINFO)

#define INSTALLPROPERTY_VERSIONMINORA "VersionMinor"
static const WCHAR INSTALLPROPERTY_VERSIONMINORW[] = {'V','e','r','s','i','o','n','M','i','n','o','r',0};
#define INSTALLPROPERTY_VERSIONMINOR WINELIB_NAME_AW(INSTALLPROPERTY_VERSIONMINOR)

#define INSTALLPROPERTY_VERSIONMAJORA "VersionMajor"
static const WCHAR INSTALLPROPERTY_VERSIONMAJORW[] = {'V','e','r','s','i','o','n','M','a','j','o','r',0};
#define INSTALLPROPERTY_VERSIONMAJOR WINELIB_NAME_AW(INSTALLPROPERTY_VERSIONMAJOR)

#define INSTALLPROPERTY_PRODUCTIDA "ProductID"
static const WCHAR INSTALLPROPERTY_PRODUCTIDW[] = {'P','r','o','d','u','c','t','I','D',0};
#define INSTALLPROPERTY_PRODUCTID WINELIB_NAME_AW(INSTALLPROPERTY_PRODUCTID)

#define INSTALLPROPERTY_REGCOMPANYA "RegCompany"
static const WCHAR INSTALLPROPERTY_REGCOMPANYW[] = {'R','e','g','C','o','m','p','a','n','y',0};
#define INSTALLPROPERTY_REGCOMPANY WINELIB_NAME_AW(INSTALLPROPERTY_REGCOMPANY)

#define INSTALLPROPERTY_REGOWNERA "RegOwner"
static const WCHAR INSTALLPROPERTY_REGOWNERW[] = {'R','e','g','O','w','n','e','r',0};
#define INSTALLPROPERTY_REGOWNER WINELIB_NAME_AW(INSTALLPROPERTY_REGOWNER)

/* MSI Version 3.0 and greater */
#define INSTALLPROPERTY_UNINSTALLABLEA "Uninstallable"
static const WCHAR INSTALLPROPERTY_UNINSTALLABLEW[] = {'U','n','i','n','s','t','a','l','l','a','b','l','e',0};
#define INSTALLPROPERTY_UNINSTALLABLE WINELIB_NAME_AW(INSTALLPROPERTY_UNINSTALLABLE)

#define INSTALLPROPERTY_PRODUCTSTATEA "State"
static const WCHAR INSTALLPROPERTY_PRODUCTSTATEW[] = {'S','t','a','t','e',0};
#define INSTALLPROPERTY_PRODUCTSTATE WINELIB_NAME_AW(INSTALLPROPERTY_PRODUCTSTATE)

#define INSTALLPROPERTY_PATCHSTATEA "State"
static const WCHAR INSTALLPROPERTY_PATCHSTATEW[] ={'S','t','a','t','e',0};
#define INSTALLPROPERTY_PATCHSTATE WINELIB_NAME_AW(INSTALLPROPERTY_PATCHSTATE)

#define INSTALLPROPERTY_PATCHTYPEA "PatchType"
static const WCHAR INSTALLPROPERTY_PATCHTYPEW[] = {'P','a','t','c','h','T','y','p','e',0};
#define INSTALLPROPERTY_PATCHTYPE WINELIB_NAME_AW(INSTALLPROPERTY_PATCHTYPE)

#define INSTALLPROPERTY_LUAENABLEDA "LUAEnabled"
static const WCHAR INSTALLPROPERTY_LUAENABLEDW[] = {'L','U','A','E','n','a','b','l','e','d',0};
#define INSTALLPROPERTY_LUAENABLED WINELIB_NAME_AW(INSTALLPROPERTY_LUAENABLED)

#define INSTALLPROPERTY_DISPLAYNAMEA "DisplayName"
static const WCHAR INSTALLPROPERTY_DISPLAYNAMEW[] = {'D','i','s','p','l','a','y','N','a','m','e',0};
#define INSTALLPROPERTY_DISPLAYNAME WINELIB_NAME_AW(INSTALLPROPERTY_DISPLAYNAME)

#define INSTALLPROPERTY_MOREINFOURLA "MoreInfoURL"
static const WCHAR INSTALLPROPERTY_MOREINFOURLW[] = {'M','o','r','e','I','n','f','o','U','R','L',0};
#define INSTALLPROPERTY_MOREINFOURL WINELIB_NAME_AW(INSTALLPROPERTY_MOREINFOURL)

/* Source List Info */
#define INSTALLPROPERTY_LASTUSEDSOURCEA "LastUsedSource"
static const WCHAR INSTALLPROPERTY_LASTUSEDSOURCEW[] = {'L','a','s','t','U','s','e','d','S','o','u','r','c','e',0};
#define INSTALLPROPERTY_LASTUSEDSOURCE WINELIB_NAME_AW(INSTALLPROPERTY_LASTUSEDSOURCEW)

#define INSTALLPROPERTY_LASTUSEDTYPEA "LastUsedType"
static const WCHAR INSTALLPROPERTY_LASTUSEDTYPEW[] = {'L','a','s','t','U','s','e','d','T','y','p','e',0};
#define INSTALLPROPERTY_LASTUSEDTYPE WINELIB_NAME_AW(INSTALLPROPERTY_LASTUSEDTYPE)

#define INSTALLPROPERTY_MEDIAPACKAGEPATHA "MediaPackagePath"
static const WCHAR INSTALLPROPERTY_MEDIAPACKAGEPATHW[] = {'M','e','d','i','a','P','a','c','k','a','g','e','P','a','t','h',0};
#define INSTALLPROPERTY_MEDIAPACKAGEPATH WINELIB_NAME_AW(INSTALLPROPERTY_MEDIAPACKAGEPATH)

#define INSTALLPROPERTY_DISKPROMPTA "DiskPrompt"
static const WCHAR INSTALLPROPERTY_DISKPROMPTW[] = {'D','i','s','k','P','r','o','m','p','t',0};
#define INSTALLPROPERTY_DISKPROMPT WINELIB_NAME_AW(INSTALLPROPERTY_DISKPROMPT)

typedef INT (CALLBACK *INSTALLUI_HANDLERA)(LPVOID, UINT, LPCSTR);
typedef INT (CALLBACK *INSTALLUI_HANDLERW)(LPVOID, UINT, LPCWSTR);

UINT WINAPI MsiAdvertiseProductA(LPCSTR, LPCSTR, LPCSTR, LANGID);
UINT WINAPI MsiAdvertiseProductW(LPCWSTR, LPCWSTR, LPCWSTR, LANGID);
#define     MsiAdvertiseProduct WINELIB_NAME_AW(MsiAdvertiseProduct)

UINT WINAPI MsiAdvertiseProductExA(LPCSTR, LPCSTR, LPCSTR, LANGID, DWORD, DWORD);
UINT WINAPI MsiAdvertiseProductExW(LPCWSTR, LPCWSTR, LPCWSTR, LANGID, DWORD, DWORD);
#define     MsiAdvertiseProductEx WINELIB_NAME_AW(MsiAdvertiseProductEx)

UINT WINAPI MsiInstallProductA(LPCSTR, LPCSTR);
UINT WINAPI MsiInstallProductW(LPCWSTR, LPCWSTR);
#define     MsiInstallProduct WINELIB_NAME_AW(MsiInstallProduct)

UINT WINAPI MsiReinstallProductA(LPCSTR, DWORD);
UINT WINAPI MsiReinstallProductW(LPCWSTR, DWORD);
#define     MsiReinstallProduct WINELIB_NAME_AW(MsiReinstallProduct)

UINT WINAPI MsiApplyPatchA(LPCSTR, LPCSTR, INSTALLTYPE, LPCSTR);
UINT WINAPI MsiApplyPatchW(LPCWSTR, LPCWSTR, INSTALLTYPE, LPCWSTR);
#define     MsiApplyPatch WINELIB_NAME_AW(MsiApplyPatch)

UINT WINAPI MsiEnumProductsA(DWORD, LPSTR);
UINT WINAPI MsiEnumProductsW(DWORD, LPWSTR);
#define     MsiEnumProducts WINELIB_NAME_AW(MsiEnumProducts)

UINT WINAPI MsiEnumFeaturesA(LPCSTR, DWORD, LPSTR, LPSTR);
UINT WINAPI MsiEnumFeaturesW(LPCWSTR, DWORD, LPWSTR, LPWSTR);
#define     MsiEnumFeatures WINELIB_NAME_AW(MsiEnumFeatures)

UINT WINAPI MsiEnumComponentsA(DWORD, LPSTR);
UINT WINAPI MsiEnumComponentsW(DWORD, LPWSTR);
#define     MsiEnumComponents WINELIB_NAME_AW(MsiEnumComponents)

UINT WINAPI MsiEnumClientsA(LPCSTR, DWORD, LPSTR);
UINT WINAPI MsiEnumClientsW(LPCWSTR, DWORD, LPWSTR);
#define     MsiEnumClients WINELIB_NAME_AW(MsiEnumClients)

UINT WINAPI MsiOpenPackageA(LPCSTR, MSIHANDLE*);
UINT WINAPI MsiOpenPackageW(LPCWSTR, MSIHANDLE*);
#define     MsiOpenPackage WINELIB_NAME_AW(MsiOpenPackage)

UINT WINAPI MsiOpenPackageExA(LPCSTR, DWORD, MSIHANDLE*);
UINT WINAPI MsiOpenPackageExW(LPCWSTR, DWORD, MSIHANDLE*);
#define     MsiOpenPackageEx WINELIB_NAME_AW(MsiOpenPackageEx)

UINT WINAPI MsiOpenProductA(LPCSTR, MSIHANDLE*);
UINT WINAPI MsiOpenProductW(LPCWSTR, MSIHANDLE*);
#define     MsiOpenProduct WINELIB_NAME_AW(MsiOpenProduct)

UINT WINAPI MsiProvideComponentFromDescriptorA(LPCSTR,LPSTR,DWORD*,DWORD*);
UINT WINAPI MsiProvideComponentFromDescriptorW(LPCWSTR,LPWSTR,DWORD*,DWORD*);
#define     MsiProvideComponentFromDescriptor WINELIB_NAME_AW(MsiProvideComponentFromDescriptor)

UINT WINAPI MsiGetProductPropertyA(MSIHANDLE,LPCSTR,LPSTR,DWORD*);
UINT WINAPI MsiGetProductPropertyW(MSIHANDLE,LPCWSTR,LPWSTR,DWORD*);
#define     MsiGetProductProperty WINELIB_NAME_AW(MsiGetProductProperty)

UINT WINAPI MsiVerifyPackageA(LPCSTR);
UINT WINAPI MsiVerifyPackageW(LPCWSTR);
#define     MsiVerifyPackage WINELIB_NAME_AW(MsiVerifyPackage)

INSTALLSTATE WINAPI MsiQueryProductStateA(LPCSTR);
INSTALLSTATE WINAPI MsiQueryProductStateW(LPCWSTR);
#define      MsiQueryProductState WINELIB_NAME_AW(MsiQueryProductState)

UINT WINAPI MsiConfigureProductA(LPCSTR, int, INSTALLSTATE);
UINT WINAPI MsiConfigureProductW(LPCWSTR, int, INSTALLSTATE);
#define     MsiConfigureProduct WINELIB_NAME_AW(MsiConfigureProduct);

UINT WINAPI MsiConfigureProductExA(LPCSTR, int, INSTALLSTATE, LPCSTR);
UINT WINAPI MsiConfigureProductExW(LPCWSTR, int, INSTALLSTATE, LPCWSTR);
#define     MsiConfigureProductEx WINELIB_NAME_AW(MsiConfigureProductEx);

UINT WINAPI MsiConfigureFeatureA(LPCSTR, LPCSTR, INSTALLSTATE);
UINT WINAPI MsiConfigureFeatureW(LPCWSTR, LPCWSTR, INSTALLSTATE);
#define     MsiConfigureFeature WINELIB_NAME_AW(MsiConfigureFeature);

UINT WINAPI MsiGetProductCodeA(LPCSTR, LPSTR);
UINT WINAPI MsiGetProductCodeW(LPCWSTR, LPWSTR);
#define     MsiGetProductCode WINELIB_NAME_AW(MsiGetProductCode)

UINT WINAPI MsiGetProductInfoA(LPCSTR, LPCSTR, LPSTR, DWORD *);
UINT WINAPI MsiGetProductInfoW(LPCWSTR, LPCWSTR, LPWSTR, DWORD *);
#define     MsiGetProductInfo WINELIB_NAME_AW(MsiGetProductInfo)

UINT WINAPI MsiEnableLogA(DWORD, LPCSTR, DWORD);
UINT WINAPI MsiEnableLogW(DWORD, LPCWSTR, DWORD);
#define     MsiEnableLog WINELIB_NAME_AW(MsiEnableLog)

INSTALLUI_HANDLERA WINAPI MsiSetExternalUIA(INSTALLUI_HANDLERA, DWORD, LPVOID);
INSTALLUI_HANDLERW WINAPI MsiSetExternalUIW(INSTALLUI_HANDLERW, DWORD, LPVOID);
#define MsiSetExternalUI WINELIB_NAME_AW(MsiSetExternalUI)

INSTALLSTATE WINAPI MsiGetComponentPathA(LPCSTR, LPCSTR, LPSTR, DWORD*);
INSTALLSTATE WINAPI MsiGetComponentPathW(LPCWSTR, LPCWSTR, LPWSTR, DWORD*);
#define MsiGetComponentPath WINELIB_NAME_AW(MsiGetComponentPath)

INSTALLSTATE WINAPI MsiQueryFeatureStateA(LPCSTR, LPCSTR);
INSTALLSTATE WINAPI MsiQueryFeatureStateW(LPCWSTR, LPCWSTR);
#define MsiQueryFeatureState WINELIB_NAME_AW(MsiQueryFeatureState)

UINT WINAPI MsiGetFeatureUsageA(LPCSTR, LPCSTR, DWORD*, WORD*);
UINT WINAPI MsiGetFeatureUsageW(LPCWSTR, LPCWSTR, DWORD*, WORD*);
#define MsiGetFeatureUsage WINELIB_NAME_AW(MsiGetFeatureUsage)

UINT WINAPI MsiEnumRelatedProductsA(LPCSTR, DWORD, DWORD, LPSTR);
UINT WINAPI MsiEnumRelatedProductsW(LPCWSTR, DWORD, DWORD, LPWSTR);
#define MsiEnumRelatedProducts WINELIB_NAME_AW(MsiEnumRelatedProducts)

UINT WINAPI MsiProvideAssemblyA(LPCSTR, LPCSTR, DWORD, DWORD, LPSTR, DWORD*);
UINT WINAPI MsiProvideAssemblyW(LPCWSTR, LPCWSTR, DWORD, DWORD, LPWSTR, DWORD*);
#define MsiProvideAssembly WINELIB_NAME_AW(MsiProvideAssembly)

UINT WINAPI MsiEnumComponentQualifiersA(LPCSTR, DWORD, LPSTR, DWORD*, LPSTR, DWORD*);
UINT WINAPI MsiEnumComponentQualifiersW(LPCWSTR, DWORD, LPWSTR, DWORD*, LPWSTR, DWORD*);
#define MsiEnumComponentQualifiers WINELIB_NAME_AW(MsiEnumComponentQualifiers)

UINT WINAPI MsiGetFileVersionA(LPCSTR, LPSTR, DWORD*, LPSTR, DWORD*);
UINT WINAPI MsiGetFileVersionW(LPCWSTR, LPWSTR, DWORD*, LPWSTR, DWORD*);
#define MsiGetFileVersion WINELIB_NAME_AW(MsiGetFileVersion)

UINT WINAPI MsiMessageBoxA(HWND, LPCSTR, LPCSTR, UINT, WORD, DWORD);
UINT WINAPI MsiMessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT, WORD, DWORD);
#define MsiMessageBox WINELIB_NAME_AW(MsiMessageBox)

UINT WINAPI MsiProvideQualifiedComponentExA(LPCSTR, LPCSTR, DWORD, LPSTR, DWORD, DWORD, LPSTR, DWORD*);
UINT WINAPI MsiProvideQualifiedComponentExW(LPCWSTR, LPCWSTR, DWORD, LPWSTR, DWORD, DWORD, LPWSTR, DWORD*);
#define MsiProvideQualifiedComponentEx WINELIB_NAME_AW(MsiProvideQualifiedComponentEx)

UINT WINAPI MsiProvideQualifiedComponentA(LPCSTR, LPCSTR, DWORD, LPSTR, DWORD*);
UINT WINAPI MsiProvideQualifiedComponentW(LPCWSTR, LPCWSTR, DWORD, LPWSTR, DWORD*);
#define MsiProvideQualifiedComponent WINELIB_NAME_AW(MsiProvideQualifiedComponent)

USERINFOSTATE WINAPI MsiGetUserInfoA(LPCSTR, LPSTR, DWORD*, LPSTR, DWORD*, LPSTR, DWORD*);
USERINFOSTATE WINAPI MsiGetUserInfoW(LPCWSTR, LPWSTR, DWORD*, LPWSTR, DWORD*, LPWSTR, DWORD*);
#define MsiGetUserInfo WINELIB_NAME_AW(MsiGetUserInfo)

UINT WINAPI MsiCollectUserInfoA(LPCSTR);
UINT WINAPI MsiCollectUserInfoW(LPCWSTR);
#define MsiCollectUserInfo WINELIB_NAME_AW(MsiCollectUserInfo)

UINT WINAPI MsiReinstallFeatureA(LPCSTR, LPCSTR, DWORD);
UINT WINAPI MsiReinstallFeatureW(LPCWSTR, LPCWSTR, DWORD);
#define MsiReinstallFeature WINELIB_NAME_AW(MsiReinstallFeature)

UINT WINAPI MsiGetShortcutTargetA(LPCSTR, LPSTR, LPSTR, LPSTR);
UINT WINAPI MsiGetShortcutTargetW(LPCWSTR, LPWSTR, LPWSTR, LPWSTR);
#define MsiGetShortcutTarget WINELIB_NAME_AW(MsiGetShortcutTarget)

INSTALLSTATE WINAPI MsiUseFeatureW(LPCWSTR, LPCWSTR);
INSTALLSTATE WINAPI MsiUseFeatureA(LPCSTR, LPCSTR);
#define MsiUseFeature WINELIB_NAME_AW(MsiUseFeature)

INSTALLSTATE WINAPI MsiUseFeatureExW(LPCWSTR, LPCWSTR, DWORD, DWORD);
INSTALLSTATE WINAPI MsiUseFeatureExA(LPCSTR, LPCSTR, DWORD, DWORD);
#define MsiUseFeatureEx WINELIB_NAME_AW(MsiUseFeatureEx)

HRESULT WINAPI MsiGetFileSignatureInformationA(LPCSTR, DWORD, PCCERT_CONTEXT*, BYTE*, DWORD*);
HRESULT WINAPI MsiGetFileSignatureInformationW(LPCWSTR, DWORD, PCCERT_CONTEXT*, BYTE*, DWORD*);
#define MsiGetFileSignatureInformation WINELIB_NAME_AW(MsiGetFileSignatureInformation)

INSTALLSTATE WINAPI MsiLocateComponentA(LPCSTR, LPSTR, DWORD *);
INSTALLSTATE WINAPI MsiLocateComponentW(LPCWSTR, LPWSTR, DWORD *);
#define  MsiLocateComponent WINELIB_NAME_AW(MsiLocateComponent)

UINT WINAPI MsiSourceListAddSourceA(LPCSTR, LPCSTR, DWORD, LPCSTR);
UINT WINAPI MsiSourceListAddSourceW(LPCWSTR, LPCWSTR, DWORD, LPCWSTR);
#define     MsiSourceListAddSource WINELIB_NAME_AW(MsiSourceListAddSource)

UINT WINAPI MsiSourceListClearAllA(LPCSTR, LPCSTR, DWORD);
UINT WINAPI MsiSourceListClearAllW(LPCWSTR, LPCWSTR, DWORD);
#define     MsiSourceListClearAll WINELIB_NAME_AW(MsiSourceListClearAll)

UINT WINAPI MsiSourceListGetInfoA(LPCSTR, LPCSTR, MSIINSTALLCONTEXT, DWORD, LPCSTR, LPSTR, LPDWORD);
UINT WINAPI MsiSourceListGetInfoW(LPCWSTR, LPCWSTR, MSIINSTALLCONTEXT, DWORD, LPCWSTR, LPWSTR, LPDWORD);
#define     MsiSourceListGetInfo WINELIB_NAME_AW(MsiSourceListGetInfo)

UINT WINAPI MsiSourceListSetInfoA(LPCSTR, LPCSTR, MSIINSTALLCONTEXT, DWORD, LPCSTR, LPCSTR);
UINT WINAPI MsiSourceListSetInfoW(LPCWSTR, LPCWSTR, MSIINSTALLCONTEXT, DWORD, LPCWSTR, LPCWSTR);
#define     MsiSourceListSetInfo WINELIB_NAME_AW(MsiSourceListSetInfo)

UINT WINAPI MsiSourceListAddSourceExA(LPCSTR, LPCSTR, MSIINSTALLCONTEXT, DWORD, LPCSTR, DWORD);
UINT WINAPI MsiSourceListAddSourceExW(LPCWSTR, LPCWSTR, MSIINSTALLCONTEXT, DWORD, LPCWSTR, DWORD);
#define     MsiSourceListAddSourceEx WINELIB_NAME_AW(MsiSourceListAddSourceEx)

UINT WINAPI MsiSourceListAddMediaDiskA(LPCSTR, LPCSTR, MSIINSTALLCONTEXT, DWORD, DWORD, LPCSTR, LPCSTR);
UINT WINAPI MsiSourceListAddMediaDiskW(LPCWSTR, LPCWSTR, MSIINSTALLCONTEXT, DWORD, DWORD, LPCWSTR, LPCWSTR);
#define     MsiSourceListAddMediaDisk WINELIB_NAME_AW(MsiSourceListAddMediaDisk)

UINT WINAPI MsiEnumPatchesA(LPCSTR, DWORD, LPSTR, LPSTR, DWORD*);
UINT WINAPI MsiEnumPatchesW(LPCWSTR, DWORD, LPWSTR, LPWSTR, DWORD*);
#define     MsiEnumPatches WINELIB_NAME_AW(MsiEnumPatches)

UINT WINAPI MsiGetFileHashA(LPCSTR, DWORD, PMSIFILEHASHINFO);
UINT WINAPI MsiGetFileHashW(LPCWSTR, DWORD, PMSIFILEHASHINFO);
#define     MsiGetFileHash WINELIB_NAME_AW(MsiGetFileHash)

UINT WINAPI MsiAdvertiseScriptA(LPCSTR, DWORD, PHKEY, BOOL);
UINT WINAPI MsiAdvertiseScriptW(LPCWSTR, DWORD, PHKEY, BOOL);
#define     MsiAdvertiseScript WINELIB_NAME_AW(MsiAdvertiseScript)

/* Non Unicode */
UINT WINAPI MsiCloseHandle(MSIHANDLE);
UINT WINAPI MsiCloseAllHandles(void);
INSTALLUILEVEL WINAPI MsiSetInternalUI(INSTALLUILEVEL, HWND*);

#ifdef __cplusplus
}
#endif

#endif /* __WINE_MSI_H */
