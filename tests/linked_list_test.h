// Copyright 2016 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LINKED_LIST_TESTS_TEST

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "algo.h"


class LinkedListTest : public ::testing::Test{
  public:
    std::vector<int> vec_of_5;
    std::vector<int> vec_of_hundred;
    std::vector<int> empty_vec;
    
    LinkedListTest(): 
      vec_of_5({1,2,3,4,5}), vec_of_hundred(), empty_vec(){
        vec_of_5.reserve(5);
        vec_of_hundred.reserve(100);
        for (int i = 0; i < 100; i++){
          vec_of_hundred.push_back(i);
        }
      }

  private:
    
};
#endif

//TODO(mlekena) write helloworld test in
// the linked_list_test.cc