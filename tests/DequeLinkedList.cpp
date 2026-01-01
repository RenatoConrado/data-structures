#include "DequeLinkedList.hpp"
#include <gtest/gtest.h>
using namespace std;

TEST(deque_linked_list, all_operations) {
  DequeLinkedList<string> list;

  EXPECT_TRUE(list.isEmpty());
  cout << "List is empty: " << boolalpha << list.isEmpty() << endl;
  EXPECT_EQ(list.size(), 0);
  cout << "List size is 0: " << list.size() << endl;
  EXPECT_THROW(auto discard = list.getFront(), invalid_argument);
  EXPECT_THROW(auto discard = list.getRear(), invalid_argument);
  EXPECT_THROW(auto discard = list.getFrontString(), invalid_argument);
  EXPECT_THROW(auto discard = list.getRearString(), invalid_argument);

  cout << list.toString();

  constexpr auto value1 = "Value1";
  constexpr auto value2 = "Value2";

  cout << endl << "Front Values" << endl;
  list.insertFront(value1);
  ASSERT_EQ(list.getFront(), value1);
  cout << "First Value: " << value1 << endl;

  list.insertFront(value2);
  ASSERT_EQ(list.getFront(), value2);
  cout << "Second Value: " << value2 << endl;

  cout << "Rear Values" << endl;
  list.insertRear(value1);
  ASSERT_EQ(list.getRear(), value1);
  cout << "First Value: " << value1 << endl;

  list.insertRear(value2);
  ASSERT_EQ(list.getRear(), value2);
  cout << "Second Value: " << value2 << endl;

  cout << list.toString() << endl;

  cout << "Delete Front" << endl;
  const auto deleteFront = list.getFront();
  cout << "Value deleted: " << list.getFrontString();
  list.deleteFront();
  ASSERT_NE(list.getFront(), deleteFront);

  cout << "Delete Rear" << endl;
  const auto deleteRear = list.getRear();
  cout << "Value deleted: " << list.getRearString();
  list.deleteRear();
  ASSERT_NE(list.getRear(), deleteRear);

  cout << list.toString() << endl;

  cout << "Deleting Operation";

  list.clear();
  ASSERT_TRUE(list.isEmpty());
  cout << "List is empty: " << boolalpha << list.isEmpty() << endl;
  ASSERT_EQ(list.size(), 0);
  cout << "size 0: " << list.size() << endl;

  cout << list.toString() << endl;
}
