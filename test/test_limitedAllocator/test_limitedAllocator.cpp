#include "ip_filter.h"
#include "test_ip_filter.h"

/*using ::testing::Return;

FooTest::FooTest() {
    // Have qux return true by default
    ON_CALL(m_bar, qux()).WillByDefault(Return(true));
    // Have norf return false by default
    ON_CALL(m_bar, norf()).WillByDefault(Return(false));
}*/

FooTest::~FooTest() {};

void FooTest::SetUp() {};

void FooTest::TearDown() {};



//("192.168.0.1",'.') -> ["192","168","0","1"]
TEST(Split, BasicSplit) {
  //arrange
  std::string ip="192.168.0.1";
  std::vector<std::string> r;
  char d='.';
  //act
    r=split(ip,d);
  //assert
    ASSERT_EQ(r[0], "192");
    ASSERT_EQ(r[1], "168");
    ASSERT_EQ(r[2], "0");
    ASSERT_EQ(r[3], "1");
}

// ("",  '.') -> [""]
TEST(Split, EmptyString) {
  //arrange
  std::string ip="";
  std::vector<std::string> r;
  char d='.';
  //act
    r=split(ip,'.');
  //assert
  ASSERT_EQ(r[0], "");
}
// ("..", '.') -> ["", "", ""]
TEST(Split, TwoDots) {
  //arrange
  std::string ip="..";
  std::vector<std::string> r;
  char d='.';
  //act
    r=split(ip,d);
  //assert
    ASSERT_EQ(r[0], "");
    ASSERT_EQ(r[1], "");
    ASSERT_EQ(r[2], "");
}

/*
TEST_F(FooTest, ByDefaultBazFalseIsFalse) {
    Foo foo(m_bar);
    EXPECT_EQ(foo.baz(false), false);
}

TEST_F(FooTest, SometimesBazFalseIsTrue) {
    Foo foo(m_bar);
    // Have norf return true for once
    EXPECT_CALL(m_bar, norf()).WillOnce(Return(true));
    EXPECT_EQ(foo.baz(false), true);
}
*/
