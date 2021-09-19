class Context {

};

class TaxStrategy{
public:
    virtual double Calculate(const Context& constext) = 0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& constext) {
        //...
    }

};

class DETax : public TaxStrategy {
public:
    virtual double Calculate(const Context& constext) {
        //...
    }

};

class FRTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& constext) {
        //...
    }

};


class SalesOrder{
private:
    TaxStrategy* strategy;
public:
    SalesOrder(StrategyFactory* strategyFactory){  // 工厂模式
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }
    double CalculateTax(){
        //...
        Context context;
        
        double val = strategy->Calculate(context);
        //...
        return val;
    }
};