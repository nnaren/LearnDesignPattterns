#include<string>
#include<iostream>

enum class RequestType
{
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3,
    UN_KOWN
};

class Reqest
{
private:
    std::string description;
    RequestType reqType;
public:
    Reqest(const std::string & desc, RequestType type) : description(desc) , reqType(type) {}
    RequestType getReqType() const {return reqType; }
    const std::string& getDescription() const { return description; }
    
};

class ChainHandler{
    ChainHandler *nextChain;
    void  sendReqestToNextHandler(const Reqest & req){
        if(nextChain != nullptr){
            nextChain->handle(req);
        }else
        {
            std::cout << "Can not process this req, Mybe a few days: " << req.getDescription() << std::endl;
        }
        
    }
protected:
    virtual bool canHandleRequest(const Reqest & req) = 0;
    virtual void processRequest(const Reqest & req) = 0;

public:
    ChainHandler() { 
        nextChain = nullptr;
    }
    void setNextChain(ChainHandler *next) { 
        nextChain = next; 
    }

    void handle(const Reqest & req){
        if (canHandleRequest(req)){
            processRequest(req);
        } else {
            sendReqestToNextHandler(req);
        }
        
    }
};


class Handler1 : public ChainHandler
{
protected:
    bool canHandleRequest(const Reqest & req) override {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }
    void processRequest(const Reqest & req) override {
        std::cout << "Handler1 is handle reqest: " << req.getDescription() << std::endl;
    }
};

class Handler2 : public ChainHandler
{
protected:
    bool canHandleRequest(const Reqest & req) override {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }
    void processRequest(const Reqest & req) override {
        std::cout << "Handler2 is handle reqest: " << req.getDescription() << std::endl;
    }
};

class Handler3 : public ChainHandler
{
protected:
    bool canHandleRequest(const Reqest & req) override {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }
    void processRequest(const Reqest & req) override {
        std::cout << "Handler3 is handle reqest: " << req.getDescription() << std::endl;
    }
};

int main(){
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);
    Reqest req("process task ...", RequestType::UN_KOWN);
    h1.handle(req);
    return 0;
}