﻿/*
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * Use of this source code is governed by the Live2D Open Software license
 * that can be found at http://live2d.com/eula/live2d-open-software-license-agreement_en.html.
 */

#pragma once

#include "Framework/src/CubismFramework.hpp"
#include "Framework/src/Math/CubismMatrix44.hpp"
#include "Framework/src/Type/csmVector.hpp"
#include "LAppModel.hpp"

/**
 * @brief サンプルアプリケーションにおいてCubismModelを管理するクラス<br>
 *         モデル生成と破棄、タップイベントの処理、モデル切り替えを行う。
 *
 */
class LAppLive2DManager
{

public:
    /**
     * @brief   クラスのインスタンス（シングルトン）を返す。<br>
     *           インスタンスが生成されていない場合は内部でインスタンを生成する。
     *
     * @return  クラスのインスタンス
     */
    static LAppLive2DManager* GetInstance();

    /**
     * @brief   クラスのインスタンス（シングルトン）を解放する。
     *
     */
    static void ReleaseInstance();

    /**
     * @brief   現在のシーンで保持しているモデルを返す
     *
     * @param[in]   no  モデルリストのインデックス値
     * @return      モデルのインスタンスを返す。インデックス値が範囲外の場合はNULLを返す。
     */
    LAppModel* GetModel(Csm::csmUint32 no) const;

    /**
     * @brief   現在のシーンで保持しているモデルの数を返す
     *
     * @return  モデルリストの数
     */
    Csm::csmUint32 GetModelCount() const;

    /**
     * @brief   現在のシーンで保持しているすべてのモデルを解放する
     *
     */
    void ReleaseAllModel();

    /**
     * @brief   モデル描画用のレンダラを再構築する。
     *
     */
    void RecreateRenderer() const;

    /**
     * @brief   モデル描画用のView行列をセットする。
     *
     * @param[in]   matrix   View行列
     *
     */
    void SetViewMatrix(Csm::CubismMatrix44* matrix);

    /**
     * @brief   画面をドラッグしたときの処理
     *
     * @param[in]   x   画面のX座標
     * @param[in]   y   画面のY座標
     */
    void OnDrag(Csm::csmFloat32 x, Csm::csmFloat32 y) const;

    /**
     * @brief   画面をタップしたときの処理
     *
     * @param[in]   x   画面のX座標
     * @param[in]   y   画面のY座標
     */
    void OnTap(Csm::csmFloat32 x, Csm::csmFloat32 y);

    /**
     * @brief   画面を更新するときの処理
     *          モデルの更新処理および描画処理を行う
     */
    void OnUpdate() const;

    /**
     * @brief   次のシーンに切り替える<br>
     *           サンプルアプリケーションではモデルセットの切り替えを行う。
     */
    void NextScene();

    /**
     * @brief   シーンを切り替える<br>
     *           サンプルアプリケーションではモデルセットの切り替えを行う。
     */
    void ChangeScene(Csm::csmInt32 index);

private:
    /**
     * @brief  コンストラクタ
     */
    LAppLive2DManager();

    /**
     * @brief  デストラクタ
     */
    virtual ~LAppLive2DManager();

    Csm::CubismMatrix44*        _viewMatrix;    ///< モデル描画に用いるView行列
    Csm::csmVector<LAppModel*>  _models;        ///< モデルインスタンスのコンテナ
    Csm::csmInt32               _sceneIndex;    ///< 表示するシーンのインデックス値
};
