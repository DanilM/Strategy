#include <QCoreApplication>
#include <iostream>

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual int DoAlgorithm(double lenSide) const = 0;
};

class Area
{

private:
    Strategy *strategy_;
public:
    Area(Strategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Area()
    {
        delete this->strategy_;
    }

    void set_strategy(Strategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    void printArea() const
    {
        int result = this->strategy_->DoAlgorithm(5);
        std::cout << "Figure Area: " << result << "\n";
    }
};

class SquareArea : public Strategy
{
public:
    int DoAlgorithm(double lenSide) const override
    {
        return lenSide*lenSide;
    }
};
class CircleArea : public Strategy
{
    int DoAlgorithm(double lenSide) const override
    {
        return 3.14*lenSide*lenSide;
    }
};

void ClientCode()
{
    Area *context = new Area(new SquareArea);
    std::cout << "Client: Strategy is set to find square area.\n";
    context->printArea();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to find circle area.\n";
    context->set_strategy(new CircleArea);
    context->printArea();
    delete context;
}

int main()
{
    ClientCode();
    return 0;
}
