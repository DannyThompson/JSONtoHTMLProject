#ifndef _ALBUMS
#define _ALBUMS
#include "JSONArray.hpp"
#include "Album.hpp"
#include "AlbumImages.hpp"

class Albums: public JSONArray
{
public:
  Albums();
  virtual ~Albums();

  int numAlbums();
  void addAlbum(Album *album);
  Albums *albumWithID(unsigned int alID);
  void loadAlbumsFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new Album();  }
  void setTracksForAlbums(Tracks *tracks);
  void setImagesForAlbums(AlbumImages *albumImages);
  
  std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; }
  void runAsserts(); 
};

#endif
