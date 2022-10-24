#pragma once

class Timer {
protected:
	int goalFlame = 0;
	int nowFlame = 0;
public:

	/// <summary>
	/// �t���[�����I�_�ɓ��B���Ă��邩
	/// </summary>
	/// <returns>���B�̐^�U�l</returns>
	bool isFinish() const;

	/// <summary>
	/// �t���[���̉��Z
	/// </summary>
	void AddFlame();

	/// <summary>
	/// �t���[���̃��Z�b�g
	/// </summary>
	void ResetFlame();

	/// <summary>
	/// �t���[���̃��Z�b�g
	/// </summary>
	void FlameEnd();

	/// <summary>
	/// �I�_�t���[���̐ݒ�
	/// </summary>
	/// <param name="GoalFlameValue">�I�_�t���[��</param>
	void SetGoalFlame(const int GoalFlameValue);

	bool isActive()const;

	int GetNowFlame()const;

	int GetGoalFlame()const;

	float GetProgress()const;
};


//class FunctionTimer {
//protected:
//	Timer actionTimer;
//	void (*functionPointer)();
//
//public:
//
//	bool isActive() {
//		return actionTimer.isActive();
//	}
//
//	void SetFunction(void(*functionPointer)()) {
//		this->functionPointer = functionPointer;
//	}
//
//	void TimerStart(int goalFlame) {
//
//		actionTimer.ResetFlame();
//		actionTimer.SetGoalFlame(goalFlame);
//	}
//	void TimerUpdate() {
//		if (!actionTimer.isFinish() && actionTimer.GetGoalFlame() != 0) {
//			actionTimer.AddFlame();
//		}
//		else if (actionTimer.GetGoalFlame() != 0) {
//			actionTimer.SetGoalFlame(0);
//			actionTimer.ResetFlame();
//			functionPointer();
//		}
//	}
//};
//
//class SceneChangeTimer :public FunctionTimer {
//protected:
//	void (*sceneFunctionPointer)(SceneID) = SceneChange;
//	SceneID Scene = TitleScene;
//public:
//	void SetFunction(void(*functionPointer)(SceneID), SceneID Scene) {
//		this->sceneFunctionPointer = functionPointer;
//		this->Scene = Scene;
//	}
//	void TimerUpdate() {
//		if (!actionTimer.isFinish() && actionTimer.GetGoalFlame() != 0) {
//			actionTimer.AddFlame();
//		}
//		else if (actionTimer.GetGoalFlame() != 0) {
//			actionTimer.SetGoalFlame(0);
//			actionTimer.ResetFlame();
//			sceneFunctionPointer(Scene);
//		}
//	}
//};