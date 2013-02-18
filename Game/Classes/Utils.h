#pragma once
class Utils
{
public:
	static int randomRange(int max);
	static int randomRange(int min, int max);
	static float randomValue();

private:
	static bool _isRandomInited;

	static void initRandom();
};