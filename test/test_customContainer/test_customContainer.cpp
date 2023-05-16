
#include <gtest/gtest.h>
#include <customContainer.h>

//1. operator []
TEST(ROUND_HOOKS, BasicReadWrite) {
  //arrange
  auto vec = customContainer<int, std::allocator<int>>{};
  //act
  vec.PushBack(0);
  vec.PushBack(1);
  //assert
  EXPECT_EQ(vec[0] ,0);
  EXPECT_EQ(vec[1] ,1);
}
/*
//2. bool Reserve(size_t capacity)
TEST(RESERVE, BasicReserve) {
  //arrange
  auto vec = customContainer<int, std::allocator<int>>{};
  //act
  vec.Reserve(5);
  //assert
  EXPECT_EQ(vec.capacity() ,5);

}


//4. reference at (size_type idx)

TEST(AT, at)
{
  //arrange
  auto vec = customContainer<int, std::allocator<int>>{};
  //act
  vec.PushBack(45);
  //assert
  EXPECT_EQ(vec.at(0) ,45);

}
*/
