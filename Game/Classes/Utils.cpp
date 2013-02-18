#include "Utils.h"
#include <cstdlib>
#include <ctime>

bool Utils::_isRandomInited = false;

void Utils::initRandom() {
	if (_isRandomInited) {
		return;
	}
	_isRandomInited =true;

	srand((unsigned)time(0));
}

int Utils::randomRange(int max) {
	initRandom();

	return rand() % max;
}
int Utils::randomRange(int min, int max) {
	initRandom();

	return (rand() + min) % max;
}
float Utils::randomValue(){
	initRandom();

	float result = (rand() % 1000000) / (float)1000000;
	return result;
}