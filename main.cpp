#include <Novice.h>
#include <cmath>
#include <assert.h>
#include "Vector3.h"
#include "Matrix4x4.h"

const char kWindowTitle[] = "LE2A_11_トヨダユウキ";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

/// <summary>
/// 3次元ベクトルの要素表示をする関数
/// </summary>
/// <param name="x">横</param>
/// <param name="y">縦</param>
/// <param name="vector">表示するベクトル</param>
/// <param name="label">名前</param>
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%0.2f", vector.x); // x
	Novice::ScreenPrintf(x + kColumnWidth, y, "%0.2f", vector.y); // y
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%0.2f", vector.z); // z
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

/// <summary>
/// 4x4行列の要素表示をする関数
/// </summary>
/// <param name="x">横</param>
/// <param name="y">縦</param>
/// <param name="matrix">表示する行列</param>
/// <param name="Name">名前</param>
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* Name) {

	Novice::ScreenPrintf(x, y, "%s", Name);

	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			// 要素描画
			Novice::ScreenPrintf(
				x + column * kColumnWidth,
				y + row * kRowHeight + kRowHeight,
				"%6.02f",
				matrix.m[row][column]
			);
		}
	}
}

/// <summary>
/// 行列の乗算
/// </summary>
/// <param name="m1">乗算する行列1</param>
/// <param name="m2">乗算する行列2</param>
/// <returns></returns>
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {

	// 結果格納用
	Matrix4x4 result;

	// 計算処理
	result.m[0][0] = (m1.m[0][0] * m2.m[0][0]) + (m1.m[0][1] * m2.m[1][0]) + (m1.m[0][2] * m2.m[2][0]) + (m1.m[0][3] * m2.m[3][0]);
	result.m[1][0] = (m1.m[1][0] * m2.m[0][0]) + (m1.m[1][1] * m2.m[1][0]) + (m1.m[1][2] * m2.m[2][0]) + (m1.m[1][3] * m2.m[3][0]);
	result.m[2][0] = (m1.m[2][0] * m2.m[0][0]) + (m1.m[2][1] * m2.m[1][0]) + (m1.m[2][2] * m2.m[2][0]) + (m1.m[2][3] * m2.m[3][0]);
	result.m[3][0] = (m1.m[3][0] * m2.m[0][0]) + (m1.m[3][1] * m2.m[1][0]) + (m1.m[3][2] * m2.m[2][0]) + (m1.m[3][3] * m2.m[3][0]);

	result.m[0][1] = (m1.m[0][0] * m2.m[0][1]) + (m1.m[0][1] * m2.m[1][1]) + (m1.m[0][2] * m2.m[2][1]) + (m1.m[0][3] * m2.m[3][1]);
	result.m[1][1] = (m1.m[1][0] * m2.m[0][1]) + (m1.m[1][1] * m2.m[1][1]) + (m1.m[1][2] * m2.m[2][1]) + (m1.m[1][3] * m2.m[3][1]);
	result.m[2][1] = (m1.m[2][0] * m2.m[0][1]) + (m1.m[2][1] * m2.m[1][1]) + (m1.m[2][2] * m2.m[2][1]) + (m1.m[2][3] * m2.m[3][1]);
	result.m[3][1] = (m1.m[3][0] * m2.m[0][1]) + (m1.m[3][1] * m2.m[1][1]) + (m1.m[3][2] * m2.m[2][1]) + (m1.m[3][3] * m2.m[3][1]);

	result.m[0][2] = (m1.m[0][0] * m2.m[0][2]) + (m1.m[0][1] * m2.m[1][2]) + (m1.m[0][2] * m2.m[2][2]) + (m1.m[0][3] * m2.m[3][2]);
	result.m[1][2] = (m1.m[1][0] * m2.m[0][2]) + (m1.m[1][1] * m2.m[1][2]) + (m1.m[1][2] * m2.m[2][2]) + (m1.m[1][3] * m2.m[3][2]);
	result.m[2][2] = (m1.m[2][0] * m2.m[0][2]) + (m1.m[2][1] * m2.m[1][2]) + (m1.m[2][2] * m2.m[2][2]) + (m1.m[2][3] * m2.m[3][2]);
	result.m[3][2] = (m1.m[3][0] * m2.m[0][2]) + (m1.m[3][1] * m2.m[1][2]) + (m1.m[3][2] * m2.m[2][2]) + (m1.m[3][3] * m2.m[3][2]);

	result.m[0][3] = (m1.m[0][0] * m2.m[0][3]) + (m1.m[0][1] * m2.m[1][3]) + (m1.m[0][2] * m2.m[2][3]) + (m1.m[0][3] * m2.m[3][3]);
	result.m[1][3] = (m1.m[1][0] * m2.m[0][3]) + (m1.m[1][1] * m2.m[1][3]) + (m1.m[1][2] * m2.m[2][3]) + (m1.m[1][3] * m2.m[3][3]);
	result.m[2][3] = (m1.m[2][0] * m2.m[0][3]) + (m1.m[2][1] * m2.m[1][3]) + (m1.m[2][2] * m2.m[2][3]) + (m1.m[2][3] * m2.m[3][3]);
	result.m[3][3] = (m1.m[3][0] * m2.m[0][3]) + (m1.m[3][1] * m2.m[1][3]) + (m1.m[3][2] * m2.m[2][3]) + (m1.m[3][3] * m2.m[3][3]);

	return result;

}

/// <summary>
/// 平行移動行列
/// </summary>
/// <param name="translate">三次元ベクトル</param>
/// <returns>平行移動した後の行列</returns>
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {

	// 結果格納用
	Matrix4x4 result;

	// 生成処理
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;

	return result;

}

/// <summary>
/// 拡大縮小行列
/// </summary>
/// <param name="scale">三次元ベクトル</param>
/// <returns></returns>
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {

	// 結果格納用
	Matrix4x4 result;

	// 生成処理
	result.m[0][0] = scale.x;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = scale.y;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = scale.z;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;

}

/// <summary>
/// x軸方向の回転行列を作成する関数
/// </summary>
/// <param name="radian">回転角度</param>
/// <returns>回転後の行列</returns>
Matrix4x4 MakeRotateXMatrix(float radian) {

	// 結果格納用
	Matrix4x4 result;

	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = std::cosf(radian);
	result.m[1][2] = std::sinf(radian);
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = -(std::sinf(radian));
	result.m[2][2] = std::cosf(radian);
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

/// <summary>
/// y軸方向の回転行列を作成する関数
/// </summary>
/// <param name="radian">回転角度</param>
/// <returns>回転後の行列</returns>
Matrix4x4 MakeRotateYMatrix(float radian) {

	// 結果格納用
	Matrix4x4 result;

	result.m[0][0] = std::cosf(radian);
	result.m[0][1] = 0.0f;
	result.m[0][2] = -(std::sinf(radian));
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = std::sinf(radian);
	result.m[2][1] = 0.0f;
	result.m[2][2] = std::cosf(radian);
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

/// <summary>
/// z軸方向の回転行列を作成する関数
/// </summary>
/// <param name="radian">回転角度</param>
/// <returns>回転後の行列</returns>
Matrix4x4 MakeRotateZMatrix(float radian) {

	// 結果格納用
	Matrix4x4 result;

	result.m[0][0] = std::cosf(radian);
	result.m[0][1] = std::sinf(radian);
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = -(std::sinf(radian));
	result.m[1][1] = std::cosf(radian);
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

/// <summary>
/// 全ての軸の回転行列を作成する関数
/// </summary>
/// <param name="rotate">回転角</param>
/// <returns>全ての軸の回転行列</returns>
Matrix4x4 MakeRotateXYZMatrix(const Vector3& rotate) {

	// 結果格納用
	Matrix4x4 result{};

	// 計算一時保存用
	Matrix4x4 tempXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 tempYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 tempZMatrix = MakeRotateZMatrix(rotate.z);

	// 計算処理
	result = Multiply(tempXMatrix, Multiply(tempYMatrix, tempZMatrix));

	return result;

}

/// <summary>
/// アフィン変換行列を生成する関数
/// </summary>
/// <param name="scale">拡大縮小行列</param>
/// <param name="rotate">回転行列</param>
/// <param name="translate">平行移動行列</param>
/// <returns>アフィン変換された行列</returns>
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {

	// 結果格納用
	Matrix4x4 result;

	// 計算処理
	Matrix4x4 S = MakeScaleMatrix(scale);
	Matrix4x4 R = MakeRotateXYZMatrix(rotate);
	Matrix4x4 T = MakeTranslateMatrix(translate);

	result.m[0][0] = S.m[0][0] * R.m[0][0];
	result.m[0][1] = S.m[0][0] * R.m[0][1];
	result.m[0][2] = S.m[0][0] * R.m[0][2];
	result.m[0][3] = 0.0f;

	result.m[1][0] = S.m[1][1] * R.m[1][0];
	result.m[1][1] = S.m[1][1] * R.m[1][1];
	result.m[1][2] = S.m[1][1] * R.m[1][2];
	result.m[1][3] = 0.0f;

	result.m[2][0] = S.m[2][2] * R.m[2][0];
	result.m[2][1] = S.m[2][2] * R.m[2][1];
	result.m[2][2] = S.m[2][2] * R.m[2][2];
	result.m[2][3] = 0.0f;

	result.m[3][0] = T.m[3][0];
	result.m[3][1] = T.m[3][1];
	result.m[3][2] = T.m[3][2];
	result.m[3][3] = 1.0f;

	return result;

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	/// 変数宣言
	Vector3 scale = { 1.2f, 0.79f, -2.1f };
	Vector3 rotate = { 0.4f, 1.43f, -0.8f };
	Vector3 translate = { 2.7f, -4.15f, 1.57f };

	Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// アフィン変換行列の要素表示
		MatrixScreenPrintf(0, 0, worldMatrix, "worldMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
