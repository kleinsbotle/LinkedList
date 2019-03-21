#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Test/List.h"
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    int n = RUN_ALL_TESTS();
    return n;
}
