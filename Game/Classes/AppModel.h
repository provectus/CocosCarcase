#include "DiamondItem.h"
#include <vector>

class AppModel
{
public:
	static AppModel* getInstance();

	AppModel();
	virtual	~AppModel();

	DiamondItem* getDiamondItemAtCell(int x, int y);
	int getTableSize();
private:
	static AppModel* _pInstace;

	std::vector<DiamondItem*> _diamonds;
};