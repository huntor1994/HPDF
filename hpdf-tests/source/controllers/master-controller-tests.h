#ifndef MASTERCONTROLLERTESTS_H
#define MASTERCONTROLLERTESTS_H

#include <QObject>
#include <QtTest>

#include <controllers/master-controller.h>
#include <test-suite.h>

namespace hpdf{
namespace controllers{
class MasterControllerTests : public TestSuite
{
    Q_OBJECT
public:
    MasterControllerTests();

private slots:
    /// @brief Called before the first test function is executed
    void initTestCase();
    /// @brief Called after the last test function was executed.
    void cleanupTestCase();
    /// @brief Called before each test function is executed.
    void init();
    /// @brief Called after every test function.
    void cleanup();

private slots:
    void welcomeMessage_returnsCorrectMessage();
private:
    MasterController masterController;
};

}
}



#endif // MASTERCONTROLLERTESTS_H
