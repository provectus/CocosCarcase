#include "AppModel.h"
#include "cocos2d.h"
#include <stdlib.h>

using namespace cocos2d;

const int DiamondTableSize = 5;

const DiamondItem* item = NULL;

AppModel* AppModel::_pInstace = 0;
AppModel* AppModel::getInstance() {
	if (_pInstace == NULL)
	{
		_pInstace = new AppModel();
		CCLog("initializing appmodel");
	}
	return _pInstace;
}

AppModel::AppModel() { 
	_diamonds.resize(DiamondTableSize*DiamondTableSize);

	for (int i = 0; i < DiamondTableSize; i++)
	{
		for (int j = 0; j < DiamondTableSize; j++)
		{
			_diamonds[i * DiamondTableSize + j] =  new DiamondItem();
		}
	}
}
AppModel::~AppModel() { 
	for (int i = 0; i <= _diamonds.size(); i++)
	{
		delete _diamonds[i];
	}
}

int AppModel::getTableSize()
{
	return DiamondTableSize;
}

DiamondItem* AppModel::getDiamondItemAtCell(int x, int y) {
	return _diamonds[x * DiamondTableSize + y];
}