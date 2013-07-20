UITableView-Datasource
======================

Some convenience classes for dealing with UITableView datasources for collections, CoreData and search results.

So I thought about it and decided to try and build something into my Snippex library whereby the datasource would be a separate class altogether..

What I ended up with was an abstract class that does all the common things, like cell creation, predicate and sorting management and also some animation stuff.
Then I used that to create a coreData subclass, a collection (array) subclass and a search (UISearchResultsController) subclass.

Now its really easy to use! Existing storyboard, no subclassing required and no setup. Just copy in the files and implement it with an existing UITableViewController. Best thing is you can swap between types really easily too, in fact you don’t even need a UITableViewController subclass in many instances..  You could write all the code in your AppDelegate or some other file and just assign the datasource from there. 

This is awesome because it means using the same datasource, cells, etc.. for multiple screens/tables is mostly 1 line of code per controller.

There’s about 100 lines in that TableViewController class and a bunch of files, but if you look carefully you’ll see that I’ve included some other SPX files that are NOT required for these new datasources to work, they are their for my convenience. :)
The datasource class is the only group you need to take into a new project to use these classes.

__Blocks__

Well, I wanted to be able to provide the cells and their config from the controller, since this class would normally know about the original object logic, so that’s why the cell are provided through blocks.

For the search I needed a way to provide the source every time its presented, because the data may have changed since it was last loaded. This allows me to request the source in its current state right before display.

The other useful block is the search one. This allow you to get a hold of the current searchString and provide your own predicate since I don’t know which field you want to search against. :)