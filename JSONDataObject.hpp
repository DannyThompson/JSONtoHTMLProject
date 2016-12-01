//Daniel Thompson
#ifndef _JSONDataObject
#define _JSONDataObject
#include<vector>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include "JSONDataItem.hpp"

class JSONDataObject {
public:
  JSONDataObject();
  virtual ~JSONDataObject();
  
  std::vector<JSONDataItem *> *listOfDataItems() const { return _listOfDataItems; }
  
  void parseFromJSONstream(std::fstream &stream);
  virtual void print();
  std::string valueForStringAttribute(std::string s);
  int valueForIntegerAttribute(std::string s);

private:
  std::vector<JSONDataItem *> *_listOfDataItems;
};

#endif
