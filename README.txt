Daniel Thompson
CS-315
Project 3

       The program works as it should.
       Each object is created and the respective JSON is parsed, then formatted in HTML.
       All classes are linked through inheritance. Artists->Albums->Tracks.
       In main, after the objects are parsed and HTML is made, the HTML is inputted into a
       MASTER.html file, which is derived from the artists_template.html.
       A new directory, called html_albums, is made every time you use "make run".
       This stores every album according to its Album ID within this directory.
       So if you wish to run the program twice in a row, you'll want to do a "make clean"
       so that it removes this directory for remaking.
       The auto iterator is used heavily in this project to iterate through vectors.

       **Side Note: A copy constructor was unable to be figured out in a timely manner, and thus is not used.
       	      	    The program still works, and things are deleted, but not as effeciently as if a copy constructor was used.
