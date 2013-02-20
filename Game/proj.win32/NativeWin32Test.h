#include "NativeTest.h"

class NativeWin32Test :	public NativeTest
{
public:
	NativeWin32Test(void);
	virtual ~NativeWin32Test(void);

	virtual NativeTest* createInsance();

	virtual void test();

};

