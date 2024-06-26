// Copyright 2021 ivan <ikhonyak@gmail.com>
#ifndef INCLUDE_HTMLPARSER_HPP_
#define INCLUDE_HTMLPARSER_HPP_
#include "ThreadPool.h"
#include "iostream"
#include "output.hpp"
#include "string"
#include "vector"

class htmlDownloader;
struct url {
  std::string domen;
  std::string uri;
};
class htmlParser {
 private:
  ThreadPool parserPool_;
  outPut& outputObj_;
  void collectIMG(std::vector<std::string> pages, htmlDownloader& downloader,
                  int depth);

 public:
  htmlParser(outPut& outputObj, int threadNum)
      : parserPool_(threadNum), outputObj_(outputObj) {}
  void startParse(std::vector<std::string> pages, htmlDownloader& downloader,
                  int depth);
};
#endif  // INCLUDE_HTMLPARSER_HPP_
