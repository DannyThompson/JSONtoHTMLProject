#include "Album.hpp"
#include "Artist.hpp"
Album::Album()
{
  _title = "";
  _genres = "";
  _year = "";
  _artistID = 0;
  _albumID = 0;
  _numImages = 0;
  _numTracks = 0;
  _primaryAlbumImage = nullptr;
  _secondaryAlbumImage = nullptr;
  
  cachedGenres = false;
  cachedTitle = false;
  cachedAlbumID = false;
  cachedArtistID = false;
  cachedNumImages = false;
  cachedNumTracks = false;
  cachedYear = false;
}

std::string Album::title()
{
  if( cachedTitle )
    return _title;
  cachedTitle = true;
  return _title = valueForStringAttribute("title");
}

std::string Album::genres()
{
  if( cachedGenres )
    return _genres;
  cachedGenres = true;
  return _genres = valueForStringAttribute("genres");
}

std::string Album::year()
{
  if( cachedYear )
    return _year;
  cachedYear = true;
  return _year = valueForStringAttribute("year");
}

unsigned Album::albumID()
{
  if( cachedAlbumID )
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album::artistID()
{
  if( cachedArtistID )
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}

unsigned Album::numTracks()
{
  if( cachedNumTracks )
    return _numTracks;
  cachedNumTracks = true;
  return _numTracks = valueForIntegerAttribute("num_tracks");
}

unsigned Album::numImages()
{
  if( cachedNumImages )
    return _numImages;
  cachedNumImages = true;
  return _numImages = valueForIntegerAttribute("num_images");
}

void Album::setTracks(Tracks *tracks)
{
  _tracks = tracks;
}

void Album::setArtist(Artist *artist)
{
  _artist = artist;
}

void Album::print()
{
  std::cout << title() << "\n";
  std::cout << genres() << "\n";
  std::cout << albumID() << "\n";
  std::cout << artistID() << "\n";
  std::cout << numTracks() << "\n";
  std::cout << year() << "\n";
  std::cout << numImages() << "\n";

  if(_primaryAlbumImage != nullptr)
    primaryImage()->print();

  if(_secondaryAlbumImage != nullptr)
    secondaryImage()->print();

  std::cout << "\n";
}


std::string Album::htmlString()
 {
   std::string temp = "<p>";
   temp+= "<strong>" + title() + "</strong>";
   temp+= "</p>";

   
   if(_primaryAlbumImage != nullptr)
     temp+= primaryImage()->htmlString();
   
   else if(_secondaryAlbumImage != nullptr)
     temp+= secondaryImage()->htmlString();
   

   // temp+= "\">";
   temp+= "<table class=\"albumInfo\">";

   temp+= "<tbody>";
   temp+= "<tr>";
   temp+= "<td class=\"aTitle\" colspan=\"2\">" + title() + "</td>";
   temp+= "</tr>";
   
   temp+= "<tr>";
   temp+= "<td class=\"tdNarrow\">Artist:</td>";
   temp+= "<td class=\"value\"> " + artist()->artistName()  + "</td>";
   temp+= "</tr>";
   temp+= "<tr>";
   temp+= "<td class=\"tdNarrow\">Genres:</td>";
   temp+= "<td class=\"value\"> " + genres() + "</td>";
   temp+= "</tr>";
   temp+= "<tr>";
   temp+= "<td>Year:</td>";
   temp+= "<td class=\"value\"> " + year() +"</td>";
   temp+= "</tr>";
   temp+= "</tbody>";
   temp+= "</table>";
   temp+= "<div class=\"clear\">&nbsp;</div>";
   temp+= tracks()->htmlString();
   
   return temp;
 }

 
 Album::~Album()
 {
  
 }
