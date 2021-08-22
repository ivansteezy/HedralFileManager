#include <QtTest>

// add necessary includes here

class HedralMainTest : public QObject
{
    Q_OBJECT

public:
    HedralMainTest();
    ~HedralMainTest();

private slots:
    void test_case1();

};

HedralMainTest::HedralMainTest()
{

}

HedralMainTest::~HedralMainTest()
{

}

void HedralMainTest::test_case1()
{

}

QTEST_APPLESS_MAIN(HedralMainTest)

#include "tst_hedralmaintest.moc"
