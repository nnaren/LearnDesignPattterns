

class NetworkState
{
public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;

    virtual ~NetworkState(){}
    // Network_Open,
    // NetWork_Close,
    // NetWork_Connect
};



class OpenState : public NetworkState
{
private:
    static NetworkState* instance_;
public:
    static NetworkState* getInstance(){
        if (instance_ == nullptr)
        {
            instance_ = new OpenState();
        }
        return instance_;
    }
    void Operation1(){
        //**********
        pNext = CloseState::getInstance();
    }
    void Operation2(){
        //..........
        pNext = ConnectState::getInstance();
    }
    void Operation3(){
        //$$$$$$$$$$
        pNext = OpenState::getInstance();
    }
};

class CloseState : public NetworkState
{
private:
    static NetworkState* instance_;
public:
    static NetworkState* getInstance(){
        if (instance_ == nullptr)
        {
            instance_ = new OpenState();
        }
        return instance_;
    }
    void Operation1(){
        //**********
        pNext = CloseState::getInstance();
    }
    void Operation2(){
        //..........
        pNext = ConnectState::getInstance();
    }
    void Operation3(){
        //$$$$$$$$$$
        pNext = OpenState::getInstance();
    }
};

class ConnectState : public NetworkState
{
private:
    static NetworkState* instance_;
public:
    static NetworkState* getInstance(){
        if (instance_ == nullptr)
        {
            instance_ = new OpenState();
        }
        return instance_;
    }
    void Operation1(){
        //**********
        pNext = CloseState::getInstance();
    }
    void Operation2(){
        //..........
        pNext = ConnectState::getInstance();
    }
    void Operation3(){
        //$$$$$$$$$$
        pNext = OpenState::getInstance();
    }
};

// 扩展子类


class NetworkProcessor {

    NetworkState* pState;
public:
    NetworkProcessor(NetworkState* pState) {
        this->pState = pState;
    }
    void Operation1(){
        //...
        pState->Operation1();
        pState = pState->pNext;
        //...
    }
    void Operation2(){
        //...
        pState->Operation1();
        pState = pState->pNext;
        //...
    }
    void Operation3(){
        //...
        pState->Operation3();
        pState = pState->pNext;
        //...
    }
};