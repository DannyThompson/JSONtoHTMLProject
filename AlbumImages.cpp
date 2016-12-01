//Daniel Thompson
#include "AlbumImages.hpp"

AlbumImages::AlbumImages(){}

//All Functions are identical in logic to the functions in ArtistImages. See that file for details on the functions

int AlbumImages::numAlbumImages()
{
  return numJSONObjects();
}

void AlbumImages::addAlbumImage(AlbumImage *albumImage)
{
  listOfAlbumImages()->push_back(albumImage);
}

AlbumImages *AlbumImages::albumImageWithID(unsigned int abID)
{
  AlbumImages *list = new AlbumImages();
  for( auto it = listOfAlbumImages()->begin(); it != listOfAlbumImages()->end(); it++ )
    if( (*it)->albumID() == abID )
      list->addAlbumImage( (*it) );
  return list;
  
}

void AlbumImages::loadAlbumImagesFromFile(std::string fileName)
{
  std::fstream abStream;
  abStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(abStream);
  abStream.close();
}


std::string AlbumImages::htmlString()
{
  std::string temp;
  for(auto it = listOfAlbumImages()->begin(); it != listOfAlbumImages()->end(); it++)
    temp+= (*it)->htmlString();
  return temp;
}


void AlbumImages::runAsserts()
{

}


AlbumImages::~AlbumImages()
{
  
}

