//Daniel Thompson
#include "AlbumImage.hpp"
#include <sstream>
#include <string>

//See ArtistImage for details on the functions. All logically identical to those in that class.

AlbumImage::AlbumImage()
{
  _type = "";
  _width = 0;
  _height = 0;
  _albumID = 0;
  _uri = "";

  cachedType = false;
  cachedWidth = false;
  cachedHeight = false;
  cachedAlbumID = false;
  cachedURI = false;
}

std::string AlbumImage::type()
{
  if( cachedType )
    return _type;
  cachedType = true;
  return _type = valueForStringAttribute("type");
}

unsigned AlbumImage::width()
{
  if( cachedWidth )
    return _width;
  cachedWidth = true;
  return _width = valueForIntegerAttribute("width");  
}

unsigned AlbumImage::height()
{
  if( cachedHeight )
    return _height;
  cachedHeight = true;
  return _height = valueForIntegerAttribute("height");
}

unsigned AlbumImage::albumID()
{
  if( cachedAlbumID )
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}

std::string AlbumImage::uri()
{
  if( cachedURI )
    return _uri;
  cachedURI = true;
  return _uri = valueForStringAttribute("uri");
}

void AlbumImage::print()
{
  std::cout << type() << "\n";
  std::cout << width() << "\n";
  std::cout << height() << "\n";
  std::cout << albumID() << "\n";
  std::cout << uri() << "\n";
}

std::string AlbumImage::htmlString()
{
  std::string w;
  std::string h;
  std::stringstream con;
  std::stringstream con2;

  con << width();
  w = con.str();
  con2 << height();
  h = con2.str();

  std::string temp = "<img class=\"image\" width=\"" + w + "\" height = \"" + h + "\"  src=\""+ uri()+ "\">"; 
    
  return temp; 
}

AlbumImage::~AlbumImage()
{
 
}
