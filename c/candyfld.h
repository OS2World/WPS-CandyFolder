
/*
 * This file was generated by the SOM Compiler.
 * FileName: candyfld.h.
 * Generated using:
 *     SOM Precompiler somipc: 2.29.1.7
 *     SOM Emitter emith: 2.42
 */

/*
 * 
 * CandyFld.idl:
 * 
 * This file is (C) Chris Wohlgemuth 2001
 * It is part of the CandyFolder package
 * 
 * Visit
 * 
 * http://candybarz.netlabs.org
 * 
 * or
 * 
 * http://www.geocities.com/SiliconValley/Sector/5785/
 * 
 * for more information
 * 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#ifndef SOM_CandyFolder_h
#define SOM_CandyFolder_h


#include <som.h>

/*
 * -- This emitter treats Method Tokens as Thunks by default.
 * -- Use the sc modifier "nothunks" to change this default
 */
#undef somresolve_
#define somresolve_(obj,mToken) ((somMethodProc*)((void)obj, mToken))

/*
 * Define the class name as an object type
 */
#ifndef CandyFolder
#define CandyFolder SOMObject
#endif
#include <wpfolder.h>

/*
 * Start of user-defined types:
 */
#ifndef SOMClass
    #define SOMClass SOMObject
#endif /* SOMClass */
#ifndef WPFolder
    #define WPFolder SOMObject
#endif /* WPFolder */
#ifndef M_WPObject
    #define M_WPObject SOMObject
#endif /* M_WPObject */
#ifndef WPObject
    #define WPObject SOMObject
#endif /* WPObject */
#ifndef M_WPFileSystem
    #define M_WPFileSystem SOMObject
#endif /* M_WPFileSystem */
#ifndef M_WPFolder
    #define M_WPFolder SOMObject
#endif /* M_WPFolder */
#ifndef M_CandyFolder
    #define M_CandyFolder SOMObject
#endif /* M_CandyFolder */

/*
 * End of user-defined types.
 */

#define CandyFolder_MajorVersion 1
#define CandyFolder_MinorVersion 1

/*
 * External name shortening if required
 */
#ifdef SOM_USE_SHORT_EXTERNAL_NAMES
#define CandyFolderNewClass candyfolderc
#pragma linkage(candyfolderc, system)
#define CandyFolderClassData candyfolderd
#define CandyFolderCClassData candyfolderx
#endif /* SOM_USE_SHORT_EXTERNAL_NAMES */

/*
 * Include the meta class file
 */
#include <candyfld.h>
/*--------------Migration------------*/
#define CandyFolder_classObj CandyFolderClassData.classObject
#define _CandyFolder CandyFolder_classObj

/*
 * Declare the class creation procedure
 */
SOMEXTERN SOMClass * SOMLINK CandyFolderNewClass(integer4 somtmajorVersion,
		integer4 somtminorVersion);
#pragma linkage(CandyFolderNewClass, system)

/*
 * Declare the class data structure
 */
SOMEXTERN struct CandyFolderClassDataStructure {
	SOMClass *classObject;
	somMToken cfRefreshContainerBackgrounds;
} SOMDLINK CandyFolderClassData;

/*
 * Declare the C specific class data structure
 */
SOMEXTERN struct CandyFolderCClassDataStructure {
	somMethodTabs parentMtab;
	somDToken instanceDataToken;
} SOMDLINK CandyFolderCClassData;

/*
 * New and Renew macros for CandyFolder
 */
#define CandyFolderNew() \
   (_somNew(_CandyFolder ? _CandyFolder : CandyFolderNewClass(CandyFolder_MajorVersion, CandyFolder_MinorVersion)))
#define CandyFolderRenew(buf) \
   (_somRenew(_CandyFolder ? _CandyFolder : CandyFolderNewClass(CandyFolder_MajorVersion, CandyFolder_MinorVersion), buf))

/*
 * Override method: wpAddFolderBackgroundPage
 */
#define CandyFolder_wpAddFolderBackgroundPage(somSelf,hwndNotebook) \
	WPFolder_wpAddFolderBackgroundPage(somSelf,hwndNotebook)

/*
 * Override method: wpOpen
 */
#define CandyFolder_wpOpen(somSelf,hwndCnr,ulView,param) \
	WPObject_wpOpen(somSelf,hwndCnr,ulView,param)

/*
 * Override method: wpDeleteFromObjUseList
 */
#define CandyFolder_wpDeleteFromObjUseList(somSelf,pUseItem) \
	WPObject_wpDeleteFromObjUseList(somSelf,pUseItem)

/*
 * Override method: wpSaveState
 */
#define CandyFolder_wpSaveState(somSelf) \
	WPObject_wpSaveState(somSelf)

/*
 * Override method: wpRestoreState
 */
#define CandyFolder_wpRestoreState(somSelf,ulReserved) \
	WPObject_wpRestoreState(somSelf,ulReserved)

/*
 * Override method: wpSaveString
 */
#define CandyFolder_wpSaveString(somSelf,pszClass,ulKey,pszValue) \
	WPObject_wpSaveString(somSelf,pszClass,ulKey,pszValue)

/*
 * Override method: wpRestoreString
 */
#define CandyFolder_wpRestoreString(somSelf,pszClass,ulKey,pszValue,pcbValue) \
	WPObject_wpRestoreString(somSelf,pszClass,ulKey,pszValue,pcbValue)

/*
 * Override method: wpSetup
 */
#define CandyFolder_wpSetup(somSelf,pszSetupString) \
	WPObject_wpSetup(somSelf,pszSetupString)

/*
 * New Method: cfRefreshContainerBackgrounds
 */
typedef void   SOMLINK somTP_CandyFolder_cfRefreshContainerBackgrounds(CandyFolder *somSelf,
		BOOL bColorChange);
#pragma linkage(somTP_CandyFolder_cfRefreshContainerBackgrounds, system)
typedef somTP_CandyFolder_cfRefreshContainerBackgrounds *somTD_CandyFolder_cfRefreshContainerBackgrounds;
#define somMD_CandyFolder_cfRefreshContainerBackgrounds "::CandyFolder::cfRefreshContainerBackgrounds"
#define CandyFolder_cfRefreshContainerBackgrounds(somSelf,bColorChange) \
    (SOM_Resolve(somSelf, CandyFolder, cfRefreshContainerBackgrounds) \
	(somSelf,bColorChange))
#ifndef SOMGD_cfRefreshContainerBackgrounds
    #if (defined(_cfRefreshContainerBackgrounds) || defined(__cfRefreshContainerBackgrounds))
        #undef _cfRefreshContainerBackgrounds
        #undef __cfRefreshContainerBackgrounds
        #define SOMGD_cfRefreshContainerBackgrounds 1
    #else
        #define _cfRefreshContainerBackgrounds CandyFolder_cfRefreshContainerBackgrounds
    #endif /* _cfRefreshContainerBackgrounds */
#endif /* SOMGD_cfRefreshContainerBackgrounds */
#ifndef SOM_DONT_USE_INHERITED_MACROS
#define CandyFolder_wpSetFldrFlags WPFolder_wpSetFldrFlags
#define CandyFolder_wpQueryFldrFlags WPFolder_wpQueryFldrFlags
#define CandyFolder_wpSetFldrFont WPFolder_wpSetFldrFont
#define CandyFolder_wpQueryFldrFont WPFolder_wpQueryFldrFont
#define CandyFolder_wpSetFldrAttr WPFolder_wpSetFldrAttr
#define CandyFolder_wpQueryFldrAttr WPFolder_wpQueryFldrAttr
#define CandyFolder_wpSetNextIconPos WPFolder_wpSetNextIconPos
#define CandyFolder_wpQueryNextIconPos WPFolder_wpQueryNextIconPos
#define CandyFolder_wpPopulate WPFolder_wpPopulate
#define CandyFolder_wpQueryContent WPFolder_wpQueryContent
#define CandyFolder_wpAddFolderView1Page WPFolder_wpAddFolderView1Page
#define CandyFolder_wpAddFolderView2Page WPFolder_wpAddFolderView2Page
#define CandyFolder_wpAddFolderView3Page WPFolder_wpAddFolderView3Page
#define CandyFolder_wpAddFolderIncludePage WPFolder_wpAddFolderIncludePage
#define CandyFolder_wpAddFolderSortPage WPFolder_wpAddFolderSortPage
#define CandyFolder_wpAddFolderSelfClosePage WPFolder_wpAddFolderSelfClosePage
#define CandyFolder_wpInitIconPosData WPFolder_wpInitIconPosData
#define CandyFolder_wpFreeIconPosData WPFolder_wpFreeIconPosData
#define CandyFolder_wpStoreIconPosData WPFolder_wpStoreIconPosData
#define CandyFolder_wpQueryIconPosition WPFolder_wpQueryIconPosition
#define CandyFolder_wpSetFldrSort WPFolder_wpSetFldrSort
#define CandyFolder_wpQueryFldrSort WPFolder_wpQueryFldrSort
#define CandyFolder_wpRestoreFldrRunObjs WPFolder_wpRestoreFldrRunObjs
#define CandyFolder_wpStoreFldrRunObjs WPFolder_wpStoreFldrRunObjs
#define CandyFolder_wpHideFldrRunObjs WPFolder_wpHideFldrRunObjs
#define CandyFolder_wpDeleteContents WPFolder_wpDeleteContents
#define CandyFolder_wpSetFldrDetailsClass WPFolder_wpSetFldrDetailsClass
#define CandyFolder_wpQueryFldrDetailsClass WPFolder_wpQueryFldrDetailsClass
#define CandyFolder_wpSearchFolder WPFolder_wpSearchFolder
#define CandyFolder_wpContainsFolders WPFolder_wpContainsFolders
#define CandyFolder_wpQueryOpenFolders WPFolder_wpQueryOpenFolders
#define CandyFolder_wpModifyFldrFlags WPFolder_wpModifyFldrFlags
#define CandyFolder_wpAddToContent WPFolder_wpAddToContent
#define CandyFolder_wpDeleteFromContent WPFolder_wpDeleteFromContent
#define CandyFolder_wpSetDetailsColumnVisibility WPFolder_wpSetDetailsColumnVisibility
#define CandyFolder_wpIsDetailsColumnVisible WPFolder_wpIsDetailsColumnVisible
#define CandyFolder_wpSetFldrSortClass WPFolder_wpSetFldrSortClass
#define CandyFolder_wpQueryFldrSortClass WPFolder_wpQueryFldrSortClass
#define CandyFolder_wpSetSortAttribAvailable WPFolder_wpSetSortAttribAvailable
#define CandyFolder_wpIsSortAttribAvailable WPFolder_wpIsSortAttribAvailable
#define CandyFolder_wpQueryIconViewPos WPFolder_wpQueryIconViewPos
#define CandyFolder_wpAddFirstChild WPFolder_wpAddFirstChild
#define CandyFolder_wpSetRealName WPFileSystem_wpSetRealName
#define CandyFolder_wpSetType WPFileSystem_wpSetType
#define CandyFolder_wpQueryType WPFileSystem_wpQueryType
#define CandyFolder_wpSetAttr WPFileSystem_wpSetAttr
#define CandyFolder_wpQueryAttr WPFileSystem_wpQueryAttr
#define CandyFolder_wpAddFile1Page WPFileSystem_wpAddFile1Page
#define CandyFolder_wpAddFile2Page WPFileSystem_wpAddFile2Page
#define CandyFolder_wpAddFile3Page WPFileSystem_wpAddFile3Page
#define CandyFolder_wpAddFileMenuPage WPFileSystem_wpAddFileMenuPage
#define CandyFolder_wpQueryCreation WPFileSystem_wpQueryCreation
#define CandyFolder_wpQueryLastAccess WPFileSystem_wpQueryLastAccess
#define CandyFolder_wpQueryLastWrite WPFileSystem_wpQueryLastWrite
#define CandyFolder_wpQueryFileSize WPFileSystem_wpQueryFileSize
#define CandyFolder_wpQueryEASize WPFileSystem_wpQueryEASize
#define CandyFolder_wpSetDateInfo WPFileSystem_wpSetDateInfo
#define CandyFolder_wpSetFileSizeInfo WPFileSystem_wpSetFileSizeInfo
#define CandyFolder_wpRefresh WPFileSystem_wpRefresh
#define CandyFolder_wpQueryRefreshFlags WPFileSystem_wpQueryRefreshFlags
#define CandyFolder_wpSetRefreshFlags WPFileSystem_wpSetRefreshFlags
#define CandyFolder_wpPrintPlainTextFile WPFileSystem_wpPrintPlainTextFile
#define CandyFolder_wpSetTitleAndRenameFile WPFileSystem_wpSetTitleAndRenameFile
#define CandyFolder_wpConfirmRenameFileWithExt WPFileSystem_wpConfirmRenameFileWithExt
#define CandyFolder_wpVerifyUpdateAccess WPFileSystem_wpVerifyUpdateAccess
#define CandyFolder_wpAddUserItemsToPopupMenu WPFileSystem_wpAddUserItemsToPopupMenu
#define CandyFolder_wpIsDiskSwapped WPFileSystem_wpIsDiskSwapped
#define CandyFolder_wpQueryRealName WPFileSystem_wpQueryRealName
#define CandyFolder_wpQueryFilename WPFileSystem_wpQueryFilename
#define CandyFolder_wpQueryDisk WPFileSystem_wpQueryDisk
#define CandyFolder_wpQueryDateInfo WPFileSystem_wpQueryDateInfo
#define CandyFolder_wpConfirmKeepAssoc WPFileSystem_wpConfirmKeepAssoc
#define CandyFolder_wpAddObjectGeneralPage WPObject_wpAddObjectGeneralPage
#define CandyFolder_wpAddObjectGeneralPage2 WPObject_wpAddObjectGeneralPage2
#define CandyFolder_wpAddObjectWindowPage WPObject_wpAddObjectWindowPage
#define CandyFolder_wpAddSettingsPages WPObject_wpAddSettingsPages
#define CandyFolder_wpAddToObjUseList WPObject_wpAddToObjUseList
#define CandyFolder_wpAllocMem WPObject_wpAllocMem
#define CandyFolder_wpAppendObject WPObject_wpAppendObject
#define CandyFolder_wpAssertObjectMutexSem WPObject_wpAssertObjectMutexSem
#define CandyFolder_wpClose WPObject_wpClose
#define CandyFolder_wpCnrInsertObject WPObject_wpCnrInsertObject
#define CandyFolder_wpCnrRemoveObject WPObject_wpCnrRemoveObject
#define CandyFolder_wpCnrSetEmphasis WPObject_wpCnrSetEmphasis
#define CandyFolder_wpConfirmDelete WPObject_wpConfirmDelete
#define CandyFolder_wpConfirmObjectTitle WPObject_wpConfirmObjectTitle
#define CandyFolder_wpCopiedFromTemplate WPObject_wpCopiedFromTemplate
#define CandyFolder_wpCopyObject WPObject_wpCopyObject
#define CandyFolder_wpCreateAnother WPObject_wpCreateAnother
#define CandyFolder_wpCreateFromTemplate WPObject_wpCreateFromTemplate
#define CandyFolder_wpCreateShadowObject WPObject_wpCreateShadowObject
#define CandyFolder_wpDelete WPObject_wpDelete
#define CandyFolder_wpDisplayHelp WPObject_wpDisplayHelp
#define CandyFolder_wpDisplayMenu WPObject_wpDisplayMenu
#define CandyFolder_wpDoesObjectMatch WPObject_wpDoesObjectMatch
#define CandyFolder_wpDraggedOverObject WPObject_wpDraggedOverObject
#define CandyFolder_wpDragOver WPObject_wpDragOver
#define CandyFolder_wpDrop WPObject_wpDrop
#define CandyFolder_wpDroppedOnObject WPObject_wpDroppedOnObject
#define CandyFolder_wpEndConversation WPObject_wpEndConversation
#define CandyFolder_wpFilterPopupMenu WPObject_wpFilterPopupMenu
#define CandyFolder_wpFindUseItem WPObject_wpFindUseItem
#define CandyFolder_wpFormatDragItem WPObject_wpFormatDragItem
#define CandyFolder_wpFree WPObject_wpFree
#define CandyFolder_wpFreeMem WPObject_wpFreeMem
#define CandyFolder_wpHide WPObject_wpHide
#define CandyFolder_wpInitData WPObject_wpInitData
#define CandyFolder_wpInsertPopupMenuItems WPObject_wpInsertPopupMenuItems
#define CandyFolder_wpInsertSettingsPage WPObject_wpInsertSettingsPage
#define CandyFolder_wpMenuItemHelpSelected WPObject_wpMenuItemHelpSelected
#define CandyFolder_wpMenuItemSelected WPObject_wpMenuItemSelected
#define CandyFolder_wpModifyPopupMenu WPObject_wpModifyPopupMenu
#define CandyFolder_wpMoveObject WPObject_wpMoveObject
#define CandyFolder_wpPrintObject WPObject_wpPrintObject
#define CandyFolder_wpQueryConcurrentView WPObject_wpQueryConcurrentView
#define CandyFolder_wpQueryButtonAppearance WPObject_wpQueryButtonAppearance
#define CandyFolder_wpQueryConfirmations WPObject_wpQueryConfirmations
#define CandyFolder_wpQueryDefaultHelp WPObject_wpQueryDefaultHelp
#define CandyFolder_wpQueryDefaultView WPObject_wpQueryDefaultView
#define CandyFolder_wpQueryDetailsData WPObject_wpQueryDetailsData
#define CandyFolder_wpQueryError WPObject_wpQueryError
#define CandyFolder_wpSetFolder WPObject_wpSetFolder
#define CandyFolder_wpQueryFolder WPObject_wpQueryFolder
#define CandyFolder_wpQueryIcon WPObject_wpQueryIcon
#define CandyFolder_wpQueryIconData WPObject_wpQueryIconData
#define CandyFolder_wpQueryMinWindow WPObject_wpQueryMinWindow
#define CandyFolder_wpQueryNameClashOptions WPObject_wpQueryNameClashOptions
#define CandyFolder_wpQueryStyle WPObject_wpQueryStyle
#define CandyFolder_wpSetTaskRec WPObject_wpSetTaskRec
#define CandyFolder_wpFindTaskRec WPObject_wpFindTaskRec
#define CandyFolder_wpQueryTitle WPObject_wpQueryTitle
#define CandyFolder_wpRegisterView WPObject_wpRegisterView
#define CandyFolder_wpReleaseObjectMutexSem WPObject_wpReleaseObjectMutexSem
#define CandyFolder_wpRender WPObject_wpRender
#define CandyFolder_wpRenderComplete WPObject_wpRenderComplete
#define CandyFolder_wpReplaceObject WPObject_wpReplaceObject
#define CandyFolder_wpRequestObjectMutexSem WPObject_wpRequestObjectMutexSem
#define CandyFolder_wpRestore WPObject_wpRestore
#define CandyFolder_wpRestoreData WPObject_wpRestoreData
#define CandyFolder_wpRestoreLong WPObject_wpRestoreLong
#define CandyFolder_wpSaveData WPObject_wpSaveData
#define CandyFolder_wpSaveImmediate WPObject_wpSaveImmediate
#define CandyFolder_wpSaveDeferred WPObject_wpSaveDeferred
#define CandyFolder_wpSaveLong WPObject_wpSaveLong
#define CandyFolder_wpScanSetupString WPObject_wpScanSetupString
#define CandyFolder_wpSetConcurrentView WPObject_wpSetConcurrentView
#define CandyFolder_wpSetButtonAppearance WPObject_wpSetButtonAppearance
#define CandyFolder_wpSetDefaultHelp WPObject_wpSetDefaultHelp
#define CandyFolder_wpSetDefaultView WPObject_wpSetDefaultView
#define CandyFolder_wpSetError WPObject_wpSetError
#define CandyFolder_wpSetIconHandle WPObject_wpSetIconHandle
#define CandyFolder_wpQueryScreenGroupID WPObject_wpQueryScreenGroupID
#define CandyFolder_wpSetupOnce WPObject_wpSetupOnce
#define CandyFolder_wpSetIcon WPObject_wpSetIcon
#define CandyFolder_wpSetIconData WPObject_wpSetIconData
#define CandyFolder_wpSetMinWindow WPObject_wpSetMinWindow
#define CandyFolder_wpSetStyle WPObject_wpSetStyle
#define CandyFolder_wpModifyStyle WPObject_wpModifyStyle
#define CandyFolder_wpSetTitle WPObject_wpSetTitle
#define CandyFolder_wpSwitchTo WPObject_wpSwitchTo
#define CandyFolder_wpUnInitData WPObject_wpUnInitData
#define CandyFolder_wpViewObject WPObject_wpViewObject
#define CandyFolder_wpQueryTrueStyle WPObject_wpQueryTrueStyle
#define CandyFolder_wpQueryHandle WPObject_wpQueryHandle
#define CandyFolder_wpUnlockObject WPObject_wpUnlockObject
#define CandyFolder_wpObjectReady WPObject_wpObjectReady
#define CandyFolder_wpIsObjectInitialized WPObject_wpIsObjectInitialized
#define CandyFolder_wpCreateShadowObjectExt WPObject_wpCreateShadowObjectExt
#define CandyFolder_wpCnrDeleteUseItem WPObject_wpCnrDeleteUseItem
#define CandyFolder_wpIsDeleteable WPObject_wpIsDeleteable
#define CandyFolder_wpQueryCoreRecord WPObject_wpQueryCoreRecord
#define CandyFolder_wpSetObjectID WPObject_wpSetObjectID
#define CandyFolder_wpQueryObjectID WPObject_wpQueryObjectID
#define CandyFolder_wpSetDefaultIconPos WPObject_wpSetDefaultIconPos
#define CandyFolder_wpQueryDefaultIconPos WPObject_wpQueryDefaultIconPos
#define CandyFolder_wpCnrRefreshDetails WPObject_wpCnrRefreshDetails
#define CandyFolder_wpFindViewItem WPObject_wpFindViewItem
#define CandyFolder_wpLockObject WPObject_wpLockObject
#define CandyFolder_wpIsLocked WPObject_wpIsLocked
#define CandyFolder_wpQueryContainerFlagPtr WPObject_wpQueryContainerFlagPtr
#define CandyFolder_wpWaitForClose WPObject_wpWaitForClose
#define CandyFolder_somDefaultInit SOMObject_somDefaultInit
#define CandyFolder_somDestruct SOMObject_somDestruct
#define CandyFolder_somDefaultCopyInit SOMObject_somDefaultCopyInit
#define CandyFolder_somDefaultAssign SOMObject_somDefaultAssign
#define CandyFolder_somDefaultConstCopyInit SOMObject_somDefaultConstCopyInit
#define CandyFolder_somDefaultVCopyInit SOMObject_somDefaultVCopyInit
#define CandyFolder_somDefaultConstVCopyInit SOMObject_somDefaultConstVCopyInit
#define CandyFolder_somDefaultConstAssign SOMObject_somDefaultConstAssign
#define CandyFolder_somDefaultVAssign SOMObject_somDefaultVAssign
#define CandyFolder_somDefaultConstVAssign SOMObject_somDefaultConstVAssign
#define CandyFolder_somInit SOMObject_somInit
#define CandyFolder_somFree SOMObject_somFree
#define CandyFolder_somUninit SOMObject_somUninit
#define CandyFolder_somGetClass SOMObject_somGetClass
#define CandyFolder_somGetClassName SOMObject_somGetClassName
#define CandyFolder_somGetSize SOMObject_somGetSize
#define CandyFolder_somIsA SOMObject_somIsA
#define CandyFolder_somIsInstanceOf SOMObject_somIsInstanceOf
#define CandyFolder_somRespondsTo SOMObject_somRespondsTo
#define CandyFolder_somDispatch SOMObject_somDispatch
#define CandyFolder_somClassDispatch SOMObject_somClassDispatch
#define CandyFolder_somCastObj SOMObject_somCastObj
#define CandyFolder_somResetObj SOMObject_somResetObj
#define CandyFolder_somDispatchV SOMObject_somDispatchV
#define CandyFolder_somDispatchL SOMObject_somDispatchL
#define CandyFolder_somDispatchA SOMObject_somDispatchA
#define CandyFolder_somDispatchD SOMObject_somDispatchD
#define CandyFolder_somPrintSelf SOMObject_somPrintSelf
#define CandyFolder_somDumpSelf SOMObject_somDumpSelf
#define CandyFolder_somDumpSelfInt SOMObject_somDumpSelfInt
#endif /* SOM_DONT_USE_INHERITED_MACROS */

#endif       /* SOM_CandyFolder_h */

#ifndef SOM_M_CandyFolder_h
#define SOM_M_CandyFolder_h


#include <som.h>

/*
 * -- This emitter treats Method Tokens as Thunks by default.
 * -- Use the sc modifier "nothunks" to change this default
 */
#undef somresolve_
#define somresolve_(obj,mToken) ((somMethodProc*)((void)obj, mToken))

/*
 * Define the class name as an object type
 */
#ifndef M_CandyFolder
#define M_CandyFolder SOMObject
#endif
#include <wpfolder.h>

/*
 * Start of user-defined types:
 */

/*
 * End of user-defined types.
 */

#define M_CandyFolder_MajorVersion 1
#define M_CandyFolder_MinorVersion 1

/*
 * External name shortening if required
 */
#ifdef SOM_USE_SHORT_EXTERNAL_NAMES
#define M_CandyFolderNewClass candyfolderMc
#pragma linkage(candyfolderMc, system)
#define M_CandyFolderClassData candyfolderMd
#define M_CandyFolderCClassData candyfolderMx
#endif /* SOM_USE_SHORT_EXTERNAL_NAMES */
/*--------------Migration------------*/
#define M_CandyFolder_classObj M_CandyFolderClassData.classObject
#define _M_CandyFolder M_CandyFolder_classObj

/*
 * Declare the class creation procedure
 */
SOMEXTERN SOMClass * SOMLINK M_CandyFolderNewClass(integer4 somtmajorVersion,
		integer4 somtminorVersion);
#pragma linkage(M_CandyFolderNewClass, system)

/*
 * Declare the class data structure
 */
SOMEXTERN struct M_CandyFolderClassDataStructure {
	SOMClass *classObject;
} SOMDLINK M_CandyFolderClassData;

/*
 * Declare the C specific class data structure
 */
SOMEXTERN struct M_CandyFolderCClassDataStructure {
	somMethodTabs parentMtab;
	somDToken instanceDataToken;
} SOMDLINK M_CandyFolderCClassData;

/*
 * New and Renew macros for M_CandyFolder
 */
#define M_CandyFolderNew() \
   (_somNew(_M_CandyFolder ? _M_CandyFolder : M_CandyFolderNewClass(M_CandyFolder_MajorVersion, M_CandyFolder_MinorVersion)))
#define M_CandyFolderRenew(buf) \
   (_somRenew(_M_CandyFolder ? _M_CandyFolder : M_CandyFolderNewClass(M_CandyFolder_MajorVersion, M_CandyFolder_MinorVersion), buf))

/*
 * Override method: wpclsQueryTitle
 */
#define M_CandyFolder_wpclsQueryTitle(somSelf) \
	M_WPObject_wpclsQueryTitle(somSelf)

/*
 * Override method: wpclsQueryStyle
 */
#define M_CandyFolder_wpclsQueryStyle(somSelf) \
	M_WPObject_wpclsQueryStyle(somSelf)

/*
 * Override method: wpclsUnInitData
 */
#define M_CandyFolder_wpclsUnInitData(somSelf) \
	M_WPObject_wpclsUnInitData(somSelf)
#ifndef SOM_DONT_USE_INHERITED_MACROS
#define M_CandyFolder_wpclsQueryIconDataN M_WPFolder_wpclsQueryIconDataN
#define M_CandyFolder_wpclsQueryIconN M_WPFolder_wpclsQueryIconN
#define M_CandyFolder_wpclsQueryOpenFolders M_WPFolder_wpclsQueryOpenFolders
#define M_CandyFolder_wpclsQueryAwakeObject M_WPFileSystem_wpclsQueryAwakeObject
#define M_CandyFolder_wpclsFileSysExists M_WPFileSystem_wpclsFileSysExists
#define M_CandyFolder_wpclsQueryObjectFromPath M_WPFileSystem_wpclsQueryObjectFromPath
#define M_CandyFolder_wpclsQueryInstanceType M_WPFileSystem_wpclsQueryInstanceType
#define M_CandyFolder_wpclsQueryInstanceFilter M_WPFileSystem_wpclsQueryInstanceFilter
#define M_CandyFolder_wpclsCreateDefaultTemplates M_WPObject_wpclsCreateDefaultTemplates
#define M_CandyFolder_wpclsInitData M_WPObject_wpclsInitData
#define M_CandyFolder_wpclsMakeAwake M_WPObject_wpclsMakeAwake
#define M_CandyFolder_wpclsNew M_WPObject_wpclsNew
#define M_CandyFolder_wpclsQueryDefaultHelp M_WPObject_wpclsQueryDefaultHelp
#define M_CandyFolder_wpclsQueryDefaultView M_WPObject_wpclsQueryDefaultView
#define M_CandyFolder_wpclsQueryDetails M_WPObject_wpclsQueryDetails
#define M_CandyFolder_wpclsQueryDetailsInfo M_WPObject_wpclsQueryDetailsInfo
#define M_CandyFolder_wpclsQueryExtendedCriteria M_WPObject_wpclsQueryExtendedCriteria
#define M_CandyFolder_wpclsQueryFolder M_WPObject_wpclsQueryFolder
#define M_CandyFolder_wpclsQueryIcon M_WPObject_wpclsQueryIcon
#define M_CandyFolder_wpclsQuerySearchInfo M_WPObject_wpclsQuerySearchInfo
#define M_CandyFolder_wpclsFindObjectFirst M_WPObject_wpclsFindObjectFirst
#define M_CandyFolder_wpclsFindObjectNext M_WPObject_wpclsFindObjectNext
#define M_CandyFolder_wpclsFindObjectEnd M_WPObject_wpclsFindObjectEnd
#define M_CandyFolder_wpclsSetError M_WPObject_wpclsSetError
#define M_CandyFolder_wpclsQueryError M_WPObject_wpclsQueryError
#define M_CandyFolder_wpclsQuerySettingsPageSize M_WPObject_wpclsQuerySettingsPageSize
#define M_CandyFolder_wpclsQueryIconData M_WPObject_wpclsQueryIconData
#define M_CandyFolder_wpclsQueryObject M_WPObject_wpclsQueryObject
#define M_CandyFolder_wpclsQueryButtonAppearance M_WPObject_wpclsQueryButtonAppearance
#define M_CandyFolder_wpclsDecUsage M_WPObject_wpclsDecUsage
#define M_CandyFolder_wpclsIncUsage M_WPObject_wpclsIncUsage
#define M_CandyFolder_wpclsInsertMultipleObjects M_WPObject_wpclsInsertMultipleObjects
#define M_CandyFolder_wpclsFindOneObject M_WPObject_wpclsFindOneObject
#define M_CandyFolder_wpclsSetSettingsPageSize M_WPObject_wpclsSetSettingsPageSize
#define M_CandyFolder_wpclsSetIconData M_WPObject_wpclsSetIconData
#define M_CandyFolder_wpclsSetIcon M_WPObject_wpclsSetIcon
#define M_CandyFolder_wpclsObjectFromHandle M_WPObject_wpclsObjectFromHandle
#define M_CandyFolder_wpclsRemoveObjects M_WPObject_wpclsRemoveObjects
#define M_CandyFolder__get_somDataAlignment SOMClass__get_somDataAlignment
#define M_CandyFolder__get_somInstanceDataOffsets SOMClass__get_somInstanceDataOffsets
#define M_CandyFolder__get_somDirectInitClasses SOMClass__get_somDirectInitClasses
#define M_CandyFolder__set_somDirectInitClasses SOMClass__set_somDirectInitClasses
#define M_CandyFolder_somNew SOMClass_somNew
#define M_CandyFolder_somNewNoInit SOMClass_somNewNoInit
#define M_CandyFolder_somRenew SOMClass_somRenew
#define M_CandyFolder_somRenewNoInit SOMClass_somRenewNoInit
#define M_CandyFolder_somRenewNoZero SOMClass_somRenewNoZero
#define M_CandyFolder_somRenewNoInitNoZero SOMClass_somRenewNoInitNoZero
#define M_CandyFolder_somAllocate SOMClass_somAllocate
#define M_CandyFolder_somDeallocate SOMClass_somDeallocate
#define M_CandyFolder__get_somClassAllocate SOMClass__get_somClassAllocate
#define M_CandyFolder__get_somClassDeallocate SOMClass__get_somClassDeallocate
#define M_CandyFolder_somGetInstanceInitMask SOMClass_somGetInstanceInitMask
#define M_CandyFolder_somGetInstanceDestructionMask SOMClass_somGetInstanceDestructionMask
#define M_CandyFolder_somGetInstanceAssignmentMask SOMClass_somGetInstanceAssignmentMask
#define M_CandyFolder_somInitClass SOMClass_somInitClass
#define M_CandyFolder_somInitMIClass SOMClass_somInitMIClass
#define M_CandyFolder_somAddStaticMethod SOMClass_somAddStaticMethod
#define M_CandyFolder_somAddDynamicMethod SOMClass_somAddDynamicMethod
#define M_CandyFolder_somOverrideSMethod SOMClass_somOverrideSMethod
#define M_CandyFolder_somClassReady SOMClass_somClassReady
#define M_CandyFolder_somGetApplyStub SOMClass_somGetApplyStub
#define M_CandyFolder_somGetClassData SOMClass_somGetClassData
#define M_CandyFolder_somSetClassData SOMClass_somSetClassData
#define M_CandyFolder_somGetClassMtab SOMClass_somGetClassMtab
#define M_CandyFolder_somGetInstanceOffset SOMClass_somGetInstanceOffset
#define M_CandyFolder_somGetInstancePartSize SOMClass_somGetInstancePartSize
#define M_CandyFolder_somGetInstanceSize SOMClass_somGetInstanceSize
#define M_CandyFolder_somGetInstanceToken SOMClass_somGetInstanceToken
#define M_CandyFolder_somGetMemberToken SOMClass_somGetMemberToken
#define M_CandyFolder_somGetMethodData SOMClass_somGetMethodData
#define M_CandyFolder_somGetRdStub SOMClass_somGetRdStub
#define M_CandyFolder_somGetMethodDescriptor SOMClass_somGetMethodDescriptor
#define M_CandyFolder_somGetMethodIndex SOMClass_somGetMethodIndex
#define M_CandyFolder_somGetMethodToken SOMClass_somGetMethodToken
#define M_CandyFolder_somGetName SOMClass_somGetName
#define M_CandyFolder_somGetNthMethodData SOMClass_somGetNthMethodData
#define M_CandyFolder_somGetNthMethodInfo SOMClass_somGetNthMethodInfo
#define M_CandyFolder_somGetNumMethods SOMClass_somGetNumMethods
#define M_CandyFolder_somGetNumStaticMethods SOMClass_somGetNumStaticMethods
#define M_CandyFolder_somGetParent SOMClass_somGetParent
#define M_CandyFolder_somGetParents SOMClass_somGetParents
#define M_CandyFolder_somGetPClsMtab SOMClass_somGetPClsMtab
#define M_CandyFolder_somGetPClsMtabs SOMClass_somGetPClsMtabs
#define M_CandyFolder_somGetVersionNumbers SOMClass_somGetVersionNumbers
#define M_CandyFolder_somSetMethodDescriptor SOMClass_somSetMethodDescriptor
#define M_CandyFolder_somFindMethod SOMClass_somFindMethod
#define M_CandyFolder_somFindMethodOk SOMClass_somFindMethodOk
#define M_CandyFolder_somFindSMethod SOMClass_somFindSMethod
#define M_CandyFolder_somFindSMethodOk SOMClass_somFindSMethodOk
#define M_CandyFolder_somLookupMethod SOMClass_somLookupMethod
#define M_CandyFolder_somCheckVersion SOMClass_somCheckVersion
#define M_CandyFolder_somDescendedFrom SOMClass_somDescendedFrom
#define M_CandyFolder_somSupportsMethod SOMClass_somSupportsMethod
#define M_CandyFolder_somDefinedMethod SOMClass_somDefinedMethod
#define M_CandyFolder_somOverrideMtab SOMClass_somOverrideMtab
#define M_CandyFolder_somDefaultInit SOMObject_somDefaultInit
#define M_CandyFolder_somDestruct SOMObject_somDestruct
#define M_CandyFolder_somDefaultCopyInit SOMObject_somDefaultCopyInit
#define M_CandyFolder_somDefaultAssign SOMObject_somDefaultAssign
#define M_CandyFolder_somDefaultConstCopyInit SOMObject_somDefaultConstCopyInit
#define M_CandyFolder_somDefaultVCopyInit SOMObject_somDefaultVCopyInit
#define M_CandyFolder_somDefaultConstVCopyInit SOMObject_somDefaultConstVCopyInit
#define M_CandyFolder_somDefaultConstAssign SOMObject_somDefaultConstAssign
#define M_CandyFolder_somDefaultVAssign SOMObject_somDefaultVAssign
#define M_CandyFolder_somDefaultConstVAssign SOMObject_somDefaultConstVAssign
#define M_CandyFolder_somInit SOMObject_somInit
#define M_CandyFolder_somFree SOMObject_somFree
#define M_CandyFolder_somUninit SOMObject_somUninit
#define M_CandyFolder_somGetClass SOMObject_somGetClass
#define M_CandyFolder_somGetClassName SOMObject_somGetClassName
#define M_CandyFolder_somGetSize SOMObject_somGetSize
#define M_CandyFolder_somIsA SOMObject_somIsA
#define M_CandyFolder_somIsInstanceOf SOMObject_somIsInstanceOf
#define M_CandyFolder_somRespondsTo SOMObject_somRespondsTo
#define M_CandyFolder_somDispatch SOMObject_somDispatch
#define M_CandyFolder_somClassDispatch SOMObject_somClassDispatch
#define M_CandyFolder_somCastObj SOMObject_somCastObj
#define M_CandyFolder_somResetObj SOMObject_somResetObj
#define M_CandyFolder_somDispatchV SOMObject_somDispatchV
#define M_CandyFolder_somDispatchL SOMObject_somDispatchL
#define M_CandyFolder_somDispatchA SOMObject_somDispatchA
#define M_CandyFolder_somDispatchD SOMObject_somDispatchD
#define M_CandyFolder_somPrintSelf SOMObject_somPrintSelf
#define M_CandyFolder_somDumpSelf SOMObject_somDumpSelf
#define M_CandyFolder_somDumpSelfInt SOMObject_somDumpSelfInt
#endif /* SOM_DONT_USE_INHERITED_MACROS */

#endif       /* SOM_M_CandyFolder_h */
