//Daniel Thompson
#ifndef _ARTISTS_HPP
#define _ARTISTS_HPP
#include "JSONArray.hpp"
#include "Artist.hpp"
#include "ArtistImages.hpp"

class Artists: public JSONArray
{
public:
  Artists();
  virtual ~Artists();

  int numArtists();
  void addArtist(Artist *artist);
  Artists *artistWithID(unsigned aID);
  void loadArtistsFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new Artist();  }
  
  void setAlbumsForArtists(Albums *albums);
  void setImagesForArtists(ArtistImages *);
  std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }
  void runAsserts();  
};
#endif
