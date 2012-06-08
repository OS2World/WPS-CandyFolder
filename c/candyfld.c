/*
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
 */
/*
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
/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using: 
 *      SOM Emitter emitctm: 2.42
 */

#ifndef SOM_Module_candyfld_Source
#define SOM_Module_candyfld_Source
#endif
#define CandyFolder_Class_Source
#define M_CandyFolder_Class_Source

#define INCL_WINWORKPLACE
#define INCL_WIN
#define INCL_DOS
#define INCL_GPI
#include <os2.h>
#include <stdio.h>
#include "candyinc.h"
#include "candyfld.ih"
#include <wpclsmgr.h> /* For wpModuleForClass() */
#include <wpdesk.ih>

#include "debug.h"
#include "except.h"

char  chrDesktopBG[CCHMAXPATH];
PFNWP pfnwpGenericNB;
PFNWP pfnwpBgNB;
PFNWP pfnwpCBCont;
PFNWP pfnwpCBFrame;
PFNWP pfnwpCheckButton;

HMODULE hRessource=NULLHANDLE;
ULONG ulRedDefault=100;
ULONG ulGreenDefault=100;
ULONG ulBlueDefault=100;

HWND hwndDesktopFolder;

char *pvImageData;
BITMAPINFO2 * pbmpInfo2;

extern BOOL readBitmapDataFromFile( char *pszFileName, char** pvImage, PBITMAPINFO2 * pbmpIHdr2 );
extern HBITMAP createBitmapFromData(char * pvImage, BITMAPINFO2 * pbmpI2, ULONG ulRed, ULONG ulGreen, ULONG ulBlue);
MRESULT EXPENTRY transparencyExampleProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
extern BOOL getMessage(char* text,ULONG ulID, LONG lSizeText, HMODULE hResource,HWND hwnd);
extern HMODULE queryModuleHandle(void);
extern ULONG cwQueryOSRelease(void);

MRESULT EXPENTRY bgNBProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) ;
MRESULT EXPENTRY candyNBProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) ;
MRESULT EXPENTRY transparencySettingsProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) ;

ULONG cfCreateMutex(void);
ULONG cfCloseMutex(void);
ULONG cfRequestMutex(ULONG ulTimeOut);
ULONG cfReleaseMutex(void);

/* The new container proc which paints the pseudo transparency */
MRESULT EXPENTRY candyContainerProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) 
{
  CandyFolderData *somThis;  
  CandyFolder  *fldrPtr;
  HWND hwndFrame;
  POWNERBACKGROUND pOBG;
  RECTL rcl;
  HPS hps;
  static ULONG ulEnd=0;

  switch(msg)
    {
    case WM_HSCROLL:
      TRY_LOUD(HSCROLL) {
        switch(SHORT2FROMMP(mp2))
          {
          case SB_LINELEFT:
          case SB_LINERIGHT:
          case SB_PAGELEFT:
          case SB_PAGERIGHT:
          case SB_SLIDERTRACK:
            hwndFrame=WinQueryWindow(hwnd, QW_PARENT);
            fldrPtr=(CandyFolder*) WinQueryWindowULong(WinWindowFromID(hwndFrame, ID_OBJECTSTOREWINDOW),QWL_USER);// object ptr.
            if(somIsObj(fldrPtr)) {
              somThis = CandyFolderGetData(fldrPtr);
              if((somThis->ulTrans & ID_TRANSPARENCY) && (somThis->hbmBG)) { 
                ulEnd=0;
                WinEnableWindowUpdate(hwnd, FALSE);
              }
            }
            break;
          case SB_SLIDERPOSITION:
            if (ulEnd==2)
              {
                WinQueryWindowRect(hwnd,&rcl);
                WinInvalidateRect(hwnd,&rcl, TRUE);
                ulEnd=0;
                break;
              }
            ulEnd=1;
          case SB_ENDSCROLL:
            WinEnableWindowUpdate(hwnd, TRUE);
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl, TRUE);
            break;
          default:
            break;
          }
      }
      CATCH(HSCROLL)
        {
        } END_CATCH;
        
        break;
        
    case WM_VSCROLL:
      TRY_LOUD(VSCROLL) {
        switch(SHORT2FROMMP(mp2))
          {
          case SB_LINEUP:
          case SB_LINEDOWN:
          case SB_PAGEUP:
          case SB_PAGEDOWN:
          case SB_SLIDERTRACK:
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl, TRUE);
            ulEnd=0;
            break;
          case SB_SLIDERPOSITION:
            if (ulEnd==2)
              {
                WinQueryWindowRect(hwnd,&rcl);
                WinInvalidateRect(hwnd,&rcl, TRUE);
                ulEnd=0;
                break;
              }
            ulEnd=1;         
          case SB_ENDSCROLL:
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl, TRUE);
            break;
          default:
            break;
          }/* switch */
      }
      CATCH(VSCROLL)
        {
        } END_CATCH;
        
        break;
        
    case WM_CONTROL:
      {
        if(SHORT2FROMMP(mp1)==CN_SCROLL) {
          BOOL bDone=FALSE; 

          TRY_LOUD(CONTROL) {
            hwndFrame=WinQueryWindow(hwnd, QW_PARENT);
            fldrPtr=(CandyFolder*) WinQueryWindowULong(WinWindowFromID(hwndFrame, ID_OBJECTSTOREWINDOW),QWL_USER);// object ptr.
            if(somIsObj(fldrPtr)) {
              somThis = CandyFolderGetData(fldrPtr);
              if((somThis->ulTrans & ID_TRANSPARENCY) && (somThis->hbmBG)) { 
                PNOTIFYSCROLL pNS;
                pNS=(PNOTIFYSCROLL)PVOIDFROMMP(mp2);
                
                if(pNS->fScroll & CMA_HORIZONTAL) {
                  WinShowWindow(hwnd, TRUE);
                }
                if(ulEnd==2) {
                  WinPostMsg(hwnd, CM_SCROLLWINDOW,MPFROMSHORT(CMA_VERTICAL), MPFROMLONG(pNS->lScrollInc * 0));
                }
                else
                  ulEnd=0;
                
                bDone=TRUE;     
              }
            }
          }
          CATCH(CONTROL)
            {
            } END_CATCH;
            if(bDone)
              return (MRESULT)0;
        }/* if(SHORT2FROMMP(mp1)==CN_SCROLL) */
        break;
      }
    case  CM_PAINTBACKGROUND:
      {
        BOOL bPaintingDone=FALSE;

        TRY_LOUD(CM_PAINTBG) {
          hwndFrame=WinQueryWindow(hwnd, QW_PARENT);
          fldrPtr=(CandyFolder*) WinQueryWindowULong(WinWindowFromID(hwndFrame,
                                                                     ID_OBJECTSTOREWINDOW),QWL_USER);// object ptr.
          if(somIsObj(fldrPtr)) {
            somThis = CandyFolderGetData(fldrPtr);
            if((somThis->ulTrans & ID_TRANSPARENCY) && (somThis->hbmBG)) { 
              POINTL ptl;
              RECTL rcl;
              
              if(ulEnd==1)
                ulEnd=2;
              /* This folder has transparency so paint it. Otherwise let the system paint it. */
              pOBG=PVOIDFROMMP(mp1);/* Presentation  space of the container */
              /* Target coords */
              ptl.x=pOBG->rclBackground.xLeft;
              ptl.y=pOBG->rclBackground.yBottom;
              /* Source rect */
              rcl=pOBG->rclBackground;
              
              // WinMapWindowPoints(pOBG->hwnd,HWND_DESKTOP,(PPOINTL)&rcl,2L);
              WinMapWindowPoints(pOBG->hwnd, hwndDesktopFolder,(PPOINTL)&rcl,2L);
              WinDrawBitmap(pOBG->hps, somThis->hbmBG, &rcl, &ptl, 0L, 0L, DBM_NORMAL);
              
              /* OK, painting done */
              bPaintingDone=TRUE;
            }
          }/* if(somIsObj(fldrPtr)) */
        }
        CATCH(CM_PAINTBG)
          {
          } END_CATCH;
          if(bPaintingDone)          
            /* OK, painting done */
            return (MRESULT)TRUE;
          
          break;/* Let the WPS paint the background */
      }/* case  CM_PAINTBACKGROUND */
    default:
      break;
    }
  return  pfnwpCBCont(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY candyFrameProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) 
{
  HWND hwndClient;
  RECTL rclClient;
  PSWP pswp, pswp2;
  MRESULT mrRC;
  CandyFolder  *fldrPtr;
  CandyFolderData *somThis;

  switch(msg)
    {
    case WM_WINDOWPOSCHANGED:
      {
        BOOL bDone=FALSE;
        
        pswp=PVOIDFROMMP(mp1);
        pswp2=pswp;
        pswp2++;
        
        TRY_LOUD(CANDY_FRAME) {
          mrRC=pfnwpCBFrame(hwnd, msg, mp1, mp2);
          bDone=TRUE;

          if(pswp->fl & (SWP_SIZE | SWP_MOVE)) {
            fldrPtr=(CandyFolder*) WinQueryWindowULong(WinWindowFromID(hwnd,
                                                                       ID_OBJECTSTOREWINDOW),QWL_USER);// object ptr.
            if(somIsObj(fldrPtr)) {
              somThis = CandyFolderGetData(fldrPtr);
              if((somThis->ulTrans & ID_TRANSPARENCY) && (somThis->hbmBG)) { 
                hwndClient=WinWindowFromID(hwnd,FID_CLIENT);
                if(hwndClient) { /* We have got a Client */
                  /* get client dimensions */
                  WinQueryWindowRect(hwndClient,&rclClient);
                  WinInvalidateRect(hwndClient,&rclClient, TRUE);
                }/* end of if(hwndClient) */
              }
            }
          }/* end of if(pswp->fl & SWP_MOVE) */
        }
        CATCH(CANDY_FRAME)
          {
          } END_CATCH;
          if(bDone)
            return mrRC;
          return (MRESULT)0;
      }
    default:
      break;
    }
  return  pfnwpCBFrame(hwnd, msg, mp1, mp2);
}



/*
 *
 *This method cycles trough all open views of the folder and forces the
 *backgrounds to be redrawn.
 */

SOM_Scope void  SOMLINK candyfolder_cfRefreshContainerBackgrounds(CandyFolder *somSelf, 
                                                                  BOOL bColorChange)
{
  PVIEWITEM pView;
  RECTL rcl;
  char text[100];
  BOOL bHaveMux=FALSE;

    CandyFolderData *somThis = CandyFolderGetData(somSelf);
    CandyFolderMethodDebug("CandyFolder","candyfolder_cfRefreshContainerBackgrounds");

    TRY_LOUD(REFRESHCONT) {
      if((_ulTrans & ID_TRANSPARENCY)) {
        /* This folder has transparency */
        if(!_hbmBG && pvImageData && pbmpInfo2 ) {
          /* No bitmap yet, so create it */ 
          if(! cfRequestMutex(10000)) {
            bHaveMux=TRUE;
            _hbmBG=createBitmapFromData(pvImageData, pbmpInfo2, _ulRed,  _ulGreen, _ulBlue);
            // cfReleaseMutex();
          }
        }
        else {
          if(bColorChange) {
            /* User changes transparency settings */
            GpiDeleteBitmap(_hbmBG);
            _hbmBG=NULLHANDLE;
            if(! cfRequestMutex(10000)) {
              bHaveMux=TRUE;
              /* Create new bitmap with new color settings */
              _hbmBG=createBitmapFromData(pvImageData, pbmpInfo2, _ulRed,  _ulGreen, _ulBlue);
              // cfReleaseMutex();
            }
          }
        }
      }
      
      for(pView=_wpFindViewItem(somSelf, VIEW_CONTENTS|VIEW_DETAILS|VIEW_TREE, NULL );pView;
          pView=_wpFindViewItem(somSelf, VIEW_CONTENTS|VIEW_DETAILS|VIEW_TREE, pView ))
        {
          //sprintf(text, "view: %d", pView->view);
          //WinMessageBox(HWND_DESKTOP,HWND_DESKTOP,text,"rrr",1234,MB_OK|MB_MOVEABLE);
          //        if(pView->view==OPEN_DETAILS)
          if(WinIsWindow(WinQueryAnchorBlock(HWND_DESKTOP), pView->handle)) {
            WinQueryWindowRect(WinWindowFromID(pView->handle, FID_CLIENT),&rcl);
            WinInvalidateRect(WinWindowFromID(pView->handle, FID_CLIENT),&rcl, TRUE);/* True because of details view */
          }
        }
    }
    CATCH(REFRESHCONT)
      {
      } END_CATCH;
      
      if(bHaveMux)
        cfReleaseMutex();
}

void cfRefreshAllOpenFolderBG(WPFolder* wpFolder)
{
  M_WPFolder *m_wpFolder;
  WPFolder*  wpOpenFolder;

  TRY_LOUD(REFRESH) {
    /* Get class object */
    m_wpFolder=(M_WPFolder*)_somGetClass(wpFolder);
    if(somIsObj(m_wpFolder)) {
      for(wpOpenFolder=_wpclsQueryOpenFolders(m_wpFolder, NULLHANDLE, QC_FIRST, FALSE);somIsObj(wpOpenFolder);
          wpOpenFolder=_wpclsQueryOpenFolders(m_wpFolder, wpOpenFolder, QC_NEXT, FALSE))
        {
          _cfRefreshContainerBackgrounds(wpOpenFolder, TRUE);
        }
    }
  }
  CATCH(REFRESH)
    {
    } END_CATCH;
    
}

SOM_Scope ULONG  SOMLINK candyfolder_wpAddFolderBackgroundPage(CandyFolder *somSelf, 
                                                               HWND hwndNotebook)
{
  ULONG ulRC;
  PAGEINFO pageInfo;
  HWND hwnd;
  PAGEINFO pageinfo;
  char pageName[100];
  HMODULE hMod;
  PSZ pszClass;
  BOOL bAdd=TRUE;

  CandyFolderData *somThis = CandyFolderGetData(somSelf);
  /* CandyFolderData *somThis = CandyFolderGetData(somSelf); */
  CandyFolderMethodDebug("CandyFolder","candyfolder_wpAddFolderBackgroundPage");

  /* Check if it's a WPRootFolder */
  if(!strcmp(_somGetClassName(somSelf),"WPRootFolder"))/* This does not work if WPRootFolder is replaced! */
    bAdd=FALSE;

  /* Check if we are a desktop folder */
  if(somResolveByName((WPDesktop*)somSelf, "wpIsCurrentDesktop")==NULL) {
    if(bAdd) {
      /* Add tranaparency page */
      pszClass=_wpModuleForClass(SOMClassMgrObject,"CandyFolder");
      DosQueryModuleHandle(pszClass, &hMod);
      //Clear the pageinfo structure
      memset((PCH)&pageinfo, 0, sizeof(PAGEINFO));
      //Fill the pageinfo structure
      pageinfo.cb = sizeof(PAGEINFO);
      pageinfo.hwndPage = NULLHANDLE;
      pageinfo.usPageStyleFlags = BKA_STATUSTEXTON;
      pageinfo.usPageInsertFlags = BKA_FIRST;
      //We want page numbers
      pageinfo.usSettingsFlags = SETTINGS_PAGE_NUMBERS;
      //The dialog procedure for this page
      pageinfo.pfnwp = transparencySettingsProc;
      //The resource DLL
      pageinfo.resid = hMod;
      //pageinfo.resid = queryModuleHandle();
      //The ID of the dialog template
      pageinfo.dlgid = IDDLG_TRANSPARENCY;
      //We need a pointer to our WPS-object in the dialog procedure
      //to call class functions
      pageinfo.pCreateParams = somSelf;
      //The ID of the help panel for this page
      pageinfo.idDefaultHelpPanel = NULLHANDLE;
      //Tell the WPS the help library name
      pageinfo.pszHelpLibraryName = NULL;
      //We have a major tab so we need a name
      /* pageName: "General" */
      //getMessage(pageName, IDSTRSETTING_GENERAL, sizeof(pageName),  hSettingsResource, hwndNotebook);
      //pageinfo.pszName = pageName;
      
      //Insert the page into the settings notebook
      _wpInsertSettingsPage(somSelf, hwndNotebook,&pageinfo);  
    }
  }
  ulRC=(CandyFolder_parent_WPFolder_wpAddFolderBackgroundPage(somSelf, 
                                                              hwndNotebook));
  
  _ulBackgroundPageID=0;
  
  /* Normal folder */
  if(bAdd) {
    if((hwnd=WinCreateWindow(hwndNotebook, WC_STATIC, "Obj_Ptr_Save",0,0,0,0,0,hwndNotebook,HWND_TOP, ID_OBJECTSTOREWINDOW,NULL,NULL))!=NULLHANDLE) {
      WinSetWindowULong(hwnd,QWL_USER,(ULONG) somSelf);//Save object ptr.
      pfnwpGenericNB=WinSubclassWindow(hwndNotebook,candyNBProc);
      _ulBackgroundPageID=ulRC;
    }
  }
  
  return ulRC;
}

SOM_Scope HWND  SOMLINK candyfolder_wpOpen(CandyFolder *somSelf, 
                                           HWND hwndCnr, ULONG ulView, 
                                           ULONG param)
{
  HWND hwndFolder;
  HWND hwndCont;
  HWND hwndBT;
  BOOL bHaveMux=FALSE;
  BOOL bIsDesktop=FALSE;

  somTD_WPDesktop_wpIsCurrentDesktop isCurrentDesktopMethodPtr;

  CandyFolderData *somThis = CandyFolderGetData(somSelf);
  CandyFolderMethodDebug("CandyFolder","candyfolder_wpOpen");
  
  hwndFolder= (CandyFolder_parent_WPFolder_wpOpen(somSelf, hwndCnr, 
                                                  ulView, param));
  
  
  if(ulView==OPEN_SETTINGS)
    return hwndFolder;

  TRY_LOUD(WP_OPEN) {
    /* Check if we are a desktop folder */
    /* Desktop folders need special processing */
    if((isCurrentDesktopMethodPtr=(somTD_WPDesktop_wpIsCurrentDesktop)somResolveByName((WPDesktop*)somSelf, "wpIsCurrentDesktop"))!=NULL) {
      /* Check if we are the current desktop */
      if(isCurrentDesktopMethodPtr((WPDesktop*)somSelf)) {
        hwndDesktopFolder=hwndFolder;
        bIsDesktop=TRUE; 
        if(!pvImageData && !pbmpInfo2) {
          if(! cfRequestMutex(10000)) {
            bHaveMux=TRUE;
            if(!readBitmapDataFromFile(chrDesktopBG, &pvImageData, & pbmpInfo2 )) {
              pvImageData=NULLHANDLE;
              pbmpInfo2=NULLHANDLE;
            }
            /* The mutex is released at the end of this func */
            //   cfReleaseMutex();
          }
        }
        //return hwndFolder; /* Desktop Folder */
      }
    }
    
    if(!bIsDesktop){  
      /* Only normal folders get a special paint procedure */
      hwndCont=WinWindowFromID(hwndFolder,FID_CLIENT);//Get container hwnd
      /* Subclass container */
      if(hwndCont){
        /* Create a hidden window to store the object pointer */
        if((hwndBT=WinCreateWindow(hwndFolder, WC_STATIC, "Obj_Ptr_Save",0,0,0,0,0,hwndFolder,
                                   HWND_TOP, ID_OBJECTSTOREWINDOW,NULL,NULL))!=NULLHANDLE) {
          WinSetWindowULong(hwndBT,QWL_USER,(ULONG) somSelf);//Save object ptr.
          
          /* Subclass container for custom  painting */
          pfnwpCBCont=WinSubclassWindow(hwndCont,candyContainerProc);
          
          /* We must catch move messages to repaint the client if necessary */
          pfnwpCBFrame=WinSubclassWindow(hwndFolder,candyFrameProc);
        }
      }
      
      if((_ulTrans & ID_TRANSPARENCY)) {
        /* This folder has transparency */
        if(!_hbmBG && pvImageData && pbmpInfo2 ) { 
          if(! cfRequestMutex(10000)) {
            bHaveMux=TRUE;
            _hbmBG=createBitmapFromData(pvImageData, pbmpInfo2, _ulRed,  _ulGreen, _ulBlue);
            //cfReleaseMutex();
          }
        }
        if(_hbmBG) {
          RECTL rectl;
          
          /* System already painted the background so invalidate it to repaint it with transparency.
             This will be obsolete when CB has support for container procs. */
          /* Create bitmap */
          WinQueryWindowRect(hwndCont, &rectl);
          WinInvalidateRect(hwndCont, &rectl, FALSE);  
        }
      }
    }
  }
  CATCH(WP_OPEN)
    {
    } END_CATCH;
    
    if(bHaveMux)
      cfReleaseMutex();
    
    return hwndFolder;
}

SOM_Scope BOOL  SOMLINK candyfolder_wpDeleteFromObjUseList(CandyFolder *somSelf, 
                                                           PUSEITEM pUseItem)
{
  BOOL bRC;
  PVIEWITEM pView;

    CandyFolderData *somThis = CandyFolderGetData(somSelf);
    CandyFolderMethodDebug("CandyFolder","candyfolder_wpDeleteFromObjUseList");

    bRC=CandyFolder_parent_WPFolder_wpDeleteFromObjUseList(somSelf, pUseItem);


    /* Check if there're any open views left*/
    TRY_LOUD(OBJUSE) {
      if((pView=_wpFindViewItem(somSelf, VIEW_ANY,NULLHANDLE))==NULLHANDLE) {
        if(_hbmBG){
          GpiDeleteBitmap(_hbmBG);
          _hbmBG=NULLHANDLE;
        }
      }
    }
    CATCH(OBJUSE)
      {
      } END_CATCH;
      
    return bRC;
}


SOM_Scope BOOL  SOMLINK candyfolder_wpSaveState(CandyFolder *somSelf)
{
    CandyFolderData *somThis = CandyFolderGetData(somSelf);
    CandyFolderMethodDebug("CandyFolder","candyfolder_wpSaveState");

    if(_ulHaveToSave==1) {
      /* Set the background of the folder to color white when using transparency.
         This prevents the WPS from loading an image and displaying it when first
         opening a folder. */
      _wpSetup(somSelf,"BACKGROUND=(none,,,C,255 255 255)");
      _ulHaveToSave=0;
    }

    _wpSaveLong(somSelf, "CandyFolder", IDKEY_TRANSPARENCY, _ulTrans);
    _wpSaveLong(somSelf, "CandyFolder", IDKEY_TRANSRED, _ulRed);
    _wpSaveLong(somSelf, "CandyFolder", IDKEY_TRANSGREEN, _ulGreen);
    _wpSaveLong(somSelf, "CandyFolder", IDKEY_TRANSBLUE, _ulBlue);

    return (CandyFolder_parent_WPFolder_wpSaveState(somSelf));
}

SOM_Scope BOOL  SOMLINK candyfolder_wpRestoreState(CandyFolder *somSelf, 
                                                   ULONG ulReserved)
{
  BOOL rc;
  somTD_WPDesktop_wpIsCurrentDesktop isCurrentDesktopMethodPtr;

    CandyFolderData *somThis = CandyFolderGetData(somSelf);
    CandyFolderMethodDebug("CandyFolder","candyfolder_wpRestoreState");

    /* Init some vars */
    _ulHaveToSave=0;
    _hbmBG=NULLHANDLE;
    if(!_wpRestoreLong(somSelf, "CandyFolder", IDKEY_TRANSPARENCY, &_ulTrans))
       _ulTrans=0;
    if(!_wpRestoreLong(somSelf, "CandyFolder", IDKEY_TRANSRED, &_ulRed))
      _ulRed=100;
    if(!_wpRestoreLong(somSelf, "CandyFolder", IDKEY_TRANSGREEN, &_ulGreen))
      _ulGreen=100;
    if(!_wpRestoreLong(somSelf, "CandyFolder", IDKEY_TRANSBLUE, &_ulBlue))
      _ulBlue=100;

    if((isCurrentDesktopMethodPtr=(somTD_WPDesktop_wpIsCurrentDesktop)somResolveByName((WPDesktop*)somSelf, "wpIsCurrentDesktop"))!=NULL) {
      /* Check if we are the current desktop */
      if(isCurrentDesktopMethodPtr((WPDesktop*)somSelf)) {
        ulRedDefault=_ulRed;
        ulGreenDefault=_ulGreen;
        ulBlueDefault=_ulBlue;
      }
    }

    return (CandyFolder_parent_WPFolder_wpRestoreState(somSelf, 
                                                       ulReserved));
}

SOM_Scope BOOL  SOMLINK candyfolder_wpSaveString(CandyFolder *somSelf, 
                                                 PSZ pszClass, 
                                                 ULONG ulKey, 
                                                 PSZ pszValue)
{
  char *pvImageDataTemp;
  BITMAPINFO2 * pbmpInfo2Temp;
  char *pvImageDataTemp2;
  BITMAPINFO2 * pbmpInfo2Temp2;
  BOOL bHaveMux=FALSE;

    CandyFolderData *somThis = CandyFolderGetData(somSelf);
    CandyFolderMethodDebug("CandyFolder","candyfolder_wpSaveString");

    TRY_LOUD(SAVE_STRING) {
      /* Check if we are a desktop folder */
      if(somResolveByName(somSelf, "wpIsCurrentDesktop")!=NULL) {
        if (strcmp(pszClass, "WPFolder") == 0) {
#if 0
          FILE *file;
          if((file=fopen("d:\\bg.txt","a"))!=NULLHANDLE) {
            sprintf(text, "Key: %d ",ulKey);
            fwrite(text, sizeof(char),strlen(text),file);
            fwrite(pszValue, sizeof(char),strlen(pszValue),file);
            sprintf(text, "\n");
            fwrite(text, sizeof(char),strlen(text),file);
            fclose(file);
          }
          DosBeep(2000, 1000);
#endif
          
          if( ulKey==2934 /* ||ulKey==2921*/ ) {
            if(!(_ulTrans & ID_COLORONLY)) {
              if(strnicmp(chrDesktopBG, pszValue, sizeof(chrDesktopBG))) {
                /* Desktop background changed. Reload the transparency bitmap. */
                strncpy(chrDesktopBG, pszValue, sizeof(chrDesktopBG));
                /* Protect the following with a semaphor later! Ths code may crash sometimes? */
                /* Get new image */
                if(! cfRequestMutex(10000)) {
                  bHaveMux=TRUE;
                  if(!readBitmapDataFromFile(chrDesktopBG, &pvImageDataTemp, & pbmpInfo2Temp )){
                    pvImageDataTemp=NULLHANDLE;
                    pbmpInfo2Temp=NULLHANDLE;
                  }
                  /* Save old mem  pointers */
                  pvImageDataTemp2=pvImageData;
                  pbmpInfo2Temp2=pbmpInfo2;
                  /* Switch to new image data */
                  pvImageData=pvImageDataTemp;
                  pbmpInfo2=pbmpInfo2Temp;
                  /* Free old image data */
                  if(pvImageDataTemp2)
                    if(DosFreeMem(pvImageDataTemp2))
                      DosBeep(100,700);
                  if(pbmpInfo2Temp2)
                    if(DosFreeMem(pbmpInfo2Temp2))
                      DosBeep(100,700);
                  //  cfReleaseMutex();
                }
                /* Cycle through all open folders and reload the background if transparency is selected */
                cfRefreshAllOpenFolderBG(somSelf);
              }
            }/* if(!(_ulTrans & ID_COLORONLY)) */
            else {            
              /* Color only selected for desktop. Discard the bitmap */
              strncpy(chrDesktopBG, "", sizeof(chrDesktopBG));
              if(! cfRequestMutex(10000)) {
                bHaveMux=TRUE;
                /* Save old mem  pointers */
                pvImageDataTemp2=pvImageData;
                pbmpInfo2Temp2=pbmpInfo2;
                /* Switch to new image data */
                pvImageData=NULL;
                pbmpInfo2=NULL;
                /* Free old image data */
                if(pvImageDataTemp2)
                  if(DosFreeMem(pvImageDataTemp2))
                    DosBeep(100,700);
                if(pbmpInfo2Temp2)
                  if(DosFreeMem(pbmpInfo2Temp2))
                    DosBeep(100,700);
                // cfReleaseMutex();
              }
              /* Cycle through all open folders and reload the background if transparency is selected */
              cfRefreshAllOpenFolderBG(somSelf);
            }/* else if(!(_ulTrans & ID_COLORONLY)) */
          }/* end of if( ulKey==2934 ) */
        }/* if (strcmp(pszClass, "WPFolder") == 0) */
      }/* if(somResolveByName(somSelf, "wpIsCurrentDesktop")!=NULL) */
    }
    CATCH(SAVE_STRING)
      {
      } END_CATCH;
      
      if(bHaveMux)
        cfReleaseMutex();
            
      return (CandyFolder_parent_WPFolder_wpSaveString(somSelf, 
                                                       pszClass, 
                                                       ulKey, pszValue));
}
    
SOM_Scope BOOL  SOMLINK candyfolder_wpRestoreString(CandyFolder *somSelf, 
                                                    PSZ pszClass, 
                                                    ULONG ulKey, 
                                                    PSZ pszValue, 
                                                    PULONG pcbValue)
{
  BOOL rc;
    CandyFolderData *somThis = CandyFolderGetData(somSelf);
    CandyFolderMethodDebug("CandyFolder","candyfolder_wpRestoreString");

    rc= (CandyFolder_parent_WPFolder_wpRestoreString(somSelf, 
                                                        pszClass, 
                                                        ulKey, 
                                                        pszValue, 
                                                        pcbValue));
    /* Check if we are a desktop folder */
    if(somResolveByName(somSelf, "wpIsCurrentDesktop")!=NULL) {
      if (strcmp(pszClass, "WPFolder") == 0) {
        if( ulKey==2934 /* ||ulKey==2921*/ ) {
          strncpy(chrDesktopBG, pszValue, sizeof(chrDesktopBG));
        }
      }
    }
    return rc;
}

SOM_Scope BOOL  SOMLINK candyfolder_wpSetup(CandyFolder *somSelf, 
                                            PSZ pszSetupString)
{
  char chrSetup[CCHMAXPATH+20];
  ULONG ulSize;
  char *chrPtr;
  int a;

  somTD_WPDesktop_wpIsCurrentDesktop isCurrentDesktopMethodPtr;

  CandyFolderData *somThis = CandyFolderGetData(somSelf);
  CandyFolderMethodDebug("CandyFolder","candyfolder_wpSetup");

  TRY_LOUD(WP_SETUP) {
    ulSize=sizeof(chrSetup);
    if(_wpScanSetupString(somSelf,pszSetupString,"BACKGROUND", chrSetup, &ulSize)) {
      if(_ulHaveToSave!=1) {/* Check if the transparency addon tries to change the background */
        /* The background changes. Not done by the addon. */
        
        /* Disable transparency for this folder */
        _ulTrans&=~ID_TRANSPARENCY;
        
        /* The WPS cycles through all views and repaints the bg with the new image */
        if(_hbmBG)
          GpiDeleteBitmap(_hbmBG);
        _hbmBG=NULLHANDLE;
      }
      
      /* Desktop folder needs special handling */
      if((isCurrentDesktopMethodPtr=(somTD_WPDesktop_wpIsCurrentDesktop)somResolveByName((WPDesktop*)somSelf, "wpIsCurrentDesktop"))!=NULL) {
        /* Check if we are the current desktop */
        if(isCurrentDesktopMethodPtr((WPDesktop*)somSelf)) {
          if(strnicmp(chrDesktopBG, chrSetup, sizeof(chrDesktopBG))) {
            /* There's a new background image. Force a reload of the image data (done in wpSaveString() */
            _wpSaveImmediate(somSelf);
          }
        }
      }
    }
    
    ulSize=sizeof(chrSetup);
    if(_wpScanSetupString(somSelf,pszSetupString,"TRANSPARENCY", chrSetup, &ulSize)) {
      ULONG ulTemp[4];
      for(a=0,chrPtr=strtok(chrSetup,", ") ; (chrPtr && a<=3); a++,chrPtr=strtok(NULL," ,") ) {
        ulTemp[a]=atoi(chrPtr);
      }
      _ulRed=(ulTemp[1]+127) & 0xff;
      _ulGreen=(ulTemp[2]+127) & 0xff;
      _ulBlue=(ulTemp[3]+127) & 0xff;
      if((isCurrentDesktopMethodPtr=(somTD_WPDesktop_wpIsCurrentDesktop)somResolveByName((WPDesktop*)somSelf, "wpIsCurrentDesktop"))!=NULL) {
        /* Check if we are the current desktop */
        if(isCurrentDesktopMethodPtr((WPDesktop*)somSelf)) {
          ulRedDefault=_ulRed;
          ulGreenDefault=_ulGreen;
          ulBlueDefault=_ulBlue;
        }
      }/* MethodPtr */
      else {
        if(ulTemp[0]==1)
          _ulTrans|=ID_TRANSPARENCY;
        else
          _ulTrans&=~ID_TRANSPARENCY;
        _cfRefreshContainerBackgrounds(somSelf, TRUE);
      }
    }/* TRANSPARENCY */
  }
  CATCH(WP_SETUP)
    {
    } END_CATCH;   
    
    return (CandyFolder_parent_WPFolder_wpSetup(somSelf, pszSetupString));
}

/**********************************************************/

SOM_Scope PSZ  SOMLINK candyfolderM_wpclsQueryTitle(M_CandyFolder *somSelf)
{
  static char classTitle[100]= {0};

    /* M_CandyFolderData *somThis = M_CandyFolderGetData(somSelf); */
    M_CandyFolderMethodDebug("M_CandyFolder","candyfolderM_wpclsQueryTitle");

    if(classTitle[0]==0) {
      hRessource=queryModuleHandle();
      if(!getMessage(classTitle,IDSTR_CLASSTITLE, sizeof(classTitle), hRessource, HWND_DESKTOP))
        strcpy(classTitle,"Candy folder");
    }

    return classTitle;

}

SOM_Scope ULONG  SOMLINK candyfolderM_wpclsQueryStyle(M_CandyFolder *somSelf)
{
    /* M_CandyFolderData *somThis = M_CandyFolderGetData(somSelf); */
    M_CandyFolderMethodDebug("M_CandyFolder","candyfolderM_wpclsQueryStyle");

    cfCreateMutex();
    
    return (M_CandyFolder_parent_M_WPFolder_wpclsQueryStyle(somSelf))|CLSSTYLE_DONTTEMPLATE/*|CLSSTYLE_NEVERTEMPLATE*/;
}


SOM_Scope void  SOMLINK candyfolderM_wpclsUnInitData(M_CandyFolder *somSelf)
{
    /* M_CandyFolderData *somThis = M_CandyFolderGetData(somSelf); */
    M_CandyFolderMethodDebug("M_CandyFolder","candyfolderM_wpclsUnInitData");

    cfCloseMutex();

    M_CandyFolder_parent_M_WPFolder_wpclsUnInitData(somSelf);
}

