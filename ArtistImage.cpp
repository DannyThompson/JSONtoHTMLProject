//Daniel Thompson
#include "ArtistImage.hpp"
#include <sstream>
#include <string>
ArtistImage::ArtistImage()
{
  _type = "";
  _width = 0;
  _height = 0;
  _artistID = 0;
  _uri = "";

  cachedType = false;
  cachedWidth = false;
  cachedHeight = false;
  cachedArtistID = false;
  cachedURI = false;
}


//The below functions are identical in AlbumImages as well, and thus will only be commented here
//Type of the image; primary or Secondary.
std::string ArtistImage::type()
{
  if( cachedType )
    return _type;
  cachedType = true;
  return _type = valueForStringAttribute("type");
}

//Returns the width of the image
unsigned ArtistImage::width()
{
  if( cachedWidth )
    return _width;
  cachedWidth = true;
  return _width = valueForIntegerAttribute("width");
}

//Returns the height of the image
unsigned ArtistImage::height()
{
  if( cachedHeight )
    return _height;
  cachedHeight = true;
  return _height = valueForIntegerAttribute("height");
}

//Returns the artistID of the assigned artist
unsigned ArtistImage::artistID()
{
  if( cachedArtistID )
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}

//Returns the URL of the image
std::string ArtistImage::uri()
{
  if( cachedURI )
    return _uri;
  cachedURI = true;
  return _uri = valueForStringAttribute("uri");
}

//Part of the linked together htmlString functions for the final project.
std::string ArtistImage::htmlString()
{
  std::string w;
  std::string h;
  std::stringstream con;
  std::stringstream con2;

  con << width();
  w = con.str();
  con2 << height();
  h = con2.str();

  std::string temp = "<img class=\"image\" width=\"" + w + "\" height = \"" + h \
    + "\"  src=\""+ uri()+ "\">";

  return temp;
}

//Print. Solely used for testing.
void ArtistImage::print()
{
  std::cout << type() << "\n";
  std::cout << width() << "\n";
  std::cout << height() << "\n";
  std::cout << artistID() << "\n";
  std::cout << uri() << "\n";
}

//Destructor linked through inheritance.
ArtistImage::~ArtistImage()
{

}
