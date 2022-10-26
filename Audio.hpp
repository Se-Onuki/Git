#pragma once

#include <Novice.h>

enum BGM_and_HandleArray {
	Sound,
	Handle
};

/// Sound
// BGM

int OpeningBGM[2] = { 0 ,-1 };
int MenuBGM[2] = { 0 ,-1 };

int Lo_FiBGM[2] = { 0,-1 };
int ClearBGM[2] = { 0,-1 };

inline void ImportAudio() {

	OpeningBGM[Sound] = Novice::LoadAudio("./Resources/Sounds/BGM/Wind_path.wav");
}