#include <Novice.h>

#include "BaseData.hpp"
#include "SpriteClass.hpp"

#include "Particle.hpp"

#include "Camera.hpp"


#include "Math.hpp"
#include "Vector2.hpp"
#include "Matrix2x2.hpp"

#include "Easing.hpp"


#include "Controller.hpp"


#include "Map.hpp"


#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"



const char kWindowTitle[] = "LC1A_05_オヌキセイヤ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, ScreenSize.x, ScreenSize.y);
//	Novice::SetWindowMode(kFullscreen);

	// キー入力結果を受け取る箱

	ImportTexture();



	unsigned int pressFlame = 0;

	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].Reset();
	
	}

	Player player[3]={ Player(TestCircleTexture, 32, 32, 0, 1),Player(TestCircleTexture, 32, 32, 0, 1),Player(TestCircleTexture, 32, 32, 0, 1) };

	for (int i = 0; i < playerCount; i++) {
		player[i].Reset(i);
	}

	Particle particleTest;
	for (int i = 0; i < ParticleMax; i++) {
		particleTest.Reset(i);
	}
	
	Bullet::BulletReset();

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


		TextureUpdate();

		flame++;
		particleTest.CheckDelete();
		for (int i = 0; i < playerCount; i++) {
			player[i].EntityMoveInput();

			if (player[i].velocity.Length() != 0 || isKeyPress(DIK_SPACE)) {
				particleTest.Spawn(player[i].position);
			}
		}

		particleTest.Update();

		for (int i = 0; i < EnemyMax; i++) {
			enemy[i].Despawn();
		}


		if (isKeyTrigger(DIK_A)) {
			for (int i = 0; i < EnemyMax; i++) {
				if (!enemy[i].isAlive) {
					enemy[i].Spawn();
					break;
				}
			}/*
			enemy[0].textureHandle = TestUVTexture;
			enemy[0].srcH = 512;
			enemy[0].srcW = 512;
			enemy[0].color = 0xFFFFFFFF;


			enemy[0].needNextFlame = 0;
			enemy[0].maxFlame = 1;*/

		}

		for (int i = 0; i < playerCount; i++) {
			player[i].EntityUpdate();
		}


		if (isKeyTrigger(DIK_B)) {
			enemy[0].position = MapCentor;
		}

		for (int i = 0; i < EnemyMax; i++) {
			enemy[i].EntityMoveUpdate();
		}

		for (int i = 0; i < playerCount; i++) {
			player[i].EnemyHit();
		}

		Bullet::BulletUpdate();
		Bullet::BulletDelete();
		Bullet::BulletEnemyHit();
	//	Bullet::BulletReset();

		
		Camera::Update();

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Bullet::DrawBullet();

		//Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, 0x000000FF, kFillModeSolid);
		enemy[0].position.Vector2Printf(0, 0);
		PolarToVector2(Vector2ToPolar(player[0].position - MapCentor)).Vector2Printf(0, 50);

		Novice::DrawLine(MapCentor.x, MapCentor.y, MapCentor.x + PolarToVector2(player[0].nowPolar).x,ToWorld( MapCentor.y + PolarToVector2(player[0].nowPolar).y), RED);

		Novice::ScreenPrintf(10, 100, "%.3f", Length(Bullet::bullet[0].position, enemy[0].position) - (Bullet::bullet[0].radius + enemy[0].radius));

		Novice::DrawEllipse(MiddleCentor.x + Camera::scroll.x, ToWorld(MiddleCentor.y + Camera::scroll.y), MapRadius, MapRadius, 0.0f, 0xFFFFFFFF, kFillModeWireFrame);

		Novice::DrawEllipse(MiddleCentor.x + Camera::scroll.x, ToWorld(MiddleCentor.y + Camera::scroll.y), 64, 64, 0.0f, 0x00FF00FF, kFillModeSolid);

	//	Novice::DrawEllipse(particleTest.particles[0].position.x, ToWorld(particleTest.particles[0].position.y), 100, 100, 0.0f, 0x00FF0077, kFillModeSolid);


		particleTest.Draw();

		for (int i = 0; i < playerCount; i++) {
			player[i].DrawEntity();
		}

		for (int i = 0; i < EnemyMax; i++) {
			if (enemy[i].isAlive) {
				enemy[i].DrawEntity();
			}
		}
	//	enemy[0].DrawEntity();
		
		Novice::ScreenPrintf(100, 100, "bullet.isAlive %d", Bullet::bullet[0].isAlive);
		Novice::ScreenPrintf(100, 150, "bullet.x %f", Bullet::bullet[0].position.x);
		Novice::ScreenPrintf(100, 170, "bullet.y %f", Bullet::bullet[0].position.y);
		Novice::ScreenPrintf(100, 250, "velocity.x %f", player[0].velocity.x);
		Novice::ScreenPrintf(100, 270, "velocity.y %f", player[0].velocity.y);
		Novice::ScreenPrintf(100, 410, "%d / %d",(enemy[0].useFlamePointer / enemy[0].needNextFlame)% enemy[0].maxFlame * enemy[0].srcW, (enemy[0].useFlamePointer));
		if (enemy[0].srcX != 0) {
			Novice::ScreenPrintf(100, 410, "%d / %d", ((int)(((SpriteClass::useFlamePointer)) / (int)(enemy[0].needNextFlame)) % (int)(enemy[0].maxFlame)) *(enemy[0].srcW), SpriteClass::useFlamePointer);

		}

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
