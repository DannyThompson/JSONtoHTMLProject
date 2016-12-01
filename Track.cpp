//Daniel Thompson
#include "Track.hpp"
#include <sstream>
#include <string>

Track::Track()
{
  _artistName = "";
  _title = "";
  _duration = "";
  _position = "";
  _albumName = "";
  _albumID = 0;

  cachedArtistName = false;
  cachedTitle = false;
  cachedAlbumName = false;
  cachedAlbumID = false;
  cachedPosition = false;
  cachedDuration = false;
  
}

std::string Track::artistName()
{
  if( cachedArtistName )
    return _artistName;
  cachedArtistName = true;
  return _artistName = valueForStringAttribute("artist_name");
}

std::string Track::title()
{
  if( cachedTitle )
    return _title;
  cachedTitle = true;
  return _title = valueForStringAttribute("title");
}

std::string Track::albumName()
{
  if( cachedAlbumName )
    return _albumName;
  cachedAlbumName = true;
  return _albumName = valueForStringAttribute("album_name");
}

unsigned Track::albumID()
{
  if( cachedAlbumID )
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}
std::string Track::duration()
{
  if( cachedDuration )
    return _duration;
  cachedDuration = true;
  return _duration = valueForStringAttribute("duration");
  
}

std::string Track::position()
{
  if( cachedPosition )
    return _position;
  cachedPosition = true;
  return _position = valueForStringAttribute("position");
  
}
  
void Track::print()
{
  std::cout << artistName() << "\n";
  std::cout << title() << "\n";
  std::cout << albumName() << "\n";
  std::cout << albumID() << "\n";
  std::cout << duration() << "\n";
  std::cout << position() << "\n";
}



std::string Track::htmlString()
{
  std::string temp = "<tr class =\"tracks\">";
 
  temp+= "<td class= \"trackName\">\"" + title() + "\"</td>";
  temp+= "<td></td>";
  temp+= "<td>" +duration() + "</td>";
  temp+="</tr>";

  return temp;
}

Track::~Track()
{
  
}
