#include "DiamondItem.h"
#include "Utils.h"

DiamondItem::DiamondItem(void)
{	
}

DiamondItem::~DiamondItem(void)
{
}

DiamondType DiamondItem::getType(){
	return (DiamondType)Utils::randomRange(3);
}