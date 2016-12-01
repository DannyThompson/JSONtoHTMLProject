//Daniel Thompson
#ifndef _JSONARRAY
#define _JSONARRAY

#include "JSONDataObject.hpp"
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>

class JSONArray {
public:
  JSONArray();
  ~JSONArray();
  std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
  virtual JSONDataObject *jsonObjectNode() = 0;
  int numJSONObjects();
  void parseJSONArray(std::fstream &stream);
  virtual void print();

protected:
  std::vector<JSONDataObject *> *_listOfDataObjects;

};
#endif
