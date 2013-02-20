#include "NativeTest.h"
#include <stdlib.h>

NativeTest* NativeTest::_pInstance = NULL;

NativeTest::NativeTest(void) { }
NativeTest::~NativeTest(void) { }

NativeTest* NativeTest::getInstance() {
	if (_pInstance == NULL) {
		_pInstance = new NativeTest();
	}

	return _pInstance;
}