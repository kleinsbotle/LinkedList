//
// Created by efg on 04.03.2019.
//


#include "List.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;

namespace{
    class ListTest : public ::testing::Test{
    public:
        List<double>* list;
        ListTest(){
             list = new List<double>;
        }
    };
}


TEST_F(ListTest, IsEmpty) {
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, IsEmpty_false){
    list->push_front(0.123);
    EXPECT_FALSE(list->is_empty());
}


TEST_F(ListTest, GetSize_empty){
    EXPECT_EQ(0, list->get_size());
}

TEST_F(ListTest, GetSize){
    list->push_front(1.123);
    list->push_front(2.123);
    list->push_front(3.123);
    list->push_front(4.123);
    EXPECT_EQ(4, list->get_size());
}

TEST_F(ListTest, At_empty){
    try{
        list->at(1);
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, At) {
    list->push_front(4.123);
    list->push_front(3.123);
    list->push_front(2.123);
    list->push_front(1.123);
    EXPECT_EQ(3.123, list->at(2));
}

TEST_F(ListTest, At_WrongIndex){
    list->push_front(1.5);
    try{
        list->at(5);
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}

TEST_F(ListTest, PushFront_empty){
    list->push_front(1.123);
    EXPECT_EQ(1.123, list->at(0));
}

TEST_F(ListTest, PushBack_empty){
    list->push_back(1.123);
    EXPECT_EQ(1.123, list->at(0));
}

TEST_F(ListTest, PushFront){
    list->push_back(1.123);
    list->push_front(0.123);
    EXPECT_EQ(0.123, list->at(0));
}


TEST_F(ListTest, PushBack){
    list->push_front(0.123);
    list->push_back(1.123);
    EXPECT_EQ(1.123, list->at(1));
}

TEST_F(ListTest, PopBack_empty){
    try{
        list->pop_back();
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, PopFront_empty){
    try{
        list->pop_front();
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, PopBack_1){
    list->push_front(1.123);
    list->pop_back();
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, PopFront_1){
    list->push_back(1.123);
    list->pop_front();
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, PopBack){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->pop_back();
    EXPECT_EQ(3.123, list->at(2));
}

TEST_F(ListTest, PopFront){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->pop_front();
    EXPECT_EQ(2.123, list->at(0));
}

TEST_F(ListTest, Insert_empty){
    try{
        list->insert(1, 1.5);
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, Insert_WrongIndex){
    list->push_front(1.5);
    try{
        list->insert(5, 2.5);
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}

TEST_F(ListTest, Insert_first){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->insert(0, 0.123);
    EXPECT_EQ(0.123, list->at(0));
}

TEST_F(ListTest, Insert){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->insert(2, 0.123);
    EXPECT_EQ(0.123, list->at(2));
}

TEST_F(ListTest, Remove_first){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->remove(0);
    EXPECT_EQ(2.123, list->at(0));
}

TEST_F(ListTest, Remove_last){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->remove(3);
    EXPECT_EQ(3.123, list->at(2));
}

TEST_F(ListTest, Remove){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->push_back(5.123);
    list->remove(2);
    EXPECT_EQ(4.123, list->at(2));
}

TEST_F(ListTest, Clear){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->clear();
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, Set_empty){
    try{
        list->set(2, 2.5);
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, Set_wrong_index){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    try{
        list->set(5, 5.5);
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}
TEST_F(ListTest, Set){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->set(2, 7.123);
    EXPECT_EQ(7.123, list->at(2));
}

TEST_F(ListTest, Set_first){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->set(0, 10.123);
    EXPECT_EQ(10.123, list->at(0));
}

TEST_F(ListTest, Set_last){
    list->push_back(1.123);
    list->push_back(2.123);
    list->push_back(3.123);
    list->push_back(4.123);
    list->set(3, 10.123);
    EXPECT_EQ(10.123, list->at(3));
}


TEST_F(ListTest, Remove_empty){
    try{
        list->remove(1);
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}


TEST_F(ListTest, Remove_wrong_index){
    list->push_front(1.5);
    try{
        list->remove(2);
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}
