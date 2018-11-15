#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <vector>
#include <string>
#include "Dish.h"
#include "Table.h"
#include "Action.h"


enum Actions{OPEN, ORDER, MOVE, CLOSE, CLOSEALL, MENU, STATUS, LOG, BACKUP, RESTORE, WRONG};

class Restaurant{
public:
	Restaurant();
	Restaurant(const Restaurant &other);
	Restaurant(Restaurant &&other);
	Restaurant(const std::string &configFilePath);
	void start();
	int getNumOfTables() const;
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
	std::vector<Dish>& getMenu();
	Table* getTable(int id);
   	std::vector<Table*>& getTables();
	Restaurant& operator=(const Restaurant &other);
	Restaurant& operator=(Restaurant &&other);
	virtual ~Restaurant();

private:
	bool open;
	int numOfTables;
	int customersId;
	std::vector<Table*> tables;
	std::vector<Dish> menu;
	std::vector<BaseAction*> actionsLog;
	std::vector<string> argsLog;

	int readNumOfTables(int &index, const std::string &file);
	void createTables(int &index, const std::string &file, int numOfTables);
	void createMenu(int &i, const std::string &file);
	void clear();
	DishType convertDish(std::string str);
	Actions convertAct(std::string str);

	OpenTable* actionOpenTable(std::string s);
	Order* actionOrder(std::string s);
	MoveCustomer* actionMove(std::string s);
	Close* actionClose(std::string s);
	CloseAll* actionCloseAll();
	PrintMenu* actionPrintMenu(std::string s);
	PrintTableStatus* actionPrintTableStatus(std::string s);
	PrintActionsLog* actionPrintActionsLog(std::string s);
	BackupRestaurant* actionBackupRestaurant(std::string s);
	RestoreResturant* actionRestoreRestaurant(std::string s);
};

#endif
