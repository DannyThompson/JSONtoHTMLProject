#ifndef _ALBUMIMAGES
#define _ALBUMIMAGES
#include "JSONArray.hpp"
#include "AlbumImage.hpp"

class AlbumImages: public JSONArray
{
public:
  AlbumImages();
  virtual ~AlbumImages();

  int numAlbumImages();
  void addAlbumImage(AlbumImage *albumImage);

  AlbumImages *albumImageWithID(unsigned int abID);
  void loadAlbumImagesFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new AlbumImage(); }

  std::vector<AlbumImage *> *listOfAlbumImages() { return (std::vector<AlbumImage *> *) _listOfDataObjects; }
  
  void runAsserts();
};

#endif
