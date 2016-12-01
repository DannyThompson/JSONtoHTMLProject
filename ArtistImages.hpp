#ifndef _ARTISTIMAGES
#define _ARTISTIMAGES
#include "JSONArray.hpp"
#include "ArtistImage.hpp"

class ArtistImages: public JSONArray
{
public:
  ArtistImages();
  virtual ~ArtistImages();

  int numArtistImages();
  void addArtistImage(ArtistImage *artistImage);

  ArtistImages *artistImageWithID(unsigned arID);
  void loadArtistImagesFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new ArtistImage(); }

  std::vector<ArtistImage *> *listOfArtistImages() { return (std::vector<ArtistImage *> *) _listOfDataObjects; }

  void runAsserts();

};
#endif
