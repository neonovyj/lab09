// Copyright 2021 ivan <ikhonyak@gmail.com>

#include "output.hpp"

#include <fstream>
#include <iostream>

#include "ThreadPool.h"
void outPut::writeFile(std::vector<std::string> imgs) {
  try {
    for (auto& img : imgs) {
      file << img << std::endl;
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void outPut::writeIMG(std::vector<std::string> imgs) {
  pool.enqueue([imgs, this]() {
    this->writeFile(imgs);
  });
}
