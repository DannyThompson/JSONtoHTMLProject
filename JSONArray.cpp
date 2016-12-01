//Daniel Thompson
#include "JSONArray.hpp"

//List of Objects represented with a vector
JSONArray::JSONArray()
{
  _listOfDataObjects = new std::vector<JSONDataObject *>;
}


void JSONArray::parseJSONArray(std::fstream &stream)
{
  char cc[2];
  cc[1] = '\0';
  if( ! (stream >> cc[0]) || cc[0] != '[' )
    {
      std::cout <<"Error #1 in reading Array\n";
      exit(1);
    }
  
    do {
      JSONDataObject *dItem = jsonObjectNode();
      dItem->parseFromJSONstream(stream);
      _listOfDataObjects->push_back(dItem);

      if( ! (stream >> cc[0]) )
	{
	  // print an error message and exit
	  std::cout << "Error #2 in reading Array\n";
	  exit(2);
	}
      
	if( cc[0] != ']' && cc[0] != ',' )
	  {
	    // print an error message and exit
	    std::cout << "Error #3 in reading Array\n";
	    exit(3);
	  }

	  } while( cc[0] != ']' );
}

int JSONArray::numJSONObjects()
{
  return _listOfDataObjects->size();
}

//used for testing
void JSONArray::print()
{
  for( auto it = _listOfDataObjects->begin(); it != _listOfDataObjects->end(); it++ )
    {
      (*it)->print();
    }
  
}

//Loops through and deletes objects
JSONArray::~JSONArray()
{
  for(auto it = _listOfDataObjects->begin(); it != _listOfDataObjects->end(); it++)
    delete (*it);

  delete _listOfDataObjects;
}
