#ifndef MUIEXTRA_H
#define MUIEXTRA_H 1

#ifndef MUIA_Framedisplay_Spec
#define MUIA_Framedisplay_Spec        0x80421794UL // V11 isg struct MUI_FrameSpec
#endif
#ifndef MUIA_Imagedisplay_Spec
#define MUIA_Imagedisplay_Spec        0x8042a547UL // V11 isg struct MUI_ImageSpec
#endif
#ifndef MUIA_Imageadjust_Type
#define MUIA_Imageadjust_Type         0x80422f2bUL // V11 i.. LONG
#endif
#ifndef MUIA_Prop_Release
#define MUIA_Prop_Release             0x80429839UL
#endif
#ifndef MUIA_Prop_DeltaFactor
#define MUIA_Prop_DeltaFactor         0x80427C5EUL
#endif
#ifndef MUIA_Prop_DoSmooth
#define MUIA_Prop_DoSmooth            0x804236ceUL // V4  i.. LONG
#endif
#ifndef MUIM_GoActive
#define MUIM_GoActive			      0x8042491aUL
#endif
#ifndef MUIM_GoInactive
#define MUIM_GoInactive 		      0x80422c0cUL
#endif
#ifndef MUIA_Group_Type
#define MUIA_Group_Type               0x8042e866UL /* V11 ..g LONG */
#endif
#ifndef MUIV_Group_Type_Horiz
#define MUIV_Group_Type_Horiz   1
#endif
#ifndef MUIM_Mccprefs_RegisterGadget
#define MUIM_Mccprefs_RegisterGadget  0x80424828UL // V20
#endif
#ifndef MUIA_Text_Copy
#define MUIA_Text_Copy                0x80427727UL /* V20 i.. BOOL              */
#endif
#ifndef MBQ_MUI_MAXMAX
#define MBQ_MUI_MAXMAX (10000)          /* use this for unlimited MaxWidth/Height */
#endif
#ifndef PopframeObject
#define PopframeObject MUI_NewObject(MUIC_Popframe
#endif
#ifndef PopimageObject
#define PopimageObject MUI_NewObject("Popimage.mui"
#endif
#ifndef CrawlingObject
#define CrawlingObject MUI_NewObject("Crawling.mcc"
#endif
#ifndef MUIM_CreateDragImage
#define MUIM_CreateDragImage          0x8042eb6fUL /* V18 */ /* Custom Class */
#endif
#ifndef MUIM_DeleteDragImage
#define MUIM_DeleteDragImage          0x80423037UL /* V18 */ /* Custom Class */
#endif
#ifndef MUIA_List_Prop_First
#define MUIA_List_Prop_First          0x80429df3UL /* V? ??? */
#endif
#ifndef MUIA_List_Prop_Entries
#define MUIA_List_Prop_Entries        0x8042a8f5UL /* V? ??? */
#endif
#ifndef MUIA_List_Prop_Visible
#define MUIA_List_Prop_Visible        0x804273e9UL /* V? ??? */
#endif
#ifndef MUIA_Prop_TrueFirst
#define MUIA_Prop_TrueFirst           0x804205dcUL /* V16 ..g LONG */
#endif
#ifndef MADF_DRAWACTIVE
#define MADF_DRAWACTIVE        (1<< 2)
#endif
#ifndef MADF_DRAWOUTER
#define MADF_DRAWOUTER         (1<<11)
#endif
#ifndef MADF_VISIBLE
#define MADF_VISIBLE           (1<<14) // The object is visible
#endif
#ifndef MADF_DRAWALL
#define MADF_DRAWALL           (MADF_DRAWACTIVE | MADF_DRAWOUTER | MADF_DRAWOBJECT)
#endif
#ifndef MUIA_Group_Forward
#define MUIA_Group_Forward            0x80421422UL
#endif
#ifndef MUII_PopFont
#define MUII_PopFont           42
#endif
#ifndef MUIM_Application_UnpushMethod
#define MUIM_Application_UnpushMethod 0x804211ddUL /* V20 */
#endif

struct MUI_ImageSpec
{
  char buf[64];
};

#if !defined(__AROS__)
struct MUI_FrameSpec
{
  char buf[8];
};

struct MUIP_DeleteDragImage { ULONG MethodID; struct MUI_DragImage *di; };              /* Custom Class */
struct MUIP_CreateDragImage { ULONG MethodID; LONG touchx; LONG touchy; ULONG flags; }; /* Custom Class */
#endif // !__AROS

#endif /* MUIEXTRA_H */
