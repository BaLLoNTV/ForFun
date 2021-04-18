// ConsoleApplication28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
class Car;
class CarBuilderBase;
class CarBuilder;
class CarMechBuilder;
class CarSalonBuilder;

class Car 
{
public:
    static CarBuilder create();
    Car(Car&& ref) noexcept
        : wheel{std::move(ref.wheel)}, mark{ std::move(ref.mark) }, body{ std::move(ref.body) }, chair{ std::move(ref.chair) }, lamp{ std::move(ref.lamp) }, trim{ std::move(ref.trim) }
    {};
private:
    Car() {};
    std::string wheel,
        mark,
        body;
    std::string chair,
        lamp,
        trim;
    friend CarBuilderBase;
    friend CarBuilder;
    friend CarMechBuilder;
    friend CarSalonBuilder;
};

class CarBuilderBase
{
public:
    operator Car() { return std::move(carRef); }
    CarMechBuilder mech() const;
    CarSalonBuilder salon() const;
protected:
    Car& carRef;
    explicit CarBuilderBase(Car& tmp)
        : carRef{ tmp } {}
};

class CarBuilder : public CarBuilderBase
{
public:
    CarBuilder() : CarBuilderBase{ TempCar }
    {
    };
protected:
    Car TempCar;
};

class CarMechBuilder : public CarBuilderBase
{
public:
    explicit  CarMechBuilder(Car& TempCar) : CarBuilderBase(TempCar) {};
    CarMechBuilder& addWheel(std::string str) 
    {
        carRef.wheel = std::move(str);
        return *this;
    };
    CarMechBuilder& addMark(std::string str)
    {
        carRef.mark = std::move(str);
        return *this;
    };
    CarMechBuilder& addBody(std::string str)
    {
        carRef.body = std::move(str);
        return *this;
    };
protected:
};

class CarSalonBuilder : public CarBuilderBase
{
public:
    explicit  CarSalonBuilder(Car& TempCar) : CarBuilderBase(TempCar) {};
    CarSalonBuilder& addChair(std::string str)
    {
        carRef.chair = std::move(str);
        return *this;
    };
    CarSalonBuilder& addLamp(std::string str)
    {
        carRef.lamp = std::move(str);
        return *this;
    };
    CarSalonBuilder& addTrim(std::string str)
    {
        carRef.trim = std::move(str);
        return *this;
    };
protected:
};


CarBuilder Car::create()
{
    return {};
};


/*
CarBuilder Car::create()
{
    CarBuilder tmp;
    return tmp;
};
*/

CarMechBuilder CarBuilderBase::mech() const
{
    CarMechBuilder tmp(carRef);
    return tmp;
};

/*
CarMechBuilder CarBuilderBase::mech() const
{
    return { carRef };
};
*/
CarSalonBuilder CarBuilderBase::salon() const
{
    CarSalonBuilder tmp(carRef);
    return tmp;
};

int main()
{ 
    {
        CarBuilder CarBuild;
        CarBuild.mech().addBody("Body0").addMark("Mark0").addWheel("Wheel0")
            .salon().addChair("Chair0").addLamp("Lamp0").addTrim("Trim0");
        Car MyCar = CarBuild;
        Car OtherCar = Car::create().mech().addBody("Body1").addMark("Mark1").addWheel("Wheel1")
            .salon().addChair("Chair1").addLamp("Lamp1").addTrim("Trim1");
        Car AbotherCar = Car::create().mech().addBody("Body2").addMark("Mark2").addWheel("Wheel2")
            .salon().addChair("Chair2").addLamp("Lamp2").addTrim("Trim2");
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
