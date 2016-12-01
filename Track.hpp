//Daniel Thompson
#ifndef _Track_hpp
#define _Track_hpp
#include "JSONDataObject.hpp"

class Track: public JSONDataObject {
  
public:
  Track();
  virtual ~Track();

  std::string artistName();
  std::string title();
  std::string albumName();
  unsigned albumID();
  std::string duration();
  std::string position();
  
  void print();
  std::string htmlString();

private:
  
  std::string _artistName, _title, _albumName, _duration, _position;
  unsigned _albumID;
  
  bool cachedArtistName, cachedTitle, cachedAlbumName, cachedDuration, cachedPosition, cachedAlbumID;
};
#endif

