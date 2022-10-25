#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "BaseData.hpp"
#include "SpriteClass.hpp"

#include "Number.hpp"
#include "Particle.hpp"

#include "Camera.hpp"
#include "Scene.hpp"

#include "Fade.hpp"


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
#include "Boss.hpp"



const char kWindowTitle[] = "LC1A_05_オヌキセイヤ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, ScreenSize.x, ScreenSize.y);
	//	Novice::SetWindowMode(kFullscreen);

		// キー入力結果を受け取る箱

	//DefaultNumberSet();
	DefaultNumberTexture[0] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/0.png");
	DefaultNumberTexture[1] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/1.png");
	DefaultNumberTexture[2] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/2.png");
	DefaultNumberTexture[3] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/3.png");
	DefaultNumberTexture[4] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/4.png");
	DefaultNumberTexture[5] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/5.png");
	DefaultNumberTexture[6] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/6.png");
	DefaultNumberTexture[7] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/7.png");
	DefaultNumberTexture[8] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/8.png");
	DefaultNumberTexture[9] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/9.png");


	const int HurtWithHeart = Novice::LoadTexture("./Resources/Texture/Title/HurtWithHeart.png");
	const int HwHBG = Novice::LoadTexture("./Resources/Texture/Title/HwHBG.png");
	const int HeartsBG = Novice::LoadTexture("./Resources/Texture/Title/Hearts.png");
	const int SpaceBG = Novice::LoadTexture("./Resources/Texture/Title/space.png");

	const int TitleHeartTexture = Novice::LoadTexture("./Resources/Texture/Title/titleHeart.png");


	const int WhiteBG = Novice::LoadTexture("./Resources/Texture/Background/WhiteBG.png");


	const int GameOver = Novice::LoadTexture("./Resources/Texture/Title/GameOver.png");

	const int HeartCount = 20;
	Vector2 HeartPosition[HeartCount] = { };
	int HeartSize[HeartCount] = { };
	int HeartLifeSpan[HeartCount] = { };

	ImportTexture();

	unsigned int pressFlame = 0;

	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].Reset();
	}


	int inputFlame = 0;
	bool canInput = false;

	int sceneFlame = 0;


	Player player[3] = { Player(Novice::LoadTexture("./Resources/Texture/Entity/Player/Idle/Heart.png"), 224, 224, 0, 1),Player(Novice::LoadTexture("./Resources/Texture/Entity/Player/Idle/Heart.png"), 224, 224, 0, 1),Player(TestCircleTexture, 32, 32, 0, 1) };

	for (int i = 0; i < playerCount; i++) {
		player[i].Reset(i);
	}

	Particle particleTest;
	Particle particleCircle;

	/*const int DefaultNumberTexture[10]{
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/0.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/1.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/2.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/3.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/4.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/5.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/6.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/7.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/8.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/9.png") };*/

	Number comboText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));

	Number killText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	Number aliveText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	Number totalText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	/*(
		{
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/0.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/1.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/2.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/3.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/4.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/5.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/6.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/7.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/8.png"),
		Novice::LoadTexture("./Resources/Texture/UI/Number/Default/9.png")
		}
	);*/
	comboText.color = 0x00000044;

	Bullet::BulletReset();



	Boss boss;



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

		fadeClass.FadeUpdate();


		switch (Scene::nowScene)
		{
		case Scene::TitleScene:

			inputFlame = 0;
			canInput = false;

			if (fadeClass.isFinish() && Scene::preScene == Scene::GameScene) {
				Scene::nowScene = Scene::GameScene;
			}

			break;
		case Scene::GameScene:
			if (fadeClass.isFinish() && Scene::preScene == Scene::ResultScene) {
				Scene::nowScene = Scene::ResultScene;
			}
			break;
		case Scene::ResultScene:
			if (fadeClass.isFinish() && Scene::preScene == Scene::TitleScene) {
				Scene::nowScene = Scene::TitleScene;
			}
			break;
		default:
			break;
		}


		TextureUpdate();

		switch (Scene::nowScene)
		{
		case Scene::TitleScene:
			for (int i = 0; i < HeartCount; i++) {
				if (HeartLifeSpan[i] <= 0) {
					HeartLifeSpan[i] = GetRandom(60 * 1, 60 * 4);
					HeartSize[i] = GetRandom(32, 32 * 3);
					HeartPosition[i] = Vector2{ (float)GetRandom(0, ScreenSize.x),(float)GetRandom(0,ScreenSize.y) };
				}
				else {
					HeartLifeSpan[i]--;
					HeartPosition[i] += {(float)(cos(Degree2Radian(HeartLifeSpan[i] * 5))) * 4, 3};
				}
			}

			if (!fadeClass.isActive() && (fadeClass.fadeColor & 0xFF) == 0x00 && Scene::preScene == Scene::TitleScene) {
				fadeClass.FlameEnd();
			}


			if (!fadeClass.isActive() && Scene::preScene == Scene::TitleScene) {
				fadeClass.FadeSetting(easeInExpo);
				//	fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFFFF);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleCentor, MiddleCentor, 0x00000000, 60 * 1.5);
			}

			if (isKeyPress(DIK_SPACE)) {

				Scene::preScene = Scene::GameScene;

				//	if (!fadeClass.isActive()) {
				fadeClass.FadeSetting(easeInExpo);
				fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFF00);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleCentor, MiddleCentor, 0xFFFFFFFF, 60 * 1.5);
				//	}

			}
			break;
		case Scene::GameScene:
			if (!fadeClass.isActive() && (fadeClass.fadeColor & 0xFF) == 0x00 && Scene::preScene == Scene::GameScene) {
				fadeClass.FlameEnd();
				inputFlame++;
			}
			else if (inputFlame < 60 && inputFlame != 0) {
				inputFlame++;
			}
			if (inputFlame >= 60) {
				canInput = true;
				inputFlame = 0;
			}

			if (!fadeClass.isActive() && Scene::preScene == Scene::GameScene) {
				fadeClass.FadeSetting(easeInExpo);
				//	fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFFFF);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleCentor, MiddleCentor, 0xFFFFFF00, 60 * 1.5);
			}

			if (isKeyPress(DIK_O)) {


				Scene::preScene = Scene::ResultScene;

				//if (!fadeClass.isActive()) {
				fadeClass.FadeSetting(easeInExpo);
				fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFF00);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleLeft, MiddleCentor, 0xFFFFFFFF, 60 * 1.5);
				//}

			}

			break;
		case Scene::ResultScene:
			if (!fadeClass.isActive() && (fadeClass.fadeColor & 0xFF) == 0x00 && Scene::preScene == Scene::ResultScene) {
				fadeClass.FlameEnd();
			}


			if (!fadeClass.isActive() && Scene::preScene == Scene::ResultScene) {
				fadeClass.FadeSetting(easeInExpo);
				//	fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFFFF);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleLeft, MiddleCentor, 0xFFFFFF00, 60 * 1.5);
			}


			if (isKeyPress(DIK_SPACE)) {


				Scene::preScene = Scene::TitleScene;

				//if (!fadeClass.isActive()) {
				fadeClass.FadeSetting(easeLinear);
				fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0x00000000);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleLeft, MiddleCentor, 0x000000FF, 60 * 2.5);
				//}

			}
			break;
		default:
			break;
		}


		switch (Scene::nowScene)
		{
		case Scene::TitleScene:

			break;
		case Scene::GameScene:
			if (canInput) {
				flame++;
			}

			particleTest.CheckDelete();
			particleCircle.CheckDelete();

			if (canInput) {
				for (int i = 0; i < playerCount; i++) {
					player[i].EntityMoveInput();

					if (player[i].velocity.Length() != 0 || isKeyPress(DIK_SPACE)) {
						particleTest.Spawn(player[i].position);
					}
				}
			}

			particleTest.Update();
			particleCircle.Update();

			for (int i = 0; i < EnemyMax; i++) {
				if (enemy[i].isAlive && BallCollision(enemy[i].position, enemy[i].radius, MapCentor, 30)) {
					particleTest.Spawn(enemy[i].position, 5, 0x00FF00FF);
				}
				enemy[i].Despawn();
			}


			if (isKeyTrigger(DIK_A)) {
				for (int i = 0; i < EnemyMax; i++) {
					if (!enemy[i].isAlive) {
						enemy[i].Spawn();
						break;
					}
				}
			}

			if (isKeyTrigger(DIK_E)) {
				for (int i = 0; i < EnemyMax; i++) {
					if (!enemy[i].isAlive) {
						//	enemy[i].Spawn();


						enemy[i].textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
						enemy[i].srcH = 128;
						enemy[i].srcW = 128;

						enemy[i].needNextFlame = 30;
						enemy[i].maxFlame = 2;

						enemy[i].radius = 32;
						enemy[i].color = 0xFF0000FF;

						PolarCoordinates test;

						test.radius = GetRandom(MapRadius * 2, MapRadius * 2.5);

						test.theta = Degree2Radian(GetRandom(0, 360));

						enemy[i].position = PolarToVector2(test) + MapCentor;

						enemy[i].speed = 5.0f;

						enemy[i].velocity = (PolarToVector2(test) * -1).Nomalize();

						enemy[i].isAlive = true;

						break;
					}
				}
			}

			player[1].nowPolar.theta = player[0].nowPolar.theta + Degree2Radian(360 / playerCount);
			player[1].prePolar.theta = player[0].prePolar.theta + Degree2Radian(360 / playerCount);
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
				if (player[i].velocity.Length() != 0) {
					for (int j = 0; j < EnemyMax; j++) {
						if (enemy[j].isAlive) {
							if (BallCollision(player[i].position, player[i].radius, enemy[j].position, enemy[j].radius)) {
								particleTest.Spawn(enemy[j].position, 10, 0x000000FF);
							}
						}
					}
				}
				player[i].EnemyHit();
			}

			Bullet::BulletUpdate();
			Bullet::BulletDelete();
			Bullet::BulletEnemyHit();
			//	Bullet::BulletReset();






			Camera::Update();
			comboText.NumberUpdate(flame);
			comboText.setDrawPosition(Number::Centor);


			break;
		case Scene::ResultScene:
			break;
		default:
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Bullet::bullet[0].position.Vector2Printf(0, 0);

		switch (Scene::nowScene)
		{
		case Scene::TitleScene:

			Novice::DrawSprite(0, 0, HwHBG, 1, 1, 0.0f, 0xFFFFFFFF);
			//Novice::DrawSprite(0, 0, HeartsBG, 1, 1, 0.0f, 0xFFFFFFFF);
			for (int i = 0; i < HeartCount; i++) {
				if (HeartLifeSpan[i] > 0) {
					DrawQuadFunction(HeartPosition[i], Vector2{ (float)HeartSize[i], (float)HeartSize[i] }, 0, 0, 91, 91, TitleHeartTexture, ColorEasingMove(0xFFFFFFAA, 0xFFFFFF00, HeartLifeSpan[i] <= 60 ? 1 - ((float)HeartLifeSpan[i]) / 60 : 0));
				}
			}


			Novice::DrawSprite(0, 0, HurtWithHeart, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(0, 0, SpaceBG, 1, 1, 0.0f, ColorEasingMove(0xFFFFFFFF, 0xFFFFFF00, cos(Degree2Radian(TextureFlame * 5))));

			//	DrawQuadFunction(MiddleCentor, { 2048,1280 }, 0, 0, 1024, 640, WhiteBG, WHITE);

			break;
		case Scene::GameScene:

			DrawQuadFunction(MiddleCentor, { 2048,1280 }, 0, 0, 1024, 640, WhiteBG, WHITE);
			/*
			Novice::SetBlendMode(BlendMode::kBlendModeAdd);
			Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, 0x444444FF, kFillModeSolid);
			Novice::SetBlendMode(BlendMode::kBlendModeNormal);
			*/



			comboText.DrawNumber(MiddleCentor, Vector2{ 56, 128 } * 6);


			Bullet::DrawBullet();

			//Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, 0x000000FF, kFillModeSolid);
			/*enemy[0].position.Vector2Printf(0, 0);
			boss.statePosition.Vector2Printf(0, 50);*/

			//Novice::ScreenPrintf(10, 100, "%.3f", Length(Bullet::bullet[0].position, enemy[0].position) - (Bullet::bullet[0].radius + enemy[0].radius));

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

			/*if (boss.isAlive) {

				if (boss.attackFlag) {
					Novice::DrawLine(boss.statePosition.x, ToWorld(boss.statePosition.y), boss.endPosition.x, ToWorld(boss.endPosition.y), 0x00ffffff);
					boss.BossDraw();
				}

				//	Novice::DrawEllipse(boss.position.x, ToWorld(boss.position.y), boss.srcX, boss.srcY, 0.0f, boss.color, kFillModeSolid);

			}*/



			//	enemy[0].DrawEntity();

			//Novice::ScreenPrintf(100, 100, "boss.attackFlag %d", boss.attackFlag);
			//Novice::ScreenPrintf(100, 150, "boss.count %f", boss.count);
			///*Novice::ScreenPrintf(100, 170, "bullet.y %f", );*/
			//Novice::ScreenPrintf(100, 250, "velocity.x %f", player[0].velocity.x);
			//Novice::ScreenPrintf(100, 270, "velocity.y %f", player[0].velocity.y);

			break;
		case Scene::ResultScene:
			Novice::DrawSprite(0, 0, HwHBG, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(0, 0, GameOver, 1, 1, 0.0f, 0xFFFFFFFF);



			break;
		default:
			break;
		}

		//	Novice::DrawBox(fadeClass.fadePosition.x - fadeClass.fadeSize.x, fadeClass.fadePosition.y - fadeClass.fadeSize.y, fadeClass.fadeSize.x * 2, fadeClass.fadeSize.y * 2, 0.0f, fadeClass.fadeColor, kFillModeSolid);
		Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, fadeClass.fadeColor, kFillModeSolid);

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
