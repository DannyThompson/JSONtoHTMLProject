//Daniel Thompson
#include <vector>
#include <fstream>
#include <iostream>
#include<cstdlib>

class JSONDataItem {
public:
  JSONDataItem();
  void parseJSONItem(std::fstream &stream);
  std::string attribute();
  int integerValue();
  std::string stringValue();
  bool isNumber();
  void print();

private:
  std::string _attribute, _svalue;
  int _ivalue;
  bool hasReadAnItem, _isNumber;

  std::string readQuotedString(std::fstream &stream);
};

