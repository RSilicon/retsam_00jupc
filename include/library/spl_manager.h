/*---------------------------------------------------------------------------*
  Project:  simple particle library
  File:     spl_manager.h

  ＳＰＬマネージャ

  $Id: spl_manager.h,v 1.3 2005/11/09 09:53:26 matsuda Exp $
  $Log: spl_manager.h,v $
  Revision 1.3  2005/11/09 09:53:26  matsuda
  SPLライブラリが更新されたので更新

  Revision 1.9  2005/08/30 09:15:30  okane_shinji
  SPL_SetDrawOrderを追加

  Revision 1.8  2005/06/27 07:46:14  okane_shinji
  ﾊ｣ｿ�･ﾞ･ﾍ｡ｼ･ｸ･网�ｼ隍�ｰｷ､ｦ､ﾈ､ｭ､ﾇ､箙ﾗｻｻ･ｵ･､･ｯ･�ﾀﾟﾄ熙ｬﾍｭｸ�､ﾋ､ﾊ､�､隍ｦ､ﾋｽ､ﾀｵ

  Revision 1.7  2005/01/20 04:20:48  okane_shinji
  パーティクル数とエミッタ数を取得する関数追加

  Revision 1.6  2004/11/26 06:07:31  okane_shinji
  機能追加

  Revision 1.5  2004/08/17 05:40:39  okane_shinji
  パーティクルのポリゴン属性のmiscフラグを変更できるように変更。

  Revision 1.4  2004/07/05 07:33:02  okane_shinji
  ポリゴンID割り当てを可変に。関数名を変更。

  Revision 1.3  2004/06/23 07:21:21  okane_shinji
  カラーアニメ、ループ再生、ポリゴン、ディレクショナルビルボードの改良

  Revision 1.2  2004/05/24 09:44:09  konoh
  ■メモリ確保の方法をユーザコールバックで行うように変更

  Revision 1.1  2004/04/08 00:23:26  konoh
  (none)

 *---------------------------------------------------------------------------*/

#ifndef __SPL_MANAGER_H__
#define __SPL_MANAGER_H__

#include "spl_emitter.h"
#include "spl_particle.h"
#include "spl_resource.h"
#include "spl_texture.h"

/* 構造体など -------------------------------------------------------------- */

// メモリ確保コールバック
typedef void* (*SPLAlloc)(u32);

// マネージャ構造体
typedef struct SPLManager
{
    // ヒープ関係
    SPLAlloc alloc;

    // リスト関係
    SPLEmitterList act_emtr_list;
    SPLEmitterList ina_emtr_list;
    SPLParticleList ina_ptcl_list;

    // リソース関係
    SPLResource* res_ary;
    SPLTexture*  tex_ary;
    u16 res_num;
    u16 tex_num;

    u16 max_emtr_num;
    u16 max_ptcl_num;
    
    //u16 min_polygonID ;
    //u16 max_polygonID ;

    struct
    {
        u32 min:6;
        u32 max:6;
        u32 current:6;
        u32 fix:6;
        u32 drawOrder:1;
        u32 reserved:7;
    } polygonID ;

    s32 misc_flag ;

    // 描画・計算に必要なマネージャのカレント環境を格納するための構造体
    struct
    {
        // 現在処理中のエミッタ
        SPLEmitter* p_emtr ;

        // 現在適用されているカメラ
        const MtxFx43*    p_cmr  ;
    } current_state ;


    u16 uCurrentCycle ;
    u16 reserved ;

} SPLManager;

/* ------------------------------------------------------------------------- */

#define SPL_MANAGER_DRAWORDER_INREVERSE 0
#define SPL_MANAGER_DRAWORDER_INTURN    1

/* ------------------------------------------------------
 * 描画順を設定
 *------------------------------------------------------*/
static inline void SPL_SetDrawOrder( SPLManager* p_mgr, int flag )
{
    p_mgr->polygonID.drawOrder = flag ;
}

/* ------------------------------------------------------
 * ポリゴン属性のmiscフラグを設定
 *------------------------------------------------------*/
static inline void SPL_SetPolygonAttrMiscFlag( SPLManager* p_mgr, int flag )
{
    p_mgr->misc_flag = flag ;
}

/* ------------------------------------------------------
 * 現在有効なエミッタの数を取得
 *------------------------------------------------------*/
static inline s32 SPL_GetEmitterNum( SPLManager* p_mgr )
{
    return p_mgr->act_emtr_list.node_num ;
}

/* ------------------------------------------------------
 * 現在有効なパーティクルの数を取得
 *------------------------------------------------------*/
static inline s32 SPL_GetWholeParticleNum( SPLManager* p_mgr )
{
    return p_mgr->max_ptcl_num - p_mgr->ina_ptcl_list.node_num ;
}



#endif
