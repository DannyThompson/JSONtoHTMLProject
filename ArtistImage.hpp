//Daniel Thompson
#ifndef _ArtistImage_hpp
#define _ArtistImage_hpp
#include "JSONDataObject.hpp"

class ArtistImage: public JSONDataObject {
  
public:
  ArtistImage();
  virtual ~ArtistImage();
  
  std::string type();
  unsigned width();
  unsigned height();
  unsigned artistID();
  std::string uri();
  
  void print();
  std::string htmlString();
  
private:
  
  std::string _type, _uri;
  unsigned _artistID, _width, _height;
  
  bool cachedType, cachedWidth, cachedHeight, cachedArtistID, cachedURI;
};
#endif




