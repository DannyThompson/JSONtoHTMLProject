//Daniel Thompson
#include "JSONDataItem.hpp"

JSONDataItem::JSONDataItem()
{
  _attribute = "";
  _svalue = "";
  _ivalue = 0;
  hasReadAnItem = false;
    _isNumber = false;

}


//Below is all the parsing logic for singular JSON items.
void JSONDataItem::parseJSONItem(std::fstream &stream)
{
  char c;
  
  if( !(stream >> c) || c != '"' )
  {
    std::cout << "Error reading item.\n";
    exit(1);
  }

  
  _attribute = readQuotedString(stream);
  
  if( !(stream>>c) || c != ':' )
    {
      std::cout <<"ERROR: Missing colon.\n";
      exit(2);
    }
  
  stream >> c;
  //Checks if the character is a digit. if so, unget.
  if( isdigit(c) )
    {
      _isNumber = true;
      stream.unget();
      stream >> _ivalue;
    }
  
  else{
     stream.unget();
    _svalue = readQuotedString(stream);
  }
}

std::string JSONDataItem:: readQuotedString(std::fstream &stream)
{  
  char c;
  std::string val;
  
  stream.get(c);
  do{
    if(  c == '\\' )
      {
	if( stream.peek() != '"' )
	  stream.get(c);

	
	stream.get(c);
	val+=c;
      }

    if(c != '"')
	val+=c;
    stream.get(c);
      
    }while( c != '"' );
  
  return val;
}

void JSONDataItem::print()
{
  std::cout << attribute();
  
  if( isNumber() )
    std::cout << integerValue();

  else
    std::cout<< stringValue();
}


//Attribute is the same as "key" from the first project. Key in the Key/value pair.
std::string JSONDataItem::attribute()
{
  return _attribute;
}

//This returns the value of the key if that value is a string
std::string JSONDataItem::stringValue()
{
  return _svalue;
}

//This returns the value of the key if that value is an integer
int JSONDataItem::integerValue()
{
  return _ivalue;
}

//Don't think this is used...but it works.
bool JSONDataItem::isNumber()
{
  return _isNumber;    
}

