//Daniel Thompson
#ifndef _Album_hpp
#define _Album_hpp
#include "JSONDataObject.hpp"
#include "Tracks.hpp"
#include "AlbumImage.hpp"

class Artist;
class Album: public JSONDataObject {

public:
  Album();
  virtual ~Album();
  
  std::string title();
  std::string genres();
  unsigned albumID();
  unsigned artistID();
  unsigned numTracks();
  unsigned numImages();
  std::string year();
  
  void setTracks(Tracks *tracks);
  void setArtist(Artist *artist);
  Artist *artist() { return _artist; }
  Tracks *tracks()  { return _tracks; }
  
  AlbumImage *&primaryImage() { return _primaryAlbumImage;   }
  AlbumImage *&secondaryImage()  { return _secondaryAlbumImage; }
  
  void print();
  std::string htmlString();

private:

  std::string _title, _genres, _year;
  unsigned _albumID, _artistID, _numTracks, _numImages;

  bool cachedTitle, cachedGenres, cachedNumImages, cachedAlbumID, cachedArtistID, cachedNumTracks, cachedYear;

  AlbumImage *_primaryAlbumImage, *_secondaryAlbumImage;
  Tracks *_tracks;
  Artist *_artist;
};
#endif
