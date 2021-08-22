#include <QtTest>
#include "../HedralApp/Services/HFMCore/TestCore.h"
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
    printHello();
}

QTEST_APPLESS_MAIN(HedralMainTest)

#include "tst_hedralmaintest.moc"
