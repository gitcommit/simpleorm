#ifndef CONN_H
#define CONN_H

class Database;

class Conn {
public:
  Conn();
  virtual void setDatabase(Database* db);
  virtual const bool hasDatabase() const;
  virtual Database* database() const;
  
private:
    Database* _database;
};

#endif CONN_H
