#include <vector>
#include <string>
//数据库访问有关的基类
class IDBConnection{
public:
    virtual void ConnectionString(std::string) =0;
};

class IDBCommand{
public:
    virtual void CommandText(std::string) =0;
    virtual IDataReader* ExecuteReader() =0;
};

class IDataReader{
public:
    virtual bool Read() = 0;
};

class IDBFactory
{
public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDataReader* CreateDBReader() = 0;
};
// SQL Server

class SqlConnection:public IDBConnection{};
class SqlCommand:public IDBCommand{};
class SqlDataReader:public IDataReader{};

class SqlDBFactory: public IDBFactory{};

// Mysql

class MysqlConnection:public IDBConnection{};
class MysqlCommand:public IDBCommand{};
class MysqlDataReader:public IDataReader{};

class MysqlDBFactory: public IDBFactory{};

// Oracle

class OracleConnection:public IDBConnection{};
class OracleCommand:public IDBCommand{};
class OracleDataReader:public IDataReader{};

class OracleDBFactory: public IDBFactory{};


class EmployeeDAO {
    IDBFactory* dbFactory;
public:
    std::vector<EmployeeDAO> GetEmployees() {
        IDBConnection* connection = dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command = dbFactory->CreateDBCommand();
        command->CommandText("...");

        IDataReader* reader = command->ExecuteReader();
        while (reader->Read())
        {
            
        }
        
    }
};