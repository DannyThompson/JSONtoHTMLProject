#include "Albums.hpp"
Albums::Albums(){}

int Albums::numAlbums()
{
  return numJSONObjects();
}

void Albums::addAlbum(Album *album)
{
  listOfAlbums()->push_back(album);
}

Albums *Albums::albumWithID( unsigned alID )
{
  Albums *newList = new Albums();
  for( auto it = listOfAlbums()->begin(); it != listOfAlbums()->end(); it++ )
    if( (*it)->artistID() == alID )
      newList->addAlbum( (*it) );
  return newList;
}

void Albums::loadAlbumsFromFile( std::string fileName)
{
  std::fstream alStream;
  alStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(alStream);
  alStream.close();
}

void Albums::setTracksForAlbums(Tracks *tracks)
{
  for( auto it = listOfAlbums()->begin(); it != listOfAlbums()->end(); it++ )
    (*it)->setTracks( tracks->trackWithID( (*it)->albumID() ) );
}


void Albums::setImagesForAlbums(AlbumImages *albumImages)
{
  for( auto it = listOfAlbums()->begin(); it != listOfAlbums()->end(); it++ )
    {
      std::vector<AlbumImage *> *t = albumImages->albumImageWithID( (*it)->albumID() )->listOfAlbumImages();
      for( auto i = t->begin(); i != t->end(); i++ )
	{
	  if( (*i)->type() == "primary" )
	    (*it)->primaryImage() = (*i);
	  else
	    (*it)->secondaryImage() = (*i);
	}
    }
}


std::string Albums::htmlString()
{
  std::string temp = "<h2>Albums</h2>";
  temp+= "<ol>";
  for(auto it = listOfAlbums()->begin(); it != listOfAlbums()->end(); it++ )
    temp+= (*it)->htmlString();
  
  temp+= "<div class=\"clear\">&nbsp;</div>";
  temp+= "</ol>";
  
  return temp;
}


void Albums::runAsserts()
{
  for( auto it = listOfAlbums()->begin(); it != listOfAlbums()->end(); it++ )
   (*it)->tracks()->print();  
}


Albums::~Albums()
{
    
}

