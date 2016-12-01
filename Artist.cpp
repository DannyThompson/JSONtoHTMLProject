//Daniel Thompson
#include "Artist.hpp"
#include "Album.hpp"

Artist::Artist()
{
  _name = "";
  _realName = "";
  _profile = "";
  _numImages = "";
  _artistID = 0;
  _primaryImage = nullptr;
  _secondaryImage = nullptr;
  
  cachedName = false;
  cachedRealName = false;
  cachedProfile = false;
  cachedNumImages = false;
  cachedArtistID = false;
}

std::string Artist::profile()
{
    if( cachedProfile )
      return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");   
}

std::string Artist::realName()
{
  if( cachedRealName )
    return _realName;
  cachedRealName = true;
  return _realName = valueForStringAttribute("real_name");
}

std::string Artist::artistName()
{
  if( cachedName )
    return _name;
  cachedName = true;
  return _name = valueForStringAttribute("artist_name");
}

std::string Artist::numImages()
{
  if( cachedNumImages )
    return _numImages;
  cachedNumImages = true;
  return _numImages = valueForStringAttribute("num_images");
}

unsigned Artist::artistID()
{
  if( cachedArtistID )
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}

void Artist::setAlbums(Albums *albums)
{
  _albums = albums;
}

void Artist::print()
{
  
  std::cout << artistName() << "\n";
  std::cout << realName() << "\n";
  std::cout << profile() << "\n";
  std::cout << numImages() << "\n";
  std::cout << artistID() << "\n";
  
  if(_primaryImage != nullptr)
    primaryImage()->print();
  
  if(_secondaryImage != nullptr)
    secondaryImage()->print();

  
  std::cout << "\n";
}


std::string Artist::htmlString()
{
  
  std::string temp = "<h2>" + artistName() + "</h2>";

  if(_primaryImage != nullptr)
    temp+= primaryImage()->htmlString();

  else if(_secondaryImage != nullptr)
    temp+= secondaryImage()->htmlString();
  
  temp+= "<table class=\"artistInfo\">";
  temp+= "<tbody>";
  temp+= "<tr>";
  temp+=  "<td class=\"tagName\">Number of Images:</td>";
  temp+= "<td class=\"value\"> "+ numImages() + "</td>";
  temp+= "</tr>";
  temp+= "<tr>";
  temp+= "<td>Profile:</td>";
  temp+= "<td class=\"value\"> "+ profile() + "</td>";
  temp+= "</tr>";
  temp+= "</tbody>";
  temp+= "</table>";

  temp+= "<div class=\"clear\">&nbsp;</div>";
  
  temp+= albums()->htmlString();
  return temp;
}

Artist::~Artist()
{
  
}
