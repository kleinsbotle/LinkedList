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
        List<char>* list;
        ListTest(){
            list = new List<char>;
        }
    };
}


TEST_F(ListTest, IsEmpty) {
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, IsEmpty_false){
    list->push_front('a');
    EXPECT_FALSE(list->is_empty());
}


TEST_F(ListTest, GetSize_empty){
    EXPECT_EQ(0, list->get_size());
}

TEST_F(ListTest, GetSize){
    list->push_front('a');
    list->push_front('b');
    list->push_front('c');
    list->push_front('d');
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
    list->push_front('d');
    list->push_front('c');
    list->push_front('b');
    list->push_front('a');
    EXPECT_EQ('d', list->at(3));
}

TEST_F(ListTest, At_WrongIndex){
    list->push_front('a');
    try{
        list->at(5);
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}

TEST_F(ListTest, PushFront_empty){
    list->push_front('a');
    EXPECT_EQ('a', list->at(0));
}

TEST_F(ListTest, PushBack_empty){
    list->push_back('a');
    EXPECT_EQ('a', list->at(0));
}

TEST_F(ListTest, PushFront){
    list->push_back('b');
    list->push_front('a');
    EXPECT_EQ('a', list->at(0));
}


TEST_F(ListTest, PushBack){
    list->push_front('a');
    list->push_back('b');
    EXPECT_EQ('b', list->at(1));
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
    list->push_front('a');
    list->pop_back();
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, PopFront_1){
    list->push_back('a');
    list->pop_front();
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, PopBack){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->pop_back();
    EXPECT_EQ('c', list->at(2));
}

TEST_F(ListTest, PopFront){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->pop_front();
    EXPECT_EQ('b', list->at(0));
}

TEST_F(ListTest, Insert_empty){
    try{
        list->insert(1, 'a');
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, Insert_WrongIndex){
    list->push_front('a');
    try{
        list->insert(5, 'b');
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}

TEST_F(ListTest, Insert_first){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->insert(0, 'z');
    EXPECT_EQ('z', list->at(0));
}

TEST_F(ListTest, Insert){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->insert(2, 'z');
    EXPECT_EQ('z', list->at(2));
}

TEST_F(ListTest, Remove_first){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->remove(0);
    EXPECT_EQ('b', list->at(0));
}

TEST_F(ListTest, Remove_last){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->remove(3);
    EXPECT_EQ('c', list->at(2));
}

TEST_F(ListTest, Remove){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->push_back('e');
    list->remove(2);
    EXPECT_EQ('d', list->at(2));
}

TEST_F(ListTest, Clear){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->clear();
    EXPECT_TRUE(list->is_empty());
}

TEST_F(ListTest, Set_empty){
    try{
        list->set(2, 'a');
    }
    catch(std::length_error &except){
        EXPECT_THAT(std::string(except.what()), Eq("The list is empty"));
    }
}

TEST_F(ListTest, Set_wrong_index){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    try{
        list->set(5, 'z');
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}

TEST_F(ListTest, Set){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->set(2, 'f');
    EXPECT_EQ('f', list->at(2));
}

TEST_F(ListTest, Set_first){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->set(0, 'g');
    EXPECT_EQ('g', list->at(0));
}

TEST_F(ListTest, Set_last){
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    list->push_back('d');
    list->set(3, 'x');
    EXPECT_EQ('x', list->at(3));
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
    list->push_front('a');
    try{
        list->remove(2);
    }
    catch(std::out_of_range &except){
        EXPECT_THAT(std::string(except.what()), Eq("Incorrect index"));
    }
}


