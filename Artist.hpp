//Daniel Thompson
#ifndef ARTIST_HPP
#define ARTIST_HPP
#include "ArtistImage.hpp"
#include "Albums.hpp"
#include "JSONDataObject.hpp"

class Artist: public JSONDataObject {
public:
  Artist();
  virtual  ~Artist();

  std::string profile();
  std::string artistName();
  std::string realName();
  std::string numImages();
  unsigned artistID();

  void  print();
  std::string htmlString();

  void setAlbums(Albums *albums);
  Albums *albums() { return _albums; }
  ArtistImage *&primaryImage()       { return _primaryImage;   }
  ArtistImage *&secondaryImage()     { return _secondaryImage; }

private:
  std::string _name, _realName, _profile, _numImages;
  unsigned _artistID;
  bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

  
  ArtistImage *_primaryImage, *_secondaryImage;
  Albums *_albums;
};

#endif
