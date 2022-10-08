#include "master-controller-tests.h"
namespace hpdf{
namespace controllers{//Instance

static MasterControllerTests instance;

MasterControllerTests::MasterControllerTests() : TestSuite("MasterControllerTests")
{

}
}
namespace controllers {//Scaffolding

void MasterControllerTests::initTestCase(){

}

void MasterControllerTests::cleanupTestCase()
{
}

void MasterControllerTests::init()
{
}

void MasterControllerTests::cleanup()
{
}

}
namespace controllers { // Tests
void MasterControllerTests::welcomeMessage_returnsCorrectMessage()
{
    QCOMPARE( masterController.welcomeMessage(), QString("Welcome to the Client Management system!") );
}
}}





