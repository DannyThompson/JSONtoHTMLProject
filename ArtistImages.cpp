//Daniel Thompson
#include "ArtistImages.hpp"

ArtistImages::ArtistImages(){}

//Number of objects in the vector
int ArtistImages::numArtistImages()
{
  return numJSONObjects();
}

//Adds the image to the vector
void ArtistImages::addArtistImage(ArtistImage *artistImage)
{
  listOfArtistImages()->push_back(artistImage);
}

//makes a vector of Artist images according to 
ArtistImages *ArtistImages::artistImageWithID(unsigned arID)
{
  ArtistImages *images = new ArtistImages();
  for(auto it = listOfArtistImages()->begin(); it != listOfArtistImages()->end(); it++ )
    if( (*it)->artistID() == arID )
      images->addArtistImage( (*it) );
  return images;
}

//Loads the JSON file of Artist Images
void ArtistImages::loadArtistImagesFromFile(std::string fileName)
{
  std::fstream aiStream;
  aiStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(aiStream);
  aiStream.close();
}

//htmlString function
std::string ArtistImages::htmlString()
{
  std::string temp;
  for( auto it = listOfArtistImages()->begin(); it != listOfArtistImages()->end(); it++)
    temp+= (*it)->htmlString();
  return temp;
}

//Intended for testing. Wasn't used much at all other than in one class.
void ArtistImages::runAsserts(){}

//Destructor
ArtistImages::~ArtistImages()
{
  
}

