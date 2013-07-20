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

__Example__

First lets define our sort descriptors

	-(NSArray *)sortDescriptors
	{
	    return @[ [NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES] ];
	}
	
Also, lets's add a method to provide our cells for both datasources 
**Note we use [weakSelf tableView] because the UISearchResultsController's tableView doesn't have its cell identifier's set

	-(void)configureCellForDataSource:(SPXDatasource *)datasource
	{
	    id __weak weakSelf = self;

	    [datasource setCellForRowAtIndexPathBlock:^
	     UITableViewCell *(UITableView *tableView, id object, NSIndexPath *indexPath)
	    {
	        // we have to use self.tableView here since that's the tableView with its cell identifier's set
	        UITableViewCell *cell = [[weakSelf tableView] dequeueReusableCellWithIdentifier:@"Cell"];
	        cell.textLabel.text = [object valueForKey:@"name"];
	        return cell;
	    }];
	}

Next, lets define our main tableView datasource

	-(void)configureCoreDataSource
	{
	    // get a new coreData based datasource
	    _coreDataSoure = [SPXCoreDataDatasource dataSourceForTableView:self.tableView
	                                                           context:self.managedObjectContext
	                                                        entityName:self.entityName];

	    // configure its sortDescriptors
	    [_coreDataSoure setSortDescriptors:[self sortDescriptors]];

	    // configure the cells for this datasource
	    [self configureCellForDataSource:_coreDataSoure];
	    [self.tableView setDataSource:_coreDataSoure];
	}

Now, let's define our search datasource

	-(void)configureSearchDataSource
	{
	    // get a new search based datasource
	    _searchDataSource = [SPXSearchDatasource dataSourceForSearchDisplayController:self.searchDisplayController];

	    // configure its sortDescriptors
	    [_searchDataSource setSortDescriptors:[self sortDescriptors]];

	    id __weak weakSelf = self;
	    [_searchDataSource setSourceWithBlock:^NSArray *
	    {
	        return [[weakSelf coreDataSoure] source];
	    }];

	    // configure how the search will be handled
	    [_searchDataSource setSearchPredicate:^NSPredicate *(NSString *searchString)
	    {
	        return [NSPredicate predicateWithFormat:@"SELF.name contains[c] %@", searchString];
	    }];

	    // configure the cells for this datasource
	    [self configureCellForDataSource:_searchDataSource];
	    [self.searchDisplayController setSearchResultsDataSource:_searchDataSource];
	}
	
Finally let's load everything up...
	
	-(void)viewDidLoad
	{
	    [super viewDidLoad];

	    [self configureCoreDataSource];
	    [self configureSearchDataSource];
	}
	
__Summary__

Of course the search datasource may not be required at all, but you can see how little code is required in order to get this working and completely hooked up to CoreData :)