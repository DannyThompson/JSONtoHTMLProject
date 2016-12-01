#Daniel Thompson

all: run.x

FLAGS = -ggdb -std=c++11 -Wextra -Wall

JSONDataItem.o: JSONDataItem.hpp JSONDataItem.cpp
	g++ $(FLAGS) -c JSONDataItem.cpp -o JSONDataItem.o

JSONDataObject.o: JSONDataObject.cpp  JSONDataObject.cpp
	g++ $(FLAGS) -c JSONDataObject.cpp -o JSONDataObject.o

JSONArray.o: JSONArray.hpp JSONArray.cpp
	g++ $(FLAGS) -c JSONArray.cpp -o JSONArray.o

Track.o: Track.hpp Track.cpp
	g++ $(FLAGS) -c Track.cpp -o Track.o

Tracks.o: Tracks.hpp Track.cpp
	g++ $(FLAGS) -c Tracks.cpp -o Tracks.o

Artist.o: Artist.hpp Artist.cpp
	g++ $(FLAGS) -c Artist.cpp -o Artist.o

Artists.o: Artists.hpp Artist.cpp
	g++ $(FLAGS) -c Artists.cpp -o Artists.o

Album.o: Album.hpp Album.cpp
	g++ $(FLAGS) -c Album.cpp -o Album.o

Albums.o: Albums.hpp Album.cpp
	g++ $(FLAGS) -c Albums.cpp -o Albums.o

AlbumImage.o: AlbumImage.hpp AlbumImage.cpp
	g++ $(FLAGS) -c AlbumImage.cpp -o AlbumImage.o

AlbumImages.o: AlbumImages.hpp AlbumImage.cpp
	g++ $(FLAGS) -c AlbumImages.cpp -o AlbumImages.o

ArtistImage.o: ArtistImage.hpp ArtistImage.cpp
	g++ $(FLAGS) -c ArtistImage.cpp -o ArtistImage.o

ArtistImages.o: ArtistImages.hpp ArtistImage.cpp
	g++ $(FLAGS) -c ArtistImages.cpp -o ArtistImages.o

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o

run.x: JSONDataItem.o JSONDataObject.o JSONArray.o Track.o Tracks.o Album.o Albums.o Artist.o Artists.o AlbumImage.o AlbumImages.o ArtistImage.o ArtistImages.o main.o
	g++ $(FLAGS) JSONDataItem.o JSONDataObject.o JSONArray.o Track.o Tracks.o Album.o Albums.o Artist.o Artists.o ArtistImage.o ArtistImages.o  AlbumImage.o AlbumImages.o main.o -o run.x


clean:
	rm -f *.o *.x *~ *#
	rm -r html_albums

run:
	mkdir html_albums
	./run.x
