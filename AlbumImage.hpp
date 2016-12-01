//Daniel Thompson
#ifndef _AlbumImage_hpp
#define _AlbumImage_hpp
#include "JSONDataObject.hpp"

class AlbumImage: public JSONDataObject {

public:
  AlbumImage();
  virtual ~AlbumImage();

  std::string type();
  unsigned width();
  unsigned height();
  unsigned albumID();
  std::string uri();

  void print();
  std::string htmlString();

private:

  std::string _type, _uri;
  unsigned _albumID, _width, _height;

  bool cachedType, cachedWidth, cachedHeight, cachedAlbumID, cachedURI;
};
#endif





