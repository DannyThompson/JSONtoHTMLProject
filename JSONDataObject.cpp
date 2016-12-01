//Daniel Thompson
#include "JSONDataObject.hpp"
#include<vector>


//Vector of objects(artists, tracks, images, albums)
JSONDataObject::JSONDataObject()
{
  _listOfDataItems = new std::vector<JSONDataItem *>;
}

void JSONDataObject::parseFromJSONstream(std::fstream &stream)
{
  char c;
  if( !(stream >> c) || c != '{' )
    {
      std::cout << "Error reading Object.\n";
      exit(EXIT_FAILURE);
    }
  
  do{
    JSONDataItem *item = new JSONDataItem();
    item->parseJSONItem( stream );
    _listOfDataItems->push_back( item );
    stream >> c;
  }while(c != '}' );
}

//Uses the c++ auto iterator
std::string JSONDataObject::valueForStringAttribute(std::string s)
{
  for( auto it = _listOfDataItems->begin(); it != _listOfDataItems->end(); it++ )
    if(s == (*it)->attribute() && !(*it)->isNumber() )
      return (*it)->stringValue();

  return "";
}
 
//Uses auto iterator again
int JSONDataObject::valueForIntegerAttribute(std::string s)
{
  for(auto it = _listOfDataItems->begin(); it != _listOfDataItems->end(); it++)
    {
      if(s == (*it)->attribute() && (*it)->isNumber() )
	return (*it)->integerValue();
    }
  return 0;
}

//Intended for testing. Not really used in this class
void JSONDataObject::print()
{

}

//Destructor. Loops throug hand deletes each item.
JSONDataObject::~JSONDataObject()
{
  for(auto it = _listOfDataItems->begin(); it != _listOfDataItems->end(); it++)
    delete (*it);

  delete _listOfDataItems;
}
