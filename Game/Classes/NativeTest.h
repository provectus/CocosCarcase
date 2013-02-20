
class NativeTest
{
public:
	static NativeTest* getInstance();

	NativeTest(void);
	virtual ~NativeTest(void);

	void test();
private:
	static NativeTest* _pInstance;
};